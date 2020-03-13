#include "UnCodeBinaire.h"

UnCodeBinaire::UnCodeBinaire(){
    m_binCode  = QRandomGenerator::global()->bounded(0xffffffff);
};

void UnCodeBinaire::setBinCode( quint32 adr, unsigned char data='\0'){
    quint32 a;
    unsigned char d;
    if( data != '\0' ){ // instruction write
        m_binCode &= 0xe3e00601; // masque : 1110 0011 1110 0000 0000 0110 0000 0001 ( code, adresse, donnee )
        m_binCode |= 0xef000000; // positionne l'instruction write ( 011 )
        a = adr;
        a <<=11;
        m_binCode |= a; // positionne l'adresse
        d = data;
        d <<=1;
        m_binCode |= d; // positionne la donnee
        m_instruction = QString("WRITE '%1' AT 0x%2").arg(QChar(data)).arg(adr, 4, 16, QChar('0'));
    } else { // instruction read
        m_binCode &= 0xe3e007ff; // masque : 11100011 1110 0000 0000 0111 1111 1111 ( code, adresse )
        m_binCode |= 0xf7000000; // positionne l'instruction read ( 101 )
        a = adr;
        a <<=11;
        m_binCode |= a;
        m_instruction = QString("READ      AT 0x%2").arg(adr, 4, 16, QChar('0'));
    }
};

quint32 UnCodeBinaire::binCode(){
   return( m_binCode );
};

QString UnCodeBinaire::showInstruction(){
    return( m_instruction );
};

QString UnCodeBinaire::showBinCode(){
    return( QString("%1").arg( m_binCode, 32, 2, QChar('0')) );
};
