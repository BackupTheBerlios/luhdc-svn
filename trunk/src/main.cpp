/***************************************************************************
 *   Copyright (C) 2006 by Augusto Beiro   *
 *   abeiro@activasistemas.com   *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/


#include <kuniqueapplication.h>
#include <kaboutdata.h>
#include <kcmdlineargs.h>
#include <kdebug.h>
#include <klocale.h>
#include <dcopclient.h>
#include "khusba.h"

static const char description[] =
    I18N_NOOP("A KDE KPart Application");

static const char version[] = "0.1";

static KCmdLineOptions options[] =
{
    KCmdLineLastOption
};

int main (int argc, char *argv[])
{
	KLocale::setMainCatalogue("kdelibs");
	KAboutData aboutdata("khusba", I18N_NOOP("KDE"),
				version, description,
				KAboutData::License_GPL, "(C) 2006, Augusto Beiro");
	aboutdata.addAuthor("Augusto Beiro",I18N_NOOP("Developer"),"abeiro@activasistemas.com");

	KCmdLineArgs::init( argc, argv, &aboutdata );
	KCmdLineArgs::addCmdLineOptions( options );
	KUniqueApplication::addCmdLineOptions();

	if (!KUniqueApplication::start())
	{
		kdDebug() << "khusba is already running!" << endl;
		return (0);
	}

	KUniqueApplication app;
	kdDebug() << "starting khusba " << endl;
	// This app is started automatically, no need for session management
	app.disableSessionManagement();
	khusba *service = new khusba;
	kdDebug() << "starting khusba " << endl;
	return app.exec();

}
