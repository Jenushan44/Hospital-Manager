#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->firstPageButton, &QPushButton::clicked, this, &MainWindow::on_mainPatient_clicked);
    connect(ui->doctorPageButton, &QPushButton::clicked, this, &MainWindow::on_mainDoctor_clicked);
    connect(ui->secondPageButton, &QPushButton::clicked, this, &MainWindow::on_secondPageButton_clicked);
    connect(ui->thirdPageButton, &QPushButton::clicked, this, &MainWindow::on_thirdPageButton_clicked);


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_mainPatient_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_mainDoctor_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}



void MainWindow::on_secondPageButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_thirdPageButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}



