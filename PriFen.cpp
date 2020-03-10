#include "PriFen.h"
#include "FenResult.h"
#include "Buffer.h"

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
    QString sResult;

    Buffer donnees(m_dataPhrase->text());

    if( m_dataPhrase->text().isEmpty() ){
        QMessageBox::critical(this, "Phrase incorrecte", "Vous n'avez pas renseigné de phrase à coder.");
        return;
     }
    while( !donnees.allIsWrite() || !donnees.allIsRead() ) {
        if( donnees.tryWrite() ){
            sResult.append( donnees.instruction() );
        }
        if( donnees.tryRead() ){
            sResult.append( donnees.instruction() );
        }
        m_fenetreResultat->ajouteLigne( sResult );
        m_fenetreResultat->show();
     }
}
