#ifndef UNCODEBINAIRE_H
#define UNCODEBINAIRE_H

#include <QApplication>
#include <QRandomGenerator>

class UnCodeBinaire{
  private :
    QString m_instruction;
    quint32 m_binCode;
  public :
    UnCodeBinaire();
    void setBinCode( quint32, unsigned char );
    quint32 binCode();
    QString showInstruction();
    QString showBinCode();
};

#endif // UNCODEBINAIRE_H
