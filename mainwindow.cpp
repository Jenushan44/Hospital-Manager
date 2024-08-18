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

    connect(ui->menuPageButton, &QPushButton::clicked, this, &MainWindow::on_btnMainPage_clicked);

    connect(ui->patientPageButton, &QPushButton::clicked, this, &MainWindow::on_btnPatientPage_clicked);    
    connect(ui->addPatientPageButton, &QPushButton::clicked, this, &MainWindow::on_btnAddPatient_clicked);
    connect(ui->searchPatientPageButton, &QPushButton::clicked, this, &MainWindow::on_btnSearchPatient_clicked);
    connect(ui->viewPatientPageButton, &QPushButton::clicked, this, &MainWindow::on_btnViewPatient_clicked);
    connect(ui->deleteViewPatient, &QPushButton::clicked, this, &MainWindow::on_deletePatientViewButton_clicked);
    connect(ui->submitPatientButton, &QPushButton::clicked, this, &MainWindow::on_btnAddPatientInfo_clicked);
    connect(ui->searchPatientButton, &QPushButton::clicked, this, &MainWindow::on_btnViewPatients_clicked);
    connect(ui->searchPatientHealthCardButton, &QPushButton::clicked, this, &MainWindow::on_searchPatientButton_clicked);
    connect(ui->deletSearchPatient, &QPushButton::clicked, this, &MainWindow::on_deletePatientSearchButton_clicked);

    connect(ui->doctorPageButton, &QPushButton::clicked, this, &MainWindow::on_btnDoctorPage_clicked);
    connect(ui->addDoctorPageButton, &QPushButton::clicked, this, &MainWindow::on_btnAddDoctor_clicked);
    connect(ui->searchDoctorButton, &QPushButton::clicked, this, &MainWindow::on_searchDoctor_clicked);
    connect(ui->viewAllDoctorsButton, &QPushButton::clicked, this, &MainWindow::on_viewDoctor_clicked);
    connect(ui->submitDoctorButton, &QPushButton::clicked, this, &MainWindow::on_btnAddDoctorInfo_clicked);

    connect(ui->emergencyPage, &QPushButton::clicked, this, &MainWindow::on_emergencyPage_clicked);
    connect(ui->addEmergencyInfoButton, &QPushButton::clicked, this, &MainWindow::on_btnAddEmergencyInfo_clicked);
    connect(ui->viewAllEmergenciesButton, &QPushButton::clicked, this, &MainWindow::on_btnViewEmergencies_clicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnMainPage_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_btnPatientPage_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_btnAddPatient_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_btnSearchPatient_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_searchPatientButton_clicked()
{
    QString searchItem = ui->healthCardSearchLineEdit->text();
    m_dbManager.searchPatient(ui->tableWidgetSearchPatient, searchItem);
}

void MainWindow::on_btnViewPatient_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}

void MainWindow::on_btnViewPatients_clicked()
{
    m_dbManager.viewPatient(ui->tableWidgetViewPatient);
}

void MainWindow::on_btnDoctorPage_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}

void MainWindow::on_btnAddDoctor_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);
}

void MainWindow::on_searchDoctor_clicked()
{
    ui->stackedWidget->setCurrentIndex(7);
}

void MainWindow::on_viewDoctor_clicked()
{
    ui->stackedWidget->setCurrentIndex(8);
}

void MainWindow::on_btnViewEmergencies_clicked()
{
    m_dbManager.viewEmergencyPatient(ui->tableWidgetEmergency);
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
    QString addEmailAddress = ui->emailAddressPatientLineEdit->text();
    QString addInsuranceCompany = ui->insuranceCompanyPatientLineEdit->text();
    QString addPrimaryCarePhysician = ui->primaryCarePhysicianPatientLineEdit->text();


    qDebug() << "Health Card Number: " << addHealthCardNumber;
    qDebug() << "First name: " << addFirstName;
    qDebug() << "Last name: " << addLastName;
    qDebug() << "Date of Birth: " << addDateOfBirth;
    qDebug() << "Gender: " << addGender;
    qDebug() << "Blood Type: " << addBloodType;
    qDebug() << "Address: " << addAddress;
    qDebug() << "Phone Number: " << addPhoneNumber;
    qDebug() << "Email Address: " << addEmailAddress;
    qDebug() << "Insurance Company: " << addInsuranceCompany;
    qDebug() << "Primary Care Physician: " << addPrimaryCarePhysician;


    if (m_dbManager.addPatient(addHealthCardNumber, addFirstName, addLastName, addDateOfBirth, addGender, addBloodType, addAddress, addPhoneNumber, addEmailAddress, addInsuranceCompany, addPrimaryCarePhysician)) {
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
    ui->emailAddressPatientLineEdit->clear();
    ui->insuranceCompanyPatientLineEdit->clear();
    ui->primaryCarePhysicianPatientLineEdit->clear();
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

void MainWindow::on_btnAddEmergencyInfo_clicked()
{
    QString emergencyHealthCardNumber = ui->healthCardNumberEmergencyLineEdit->text();
    QString emergencyFirstName = ui->firstNameEmergencyLineEdit->text();
    QString emergencyLastName = ui->lastNameEmergencyLineEdit->text();
    QString emergencyDateOfBirth = ui->birthdayEmergencyLineEdit->text();
    QString emergencyGender = ui->genderEmergencyLineEdit->text();
    QString emergencyBloodType = ui->bloodTypeEmergencyLineEdit->text();
    QString emergencyContactNumber = ui->emergencyContactNumberLineEdit->text();
    QString emergencyContactRelation = ui->emergencyContactRelationLineEdit->text();
    QString emergencyContactName = ui->emergencContactNameLineEdit->text();
    QString emergencyReason = ui->emergencyReasonLineEdit->text();
    QString emergencySymptoms = ui->emergencySymptomsLineEdit->text();
    QString emergencyCurrentMedicalConditions = ui->currentMedicalConditionsLineEdit->text();
    QString emergencyAllergies = ui->allergiesEmergencyLineEdit->text();
    QString emergencyMedication = ui->medicationEmergencyLineEdit->text();
    QString emergencyTime = ui->emergencyTimeLineEdit->text();

    qDebug() << "Health Card Number: " << emergencyHealthCardNumber;
    qDebug() << "First Name: " << emergencyFirstName;
    qDebug() << "Last Name: " << emergencyLastName;
    qDebug() << "Birthday: " << emergencyDateOfBirth;
    qDebug() << "Gender: " << emergencyGender;
    qDebug() << "Blood Type: " << emergencyBloodType;
    qDebug() << "Emergency Contact Name: " << emergencyContactName;
    qDebug() << "Emergency Contact Relation: " << emergencyContactRelation;
    qDebug() << "Emergency Contact Phone Number: " << emergencyContactNumber;
    qDebug() << "Emergency Reason: " << emergencyReason;
    qDebug() << "Symptoms: " << emergencyHealthCardNumber;
    qDebug() << "Current Medical Conditions: " << emergencyCurrentMedicalConditions;
    qDebug() << "Allergies: " << emergencyAllergies;
    qDebug() << "Medication: " << emergencyMedication;
    qDebug() << "Emergency Time: " << emergencyTime;

    if (m_dbManager.addEmergency(emergencyHealthCardNumber, emergencyFirstName, emergencyLastName, emergencyDateOfBirth, emergencyGender, emergencyBloodType, emergencyContactName, emergencyContactRelation, emergencyContactNumber, emergencyReason, emergencySymptoms, emergencyCurrentMedicalConditions, emergencyAllergies, emergencyMedication, emergencyTime)) {
        QMessageBox::information(this, "Success", "Patient successfully added");
    } else {
        QMessageBox::warning(this, "Failiure", "Failed to add Patient");
    }

    ui->healthCardNumberEmergencyLineEdit->clear();
    ui->firstNameEmergencyLineEdit->clear();
    ui->lastNameEmergencyLineEdit->clear();
    ui->birthdayEmergencyLineEdit->clear();
    ui->genderEmergencyLineEdit->clear();
    ui->bloodTypeEmergencyLineEdit->clear();
    ui->emergencyContactNumberLineEdit->clear();
    ui->emergencyContactRelationLineEdit->clear();
    ui->emergencContactNameLineEdit->clear();
    ui->emergencyReasonLineEdit->clear();
    ui->emergencySymptomsLineEdit->clear();
    ui->currentMedicalConditionsLineEdit->clear();
    ui->allergiesEmergencyLineEdit->clear();
    ui->medicationEmergencyLineEdit->clear();
    ui->emergencyTimeLineEdit->clear();
}

void MainWindow::on_deletePatientViewButton_clicked()
{
    int selectedRow = ui->tableWidgetViewPatient->currentRow();

    if (selectedRow < 0) {
        QMessageBox::warning(this, "Delete", "Please select a patient to delete");
    }

    QString healthCardNumber = ui->tableWidgetViewPatient->item(selectedRow, 0)->text();

    if (m_dbManager.deletePatient(healthCardNumber)) {
        ui->tableWidgetViewPatient->removeRow(selectedRow);
        QMessageBox::information(this, "Delete", "Patient deleted successfully");
    } else {
        QMessageBox::critical(this, "Delete", "Failed to delete patient");
    }
}

void MainWindow::on_deletePatientSearchButton_clicked()
{
    int selectedRow = ui->tableWidgetSearchPatient->currentRow();

    if (selectedRow < 0) {
        QMessageBox::warning(this, "Delete", "Please select a patient to delete");
    }

    QString healthCardNumber = ui->tableWidgetSearchPatient->item(selectedRow, 0)->text();

    if (m_dbManager.deletePatient(healthCardNumber)) {
        ui->tableWidgetSearchPatient->removeRow(selectedRow);
        QMessageBox::information(this, "Delete", "Patient deleted successfully");
    } else {
        QMessageBox::critical(this, "Delete", "Failed to delete patient");
    }
}


