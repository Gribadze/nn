#ifndef NN_LAYER_H
#define NN_LAYER_H

#include <vector>
#include <NN/Neuron.h>

class Layer {
private:
    std::vector<Neuron> m_neurons;
public:
    Layer(int size);
    void setValue(int neuronNum, const double value);
    void print() const;
};
#endif
