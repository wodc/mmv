#ifndef FENRESULT_H
#define FENRESULT_H

#include <QApplication>
#include <QtWidgets>

class FenResult : public QDialog
{
    public:
    FenResult();
    void ajouteLigne( QString );

    private:
    QTextEdit   *m_resultTexte;
    QVBoxLayout *m_layoutResult;
};

#endif // FENRESULT_H
