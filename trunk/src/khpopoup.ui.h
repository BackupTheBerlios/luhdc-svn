/****************************************************************************
** ui.h extension file, included from the uic-generated form implementation.
**
** If you want to add, delete, or rename functions or slots, use
** Qt Designer to update this file, preserving your code.
**
** You should not define a constructor or destructor in this file.
** Instead, write your code in functions called init() and destroy().
** These will automatically be called by the form's constructor and
** destructor.
*****************************************************************************/
void MyPopUp::setMessage(QString text,QString id,QWidget *parent) {
    static char alreadyc=0;
    
    disconnect(  launchSend, SIGNAL( clicked() ),parent,SLOT(launch()));
    disconnect(  launchInfo, SIGNAL( clicked() ),parent,SLOT(launchInfo()));
    message->setText(text);
    usbid->setText(id);
   
    connect(  launchSend, SIGNAL( clicked() ),parent,SLOT(launch()));
    connect(  launchInfo, SIGNAL( clicked() ),parent,SLOT(launchInfo()));
   
   return;
    }

