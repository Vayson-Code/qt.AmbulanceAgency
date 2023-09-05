#include "connection.h"

Connection::Connection()
{

}

bool Connection::createconnect()
{

QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("Source_Projet2A");
db.setUserName("yahya");//inserer nom de l'utilisateur
db.setPassword("yahya");//inserer mot de passe de cet utilisateur

    return  db.open();
}
