#ifndef NN_NEURON_H
#define NN_NEURON_H

#include <iostream>
#include <vector>
#include <NN/Activation/IActivation.h>
#include <NN/Activation/Sigmoid.h>
#include <NN/Activation/Tanh.h>
#include <NN/Activation/ActivationFactory.h>

class Neuron {
private:
    double m_input;
    double m_output;
    double m_derivedVal;
    const Activation::IActivation *m_activation;
public:

    explicit Neuron(
            double t_input = 0.0,
            Activation::IActivation *t_activation = Activation::ActivationFactory::create(
                    Activation::ActivationType::Sigmoid)
    );

    double getInput() const { return this->m_input; }

    double getOutput() const { return this->m_output; }

    Neuron(const Neuron &copy);

    ~Neuron();

    Neuron *clone() const;

    void setValue(double t_input);

    void print() const;

    double getDerived() const { return this->m_derivedVal; }

private:
    void calc();
};

#endif
