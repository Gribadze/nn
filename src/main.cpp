#include <iostream>
#include <iomanip>
#include <vector>
#include <NN/NeuralNetwork.h>

using namespace std;

int main() {
    NeuralNetwork nn{{3, 2, 3}};
    nn.setInput({1, 0, 1});
    nn.feedForward();
    nn.print();
    return 0;
}
