#include <iostream>
#include <cassert>
#include <string>
#include <iomanip>
#include <NN/InputLayer.h>
#include <NN/HiddenLayer.h>
#include <NN/OutputLayer.h>
#include <NN/NeuralNetwork.h>

using namespace std;

NeuralNetwork::NeuralNetwork(const vector<int> &topology) : m_errorTotal(0.0) {
    const unsigned long topologySize = topology.size();
    assert(topologySize > 2);
    this->m_layers.push_back(new InputLayer(topology.at(0)));
    for (unsigned long i = 1; i < topologySize - 1; i++) {
        this->m_layers.push_back(new HiddenLayer(topology.at(i)));
    }
    this->m_layers.push_back(new OutputLayer(topology.at(topologySize - 1)));
    for (unsigned long i = 0; i < topologySize - 1; i++) {
        this->m_weights.emplace_back(Matrix(topology.at(i), topology.at(i + 1), true));
    }
}

NeuralNetwork::~NeuralNetwork() {
    for (auto *layer : this->m_layers) {
        delete layer;
    }
}

void NeuralNetwork::setInput(const vector<double> &inputs) {
    Layer *inputLayer = this->m_layers.at(0);
    for (unsigned long i = 0; i < inputs.size(); i++) {
        inputLayer->setValue(i, inputs.at(i));
    }
}

void NeuralNetwork::setTarget(const vector<double> &targets) {
    for (auto &targetValue : targets) {
        m_target.push_back(targetValue);
    }
}

void NeuralNetwork::feedForward() {
    for (unsigned long i = 0; i < this->m_layers.size() - 1; i++) {
        Layer *currentLayer = this->m_layers.at(i);
        Layer *nextLayer = this->m_layers.at(i + 1);
        Matrix values = currentLayer->getValues();
        Matrix nextValues = values * this->m_weights.at(i);
        nextLayer->setValues(nextValues.toVector());
    }
}

void NeuralNetwork::backPropogation() {


}

void NeuralNetwork::print() const {
    unsigned long layerIndex = 0;
    string blockSeparator(80, '=');
    for (auto *layer : this->m_layers) {
        cout << blockSeparator << endl;
        layer->print();
        if (layerIndex != this->m_layers.size() - 1) {
            cout << blockSeparator << endl;
            cout << "__wieghts__" << endl;
            this->m_weights.at(layerIndex).print();
        }
        layerIndex++;
    }
    cout << blockSeparator << endl;
}

