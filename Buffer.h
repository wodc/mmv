#ifndef BUFFER_H
#define BUFFER_H

#include <QApplication>
#include <QVector>
#include <QRandomGenerator>
#include "UnElement.h"

class Buffer{
  private :
    quint32 const mc_tailleMem = 0x400;
    int m_size;
    int m_indice;
    int m_cWr;
    int m_cRd;
    unsigned int m_AdrLu;
    QVector<UnElement> *m_el;
    QString m_instruction;

  public :
    Buffer( QString );
    bool tryWrite();
    bool allIsWrite();
    bool tryRead();
    bool allIsRead();
    QString instruction();
};

#endif // BUFFER_H
