#ifndef NN_OUTPUT_NEURON_H
#define NN_OUTPUT_NEURON_H

#include <iostream>
#include <vector>
#include <NN/Neuron.h>

class OutputNeuron: public Neuron {
public:
    Neuron * clone() const { return new OutputNeuron(*this); }
    double getValue() const { return this->getInput(); }
};

#endif

