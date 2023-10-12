/**
    @file comptebancaire.h
    @brief Déclaration de la classe CompteBancaire
    @version 1.0
    @author Enzo Le Galiard
    @date 12/10/2023
    */
#ifndef COMPTEBANCAIRE_H
#define COMPTEBANCAIRE_H


class CompteBancaire
{
protected:
    /**solde du compte*/
    float solde;
public:
    CompteBancaire(const float _solde = 0);
    void Deposer(const float _montant);
    bool Retirer(const float _montant);
    float ConsulterSolde();
};

#endif // COMPTEBANCAIRE_H
