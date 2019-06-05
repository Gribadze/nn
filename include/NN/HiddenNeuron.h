#ifndef NN_HIDDEN_NEURON_H
#define NN_HIDDEN_NEURON_H

#include <NN/Neuron.h>

class HiddenNeuron : public Neuron {
public:
    HiddenNeuron() : Neuron() {}

    Neuron *clone() const override { return new HiddenNeuron(*this); }

    double getValue() const override { return this->getOutput(); }
};

#endif
