#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <dbManager.h>
#include <QSettings>
#include <QMessageBox>
#include <QString>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , m_dbManager("C:\\Users\\jenus\\Downloads\\HospitalManager\\hospital.db")
{
    ui->setupUi(this);

    connect(ui->menuPageButton1, &QPushButton::clicked, this, &MainWindow::on_btnMainPage_clicked);


    connect(ui->patientPageButton, &QPushButton::clicked, this, &MainWindow::on_btnPatientPage_clicked);
    connect(ui->addPatientPageButton, &QPushButton::clicked, this, &MainWindow::on_btnAddPatient_clicked);
    connect(ui->searchPatientPageButton, &QPushButton::clicked, this, &MainWindow::on_btnSearchPatient_clicked);
    connect(ui->viewPatientPageButton, &QPushButton::clicked, this, &MainWindow::on_btnViewPatient_clicked);
    connect(ui->submitPatientButton, &QPushButton::clicked, this, &MainWindow::on_btnAddPatientInfo_clicked);
    connect(ui->viewAllPatientsButton, &QPushButton::clicked, this, &MainWindow::on_btnViewPatients_clicked);

    connect(ui->doctorPageButton, &QPushButton::clicked, this, &MainWindow::on_btnDoctorPage_clicked);
    connect(ui->addDoctorPageButton, &QPushButton::clicked, this, &MainWindow::on_btnAddDoctor_clicked);
    connect(ui->searchDoctorButton, &QPushButton::clicked, this, &MainWindow::on_searchDoctor_clicked);
    connect(ui->viewAllDoctorsButton, &QPushButton::clicked, this, &MainWindow::on_viewDoctor_clicked);
    connect(ui->submitDoctorButton, &QPushButton::clicked, this, &MainWindow::on_btnAddDoctorInfo_clicked);

    connect(ui->emergencyPage, &QPushButton::clicked, this, &MainWindow::on_emergencyPage_clicked);


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnPatientPage_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
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

void MainWindow::on_btnDoctorPage_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}

void MainWindow::on_btnAddDoctor_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);
}

void MainWindow::on_btnViewPatients_clicked()
{
    m_dbManager.viewPatient(ui->tableWidget);
}

void MainWindow::on_searchDoctor_clicked()
{
    ui->stackedWidget->setCurrentIndex(7);
}

void MainWindow::on_viewDoctor_clicked()
{
    ui->stackedWidget->setCurrentIndex(8);
}

void MainWindow::on_emergencyPage_clicked()
{
    ui->stackedWidget->setCurrentIndex(9);
}


void MainWindow::on_btnAddPatientInfo_clicked()
{
    QString addHealthCardNumber = ui->healthCardNumberLineEdit->text();
    QString addFirstName = ui->firstNamePatientLineEdit->text();
    QString addLastName = ui->lastNamePatientLineEdit->text();
    QString addDateOfBirth = ui->dateOfBirthPatientLineEdit->text();
    QString addGender = ui->genderPatientLineEdit->text();
    QString addBloodType = ui->bloodTypePatientLineEdit->text();
    QString addAddress = ui->addressPatientLineEdit->text();
    QString addPhoneNumber = ui->phoneNumberPatientLineEdit->text();

    qDebug() << "Health Card Number: " << addHealthCardNumber;
    qDebug() << "First name: " << addFirstName;
    qDebug() << "Last name: " << addLastName;
    qDebug() << "Date of Birth: " << addDateOfBirth;
    qDebug() << "Gender: " << addGender;
    qDebug() << "Address: " << addAddress;
    qDebug() << "Phone Number: " << addPhoneNumber;

    if (m_dbManager.addPatient(addHealthCardNumber, addFirstName, addLastName, addDateOfBirth, addGender, addBloodType, addAddress, addPhoneNumber)) {
        QMessageBox::information(this, "Success", "Patient successfully added!");
    } else {
        QMessageBox::warning(this, "Failiure", "Failed to add patient");
    }

    ui->healthCardNumberLineEdit->clear();
    ui->firstNamePatientLineEdit->clear();
    ui->lastNamePatientLineEdit->clear();
    ui->dateOfBirthPatientLineEdit->clear();
    ui->genderPatientLineEdit->clear();
    ui->bloodTypePatientLineEdit->clear();
    ui->addressPatientLineEdit->clear();
    ui->phoneNumberPatientLineEdit->clear();
}

void MainWindow::on_btnAddDoctorInfo_clicked()
{
    QString doctorIdNumber = ui->doctorIdNumberLineEdit->text();
    QString firstName = ui->firstNameDoctorLineEdit->text();
    QString lastName = ui->lastNameDoctorLineEdit->text();
    QString dateOfBirth = ui->dateOfBirthDoctorLineEdit->text();
    QString gender = ui->genderDoctorLineEdit->text();
    QString bloodType = ui->bloodTypeDoctorLineEdit->text();
    QString address = ui->addressDoctorLineEdit->text();
    QString phoneNumber = ui->phoneNumberDoctorLineEdit->text();

    qDebug() << "Doctor Id Number: " << doctorIdNumber;
    qDebug() << "First name: " << firstName;
    qDebug() << "Last name: " << lastName;
    qDebug() << "Date of Birth: " << dateOfBirth;
    qDebug() << "Gender: " << gender;
    qDebug() << "Address: " << address;
    qDebug() << "Phone Number: " << phoneNumber;

    if (m_dbManager.addDoctor(doctorIdNumber, firstName, lastName, dateOfBirth, gender, bloodType, address, phoneNumber)) {
        QMessageBox::information(this, "Success", "Doctor successfully added!");
    } else {
        QMessageBox::warning(this, "Failiure", "Failed to add doctor");
    }

    ui->doctorIdNumberLineEdit->clear();
    ui->firstNameDoctorLineEdit->clear();
    ui->lastNameDoctorLineEdit->clear();
    ui->dateOfBirthDoctorLineEdit->clear();
    ui->genderDoctorLineEdit->clear();
    ui->bloodTypeDoctorLineEdit->clear();
    ui->addressDoctorLineEdit->clear();
    ui->phoneNumberDoctorLineEdit->clear();
}




























