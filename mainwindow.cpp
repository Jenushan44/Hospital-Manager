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
    connect(ui->menuPageButton3, &QPushButton::clicked, this, &MainWindow::on_btnMainPage_clicked);
    connect(ui->menuPageButton4, &QPushButton::clicked, this, &MainWindow::on_btnMainPage_clicked);
    connect(ui->menuPageButton5, &QPushButton::clicked, this, &MainWindow::on_btnMainPage_clicked);
    connect(ui->menuPageButton6, &QPushButton::clicked, this, &MainWindow::on_btnMainPage_clicked);
    connect(ui->menuPageButton7, &QPushButton::clicked, this, &MainWindow::on_btnMainPage_clicked);
    connect(ui->addPatientPageButton, &QPushButton::clicked, this, &MainWindow::on_btnAddPatient_clicked);
    connect(ui->searchPatientPageButton, &QPushButton::clicked, this, &MainWindow::on_btnSearchPatient_clicked);
    connect(ui->viewPatientPageButton, &QPushButton::clicked, this, &MainWindow::on_btnViewPatient_clicked);
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
    ui->stackedWidget->setCurrentIndex(5);
}

void MainWindow::on_btnMainPage_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_btnAddPatient_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_btnSearchPatient_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_btnViewPatient_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}



