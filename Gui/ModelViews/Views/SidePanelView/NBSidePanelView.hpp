/*
	*
	* NBSidePanel.hpp - NBSidePanel.cpp header
	*
*/

#ifndef NBSIDEPANELVIEW_HPP
#define NBSIDEPANELVIEW_HPP

#include <Global.hpp>
#include <NBTools.hpp>
#include <NBSidePanelModel.hpp>
#include <NBGuiWidgets.hpp>

class NBSidePanel : public QWidget {
	Q_OBJECT

	public:
		NBSidePanel();

		NBSidePanelModel *spModel;

	private:
		void setupView();

	public slots:
		void updateBookmarks();
		void updateDevices();

	private slots:
		void handleClick( const QModelIndex );

	protected:
		void dragEnterEvent( QDragEnterEvent* );
		void dragMoveEvent( QDragMoveEvent* );
		void dropEvent( QDropEvent* );

	Q_SIGNALS:
		void showFolders();
		void driveClicked( QString );
		void copy( QStringList, QString, NBIOMode::Mode );
		void move( QStringList, QString, NBIOMode::Mode );
};

/*
class NBSidePanel : public QTreeView {
	Q_OBJECT

	public:
		NBSidePanel();

		NBSidePanelModel *spModel;

	private:
		void setupView();

		NBSidePanelDelegate *iDelegate;

	public slots:
		void updateBookmarks();
		void updateDevices();

	private slots:
		void handleClick( const QModelIndex );

	protected:
		void dragEnterEvent( QDragEnterEvent* );
		void dragMoveEvent( QDragMoveEvent* );
		void dropEvent( QDropEvent* );

	Q_SIGNALS:
		void showFolders();
		void driveClicked( QString );
		void copy( QStringList, QString, NBIOMode::Mode );
		void move( QStringList, QString, NBIOMode::Mode );
};
*/
#endif