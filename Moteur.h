#ifndef MOTEUR_H
#define MOTEUR_H

#include <QApplication>
#include <QVector>
#include <QRandomGenerator>
#include <QDataStream>
#include "UneLettre.h"

typedef union conv {
    quint32 i;
    unsigned char ch[4];
} t_conv;

class Moteur{
  private :
    quint32 const mc_tailleMem = 0x400;
    int m_size;
    int m_indice;
    int m_cWr;
    int m_cRd;
    unsigned int m_AdrLu;
    QVector<UneLettre> m_el;
    QString m_instruction;

  public :
    Moteur( QString );
    bool tryWrite(QDataStream &);
    bool allIsWrite();
    bool tryRead(QDataStream &);
    bool allIsRead();
    QString instruction();
};

#endif // MOTEUR_H
