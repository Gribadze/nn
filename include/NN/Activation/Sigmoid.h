#ifndef NN_SIGMOID_H
#define NN_SIGMOID_H

#include <cmath>
#include <NN/Activation/ActivationBase.h>

namespace Activation {
    class Sigmoid : public ActivationBase {
    public:
        IActivation *clone() const override { return new Sigmoid(*this); }

        double operator()(double input) const override {
            return 1 / (1 + exp(-input));
        }
    };
}

#endif //NN_SIGMOID_H
