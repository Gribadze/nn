#ifndef NN_NEURAL_NETWORK_H
#define NN_NEURAL_NETWORK_H

#include <vector>
#include <NN/Matrix.h>
#include <NN/Layer.h>

class NeuralNetwork {
private:
    std::vector<Layer *> m_layers;
    std::vector<Matrix> m_weights;
    std::vector<double> m_target;
    double m_errorTotal;
public:
    explicit NeuralNetwork(const std::vector<int> &topology);

    ~NeuralNetwork();

    void setInput(const std::vector<double> &inputs);

    void setTarget(const std::vector<double> &targets);

    void feedForward();

    void backPropogation();

    void print() const;
};

#endif
