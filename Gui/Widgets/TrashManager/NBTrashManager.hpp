/*
	*
	* NBTrashManager.hpp - NewBreeze FolderView Class Header
	*
*/

#pragma once
#ifndef NBTRASHMANAGER_HPP
#define NBTRASHMANAGER_HPP

#include <Global.hpp>
#include <NBButtons.hpp>
#include <NBTrashView.hpp>
#include <NBTrashModel.hpp>
#include <NBTrashNode.hpp>
#include <NBDialog.hpp>
#include <NBMessageDialog.hpp>
#include <NBTools.hpp>
#include <NBGuiWidgets.hpp>

class NBTrashManager : public NBDialog {
	Q_OBJECT

	public :
		NBTrashManager( QWidget *parent = 0 );

		QModelIndexList getSelection();
		bool hasSelection();

	private :
		void setupGui();
		void setDialogProperties();
		void createAndSetupActions();

		void updateButtons();

		NBTrashView *TrashView;
		NBTrashModel *tModel;
		QMenu *customMenu;

		NBButtons *restoreButtons, *deleteButtons;

		QClipboard *ClipBoard;
		QAction *reloadAct;
		QAction *restoreAct, *restoreAllAct, *deleteAct, *emptyAct;

	public slots :
		void doReload();

		void handleFailedRestore( QModelIndexList );

		void restoreSelected();
		void restoreAll();

		void deleteSelected();
		void emptyTrash();
};

#endif
