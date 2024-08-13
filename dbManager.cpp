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
