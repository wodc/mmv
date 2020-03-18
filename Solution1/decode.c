#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <inttypes.h>

typedef union {
	unsigned char 	dc[4];
	uint32_t 		di;
} data_t32;

int main(int argc, char *argv[] ){
	char buff[0x400]; 
	data_t32 data;
	char *fName=NULL;
	char flag_arg='\0';
	int fi=0;
	
	for(int i=0;i<argc;i++ ){
		if( strlen( argv[i]) > 1 && argv[i][0] == '-'){
			flag_arg = argv[i][1];
		} else {
			if( flag_arg == 'f' ){
				fName = malloc( strlen(argv[i] +1 ) );
				strcpy( fName, argv[i] );
				flag_arg='\0';
			}
		}
	}	
	if( fName == NULL ){
		fprintf(stderr, "usage : %s -f <file>\n", argv[0] );
		return(1);
	} else {
		if( (fi=open(fName,O_RDONLY)) > 0 ){
			int nblu=0;
			uint32_t inst;
			uint32_t adr;
			uint32_t value;
			while( (nblu = read(fi, data.dc, 4)) == 4 ){
				/* decode les 4 octets ( 32 bits ) 
				   masque : nnniiinn nnnaaaaa aaaaannd dddddddn 
				   n=none
				   i=instruction ( 011 Write, 101 Read )
				   a=adresse ( 10 bits de 0x0 à 0x3ff )
				   d=donnee ( 8 bits )
				*/
				inst  = data.di;
				inst  >>=26;
				inst  &= 0x7; // 3 bits 7=111
				adr   = data.di;
				adr   >>=11;
				adr   &= 0x3ff; // 10 bits 3ff=11 1111 1111
				value = data.di;
				value >>=1;
				value &= 0xff; // 8 bits ff=1111 1111				
				if( inst == 0x3 ){ // write 011
					buff[ adr ] = value;
				} else if( inst == 0x5 ){ // read 101
					fputc( buff[ adr ], stdout );
				}
			}
			fputc( '\n', stdout );
			close(fi);
		} else {
			fprintf(stderr, "erreur d'ouverture du fichier : %s\n", fName );
			return(2);
		}
		free(fName);
	}
	return(0);
}
