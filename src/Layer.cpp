#include <iostream>
#include <cassert>
#include <NN/Layer.h>

using namespace std;

Layer::Layer(unsigned long size)
        : m_size(size) {}

Layer::Layer(const Layer &copy)
        : m_size(copy.m_size) {
    for (unsigned long i = 0; i < this->m_size; i++) {
        this->m_neurons.push_back(copy.m_neurons.at(i)->clone());
    }
}

Layer::~Layer() {
    for (auto *neuron : this->m_neurons) {
        delete neuron;
    }
}

void Layer::setValue(unsigned long neuronNum, const double value) {
    this->m_neurons.at(neuronNum)->setValue(value);
}

void Layer::setValues(const vector<double> &values) {
    assert(values.size() == this->m_size);
    for (unsigned long i = 0; i < this->m_size; i++) {
        this->m_neurons.at(i)->setValue(values.at(i));
    }
}

Matrix Layer::getValues() const {
    Matrix inputs(1, this->m_size);
    for (unsigned long i = 0; i < this->m_size; i++) {
        inputs.setValue(0, i, this->m_neurons.at(i)->getValue());
    }
    return std::move(inputs);
}

void Layer::print() const {
    for (auto &neuron : this->m_neurons) {
        neuron->print();
        cout << "\t";
    }
    cout << endl;
}
