#include <iostream>
#include <string>
#include <iomanip>
#include <NN/NeuralNetwork.h>

using namespace std;

NeuralNetwork::NeuralNetwork(const vector<int> &topology) {
    for (auto &layerSize : topology) {
        this->m_layers.emplace_back(Layer{layerSize});
    }
}

void NeuralNetwork::setInput(const vector<int> &inputs) {
    Layer &inputLayer = this->m_layers.at(0);
    for (int i = 0; i < inputs.size(); i++) {
       inputLayer.setValue(i, inputs.at(i));
    }
}

void NeuralNetwork::print() const {
    int layerIndex = 0;
    string blockSeparator(80, '=');
    for (auto &layer : this->m_layers) {
        if (layerIndex == 0) {
            cout << blockSeparator << endl;
            cout << "Input" << endl; 
        }
        if (layerIndex == 1) {
            cout << blockSeparator << endl;
            cout << "Hidden" << endl;
        }
        if (layerIndex == this->m_layers.size() - 1) {
            cout << blockSeparator << endl;
            cout << "Output" << endl;
        }
        layer.print();
        layerIndex++;
    }
    cout << blockSeparator << endl;
}

