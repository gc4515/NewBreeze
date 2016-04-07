/*
	*
	* TextEditor.hpp - NewBreeze File Folder Encryption Class Header
	*
*/

#pragma once

#include <Global.hpp>
#include <Wordy.hpp>

#include <QtPlugin>
#include <NBPluginInterface.hpp>

class TextEditor : public QObject, NBPluginInterface {
	Q_OBJECT
	#if QT_VERSION >= 0x050000
		Q_PLUGIN_METADATA( IID "org.NewBreeze.NBPluginInterface" FILE "Crypt5.json" )
	#endif
	Q_INTERFACES( NBPluginInterface )

	public:
		/* Name of the plugin */
		QString name();

		/* The plugin version */
		QString version();

		/* The QAction hooks for menus/toolbars */
		QList<QAction*> actions( QStringList );

		/* Interface type: preview, rename etc */
		NBPluginInterface::Interface interface();

		/* Interface type: preview, rename etc */
		NBPluginInterface::Type type();

		/* Plugin load contexts */
		NBPluginInterface::Contexts contexts();

		/* Mimetypes handled by the plugin */
		QStringList mimetypes();

		/* Store the called widget pointer */
		void setCaller( QWidget* );

	private:
		Wordy *wordy;
};