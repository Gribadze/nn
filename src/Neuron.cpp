#include <iostream>
#include <NN/Neuron.h>

using namespace std;

Neuron::Neuron(const double t_input, Activation::IActivation *t_activation) 
    : m_input(t_input), m_activation(t_activation) 
{
    this->calc();
}

Neuron::~Neuron() {
    if (this->m_activation) {
        delete this->m_activation;
    }
}

void Neuron::setInput(const double t_input) {
    this->m_input = t_input;
    this->calc();
}

void Neuron::print() const {
    cout << "{" << this->m_input << "," << this->m_output << "," << 
        this->m_derivedVal << "}";
} 

void Neuron::calc() {
    this->m_output = (*this->m_activation)(this->m_input);
    this->m_derivedVal = this->m_activation->derivative(this->m_input);
}
