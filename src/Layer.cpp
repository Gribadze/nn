#include <NN/Layer.h>

Layer::Layer(int size) {
    for (int i = 0; i < size; i++) {
        this->m_neurons.emplace_back(Neuron{});
    }
}

void Layer::print() {
    for (auto &neuron : this->m_neurons) {
        neuron.print();
    }
}
