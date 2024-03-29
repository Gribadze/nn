#include <iostream>
#include <NN/Neuron.h>

using namespace std;

Neuron::Neuron(const double t_input, Activation::IActivation *t_activation)
        : m_input(t_input), m_output(0.0), m_derivedVal(0.0) {
    this->m_activation = t_activation->clone();
    this->calc();
}

Neuron::Neuron(const Neuron &copy)
        : m_input(copy.m_input) {
    this->m_activation = copy.m_activation->clone();
    this->calc();
}

Neuron::~Neuron() {
    delete this->m_activation;
}

void Neuron::setValue(const double t_input) {
    this->m_input = t_input;
    this->calc();
}

void Neuron::print() const {
    cout << "{" << this->getValue() << "}";
}

void Neuron::calc() {
    this->m_output = (*this->m_activation)(this->m_input);
    this->m_derivedVal = this->m_activation->derivative(this->m_input);
}
