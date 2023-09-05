#include "alerte.h"

Alerte::Alerte()
{
    //ctor
}
Alerte::Alerte(int ID_A,QString ADRESSE,int STATUS,QString CHEMAIN_VOCAL)
{
    this->ID_A=ID_A;
    this->ADRESSE=ADRESSE;
    this->STATUS=STATUS;
    this->CHEMAIN_VOCAL=CHEMAIN_VOCAL;
}


Alerte::~Alerte()
{
    //dtor
}
bool Alerte::ajouter()
{
    QSqlQuery query;
    //QString res=QString::number(ID_A);
    //QString ses=QString::number(STATUS);
    query.prepare("insert into ALERTE(ID_A,ADRESSE,STATUS,CHEMAIN_VOCAL)""values(:n,:l,:s,:c)");
    query.bindValue(":n",ID_A);
    query.bindValue(":l",ADRESSE);
    query.bindValue(":s",STATUS);
    query.bindValue(":c",CHEMAIN_VOCAL);
    return query.exec();
}
QSqlQueryModel* Alerte::afficher(int t)
{
  QSqlQueryModel * model=new QSqlQueryModel();
  if(t==0)
  {
  model->setQuery("select * from ALERTE");
  }
  if(t==1)
  {
  model->setQuery("select * from ALERTE order by ID_A");
  }
  if(t==2)
  {
  model->setQuery("select * from ALERTE order by STATUS");
  }
  if(t==3)
  {
  model->setQuery("select * from ALERTE order by ADRESSE");
  }
  model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID_A"));
  model->setHeaderData(1,Qt::Horizontal,QObject::tr("ADRESSE"));
  model->setHeaderData(2,Qt::Horizontal,QObject::tr("STATUS"));
  model->setHeaderData(3,Qt::Horizontal,QObject::tr("FICHIER AUDIO"));
  return model;
}
bool Alerte::supprimer(int n)
{
    QSqlQuery query;
    query.prepare("delete from ALERTE where ID_A=:n");
    query.bindValue(":n",n);
    return query.exec();
}
bool Alerte::modifier()
{
    QSqlQuery query;
    //QString res=QString::number(ID_A);
    //QString ses=QString::number(STATUS);
    query.prepare("update ALERTE SET ""ADRESSE=:l,STATUS=:s,CHEMAIN_VOCAL=:c where ID_A=:n");
    query.bindValue(":n",ID_A);
    query.bindValue(":l",ADRESSE);
    query.bindValue(":s",STATUS);
    query.bindValue(":c",CHEMAIN_VOCAL);
    return query.exec();
}

QSqlQueryModel* Alerte::re(QString r,int t)
{
    QSqlQueryModel * model=new QSqlQueryModel();
    if(t==0)
    {
   model->setQuery("select * from ALERTE where ID_A like '"+r+"%'or ADRESSE like '"+r+"%' or STATUS like '"+r+"%' or CHEMAIN_VOCAL like '"+r+"%' ");
    }
    if(t==1)
    {
    model->setQuery("select * from ALERTE where ID_A like '"+r+"%'or ADRESSE like '"+r+"%' or STATUS like '"+r+"%' or CHEMAIN_VOCAL like '"+r+"%' order by ID_A");
    }
    if(t==2)
    {
    model->setQuery("select * from ALERTE where ID_A like '"+r+"%'or ADRESSE like '"+r+"%' or STATUS like '"+r+"%' or CHEMAIN_VOCAL like '"+r+"%' order by STATUS");
    }
    if(t==3)
    {
   model->setQuery("select * from ALERTE where ID_A like '"+r+"%'or ADRESSE like '"+r+"%' or STATUS like '"+r+"%' or CHEMAIN_VOCAL like '"+r+"%' order by ADRESSE");
    }
  model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID_A"));
  model->setHeaderData(1,Qt::Horizontal,QObject::tr("ADRESSE"));
  model->setHeaderData(2,Qt::Horizontal,QObject::tr("STATUS"));
  model->setHeaderData(3,Qt::Horizontal,QObject::tr("FICHIER AUDIO"));
  return model;
}
