#include <QApplication>
#include <QTranslator>
#include <QLocale>
#include <QLibraryInfo>
#include "FenPrincipale.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    qsrand(QDateTime::currentMSecsSinceEpoch() / 1000);

    QString locale = QLocale::system().name().section('_', 0, 0);
    QTranslator translator;
    translator.load(QString("qt_") + locale, QLibraryInfo::location(QLibraryInfo::TranslationsPath));
    app.installTranslator(&translator);

    FenPrincipale fenetre;
    fenetre.show();

    return app.exec();
}
