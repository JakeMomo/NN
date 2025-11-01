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


struct Activation {

public:
    template<typename T>
    double eval(T nb);

    template<typename T, int size>
    void eval(T const vec[size], T output[size]) {
        for(int i=0 ; i<size ; i++) {
            output[i] = calcul(vec[i]);
        }
    }

    template <typename T>
    double derivee(T nb);

    template <typename T, int size>
    void derivee(T vec[]) {
        for(int i=0 ; i<size ; i++) {
            vec[i] = derivee(vec[i]);
        }
    }
};


struct Sigmoid: Activation {
public:
    template<typename T>
    double eval(T nb) {
        return 1 / (1 + exp(-nb));
    }

    template <typename T>
    double derivee(T nb) {
        T res = eval(nb);
        return res * (1 - res);
    }
};

#endif //TRANSFER_H

