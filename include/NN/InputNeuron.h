#ifndef NN_INPUT_NEURON_H
#define NN_INPUT_NEURON_H

#include <NN/Neuron.h>

class InputNeuron : public Neuron {
public:
    InputNeuron() : Neuron() {}

    Neuron *clone() const override { return new InputNeuron(*this); }

    double getValue() const override { return this->getInput(); }
};

#endif
