#ifndef NN_LAYER_H
#define NN_LAYER_H

#include <vector>
#include <NN/Neuron.h>
#include <NN/Matrix.h>

class Layer {
private:
    int m_size;
protected:
    Layer(int size);
    std::vector<Neuron *> m_neurons;
    Matrix getInputs() const;
    Matrix getOutputs() const;
    Matrix getDerived() const;
public:
    Layer(const Layer &copy);
    virtual ~Layer();
    int getSize() const { return m_size; }
    void setValue(int neuronNum, const double value);
    void setValues(std::vector<double> values);
    virtual Matrix getValues() const;
    virtual void print() const;
};
#endif
