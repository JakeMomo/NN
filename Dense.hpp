#ifndef DENSE_HPP_INCLUDED
#define DENSE_HPP_INCLUDED

#include "Layer.hpp"
#include "matops.hpp"
#include "activation.hpp"


template<typename T, int inputSize, int nbNeurones>
struct Dense: Layer<T, inputSize, nbNeurones> {
public:

    Dense(T** p, T* b, Activation<T>* a) {
        this->poids = p;
        this->biais = b;
        this->activation = a;
    }


    void forward(T input[inputSize], T output[nbNeurones]) {
        matVecMul<T, nbNeurones, inputSize>(this->poids, input, output);
        vecAcc<T, nbNeurones>(output, this->biais);
    }
};

#endif // DENSE_HPP_INCLUDED
