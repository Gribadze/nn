#include <iostream>
#include <string>
#include <iomanip>
#include <NN/NeuralNetwork.h>

using namespace std;

NeuralNetwork::NeuralNetwork(const vector<int> &topology) {
    for (auto &layerSize : topology) {
        this->m_layers.push_back(Layer(layerSize));
    }
    for (int i = 0; i < (topology.size() - 1); i++) {
        this->m_weights.push_back(
                Matrix{topology.at(i), topology.at(i + 1), true}
                );
    }
}

void NeuralNetwork::setInput(const vector<int> &inputs) {
    Layer &inputLayer = this->m_layers.at(0);
    for (int i = 0; i < inputs.size(); i++) {
       inputLayer.setValue(i, inputs.at(i));
    }
}

void NeuralNetwork::feedForward() {
    for (int i = 0; i < this->m_layers.size() - 1; i++) {
        Layer &currentLayer = this->m_layers.at(i);
        Layer &nextLayer = this->m_layers.at(i + 1);
        Matrix values;
        if (i == 0) {
            values = currentLayer.getInputs();
        } else {
            values = currentLayer.getOutputs();
        }
        Matrix nextValues = values * this->m_weights.at(i);
        nextLayer.setValues(nextValues.toVector());
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
        if (layerIndex != this->m_layers.size() - 1) {
            cout << "__wieghts__" << endl;
            this->m_weights.at(layerIndex).print();
        }
        layerIndex++;
    }
    cout << blockSeparator << endl;
}

