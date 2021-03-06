/*
	*
	* NBArchive.hpp - NBArchive.cpp header
	*
*/

#pragma once

#include "common.hpp"

#include "NBTools.hpp"
#include "NBLibBZip2.hpp"
#include "NBLibGZip.hpp"
#include "NBLibLzma.hpp"
#include "NBLibLzma2.hpp"

class NBCOMMON_DLLSPEC NBArchive {

	public:
		NBArchive( QString );

		// Convinience Functions
		void updateInputFiles( QStringList );
		void setWorkingDir( QString );
		void setDestination( QString );

		// Workers
		void create();
		int extract();

	private:
		int copyData( struct archive *ar, struct archive *aw );
		int setFilterFormat( struct archive *ar, QMimeType mType );

		QString archiveName;

		QStringList inputList;
		QString dest;
		QString src;
};
