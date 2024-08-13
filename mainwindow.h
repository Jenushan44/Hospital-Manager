#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QStackedWidget>
#include "dbManager.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btnPatientPage_clicked();
    void on_btnDoctorPage_clicked();
    void on_btnMainPage_clicked();
    void on_btnAddPatient_clicked();
    void on_btnSearchPatient_clicked();
    void on_btnViewPatient_clicked();

private:
    Ui::MainWindow *ui;
    DbManager m_dbManager;

    void setupConnections();
};

#endif // MAINWINDOW_H


