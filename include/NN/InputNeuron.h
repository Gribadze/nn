#ifndef NN_INPUT_NEURON_H
#define NN_INPUT_NEURON_H

#include <iostream>
#include <vector>
#include <NN/Neuron.h>

class InputNeuron: public Neuron {
public:
    Neuron * clone() const { return new InputNeuron(*this); }
    double getValue() const { return this->getInput(); }
};

#endif
