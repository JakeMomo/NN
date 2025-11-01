//
// Created by jamorin on 26/10/25.
//

#ifndef LAYER_H
#define LAYER_H

#include "matops.hpp"
#include "activation.hpp"

/***
 *
 *
***/
template<typename T, int nbNeurones, int inSize>
void layer(T const poids[nbNeurones][inSize], T const biais[nbNeurones], T const input[inSize], T output[nbNeurones]) {
    T intermediaire[nbNeurones];
    matVecMul<T, nbNeurones, inSize>(poids, input, intermediaire);
    vecAdd<T, nbNeurones>(intermediaire, biais, output);
}

template<typename T>
class Layer {
public:
    Activation *activation;
    T** poids;
    T* biais;


    template<int nbNeurones, int inSize>
    Layer(Activation* a, T p[nbNeurones][inSize], T b[nbNeurones]) {
        activation = a;
        poids = poids;
        biais = biais;
    }

    ~Layer() {
        delete[] poids;
        delete[] biais;
        delete activation;
    }

    template<int size>
    void forward();
};

#endif //LAYER_H
