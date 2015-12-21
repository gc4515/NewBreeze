/*
	*
	* NBCrumb.hpp - The Segmented Buttons Class Header
	*
*/

#pragma once

#include <Global.hpp>
#include <NBTools.hpp>
#include <NBGuiWidgets.hpp>

class NBCrumb : public QWidget {
	Q_OBJECT

	public:
		/* A button */
		/* @p1 Full Path until the current crumb */
		NBCrumb( QString, bool currentPath, QWidget *parent );

		/* Size hint */
		QSize sizeHint() const;

		QString path();

	public slots:
		void showMenu();

	private:
		void initPrivateVariables();

		/* Path */
		QString mPath;
		QString mCrumbText;
		QDir cwd;

		/* Current Dir? */
		bool m_Current;

		/* Button Size */
		int mWidth;

		/* Menu */
		QMenu *mMenu;

		/* The crumb was pressed */
		bool m_Pressed;

		/* Menu button was pressed */
		bool m_MenuButtonPressed;

	private slots:
		void onMenuItemClicked();

	protected:
		void mousePressEvent( QMouseEvent* );
		void mouseReleaseEvent( QMouseEvent* );

		void enterEvent( QEvent* );
		void leaveEvent( QEvent* );

		void paintEvent( QPaintEvent* );

	Q_SIGNALS:
		void loadPath( QString );
};
