#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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

   // void on_thirdPageButton_clicked();

    void on_addPatient_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
