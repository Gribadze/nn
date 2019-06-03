#include <iostream>
#include <cassert>
#include <NN/Layer.h>

using namespace std;

Layer::Layer(int size)
    : m_size(size), m_neurons(vector<Neuron>(size))
{}

void Layer::setValue(int neuronNum, const double value) {
    this->m_neurons.at(neuronNum).setInput(value);
}

void Layer::setValues(vector<double> values) {
    assert(values.size() == this->m_size);
    for (int i = 0; i < this->m_size; i++) {
        this->m_neurons.at(i).setInput(values.at(i));
    }
}

Matrix Layer::getInputs() const {
    Matrix inputs(1, this->m_size);
    for (int i = 0; i < this->m_size; i++) {
        inputs.setValue(0, i, this->m_neurons.at(i).getInput());
    }
    return std::move(inputs);
}

Matrix Layer::getOutputs() const {
    Matrix inputs(1, this->m_size);
    for (int i = 0; i < this->m_size; i++) {
        inputs.setValue(0, i, this->m_neurons.at(i).getOutput());
    }
    return std::move(inputs);
}

Matrix Layer::getDerived() const {
    Matrix inputs(1, this->m_size);
    for (int i = 0; i < this->m_size; i++) {
        inputs.setValue(0, i, this->m_neurons.at(i).getDerived());
    }
    return std::move(inputs);
}

void Layer::print() const {
    for (auto &neuron : this->m_neurons) {
        neuron.print();
        cout << "\t";
    }
    cout << endl;
}
