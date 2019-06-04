#ifndef NN_HIDDEN_NEURON_H
#define NN_HIDDEN_NEURON_H

#include <iostream>
#include <vector>
#include <NN/Neuron.h>

class HiddenNeuron: public Neuron {
public:
    Neuron * clone() const { return new HiddenNeuron(*this); }
    double getValue() const { return this->getOutput(); }
};

#endif
