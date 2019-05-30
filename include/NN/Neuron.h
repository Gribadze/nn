#ifndef NN_NEURON_H
#define NN_NEURON_H

#include <iostream>
#include <vector>
#include <NN/Activation.h>

class Neuron {
private:
    double m_input;
    double m_output;
    double m_derivedVal;
    const Activation::IActivation &m_activation;
public:
    explicit Neuron(
            const double t_input = 0.0, 
            Activation::IActivation &&t_activation = Activation::Sigmoid{}
            ); 
    ~Neuron() {}
    void setInput(const double t_input);
    double getInput() const { return this->m_input; }
    double getOutput() const { return this->m_output; }
    double getDerived() const { return this->m_derivedVal; } 
    void print() const;
private:
    void calc();
};

#endif
