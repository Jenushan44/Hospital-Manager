#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    DB_Connection = QSqlDatabase::addDatabase("QSQLITE");
    DB_Connection.setDatabaseName("HospitalManagement.db");
    DB_Connection.open();

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

void MainWindow::on_addPatientDB_clicked()
{
    QString healthCard = ui->patientHealthCardNumber->text();
    QString firstName = ui->patientFirstNameInput->text();
    QString lastName = ui->patientLastNameInput->text();
    QString birthday = ui->patientBirthdayInput->text();
    QString address = ui->patientAddressInput->text();
    QString phoneNumber = ui->patientPhoneNumberInput->text();
    QString gender = ui->patientGenderInput->text();

    addPatient(healthCard, firstName, lastName, birthday, address, phoneNumber, gender);

    ui->patientHealthCardNumber->clear();
    ui->patientFirstNameInput->clear();
    ui->patientLastNameInput->clear();
    ui->patientBirthdayInput->clear();
    ui->patientAddressInput->clear();
    ui->patientPhoneNumberInput->clear();
    ui->patientGenderInput->clear();
}

void MainWindow::addPatient(const QString &healthCard, const QString &firstName, const QString &lastName, const QString &birthday, const QString &address, const QString &phoneNumber, const QString &gender) {

    QSqlQuery query;
    query.prepare("INSERT INTO patient (healthCard, firstName, lastName, birthday, address, phoneNumber, gender) VALUES (:healthCard, :firstName, :lastName, :birthday, :address, :phoneNumber, :gender)");
    query.bindValue(":healthCard", healthCard);
    query.bindValue(":firstName", firstName);
    query.bindValue(":lastName", lastName);
    query.bindValue(":birthday", birthday);
    query.bindValue(":address", address);
    query.bindValue(":phoneNumber", phoneNumber);
    query.bindValue(":gender", gender);

    if(!query.exec()) {
        qDebug() << "Add patient failed: " << query.lastError();
    } else {
        qDebug() << "Patient added successfully";
    }
}



