#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->patientPageButton, &QPushButton::clicked, this, &MainWindow::on_btnPatientPage_clicked);
    connect(ui->doctorPageButton, &QPushButton::clicked, this, &MainWindow::on_btnDoctorPage_clicked);
    connect(ui->menuPageButton1, &QPushButton::clicked, this, &MainWindow::on_btnMainPage_clicked);
    connect(ui->menuPageButton2, &QPushButton::clicked, this, &MainWindow::on_btnMainPage_clicked);
    connect(ui->addPatientPageButton, &QPushButton::clicked, this, &MainWindow::on_addPatient_clicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnPatientPage_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_btnDoctorPage_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_btnMainPage_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_addPatient_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

