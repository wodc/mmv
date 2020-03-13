#ifndef UNELETTRE_H
#define UNELETTRE_H

#include <QApplication>
#include <QRandomGenerator>

#include "UnCodeBinaire.h"

class UneLettre{
  private :
    unsigned char m_c;
    quint32  m_adr;
    unsigned char m_flag;
  public :
    UneLettre();
    void setElement( QChar );
    unsigned char element();
    bool write( unsigned int, UnCodeBinaire & );
    bool read( UnCodeBinaire & );
};

#endif // UNELETTRE_H
