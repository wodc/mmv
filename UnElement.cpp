#include "UnElement.h"

UnElement::UnElement(){
    m_c=0;
    m_adr=0;
    m_flag=0;
};

void UnElement::setElement(QChar ch){
    m_c=ch.cell();
};

unsigned char UnElement::element(){
    return(m_c);
};

bool UnElement::write( unsigned int adr ){
    if( m_flag == 0 ){
        m_adr  = adr;
        m_flag = 1;
        m_instruction = QString("WRITE '%1' AT 0x%2").arg(QChar(m_c)).arg(m_adr, 4, 16, QChar('0'));
        m_instruction.append( QChar::LineFeed );
        return true;
    }
    return false;
};

bool UnElement::read( unsigned int *adr ){
    if( m_flag == 1 ){
        *adr   = m_adr;
        m_flag = 2;
        m_instruction = QString("READ AT 0x%2").arg(m_adr, 4, 16, QChar('0'));
        m_instruction.append( QChar::LineFeed );
        return true;
    }
    return false;
};

QString UnElement::instruction(){
    return(m_instruction);
};
