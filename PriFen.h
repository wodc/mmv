#ifndef PRIFEN_H
#define PRIFEN_H

#include <QApplication>
#include <QtWidgets>
#include "FenResult.h"

class PriFen : public QWidget
{
    Q_OBJECT

    public:
    PriFen();

    public slots:
    void ouvrirResultat();

    private:
    QFormLayout *m_layoutData;
    QLineEdit   *m_dataPhrase;

    QPushButton *m_boutonLancer;
    QPushButton *m_boutonReset;
    QPushButton *m_boutonQuitter;
    QHBoxLayout *m_layoutGo;

    QVBoxLayout *m_layoutGlobale;
    FenResult   *m_fenetreResultat;
};

#endif // PRIFEN_H
