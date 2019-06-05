#ifndef NN_OUTPUT_NEURON_H
#define NN_OUTPUT_NEURON_H

#include <NN/Neuron.h>

class OutputNeuron : public Neuron {
public:
    Neuron *clone() const override { return new OutputNeuron(*this); }

    double getValue() const override { return this->getInput(); }
};

#endif

