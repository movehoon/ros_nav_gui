/**
 * @file /include/ros_nav_gui/main_window.hpp
 *
 * @brief Qt based gui for ros_nav_gui.
 *
 * @date November 2010
 **/
#ifndef ros_nav_gui_MAIN_WINDOW_H
#define ros_nav_gui_MAIN_WINDOW_H

/*****************************************************************************
** Includes
*****************************************************************************/

#include <QtGui/QMainWindow>
#include "ui_main_window.h"
#include "qnode.hpp"

/*****************************************************************************
** Namespace
*****************************************************************************/

namespace ros_nav_gui {

/*****************************************************************************
** Interface [MainWindow]
*****************************************************************************/
/**
 * @brief Qt central, all operations relating to the view part here.
 */
class MainWindow : public QMainWindow {
Q_OBJECT

public:
	MainWindow(int argc, char** argv, QWidget *parent = 0);
	~MainWindow();

	void ReadSettings(); // Load up qt program settings at startup
	void WriteSettings(); // Save qt program settings when closing

	void closeEvent(QCloseEvent *event); // Overloaded function
	void showNoMasterMessage();

public Q_SLOTS:
	/******************************************
	** Auto-connections (connectSlotsByName())
	*******************************************/
	void on_actionAbout_triggered();
	void on_button_connect_clicked(bool check );
	void on_checkbox_use_environment_stateChanged(int state);

	void on_button_initialPosition_clicked(bool check);
	void on_button_manualInitialPosition_clicked(bool check);
	void on_button_manualDestination_clicked(bool check);
	void on_button_destination1_clicked(bool check);
	void on_button_destination2_clicked(bool check);
	void on_button_destination3_clicked(bool check);
	void on_button_destination4_clicked(bool check);

    /******************************************
    ** Manual connections
    *******************************************/
    void updateLoggingView(); // no idea why this can't connect automatically

private:
	Ui::MainWindowDesign ui;
	QNode qnode;
};

}  // namespace ros_nav_gui

#endif // ros_nav_gui_MAIN_WINDOW_H
