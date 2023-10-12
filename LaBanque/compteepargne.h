/**
    @file comptebancaire.h
    @brief Déclaration de la classe CompteEpargne qui hérite de CompteBancaire
    @version 1.0
    @author Enzo Le Galiard
    @date 12/10/2023
    */
#ifndef COMPTEEPARGNE_H
#define COMPTEEPARGNE_H

#include "comptebancaire.h"

class CompteEpargne : public CompteBancaire
{
private:
    /** taux d'intérêt exprimer en pour cent*/
    float tauxInterets = 3;
public:
    CompteEpargne(const float _solde, const float _tauxInterets);
    float CalculerInterets();
    void ModifierTaux(float _nouveauTaux);
};

#endif // COMPTEEPARGNE_H
