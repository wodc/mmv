#include "UnElement.h"

UnElement::UnElement(){
    m_c        = 0;
    m_adr      = 0;
    m_flag     = 0;
    m_binCode[0]  = QRandomGenerator::global()->bounded(0xffffffff);
    m_binCode[0] &= 0xe3e00601;
    m_binCode[1]  = QRandomGenerator::global()->bounded(0xffffffff);
    m_binCode[1] &= 0xe3e007ff;
};

void UnElement::setElement(QChar ch){
    m_c=ch.cell();
};

unsigned char UnElement::element(){
    return(m_c);
};

bool UnElement::write( unsigned int adr ){
    quint32 a;
    unsigned char d;
    if( m_flag == 0 ){
        m_adr  = adr;
        m_flag = 1;
        m_binCode[0] |= 0xef000000;
        a = m_adr;
        a <<=11;
        m_binCode[0] |= a;
        d = m_c;
        d <<=1;
        m_binCode[0] |= d;
        m_instruction = QString("WRITE '%1' AT 0x%2").arg(QChar(m_c)).arg(m_adr, 4, 16, QChar('0'));
        return true;
    }
    return false;
};

bool UnElement::read( unsigned int *adr ){
    quint32 a;
    if( m_flag == 1 ){
        *adr   = m_adr;
        m_flag = 2;
        m_binCode[1] |= 0xf7000000;
        a = m_adr;
        a <<=11;
        m_binCode[1] |= a;
        m_instruction = QString("READ      AT 0x%2").arg(m_adr, 4, 16, QChar('0'));
        return true;
    }
    return false;
};

QString UnElement::instruction(){
    return(m_instruction);
};

quint32 UnElement::binCode(char inst){
    if( inst == 'w')
        return(m_binCode[0]);
    else if( inst == 'r' )
        return(m_binCode[1]);
    return('\0');
}
