#ifndef NN_NEURON_H
#define NN_NEURON_H

#include <iostream>
#include <vector>
#include <NN/Activation.h>

typedef std::vector<double> vector_d;

class Neuron {
public:
    explicit Neuron(const Activation::IActivation &t_activation, const double t_input = 0.0) 
        : m_input(t_input), m_activation(t_activation) 
    {
        this->calc();
    }
    
    explicit Neuron(Activation::IActivation &&t_activation, const double t_input = 0.0) 
        : m_input(t_input), m_activation(std::move(t_activation)) 
    {
        this->calc();
    }

    ~Neuron() {}

    void setInput(const double t_input) {
        this->m_input = t_input;
        this->calc();
    }

    double getInput() const {
        return this->m_input;
    }

    double getOutput() const {
        return this->m_output;
    }

    double getDerived() const {
        return this->m_derivedVal;
    } 

    void print() const {
        std::cout << "{" << this->m_input << "," << this->m_output << "," << this->m_derivedVal << "}" << std::endl;
    } 

private:
    double m_input;
    double m_output;
    double m_derivedVal;
    const Activation::IActivation &m_activation;

    void calc() {
        this->m_output = this->m_activation(this->m_input);
        this->m_derivedVal = this->m_activation.derivative(this->m_input);
    }
};
#endif
