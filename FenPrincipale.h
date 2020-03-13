#ifndef FENPRINCIPALE_H
#define FENPRINCIPALE_H

#include <QApplication>
#include <QtWidgets>
#include <QDataStream>
#include "FenResultat.h"

class FenPrincipale : public QWidget
{
    Q_OBJECT

    public:
    FenPrincipale();

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
    FenResultat  *m_fenetreResultat;
};

#endif // FENPRINCIPALE_H
