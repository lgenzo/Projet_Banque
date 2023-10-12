/**
    @file Comptebancaire.cpp
    @brief implémentation de la classe CompteBancaire
    @version 1.0
    @author Enzo Le Galiard
    @date 12/10/2023
    */
#include "comptebancaire.h"

/**
   @brief CompteBancaire::CompteBancaire le constructeur de la classe CompteBancaire
   @details créer un compte bancaire avec un solde rattache
   @param _solde solde du compte
   @author Enzo Le Galiard
 */
CompteBancaire::CompteBancaire(const float _solde):
    solde(_solde)
{  
}

/**
   @brief CompteBancaire::Deposer
   @details permet de déposer un montant sur le compre
   @param _montant le montant à déposer
   @author Enzo Le Galiard
 */
void CompteBancaire::Deposer(const float _montant)
{
    solde+=_montant;
}

/**
   @brief CompteBancaire::Retirer
   @details permet de retirer un montant du le compre si le solde est siffisant, retourn true si c'est vrai et false sinon
   @param _montant le montant à retirer
   @author Enzo Le Galiard
 */
bool CompteBancaire::Retirer(const float _montant)
{
    bool possible=false;
    if(_montant>solde){
        return possible;
    }
    else{
        possible=true;
        solde-=_montant;
    }
    return possible;
}

/**
   @brief CompteBancaire::ConsulterSolde
   @details permet de consulter le solde
   @author Enzo Le Galiard
 */
float CompteBancaire::ConsulterSolde()
{
    return solde;
}
