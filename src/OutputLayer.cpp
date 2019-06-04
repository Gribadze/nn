#include <iostream>
#include <NN/OutputLayer.h>
#include <NN/OutputNeuron.h>

using namespace std;

OutputLayer::OutputLayer(int size)
    : Layer(size)
{
    for (int i = 0; i < size; i++) {
        this->m_neurons.push_back(new OutputNeuron());
    }
}

void OutputLayer::print() const {
    cout << "Output Layer" << endl;
    Layer::print();
}

