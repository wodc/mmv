# mmv
mini MV
exercice sur les bits

L'application Qt code une phrase sur 32 bits pour créer un fichier binaire
L'exercice consiste à écrire un programme C qui décode ce fichier binaire

Les paquets de 32 bits sont codé de la façon suivante :

poid : 	33222222 22221111 11111100 00000000
		21098765 43210987 65432109 87654321
bits : 	nnniiinn nnnaaaaa aaaaannd dddddddn

i contenu sur 3  bits de 27 a 29 est l'instruction Write = 011 Read = 101
a contenu sur 10 bits de 12 a 21 est l'adresse ou se passe l'operation dans la memoire ( de taille 1024 = 0x400 )
d contenu sur  8 bits de 02 a 09 est la donnée ( pour l'instruction write )

lors d'un  write on stock la donnée à l'adresse indiquée.
lors d'un read on lit et on affiche a l'ecran le contenu de l'adresse indiquée.


  
