#ifndef DENSE_HPP_INCLUDED
#define DENSE_HPP_INCLUDED

#include "Layer.hpp"
#include "matops.hpp"
#include "activation.hpp"


template<typename T, int nbNeurones, int inputSize>
struct Dense: Layer<T, inputSize, nbNeurones> {
public:

    Dense(T* p, T* b, Activation<T>* a) {
        this->poids = p;
        this->biais = b;
        this->activation = a;
    }

    Dense(Activation<T>* a) {
        this.poids = (T*) malloc(inputSize * nbNeurones * sizeof(T));
        this.biais = (T*) malloc(nbNeurones * sizeof(T));
    }


    void forward(T input[inputSize], T output[nbNeurones]) {
        matVecMul<T, nbNeurones, inputSize>(this->poids, input, output);
        vecAcc<T, nbNeurones>(output, this->biais);
        this->activation->template eval<nbNeurones>(output);
    }

    void backward(T const input[inputSize], T const output[nbNeurones], T const target[nbNeurones], T taux) {
        T* vecDelta_p = (T*) malloc(inputSize * nbNeurones * sizeof(T)); // [nbNeurones][sizeIn]
        T (*vecDelta)[inputSize] = (T(*)[inputSize]) vecDelta_p;

        for(int i=0 ; i<nbNeurones ; i++) {
            for(int j=0 ; j<inputSize ; j++) {
                T dE_dOut = output[i] - target[i]; // marche pour square error
                T dSigmoid = this->activation->derivee(output[i]);
                T dPreSigmoid_dPoids = input[j];

                vecDelta[i][j] = taux * dE_dOut * dSigmoid * dPreSigmoid_dPoids;
            }
        }
        matSub<T, nbNeurones, inputSize>(this->poids, vecDelta_p);

        free(vecDelta_p);
    }

};

#endif // DENSE_HPP_INCLUDED
