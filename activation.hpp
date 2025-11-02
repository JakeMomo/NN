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

template<typename T, int size>
void sigmoid(T in[size]) {
    for(int i=0 ; i<size ; i++) {
        in[i] = 1 / (1 + exp(-in[i]));
    }
}



template<typename T>
struct Activation {
public:

    virtual T eval(T nb) = 0;

    virtual T derivee(T nb) = 0;

    template<int size>
    void eval(T const vec[size], T output[size]) {
        for(int i=0 ; i<size ; i++) {
            output[i] = eval(vec[i]);
        }
    }

    template<int size>
    void eval(T vec[size]) {
        for(int i=0 ; i<size ; i++) {
            vec[i] = eval(vec[i]);
        }
    }


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

    T eval(T nb) override {
        return 1 / (1 + exp(-nb));
    }


    T derivee(T output) override {
        return output * (1 - output);
    }

};

#endif //TRANSFER_H

