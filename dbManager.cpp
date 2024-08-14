#include "dbManager.h"

DbManager::DbManager(const QString& path) {
    m_db = QSqlDatabase::addDatabase("QSQLITE");
    m_db.setDatabaseName(path);

    if (!m_db.open()) {
        qDebug() << "Error: Connection with database failed";
    } else {
        qDebug() << "Database: connect ok";
    }
}

bool DbManager::addPatient(const QString& healthCardNumber, const QString& firstName, const QString& lastName, const QString& dateOfBirth, const QString& gender, const QString& bloodType, const QString& address, const QString& phoneNumber) {

    //bool success = false;

    QSqlQuery query;
    query.prepare("INSERT INTO patients (health_card_number, first_name, last_name, date_of_birth, gender, blood_type, address, phone_number) "
                  "VALUES (:healthCardNumber, :firstName, :lastName, :dateOfBirth, :gender, :bloodType, :address, :phoneNumber)");
    query.bindValue(":healthCardNumber", healthCardNumber);
    query.bindValue(":firstName", firstName);
    query.bindValue(":lastName", lastName);
    query.bindValue(":dateOfBirth", dateOfBirth);
    query.bindValue(":gender", gender);
    query.bindValue(":bloodType", bloodType);
    query.bindValue(":address", address);
    query.bindValue(":phoneNumber", phoneNumber);

    if(query.exec()) {
        qDebug() << "Patient added successfully";
        return true;
    } else {
        qDebug() << "Error: Patient not added: " << query.lastError();
        return false;
    }
}
