/***************************************************************************
                          traywin.cpp  -  description
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

#include "traywin.h"
#include <qwidget.h>
#include <kapp.h>
#include <dcopobject.h>
#include <dcopclient.h>
#include <kpassivepopup.h>
#include <kiconloader.h>
#include "khpopoup.h"
#include <kprocess.h>

traywin::traywin (QWidget* parent , const char* name , const QString &text,const QString &id) {
	did=id;
        dname=text;
	padre=parent;
	KIconLoader *loader = new KIconLoader;
	this->setPixmap( loader->loadIcon("info",KIcon::NoGroup, KIcon::SizeSmall));
	
}
traywin::~traywin(){
}
KPopupMenu*  traywin::contextMenu () {
    return 0;
}
KActionCollection * traywin::actionCollection() {
    return 0;
}

void traywin::MyShow() {
	
	popup=new KPassivePopup();
	mypopup=new MyPopUp(popup);
	
 	
	mypopup->setPaletteBackgroundColor(QColor::QColor(255,255,255));
	
	
	//popup->setTimeout(0);
	popup->setView(mypopup);
	mypopup->adjustSize();
	mypopup->setMessage(dname,did,this);	
	QPoint ppos=popup->mapToGlobal(QPoint(0,0));	

	
	qDebug("%d ,%d",ppos.x(),ppos.y());

	QWidget* tmp = QApplication::desktop();
  	
	popup->show();
	popup->move(tmp->width()-popup->width(),tmp->height()-popup->height());
	

	connect( popup, SIGNAL( clicked() ),padre, SLOT(myClose()));
       
}

void traywin::setText(QString text,QString id) {

	mypopup->setMessage(text,id,this);
        did=id;
        dname=text;	
	popup->show();
	QWidget* tmp = QApplication::desktop();
  	
	
	popup->move(tmp->width()-popup->width(),tmp->height()-popup->height());

	}
void traywin::mousePressEvent(QMouseEvent *e)  {
    
	popup->show();
	QWidget* tmp = QApplication::desktop();
  	
	
	popup->move(tmp->width()-popup->width(),tmp->height()-popup->height());
 
    
}

void traywin::CloseMe()  {
        qDebug("Exiting...");
        
	this->close();
	
 
    
}

void traywin::launch()  {

   
   KProcess *proc = new KProcess;
   qDebug("Launching...");
   *proc << "/usr/bin/khusba_send";
   *proc << did;
    proc->start( KProcess::DontCare);
    CloseMe();
}  
void traywin::launchInfo()  {

   
   KProcess *proc = new KProcess;
   qDebug("Launching...");
   *proc << "/usr/bin/khusba_info";
   *proc << did;
    proc->start( KProcess::DontCare);
    CloseMe();
}  

  

