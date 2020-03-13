#include "UneLettre.h"

UneLettre::UneLettre(){
    m_c        = 0;
    m_adr      = 0;
    m_flag     = 0;
    m_binCode[0]  = QRandomGenerator::global()->bounded(0xffffffff);
    m_binCode[0] &= 0xe3e00601;
    m_binCode[1]  = QRandomGenerator::global()->bounded(0xffffffff);
    m_binCode[1] &= 0xe3e007ff;
};

void UneLettre::setElement(QChar ch){
    m_c=ch.cell();
};

unsigned char UneLettre::element(){
    return(m_c);
};

bool UneLettre::write( unsigned int adr, UnCodeBinaire& cbin ){
    if( m_flag == 0 ){
        m_adr  = adr;
        m_flag = 1;
        cbin.setBinCode( m_adr, m_c );
        m_instruction = QString("WRITE '%1' AT 0x%2").arg(QChar(m_c)).arg(m_adr, 4, 16, QChar('0'));
        return true;
    }
    return false;
};

bool UneLettre::read( UnCodeBinaire& cbin ){
    if( m_flag == 1 ){
        m_flag = 2;
        cbin.setBinCode( m_adr, '\0' );
        m_instruction = QString("READ      AT 0x%2").arg(m_adr, 4, 16, QChar('0'));
        return true;
    }
    return false;
};

QString UneLettre::instruction(){
    return(m_instruction);
};

quint32 UneLettre::binCode(char inst){
    if( inst == 'w')
        return(m_binCode[0]);
    else if( inst == 'r' )
        return(m_binCode[1]);
    return('\0');
}
