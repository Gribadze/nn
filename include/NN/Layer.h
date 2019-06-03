#ifndef NN_LAYER_H
#define NN_LAYER_H

#include <vector>
#include <NN/Neuron.h>
#include <NN/Matrix.h>

class Layer {
private:
    std::vector<Neuron> m_neurons;
    int m_size;
public:
    Layer(int size);
    void setValue(int neuronNum, const double value);
    void setValues(std::vector<double> values);
    int getSize() const { return m_size; }
    Matrix getInputs() const;
    Matrix getOutputs() const;
    Matrix getDerived() const;
    void print() const;
};
#endif
