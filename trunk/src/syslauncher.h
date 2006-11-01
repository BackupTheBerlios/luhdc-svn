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
#ifndef SYSLAUNCHER_H
#define SYSLAUNCHER_H

#include <qwidget.h>
#include "traywin.h"

/**
	@author Augusto Beiro <abeiro@activasistemas.com>
*/
class syslauncher : public QWidget
{
Q_OBJECT
public:
    syslauncher();

    ~syslauncher();

    void Add(QString text,QString id);
    void UpdateText(QString text,QString id);
    traywin *myTray;
    


public slots:
    void myClose();

};

#endif
