#ifndef CONFIGDIALOGIMPL_H
#define CONFIGDIALOGIMPL_H
//
#include <QDialog>
#include <QString>
#include "ui_configdialog.h"
#include "configcreator.h"
//
class ConfigDialogImpl : public QDialog, public Ui::ConfigDialog {
Q_OBJECT
public:
	ConfigDialogImpl( QWidget * parent = 0, Qt::WFlags f = 0 );
	
	int triggerShowAction();	
	void dispose();
	void refresh();
	void loadDefaultValues();
	
protected:
	
	void undoChanges();
	void saveState();
	void init();
private slots:
	void clickedSaveConfig();
	void clickedCancel();
};
#endif





