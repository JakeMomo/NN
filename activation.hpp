//
// Created by jamorin on 26/10/25.
//

#ifndef TRANSFER_H
#define TRANSFER_H

#include "math.h"

template<typename T, int size>
void sigmoid(T const in[size], T out[size]) {
    for(int i=0 ; i<size ; i++) {
        out[i] = 1 / (1 + exp(-in[i]));
    }
}


template<typename T>
struct Activation {

public:

    double eval(T nb);

    template<int size>
    void eval(T const vec[size], T output[size]) {
        for(int i=0 ; i<size ; i++) {
            output[i] = calcul(vec[i]);
        }
    }

    double derivee(T nb);

    template <int size>
    void derivee(T vec[]) {
        for(int i=0 ; i<size ; i++) {
            vec[i] = derivee(vec[i]);
        }
    }
};


template<typename T>
struct Sigmoid: Activation<T> {
public:

    double eval(T nb) {
        return 1 / (1 + exp(-nb));
    }


    double derivee(T nb) {
        T res = eval(nb);
        return res * (1 - res);
    }
};

#endif //TRANSFER_H

