#ifndef ALERTE_H
#define ALERTE_H
#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>

class Alerte
{
    public:
        Alerte();
        Alerte(int ID_A,QString ADRESSE,int STATUS,QString CHEMAIN_VOCAL);
        ~Alerte();

bool ajouter();
QSqlQueryModel * afficher(int t);
bool supprimer(int);
bool modifier();
QSqlQueryModel * re(QString r,int t);

        int GetID_A() { return ID_A; }
        void SetID_A(int val) { ID_A = val; }
         QString GetADRESSE() { return ADRESSE; }
        void SetADRESSE( QString val) { ADRESSE = val; }
        int GetSTATUS() { return STATUS; }
        void SetSTATUS(int val) { STATUS = val; }
        QString GetCHEMAIN_VOCAL() { return CHEMAIN_VOCAL; }
        void SetCHEMAIN_VOCAL( QString val) { CHEMAIN_VOCAL = val; }

    private:
        int ID_A;
        QString ADRESSE;
        int STATUS;
        QString CHEMAIN_VOCAL;
};

#endif // ALERTE_H
