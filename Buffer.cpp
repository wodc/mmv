#include "Buffer.h"
#include "UnElement.h"

Buffer::Buffer( QString data ){
    m_size   = data.size();
    m_indice = 0;
    m_cWr    = 0;
    m_cRd    = 0;
    m_el = new QVector<UnElement>(m_size);

    for (int i = 0; i < m_size; ++i) {
        (*m_el)[i].setElement( data.at(i) );
    }

};

bool Buffer::tryWrite(){
    quint32 ind = qrand()%m_size;
    quint32 adr = qrand()%mc_tailleMem;
    if(m_cWr>(2*m_cRd)){ ind=m_indice; }
    if( (*m_el)[ind].write(adr) ){
        m_instruction = (*m_el)[ind].instruction();
        m_cWr++;
        return(true);
    }
    return( false);
};

bool Buffer::allIsWrite(){
    return( m_cWr == m_size );
}

bool Buffer::tryRead(){
   if( (*m_el)[m_indice].read( &m_AdrLu ) ){
       m_instruction = (*m_el)[m_indice++].instruction();
       m_cRd++;
       return(true);
   }
   return( false);
};

bool Buffer::allIsRead(){
    return( m_cRd == m_size );
}

QString Buffer::instruction(){
    return( m_instruction );
};
