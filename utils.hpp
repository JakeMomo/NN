#ifndef UTILS_H
#define UTILS_H

#include "math.h"

using namespace std;

template<typename T, int size>
T squareError(T const vec[size], T const ref[size]) {
    T err = 0;
    for(int i=0 ; i<size ; i++) {
        err += 0.5 * pow(vec[i] - ref[i], 2);
    }
    return err;
}


// formule pour un neurone i : delta(poids) = taux * (ref(i) - vec(i)) * transfert'(poids(i)) * entree(i)
// transfer' = dérivée de la fonctione de transfert
// MARCHE UNIQUEMENT POUR SIGMOID ET SQUARE ERROR
template <typename T, int sizeIn, int nbNeurones>
void deltaRule(T const poids[nbNeurones][sizeIn], T const biais[nbNeurones], T const entree[sizeIn], T const sortie_sigmoid[nbNeurones], T const target[sizeIn], T taux, T vecDelta[nbNeurones][sizeIn])
{
    for(int i=0 ; i<nbNeurones ; i++) {
        for(int j=0 ; j<sizeIn ; j++) {
            T dE_dOut = sortie_sigmoid[i] - target[i]; // marche pour square error
            T dSigmoid = sortie_sigmoid[i] * (1 - sortie_sigmoid[i]); // dérivée de sigmoid
            T dPreSigmoid_dPoids = entree[j];

            vecDelta[i][j] = taux * dE_dOut * dSigmoid * dPreSigmoid_dPoids;
        }
    }
}

template <typename T, int sizeIn1, int sizeIn2, int nbNeurones>
void deltaRule2(T const poids[nbNeurones][sizeIn1], T const biais[nbNeurones], T const entree[sizeIn1], T const sortie_sigmoid1[nbNeurones], T const sortie_sigmoid2[nbNeurones], T const target[nbNeurones], T taux, T vecDelta[nbNeurones][sizeIn2])
{
    T deltaIntermediaire[sizeIn2];


    for(int i=0 ; i<nbNeurones ; i++) {
        for(int j=0 ; j<sizeIn2 ; j++) {
            T dE_dOut2 = sortie_sigmoid2[i] - target[i]; // marche pour square error
            T dSigmoid2 = sortie_sigmoid2[i] * (1 - sortie_sigmoid2[i]); // dérivée de sigmoid
            T dPreSigmoid_dortie1 = poids[i][j];

            T dSigmoid1 = sortie_sigmoid1[i] * (1 - sortie_sigmoid1[i]);
            T dPreSigmoid_dentree = entree[i];


            vecDelta[i][j] = taux * dE_dOut2 * dSigmoid2 * dPreSigmoid_dortie1 * dPreSigmoid_dentree;
        }
    }
}


#endif
