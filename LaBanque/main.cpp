#include <iostream>
#include "menu.h"
#include "comptebancaire.h"


using namespace std;

enum CHOIX_PRINCIPAL
{
 CONSULTER = 1,
 DEPOT = 2,
 RETRAIT = 3,
 QUITTER = 4
};

int main()
{
    CompteBancaire monCompte(1000);
    int choix;
    float depot, retrait;
    try {
        Menu principal("../LaBanque/compteBancaire.txt");
        do
         {
             choix = principal.Afficher();
             switch (choix)
             {
             case CONSULTER:
                 cout << "Vous avez choisi CONSULTER" << endl;
                 cout << "votre solde est de "<< monCompte.ConsulterSolde()<< endl;
                 Menu::AttendreAppuiTouche();
                 break;

             case DEPOT:
                 cout << "Vous avez choisi DEPOT" << endl;
                 cout << "combien voulez vous déposez ?" << endl;
                 cin >> depot;
                 monCompte.Deposer(depot);
                 cout << "votre nouveau solde est de "<<monCompte.ConsulterSolde()<<endl;
                 Menu::AttendreAppuiTouche();
                 break;

             case RETRAIT:
                 cout << "Vous avez choisi RETRAIT" << endl;
                 cout << "combien voulez vous retirer ?" << endl;
                 cin >> retrait;
                 if(monCompte.Retirer(retrait)==false){
                     cout<<"solde insufisant"<<endl;
                 }
                 else{
                     cout << "votre nouveau solde est de "<<monCompte.ConsulterSolde()<<endl;
                 }
                 Menu::AttendreAppuiTouche();
                 break;
             }
         } while(choix != QUITTER);
    }
    catch (std::runtime_error & e) {

        cout<< e.what() <<endl;
        exit(EXIT_FAILURE);
    }

    return 0;
}
