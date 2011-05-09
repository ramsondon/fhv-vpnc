#ifndef MAINWINDOWIMPL_H
#define MAINWINDOWIMPL_H
//
#include <QMainWindow>
#include <QLineEdit>
#include "ui_mainwindow.h"
#include "configdialogimpl.h"
#include "config.h"
//
class MainWindowImpl : public QMainWindow, public Ui::MainWindow {
Q_OBJECT
public:
	MainWindowImpl( QWidget * parent = 0, Qt::WFlags f = 0 );
	
protected:		
	ConfigDialogImpl* configDialog;
	bool isChecked;
	
	void dispose();
	
private slots:
	int clickedOpenConfig();
	void clickedConnect();
	void clickedCancel();
	void changedCheckBox();
};
#endif




