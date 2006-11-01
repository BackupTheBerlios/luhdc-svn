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
#include "syslauncher.h"
#include <kiconloader.h>
#include "traywin.h"

syslauncher::syslauncher()
 : QWidget()
{
	return ;
}


syslauncher::~syslauncher()
{
}

void syslauncher::Add(QString text,QString id) {

	
	KIconLoader *loader = new KIconLoader;
	myTray=new traywin(this,"",text,id);
	myTray->setPixmap( loader->loadIcon("info",KIcon::NoGroup, KIcon::SizeSmall));
	myTray->show();
	myTray->MyShow();
}

void syslauncher::UpdateText(QString text,QString id) {
		
	if (myTray) {
		myTray->setText(text,id);
		
	}
	else
		Add(text,id);

}

void syslauncher::myClose() {
	qDebug("Exiting...");
	myTray->CloseMe();
	myTray=NULL;
	close();

}

