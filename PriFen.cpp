#include "FenResult.h"
#include "PriFen.h"

PriFen::PriFen() : QWidget()
{
    this->setWindowTitle("Construction de l'exercice");

    m_dataPhrase      = new QLineEdit;
    m_dataPhrase->setFixedWidth( 600 );
    m_layoutData      = new QFormLayout;
    m_layoutData->addRow("Phrase a traiter", m_dataPhrase);

    m_boutonLancer    = new QPushButton("Go");
    m_boutonReset     = new QPushButton("Reset");
    m_boutonQuitter   = new QPushButton("Quitter");
    m_layoutGo        = new QHBoxLayout;

    m_fenetreResultat = new FenResult;

    m_layoutGo->addWidget( m_boutonLancer);
    m_layoutGo->addWidget( m_boutonReset);
    m_layoutGo->addWidget( m_boutonQuitter);

    m_layoutGlobale   = new QVBoxLayout( this );
    m_layoutGlobale->addLayout( m_layoutData );
    m_layoutGlobale->addLayout( m_layoutGo );

    QObject::connect(m_boutonLancer, SIGNAL(clicked()), this, SLOT(ouvrirResultat()));
    QObject::connect(m_boutonReset, SIGNAL(clicked()), m_dataPhrase, SLOT(clear()));
    QObject::connect(m_boutonQuitter , SIGNAL(clicked()), qApp, SLOT(quit()));
}

void PriFen::ouvrirResultat()
{
    QChar c;
    QString sResult;

    if( m_dataPhrase->text().isEmpty() ){
        QMessageBox::critical(this, "Phrase incorrecte", "Vous n'avez renseigné de phrase à coder.");
        return;
     }
    for (int i = 0; i < m_dataPhrase->text().size(); ++i) {
        c = m_dataPhrase->text().at(i);
        sResult.append( c );
        sResult.append( QChar::LineFeed );
        m_fenetreResultat->ajouteLigne( sResult );
        m_fenetreResultat->show();
     }
}
