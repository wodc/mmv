#include <QApplication>
#include <QPushButton>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QPushButton bouton("Clic pour demarrer...");
    bouton.show();

    return app.exec();
}
