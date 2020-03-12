#include "PriFen.h"
#include "FenResult.h"
#include "Buffer.h"

PriFen::PriFen() : QWidget()
{
    this->setWindowTitle("Construction de l'exercice");

    m_dataPhrase       = new QLineEdit;
    m_dataPhrase->setFixedWidth( 600 );
    m_labelPhrase      = new QLabel("Phrase a traiter :");
    m_layoutData       = new QGridLayout;
    m_layoutData->addWidget(m_labelPhrase, 0, 0);
    m_layoutData->addWidget(m_dataPhrase, 0, 1);

    m_fichierBinaire   = new QLineEdit;
    m_fichierBinaire->setEnabled(false);
    m_labelFichier     = new QLabel("Fichier résultat :");
    m_boutonSelection  = new QPushButton("Choisir");

    m_layoutData->addWidget(m_labelFichier, 1, 0);
    m_layoutData->addWidget(m_boutonSelection, 1, 1);
    m_layoutData->addWidget(m_fichierBinaire, 2, 1);

    m_boutonLancer     = new QPushButton("Go");
    m_boutonReset      = new QPushButton("Reset");
    m_boutonQuitter    = new QPushButton("Quitter");
    m_layoutGo         = new QHBoxLayout;

    m_fenetreResultat = new FenResult;

    m_layoutGo->addWidget( m_boutonLancer);
    m_layoutGo->addWidget( m_boutonReset);
    m_layoutGo->addWidget( m_boutonQuitter);

    m_layoutGlobale   = new QVBoxLayout( this );
    m_layoutGlobale->addLayout( m_layoutData );
    m_layoutGlobale->addLayout( m_layoutGo );

    QObject::connect(m_boutonSelection, SIGNAL(clicked()), this, SLOT(selectionFichier()));
    QObject::connect(m_boutonLancer, SIGNAL(clicked()), this, SLOT(ouvrirResultat()));
    QObject::connect(m_boutonReset, SIGNAL(clicked()), m_dataPhrase, SLOT(clear()));
    QObject::connect(m_boutonQuitter , SIGNAL(clicked()), qApp, SLOT(quit()));
}

void PriFen::ouvrirResultat()
{
    QString sResult;

    if( m_dataPhrase->text().isEmpty() ){
        QMessageBox::critical(this, "Phrase incorrecte", "Vous n'avez pas renseigné de phrase à coder.");
        return;
     }
    if( false && m_fichierBinaire->text().isEmpty() ){
        QMessageBox::critical(this, "Aucun fichier choisi", "Vous n'avez pas selectionné de fichier.");
        return;
     }

    Buffer *donnees = new Buffer(m_dataPhrase->text());
    while( !donnees->allIsWrite() || !donnees->allIsRead() ) {
        if( donnees->tryWrite() ){
            sResult.append( donnees->instruction() );
        }
        if( donnees->tryRead() ){
            sResult.append( donnees->instruction() );
        }
        m_fenetreResultat->ajouteLigne( sResult );
     }
    delete donnees;

    m_fenetreResultat->show();
}

void PriFen::selectionFichier(){
    QString fichier;

    fichier = QFileDialog::getSaveFileName(this, "Choisir le fichier à créer", QString());
    if( false && fichier.isEmpty() ){
        m_fichierBinaire->setText( "" );
        QMessageBox::critical(this, "Aucun fichier choisi", "Vous n'avez pas selectionné de fichier.");
        return;
     } else {
        m_fichierBinaire->setText( fichier );
    }
}
