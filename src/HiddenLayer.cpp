#include <iostream>
#include <NN/HiddenLayer.h>
#include <NN/HiddenNeuron.h>

using namespace std;

HiddenLayer::HiddenLayer(unsigned long size)
        : Layer(size) {
    for (unsigned long i = 0; i < size; i++) {
        this->m_neurons.push_back(new HiddenNeuron());
    }
}

void HiddenLayer::print() const {
    cout << "Hidden Layer" << endl;
    Layer::print();
}
