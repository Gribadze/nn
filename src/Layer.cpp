#include <iostream>
#include <NN/Layer.h>

using namespace std;

Layer::Layer(int size) {
    for (int i = 0; i < size; i++) {
        this->m_neurons.emplace_back(Neuron{});
    }
}

void Layer::setValue(int neuronNum, const double value) {
    this->m_neurons.at(neuronNum).setInput(value);
}

void Layer::print() const {
    for (auto &neuron : this->m_neurons) {
        neuron.print();
        cout << "\t";
    }
    cout << endl;
}
