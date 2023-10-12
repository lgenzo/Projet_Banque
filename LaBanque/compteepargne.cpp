/**
    @file Comptebancaire.cpp
    @brief implémentation de la classe CompteEpargne
    @version 1.0
    @author Enzo Le Galiard
    @date 12/10/2023
    */
#include "compteepargne.h"

/**
 * @brief CompteEpargne::CompteEpargne
 * @details créer un compte Epargne avec un solde et un taux d'interêts rattaché
 * @param _solde est le solde du compte epargne
 * @param _tauxInterets est le taux applicqué au solde du compte epargne
 */
CompteEpargne::CompteEpargne(const float _solde, const float _tauxInterets):
    CompteBancaire(_solde),
    tauxInterets(_tauxInterets)
{
}

/**
 * @brief CompteEpargne::CalculerInterets
 * @details Calcule le solde du compte une fois les intérêts appliqués
 * @return retourne le nouveau solde après aplication des taux d'intérêts
 */
float CompteEpargne::CalculerInterets()
{
    float nouveauSolde;
    return nouveauSolde=solde+(solde*tauxInterets/1000);
}

/**
 * @brief CompteEpargne::ModifierTaux
 * @details change le taux d'intérêts pas la valeur passé en paramètre
 * @param _nouveauTaux est la modification du taux d'intérêts
 */
void CompteEpargne::ModifierTaux(float _nouveauTaux)
{
    tauxInterets=_nouveauTaux;
}
