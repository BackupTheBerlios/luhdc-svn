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


#include "khusba.h"
#include <kdebug.h>
#include <kapplication.h>
#include "syslauncher.h"


khusba::khusba() : DCOPObject("serviceInterface")
{
	kdDebug() << "Starting new service... " << endl;
	m_List = QStringList();
	myTray=NULL;
}

khusba::~khusba()
{
	kdDebug() << "Going away... " << endl;
}

QString khusba::string(int idx)
{
	return *m_List.at(idx);
}

QStringList khusba::list()
{
	return m_List;
}

void khusba::add(QString arg)
{
	kdDebug() << "Adding " << arg << " to the list" << endl;
	m_List << arg;
}

bool khusba::remove(QString arg)
{
	QStringList::Iterator it = m_List.find(arg);
	if (it != m_List.end())
	{
		m_List.remove(it);
	}
	else
		return false;
	return true;
}

bool khusba::exit()
{
	kapp->quit();
}

void khusba::MyNotify(QString text,QString id) {
	
	if (!myTray) {
		myTray=new syslauncher();
		myTray->Add(text,id);
	}
	else {
		
		myTray->UpdateText(text,id);
	}


}
