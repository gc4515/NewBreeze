/*
	*
	* NBLabels.cpp - Different types of customized labels for NewBreeze
	*
*/

#include <NBLabels.hpp>

NBPicLabel::NBPicLabel( QPixmap pixmap, QString style ) : QLabel() {

	setPixmap( pixmap );
	Style = QString( style );
};

void NBPicLabel::mousePressEvent( QMouseEvent *mEvent ) {

	emit clicked();
	mEvent->accept();
}

NBClickLabel::NBClickLabel( QPixmap icon ) : QLabel() {

	clickEnabled = true;

	setPixmap( icon );
	setAlignment( Qt::AlignCenter );
};

NBClickLabel::NBClickLabel( QString text ) : QLabel() {

	clickEnabled = true;

	setText( text );
	setAlignment( Qt::AlignCenter );
};

void NBClickLabel::mousePressEvent( QMouseEvent *mEvent ) {

	if ( clickEnabled )
		emit pressed();

	mEvent->accept();
};

void NBClickLabel::mouseReleaseEvent( QMouseEvent *mEvent ) {

	if ( clickEnabled and rect().contains( mEvent->pos() ) ) {
		emit clicked();
		emit released();
	}

	mEvent->accept();
};

void NBClickLabel::setClickable( bool canClick ) {

	clickEnabled = canClick;
};

NBInfoLabel::NBInfoLabel() : QLabel() {

	setAlignment( Qt::AlignCenter );
	setFont( QFont( "Envy Code R", 12 ) );
};

void NBInfoLabel::setText( QString name, QString size, QString type, QString perm ) {

	QString text = QString(
		"<table style='width: 700px; height: 56px;'>"			\
		"	<tr>"												\
		"		<td colspan=3 align = 'left'>%1</td>"			\
		"	</tr>"												\
		"	<tr>"												\
		"		<td width=300 align='left'>%2</td>"				\
		"		<td width=300 align='left'>%3</td>"				\
		"		<td width=100 align='center'>%4</td>"			\
		"	</tr>"												\
		"</table>"
	);

	QLabel::setText( text.arg( name ).arg( size ).arg( type ).arg( perm ) );
};
