
#ifndef DBMANAGER_H
#define DBMANAGER_H

#include <QSqlDatabase>
#include <QString>
#include <QDebug>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>
#include <QTableWidget>

class DbManager {
public:
    DbManager(const QString& path);
    bool addPatient(const QString& addHealthCardNumber, const QString& addFirstName, const QString& addLastName, const QString& addDateOfBirth, const QString& addGender, const QString& addBloodType, const QString& addAddress, const QString& addPhoneNumber, const QString& addEmailAddress, const QString& addInsuranceCompany, const QString& addPrimaryCarePhysician);
    bool viewPatient(QTableWidget* tableWidget);
    bool viewEmergencyPatient(QTableWidget* tableWidget);
    bool searchPatient(QTableWidget* tableWidget, const QString searchItem);
    bool addDoctor(const QString& doctorIdNumber, const QString& firstName, const QString& lastName, const QString& dateOfBirth, const QString& gender, const QString& bloodType, const QString& address, const QString& phoneNumber);
    bool addEmergency(const QString& healthCardNumber, const QString& firstName, const QString& lastName, const QString& dateOfBirth, const QString& gender, const QString& bloodType, const QString& emergencyContactName, const QString& emergencyContactRelation, const QString& emergencyContactNumber, const QString& emergencyReason, const QString& symptoms, const QString& currentMedicalConditions, const QString& allergies, const QString& medication, const QString& emergencyTime);

private:
    QSqlDatabase m_db;
};

#endif // DBMANAGER_H
