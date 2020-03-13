#ifndef FENRESULTAT_H
#define FENRESULTAT_H

#include <QApplication>
#include <QtWidgets>

class FenResultat : public QDialog
{
    public:
    FenResultat();
    void ajouteLigne( QString );

    private:
    QTextEdit   *m_resultTexte;
    QVBoxLayout *m_layoutResult;
};

#endif // FENRESULTAT_H
