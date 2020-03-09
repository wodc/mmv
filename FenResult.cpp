#include "FenResult.h"

FenResult::FenResult() : QDialog()
{
    this->setWindowTitle("Code résultat");
    this->setMinimumWidth( 200 );
    this->setMinimumHeight( 800 );

    m_resultTexte  = new QTextEdit();
    m_resultTexte->setReadOnly( true );
    m_layoutResult = new QVBoxLayout( this );

    this->setFont(  QFont("Courier New", 14, QFont::Bold) );

    m_layoutResult->addWidget( m_resultTexte);
}

void FenResult::ajouteLigne( QString texte ){
    m_resultTexte->setText( texte );
}
