/**
    @file comptebancaire.h
    @brief Déclaration de la classe CompteClient
    @version 1.0
    @author Enzo Le Galiard
    @date 12/10/2023
    */
#ifndef COMPTECLIENT_H
#define COMPTECLIENT_H
#include "comptebancaire.h"
#include "compteepargne.h"
#include <string>

using namespace std;

class CompteClient
{
private:
    /** pointeur sur un compteBancaire*/
    CompteBancaire *monCompteBancaire;
    /** pointeur sur un CompteEpargne*/
    CompteEpargne *monCompteEpargne;
    /** nom est un string pour le nom du client*/
    string nom;
    /** numéro est un int et est le numéro de client*/
    int numero;
public:
    CompteClient(const string _nom,const int _numero);
    ~CompteClient();
    void OuvrirCompteEpargne();
    void GererCompteBancaire();
    void GererCompteEpargne();
};

#endif // COMPTECLIENT_H
