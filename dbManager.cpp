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

bool DbManager::viewPatient(QTableWidget* tableWidget) {
    QSqlQuery query("SELECT * FROM patients");

    if (!query.exec()) {
        qDebug() << "Error: execution failed: " << query.lastError();
        return false;
    }

    tableWidget->setColumnCount(8);

    QStringList headers;
    headers << "Health Card" << "First Name" << "Last Name" << "Birthday" << "Gender" << "Blood Type" << "Address" << "Phone Number";
    tableWidget->setHorizontalHeaderLabels(headers);

    tableWidget->setRowCount(0);
    int row = 0;

    while(query.next()) {
        tableWidget->insertRow(row);

        QString healthCardNumber = query.value("health_card_number").toString();
        QString firstName = query.value("first_name").toString();
        QString lastName = query.value("last_name").toString();
        QString dateOfBirth = query.value("date_of_birth").toString();
        QString gender = query.value("gender").toString();
        QString bloodType = query.value("blood_type").toString();
        QString address = query.value("address").toString();
        QString phoneNumber = query.value("phone_number").toString();

        tableWidget->setItem(row, 0, new QTableWidgetItem(healthCardNumber));
        tableWidget->setItem(row, 1, new QTableWidgetItem(firstName));
        tableWidget->setItem(row, 2, new QTableWidgetItem(lastName));
        tableWidget->setItem(row, 3, new QTableWidgetItem(dateOfBirth));
        tableWidget->setItem(row, 4, new QTableWidgetItem(gender));
        tableWidget->setItem(row, 5, new QTableWidgetItem(bloodType));
        tableWidget->setItem(row, 6, new QTableWidgetItem(address));
        tableWidget->setItem(row, 7, new QTableWidgetItem(phoneNumber));

        row++;
    }
    return true;
}

bool DbManager::searchPatient(QTableWidget* tableWidget, const QString& healthCardNumber) {

    QSqlQuery query;
    query.prepare("SELECT * FROM patients WHERE healthCardNumber = :healthCardNumber");
    query.bindValue(":healthCardNumber", healthCardNumber);

    if (!query.exec()) {
        qDebug() << "Error: execution failed: " << query.lastError();
        return false;
    }

    tableWidget->setRowCount(0);
    int row = 0;

    while (query.next()) {
        tableWidget->insertRow(row);

        for (int col = 0; col < query.record().count(); col++) {
            QTableWidgetItem* item = new QTableWidgetItem(query.value(col).toString());
            tableWidget->setItem(row, col, item);
        }
        row++;
    }
    return (row > 0);
    /*
    QStringList headers;
    headers << "Health Card" << "First Name" << "Last Name" << "Birthday" << "Gender" << "Blood Type" << "Address" << "Phone Number";
    tableWidget->setHorizontalHeaderLabels(headers);

    tableWidget->setRowCount(0);
    int row = 0;

    while(query.next()) {
        tableWidget->insertRow(row);

        QString healthCardNumber = query.value("health_card_number").toString();
        QString firstName = query.value("first_name").toString();
        QString lastName = query.value("last_name").toString();
        QString dateOfBirth = query.value("date_of_birth").toString();
        QString gender = query.value("gender").toString();
        QString bloodType = query.value("blood_type").toString();
        QString address = query.value("address").toString();
        QString phoneNumber = query.value("phone_number").toString();

        tableWidget->setItem(row, 0, new QTableWidgetItem(healthCardNumber));
        tableWidget->setItem(row, 1, new QTableWidgetItem(firstName));
        tableWidget->setItem(row, 2, new QTableWidgetItem(lastName));
        tableWidget->setItem(row, 3, new QTableWidgetItem(dateOfBirth));
        tableWidget->setItem(row, 4, new QTableWidgetItem(gender));
        tableWidget->setItem(row, 5, new QTableWidgetItem(bloodType));
        tableWidget->setItem(row, 6, new QTableWidgetItem(address));
        tableWidget->setItem(row, 7, new QTableWidgetItem(phoneNumber));

        row++;
    }
    return true;
*/
}

bool DbManager::addDoctor(const QString& doctorIdNumber, const QString& firstName,  const QString& lastName, const QString& dateOfBirth, const QString& gender, const QString& bloodType, const QString& address, const QString& phoneNumber) {

    QSqlQuery query;
    query.prepare("INSERT INTO doctors (doctor_id_number, first_name,  last_name, date_of_birth, gender, blood_type, address, phone_number)"
                  "VALUES (:doctorIdNumber, :firstName, :lastName, :dateOfBirth, :gender, :bloodType, :address, :phoneNumber)");
    query.bindValue(":doctorIdNumber", doctorIdNumber);
    query.bindValue(":firstName", firstName);
    query.bindValue(":lastName", lastName);
    query.bindValue(":dateOfBirth", dateOfBirth);
    query.bindValue(":gender", gender);
    query.bindValue(":bloodType", bloodType);
    query.bindValue(":address", address);
    query.bindValue(":phoneNumber", phoneNumber);

    if(query.exec()) {
        qDebug() << "Doctor added successfully";
        return true;
    } else {
        qDebug() << "Error: Doctor not added: " << query.lastError();
        return false;
    }
}
