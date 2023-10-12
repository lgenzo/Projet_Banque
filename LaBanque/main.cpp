#include <iostream>
#include "compteclient.h"
#include "compteepargne.h"
#include "menu.h"
#include "comptebancaire.h"


using namespace std;

enum CHOIX_PRINCIPAL
{
 OUVRIR_EPARGNE = 1,
 GERER_BANCAIRE,
 GERER_EPARGNE ,
 QUITTER
};

int main()
{
    CompteClient monCompte("enzo",49);
    int choix;
    try {
        Menu principal("../LaBanque/client.txt");
        do
         {
             choix = principal.Afficher();
             switch (choix)
             {
             case OUVRIR_EPARGNE:
                 cout << "Vous avez choisi OUVRIR_EPARGNE" << endl;
                 monCompte.OuvrirCompteEpargne();
                 Menu::AttendreAppuiTouche();
                 break;

             case GERER_BANCAIRE:
                 cout << "Vous avez choisi GERER_BANCAIRE" << endl;
                 monCompte.GererCompteBancaire();
                 Menu::AttendreAppuiTouche();
                 break;

             case GERER_EPARGNE:
                 cout << "Vous avez choisi GERER_EPARGNE" << endl;
                 monCompte.GererCompteEpargne();
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
