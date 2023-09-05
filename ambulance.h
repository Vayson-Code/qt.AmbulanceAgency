#ifndef AMBULANCE_H
#define AMBULANCE_H
#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>

class ambulance
{
    public:
        ambulance();
        ambulance(QString MATRICULE,QString ETAT,int TYPE,float KILOMETRAGE,int DISPONIBLE);
        ~ambulance();


        bool ajouter();
        QSqlQueryModel * afficher(int);
        bool supprimer(QString);
        bool modifier();
        QSqlQueryModel * re(QString r,int t);

        QString GetMATRICULE() { return MATRICULE; }
        void SetMATRICULE(QString val) { MATRICULE = val; }
        QString GetETAT() { return ETAT; }
        void SetETAT(QString val) { ETAT = val; }
        int GetTYPE() { return TYPE; }
        void SetTYPE(int val) { TYPE = val; }
        float GetKILOMETRAGE() { return KILOMETRAGE; }
        void SetKILOMETRAGE(float val) { KILOMETRAGE = val; }
        int GetDISPONIBLE() { return DISPONIBLE; }
        void SetDISPONIBLE(int val) { DISPONIBLE = val; }

    protected:

    private:
        QString MATRICULE;
        QString ETAT;
        int TYPE;
        float KILOMETRAGE;
        int DISPONIBLE;
};

#endif // AMBULANCE_H
