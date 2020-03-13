#include "Moteur.h"
#include "UneLettre.h"

Moteur::Moteur( QString data ){
    m_size   = data.size();
    m_indice = 0; // Indice dans m_el
    m_indBin = 0; // indice dans m_bin
    m_cWr    = 0;
    m_cRd    = 0;
    m_el.resize(m_size);
    m_bin.resize(m_size*2); // 2 type d'instruction write et read

    for (int i = 0; i < m_size; ++i) {
        m_el[i].setElement( data.at(i) );
    }

};

bool Moteur::tryWrite(QDataStream& out){
    quint32 ind = QRandomGenerator::global()->bounded(m_size);
    quint32 adr = QRandomGenerator::global()->bounded(mc_tailleMem);
    t_conv a;

    if(m_cWr>(2*m_cRd)){ ind=m_indice; }
    if( m_el[ind].write(adr, m_bin[m_indBin] ) ){
        a.i = m_bin[m_indBin].binCode();
        for(int i=2;i<4;i++) out << a.ch[i];
        for(int i=0;i<2;i++) out << a.ch[i];
        m_instruction = m_bin[m_indBin].showInstruction();
        m_instruction.append( QString(" -> [%1]").arg(m_bin[m_indBin].showBinCode()) );
        m_instruction.append( QChar::LineFeed );
        ++m_indBin;
        m_cWr++;
        return(true);
    }
    return( false);
};

bool Moteur::allIsWrite(){
    return( m_cWr == m_size );
}

bool Moteur::tryRead(QDataStream& out){
   t_conv a;
   if( m_el[m_indice].read( m_bin[m_indBin] ) ){
       a.i = m_bin[m_indBin].binCode();
       for(int i=2;i<4;i++) out << a.ch[i];
       for(int i=0;i<2;i++) out << a.ch[i];
       m_instruction = m_bin[m_indBin].showInstruction();
       m_instruction.append( QString(" -> [%1]").arg(m_bin[m_indBin].showBinCode()) );
       m_instruction.append( QChar::LineFeed );
       ++m_indice;
       ++m_indBin;
       m_cRd++;
       return(true);
   }
   return( false);
};

bool Moteur::allIsRead(){
    return( m_cRd == m_size );
}

QString Moteur::instruction(){
    return( m_instruction );
};
