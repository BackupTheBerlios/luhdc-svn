/***************************************************************************
                          traywin.h  -  description
                             -------------------
    begin                : sáb dic 11 2004
    copyright            : (C) 2004 by Augusto Beiro
    email                : abeiro@activasistemas.com
 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/

#ifndef TRAYWIN_H
#define TRAYWIN_H

#include <ksystemtray.h>
#include <qwidget.h>
#include <kpassivepopup.h>
#include "khpopoup.h"
/**
  *@author Augusto Beiro
  */

class traywin : public KSystemTray  {
Q_OBJECT
public: 
	traywin (QWidget* parent = 0, const char* name = 0 , const QString &text="",const QString &id="") ;
	~traywin();
	KPopupMenu*  contextMenu ();
 	KActionCollection * actionCollection();
	void setText(QString text,QString id);

	void MyShow();
 	QString dname;
	QString did;
	QWidget *padre;

	KPassivePopup *popup;
	MyPopUp * mypopup;
	

public slots:
	void CloseMe();
	void launch();
	void launchInfo();
	

protected:
  KSystemTray* trayicon;
  void mousePressEvent(QMouseEvent *e);
  
};

#endif
