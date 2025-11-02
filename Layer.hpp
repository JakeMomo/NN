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

template<typename T, int inputSize, int outputSize>
struct Layer {
public:
    Activation<T> *activation;
    T* poids;
    T* biais;

    ~Layer() {
        free(activation);
        free(poids);
        free(biais);
    }


    virtual void forward(T input[inputSize], T output[outputSize]){};
};

#endif //LAYER_H
