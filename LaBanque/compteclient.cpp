/**
    @file CompteClient.cpp
    @brief implémentation de la classe CompteClient
    @version 1.0
    @author Enzo Le Galiard
    @date 12/10/2023
    */
#include "compteclient.h"
#include "menu.h"
#include <iostream>
/**
 * @brief The CHOIX_EPARGNE enum
 * @details donne les différent choix du menu CompteEpargne
 */
enum CHOIX_EPARGNE
{
 CONSULTER_EPARGNE = 1,
 DEPOT_EPARGNE,
 RETRAIT_EPARGNE ,
 INTERETS_EPARGNE,
 QUITTER_EPARGNE
};
/**
 * @brief The CHOIX_BANCAIRE enum
 * @details donne les différent choix du menu CompteBancaire
 */
enum CHOIX_BANCAIRE
{
 CONSULTER_BANCAIRE = 1,
 DEPOT_BANCAIRE,
 RETRAIT_BANCAIRE ,
 QUITTER_BANCAIRE
};

/**
 * @brief CompteClient::CompteClient le constructeur de CompteClient
 * @details créer un compte bancaire avec un solde de 0
 * @param _nom le nom du client
 * @param _numero le numéro du client
 */
CompteClient::CompteClient(const string _nom,const int _numero):
    nom(_nom),
    numero(_numero)
{
    monCompteBancaire = new CompteBancaire(0);
    monCompteEpargne = nullptr;
}

/**
 * @brief CompteClient::~CompteClient le destructeur de CompteClient
 * @details détruit les compte bancaire et epargne si il ne sont pas égale à nullptr
 */
CompteClient::~CompteClient()
{
    if(monCompteBancaire != nullptr){
        delete monCompteBancaire;
    }
    if(monCompteEpargne != nullptr){
        delete monCompteEpargne;
    }
}

/**
 * @brief CompteClient::OuvrirCompteEpargne
 * @details ouvre un compte épargne en demandant le solde à mettre dessus et sont taux d'intérêt
 */
void CompteClient::OuvrirCompteEpargne()
{
    float solde, taux;
    if(monCompteEpargne == nullptr){
        cout<<"combien voulez vous mettre sur le compte épargne ? ";
        cin >> solde;
        cout<<"quel est le taux d'intérêts de votre compte épargne ? ";
        cin >> taux;
        monCompteEpargne = new CompteEpargne(solde, taux);
    }
    else{
        cout<<"un compte épargne existe déjà, impossible d'en créer un nouveau"<<endl;
        exit(EXIT_FAILURE);
    }
}

/**
 * @brief CompteClient::GererCompteBancaire
 * @details lance l'affichage de la gestion de compte bancaire
 */
void CompteClient::GererCompteBancaire()
{
    monCompteBancaire;
    int choix;
    float depot, retrait;
    try {
        Menu bancaire("../LaBanque/compteBancaire.txt");
        do
         {
             choix = bancaire.Afficher();
             switch (choix)
             {
             case CONSULTER_BANCAIRE:
                 cout << "Vous avez choisi CONSULTER" << endl;
                 cout << "votre solde est de "<< monCompteBancaire->ConsulterSolde()<< endl;
                 Menu::AttendreAppuiTouche();
                 break;

             case DEPOT_BANCAIRE:
                 cout << "Vous avez choisi DEPOT" << endl;
                 cout << "combien voulez vous déposez ?" << endl;
                 cin >> depot;
                 monCompteBancaire->Deposer(depot);
                 cout << "votre nouveau solde est de "<<monCompteBancaire->ConsulterSolde()<<endl;
                 Menu::AttendreAppuiTouche();
                 break;

             case RETRAIT_BANCAIRE:
                 cout << "Vous avez choisi RETRAIT" << endl;
                 cout << "combien voulez vous retirer ?" << endl;
                 cin >> retrait;
                 if(monCompteBancaire->Retirer(retrait)==false){
                     cout<<"solde insufisant"<<endl;
                 }
                 else{
                     cout << "votre nouveau solde est de "<<monCompteBancaire->ConsulterSolde()<<endl;
                 }
                 Menu::AttendreAppuiTouche();
                 break;
             }
         } while(choix != QUITTER_BANCAIRE);
    }
    catch (std::runtime_error & e) {

        cout<< e.what() <<endl;
        exit(EXIT_FAILURE);
    }
}

/**
 * @brief CompteClient::GererCompteEpargne
 * @details lance l'affichage de la gestion de compte epargne
 */
void CompteClient::GererCompteEpargne()
{
    monCompteEpargne;
    int choix;
    float depot, retrait;
    try {
        Menu epargne("../LaBanque/compteEpargne.txt");
        do
         {
             choix = epargne.Afficher();
             switch (choix)
             {
             case CONSULTER_EPARGNE:
                 cout << "Vous avez choisi CONSULTER" << endl;
                 cout << "votre solde est de "<< monCompteEpargne->ConsulterSolde()<< endl;
                 Menu::AttendreAppuiTouche();
                 break;

             case DEPOT_EPARGNE:
                 cout << "Vous avez choisi DEPOT" << endl;
                 cout << "combien voulez vous déposez ?" << endl;
                 cin >> depot;
                 monCompteEpargne->Deposer(depot);
                 cout << "votre nouveau solde est de "<<monCompteEpargne->ConsulterSolde()<<endl;
                 Menu::AttendreAppuiTouche();
                 break;

             case RETRAIT_EPARGNE:
                 cout << "Vous avez choisi RETRAIT" << endl;
                 cout << "combien voulez vous retirer ?" << endl;
                 cin >> retrait;
                 if(monCompteEpargne->Retirer(retrait)==false){
                     cout<<"solde insufisant"<<endl;
                 }
                 else{
                     cout << "votre nouveau solde est de "<<monCompteEpargne->ConsulterSolde()<<endl;
                 }
                 Menu::AttendreAppuiTouche();
                 break;


             case INTERETS_EPARGNE:
                 cout << "Vous avez choisi INTERETS" << endl;
                 cout << "votre solde après les interets est de "<< monCompteEpargne->CalculerInterets()<< endl;
                 Menu::AttendreAppuiTouche();
                 break;
             }
         } while(choix != QUITTER_EPARGNE);
    }
    catch (std::runtime_error & e) {

        cout<< e.what() <<endl;
        exit(EXIT_FAILURE);
    }
}
