#include "database.h"

DataBase::DataBase(QObject *parent)
    : QObject{parent}
{

    dataBase = new QSqlDatabase();
}

DataBase::~DataBase()
{
    delete dataBase;
}

/*!
 * \brief Метод добавляет БД к экземпляру класса QSqlDataBase
 * \param driver драйвер БД
 * \param nameDB имя БД (Если отсутствует Qt задает имя по умолчанию)
 */
void DataBase::AddDataBase(QString driver, QString nameDB)
{
    *dataBase = QSqlDatabase::addDatabase(driver, nameDB);
}

/*!
 * \brief Метод подключается к БД
 * \param для удобства передаем контейнер с данными необходимыми для подключения
 * \return возвращает тип ошибки
 */
void DataBase::ConnectToDataBase(QVector<QString> data)
{

    dataBase->setHostName(data[hostName]);
    dataBase->setDatabaseName(data[dbName]);
    dataBase->setUserName(data[login]);
    dataBase->setPassword(data[pass]);
    dataBase->setPort(data[port].toInt());

    ///Тут должен быть код ДЗ

    bool status;
    status = dataBase->open( );
    emit sig_SendStatusConnection(status);

}

void DataBase::ReadAnswerFromDB()
{
    emit sig_SendDataFromDB(sqlModel);
}

void DataBase::ClearModel()
{
    if (sqlModel != nullptr)
        sqlModel->clear();
}
/*!
 * \brief Метод производит отключение от БД
 * \param Имя БД
 */
void DataBase::DisconnectFromDataBase(QString nameDb)
{

    *dataBase = QSqlDatabase::database(nameDb);
    dataBase->close();

}
/*!
 * \brief Метод формирует запрос к БД.
 * \param request - SQL запрос
 * \return
 */
void DataBase::RequestToDB(int typeRequest)
{
    ///Тут должен быть код ДЗ

    switch(typeRequest) {
    case requestAllFilms: {        
        QSqlTableModel* sqlTableModel = new QSqlTableModel(this, *dataBase);
        sqlTableModel->setTable("film");
        sqlTableModel->select();
        sqlModel = sqlTableModel;
        break;
    }
    case requestHorrors: {
        sqlModel = new QSqlQueryModel(this);
        request = "SELECT title, description FROM film f "
                  "JOIN film_category fc on f.film_id = fc.film_id "
                  "JOIN category c on c.category_id  = fc.category_id "
                  "WHERE c.name = 'Horror'";
        sqlModel->setQuery(request, *dataBase);
        break;
    }
    case requestComedy: {
        sqlModel = new QSqlQueryModel(this);
        request = "SELECT title, description FROM film f "
                  "JOIN film_category fc on f.film_id = fc.film_id "
                  "JOIN category c on c.category_id  = fc.category_id "
                  "WHERE c.name = 'Comedy'";
        sqlModel->setQuery(request, *dataBase);
        break;

    }
    default: break;
    }
    emit sig_SendStatusRequest(sqlModel->lastError());
}

/*!
 * @brief Метод возвращает последнюю ошибку БД
 */
QSqlError DataBase::GetLastError()
{
    return dataBase->lastError();
}
