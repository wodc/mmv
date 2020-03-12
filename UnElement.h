#ifndef UNELEMENT_H
#define UNELEMENT_H

#include <QApplication>
#include <QRandomGenerator>

class UnElement{
  private :
    unsigned char m_c;
    quint32  m_adr;
    unsigned char m_flag;
    QString m_instruction;
    quint32 m_binCode[2];
  public :
    UnElement();
    void setElement( QChar );
    unsigned char element();
    bool write( unsigned int );
    bool read( unsigned int *  );
    QString instruction();
    quint32 binCode(char);
};

#endif // UNELEMENT_H
