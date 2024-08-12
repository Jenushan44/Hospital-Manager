#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSql>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
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
    void on_addPatientDB_clicked();

private:
    void addPatient(const QString &healthCard, const QString &firstName, const QString &lastName, const QString &birthday, const QString &address, const QString &phoneNumber, const QString &gender);

    Ui::MainWindow *ui;
    QSqlDatabase DB_Connection;
};
#endif // MAINWINDOW_H
