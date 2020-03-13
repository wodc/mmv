#include "FenResultat.h"

FenResultat::FenResultat() : QDialog()
{
    this->setWindowTitle("Code résultat");
    this->setMinimumWidth( 800 );
    this->setMinimumHeight( 800 );

    m_resultTexte  = new QTextEdit();
    m_resultTexte->setReadOnly( true );
    m_layoutResult = new QVBoxLayout( this );

    this->setFont( QFont("Courier New", 12) );

    m_layoutResult->addWidget( m_resultTexte );
}

void FenResultat::ajouteLigne( QString texte ){
    m_resultTexte->setText( texte );
}
