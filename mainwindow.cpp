#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <dbManager.h>
#include <QSettings>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , m_dbManager("C:\\Users\\jenus\\Downloads\\HospitalManager\\HospitalManager.db")
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

    connect(ui->submitButton, &QPushButton::clicked, this, &MainWindow::on_btnAddPatientInfo_clicked);
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


void MainWindow::on_btnAddPatientInfo_clicked()
{
    QString healthCardNumber = ui->healthCardNumberLineEdit->text();
    QString firstName = ui->firstNameLineEdit->text();
    QString lastName = ui->lastNameLineEdit->text();
    QString dateOfBirth = ui->dateOfBirthLineEdit->text();
    QString gender = ui->genderLineEdit->text();
    QString bloodType = ui->bloodTypeLineEdit->text();
    QString address = ui->addressLineEdit->text();
    QString phoneNumber = ui->phoneNumberLineEdit->text();

    qDebug() << "Health Card Number: " << healthCardNumber;
    qDebug() << "First name: " << firstName;
    qDebug() << "Last name: " << lastName;
    qDebug() << "Date of Birth: " << dateOfBirth;
    qDebug() << "Gender: " << gender;
    qDebug() << "Address: " << address;
    qDebug() << "Phone Number: " << phoneNumber;


    if (m_dbManager.addPatient(healthCardNumber, firstName, lastName, dateOfBirth, gender, bloodType, address, phoneNumber)) {
        QMessageBox::information(this, "Success", "Patient successfully added!");
    } else {
        QMessageBox::warning(this, "Failiure", "Failed to add patient");
    }

    ui->healthCardNumberLineEdit->clear();
    ui->firstNameLineEdit->clear();
    ui->lastNameLineEdit->clear();
    ui->dateOfBirthLineEdit->clear();
    ui->genderLineEdit->clear();
    ui->bloodTypeLineEdit->clear();
    ui->addressLineEdit->clear();
    ui->phoneNumberLineEdit->clear();



}

