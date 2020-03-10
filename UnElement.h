#ifndef UNELEMENT_H
#define UNELEMENT_H

#include <QApplication>

class UnElement{
  private :
    unsigned char m_c;
    unsigned int  m_adr;
    unsigned char m_flag;
    QString m_instruction;
  public :
    UnElement();
    void setElement( QChar );
    unsigned char element();
    bool write( unsigned int );
    bool read( unsigned int *  );
    QString instruction();
};

#endif // UNELEMENT_H
