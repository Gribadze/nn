#ifndef NN_LAYER_H
#define NN_LAYER_H

#include <iostream>
#include <vector>
#include <NN/Neuron.h>

class Layer {
public:

    void print();
private:
    std::vector<Neuron *> m_neurons;
};
#endif
