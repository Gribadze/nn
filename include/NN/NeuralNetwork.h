#ifndef NN_NEURAL_NETWORK_H
#define NN_NEURAL_NETWORK_H

#include <vector>
#include <NN/Layer.h>

class NeuralNetwork {
private:
    std::vector<Layer> m_layers;
public:
    explicit NeuralNetwork(const std::vector<int> &topology);
    void setInput(const std::vector<int> &inputs);
    void print() const;
};
#endif
