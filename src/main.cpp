#include <iostream>
#include <iomanip>
#include <vector>
#include <NN/Activation.h>
#include <NN/Neuron.h>
#include <NN/Matrix.h>

using namespace std;

void MatrixTest() {
    Matrix m(3, 2, true);
    m.print();
    cout << "=====================" << endl;
    Matrix mt(m.transpose());
    mt.print();
}

int main(void) {
    MatrixTest();
    return 0;
}
