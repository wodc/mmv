#include "UneLettre.h"

UneLettre::UneLettre(){
    m_c        = 0;
    m_adr      = 0;
    m_flag     = 0;
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
        return true;
    }
    return false;
};

bool UneLettre::read( UnCodeBinaire& cbin ){
    if( m_flag == 1 ){
        m_flag = 2;
        cbin.setBinCode( m_adr, '\0' );
        return true;
    }
    return false;
};

