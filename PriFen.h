#ifndef PRIFEN_H
#define PRIFEN_H

#include <QApplication>
#include <QtWidgets>
#include <QDataStream>
#include "FenResult.h"

class PriFen : public QWidget
{
    Q_OBJECT

    public:
    PriFen();

    public slots:
    void ouvrirResultat();
    void selectionFichier();

    private:
    QGridLayout  *m_layoutData;
    QLabel       *m_labelPhrase;
    QLineEdit    *m_dataPhrase;
    QLabel       *m_labelFichier;
    QLineEdit    *m_fichierBinaire;
    QPushButton  *m_boutonSelection;

    QPushButton  *m_boutonLancer;
    QPushButton  *m_boutonReset;
    QPushButton  *m_boutonQuitter;
    QHBoxLayout  *m_layoutGo;

    QVBoxLayout  *m_layoutGlobale;
    FenResult    *m_fenetreResultat;
};

#endif // PRIFEN_H
