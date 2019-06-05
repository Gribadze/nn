#ifndef NN_LAYER_H
#define NN_LAYER_H

#include <vector>
#include <NN/Neuron.h>
#include <NN/Matrix.h>

class Layer {
private:
    unsigned long m_size;
protected:
    explicit Layer(unsigned long size);

    std::vector<Neuron *> m_neurons;
public:
    Layer(const Layer &copy);

    virtual ~Layer();

    int getSize() const { return m_size; }

    void setValue(unsigned long neuronNum, double value);

    void setValues(const std::vector<double> &values);

    virtual Matrix getValues() const;

    virtual void print() const;
};

#endif
