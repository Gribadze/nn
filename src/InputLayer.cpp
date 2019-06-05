#include <iostream>
#include <NN/InputNeuron.h>
#include <NN/InputLayer.h>

using namespace std;

InputLayer::InputLayer(unsigned long size)
        : Layer(size) {
    for (unsigned long i = 0; i < size; i++) {
        this->m_neurons.push_back(new InputNeuron());
    }
}

void InputLayer::print() const {
    cout << "Input layer" << endl;
    Layer::print();
}
