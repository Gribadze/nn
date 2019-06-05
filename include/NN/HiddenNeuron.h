#ifndef NN_HIDDEN_NEURON_H
#define NN_HIDDEN_NEURON_H

#include <NN/Neuron.h>

class HiddenNeuron : public Neuron {
public:
    Neuron *clone() const override { return new HiddenNeuron(*this); }

    double getValue() const override { return this->getOutput(); }
};

#endif
