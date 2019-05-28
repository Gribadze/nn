#include <iostream>
#include <iomanip>
#include <vector>
#include <NN/Activation.h>
#include <NN/Neuron.h>

void ActivationTest() {
    Activation::Step step;
    Activation::Linear linear(0.5f);
    Activation::Sigmoid sigmoid;
    Activation::Tanh tanh;
    Activation::ReLu reLu;
    Activation::LeakyReLu leakyReLu(0.1f);
    Activation::ELU elu(0.1f);
    const int columnWidth = 10;
    std::cout << std::setw(columnWidth) << "Value" <<
        " -> " << std::setw(columnWidth) << "Step" << 
        " -> " << std::setw(columnWidth) << "Linear" << 
        " -> " << std::setw(columnWidth) << "Sigmoid" <<
        " -> " << std::setw(columnWidth) << "Tanh" <<
        " -> " << std::setw(columnWidth) << "ReLu" <<
        " -> " << std::setw(columnWidth) << "LeakyReLu" <<
        " -> " << std::setw(columnWidth) << "ELU" <<
        std::endl;
    for (float i = -1.0f; i < 1.1f; i+=0.2f) {
        std::cout.precision(6);
        std::cout << std::fixed << std::setw(columnWidth) << i << 
            " -> " << std::setw(columnWidth) << step(i) << 
            " -> " << std::setw(columnWidth) << linear(i) << 
            " -> " << std::setw(columnWidth) << sigmoid(i) << 
            " -> " << std::setw(columnWidth) << tanh(i) << 
            " -> " << std::setw(columnWidth) << reLu(i) << 
            " -> " << std::setw(columnWidth) << leakyReLu(i) << 
            " -> " << std::setw(columnWidth) << elu(i) << 
            std::endl;
    }
}

void NeuronTest() {
    Neuron n(Activation::Sigmoid{}, 1.4);
    double output = n.getOutput();
    std::cout << output << std::endl;
}

int main(void) {
    NeuronTest();
    return 0;
}
