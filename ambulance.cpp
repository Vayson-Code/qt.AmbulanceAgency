#include "ambulance.h"

ambulance::ambulance()
{
MATRICULE="";
ETAT="";
TYPE=0;
KILOMETRAGE=0;
DISPONIBLE=0;
}

ambulance::ambulance(QString MATRICULE,QString ETAT,int TYPE,float KILOMETRAGE,int DISPONIBLE)
{
this->MATRICULE=MATRICULE;
this->ETAT=ETAT;
this->TYPE=TYPE;
this->KILOMETRAGE=KILOMETRAGE;
this->DISPONIBLE=DISPONIBLE;
}

ambulance::~ambulance()
{

}



bool ambulance::ajouter()
{
    QSqlQuery query;
    QString res=QString::number(KILOMETRAGE);
    //QString ses=QString::number(ALERTE_STATUS);
    query.prepare("insert into AMBULANCE(MATRICULE,ETAT,TYPE,KILOMETRAGE,DISPONIBLE)""values(:m,:e,:t,:k,:d)");
    query.bindValue(":m",MATRICULE);
    query.bindValue(":e",ETAT);
    query.bindValue(":t",TYPE);
    query.bindValue(":k",res);
    query.bindValue(":d",DISPONIBLE);
    return query.exec();
}


QSqlQueryModel* ambulance::afficher(int t)
{
  QSqlQueryModel * model=new QSqlQueryModel();

  if(t==0)
    {
    model->setQuery("select * from AMBULANCE");
    }
    if(t==1)
    {
    model->setQuery("select * from AMBULANCE order by MATRICULE");
    }
    if(t==2)
    {
    model->setQuery("select * from AMBULANCE order by TYPE");
    }
    if(t==3)
    {
    model->setQuery("select * from AMBULANCE order by KILOMETRAGE");
    }

  model->setHeaderData(0,Qt::Horizontal,QObject::tr("MATRICULE"));
  model->setHeaderData(1,Qt::Horizontal,QObject::tr("ETAT"));
  model->setHeaderData(2,Qt::Horizontal,QObject::tr("TYPE"));
  model->setHeaderData(3,Qt::Horizontal,QObject::tr("KILOMETRAGE"));
  model->setHeaderData(4,Qt::Horizontal,QObject::tr("DISPONIBLE"));
  return model;
}

QSqlQueryModel* ambulance::re(QString r,int t)
{
    QSqlQueryModel * model=new QSqlQueryModel();
    if(t==0)
    {
   model->setQuery("select * from AMBULANCE where MATRICULE like '"+r+"%'or ETAT like '"+r+"%' or TYPE like '"+r+"%' or KILOMETRAGE like '"+r+"%' or DISPONIBLE like '"+r+"%' ");
    }
    if(t==1)
    {
    model->setQuery("select * from AMBULANCE where MATRICULE like '"+r+"%'or ETAT like '"+r+"%' or TYPE like '"+r+"%' or KILOMETRAGE like '"+r+"%' or DISPONIBLE like '"+r+"%' order by MATRICULE");
    }
    if(t==2)
    {
    model->setQuery("select * from AMBULANCE where MATRICULE like '"+r+"%'or ETAT like '"+r+"%' or TYPE like '"+r+"%' or KILOMETRAGE like '"+r+"%' or DISPONIBLE like '"+r+"%' order by TYPE");
    }
    if(t==3)
    {
   model->setQuery("select * from AMBULANCE where MATRICULE like '"+r+"%'or ETAT like '"+r+"%' or TYPE like '"+r+"%' or KILOMETRAGE like '"+r+"%' or DISPONIBLE like '"+r+"%' order by KILOMETRAGE");
    }
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("MATRICULE"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("ETAT"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("TYPE"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("KILOMETRAGE"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("DISPONIBLE"));
    return model;
}

bool ambulance::supprimer(QString m)
{
    QSqlQuery query;
    query.prepare("delete from AMBULANCE where MATRICULE=:m");
    query.bindValue(":m",m);
    return query.exec();
}


bool ambulance::modifier()
{
    QSqlQuery query;
    QString res=QString::number(KILOMETRAGE);
    //QString ses=QString::number(ALERTE_STATUS);
    query.prepare("update AMBULANCE SET ""ETAT=:e,TYPE=:t,KILOMETRAGE=:k,DISPONIBLE=:d where MATRICULE=:m");
    query.bindValue(":m",MATRICULE);
    query.bindValue(":e",ETAT);
    query.bindValue(":t",TYPE);
    query.bindValue(":k",res);
    query.bindValue(":d",DISPONIBLE);
    return query.exec();
}
