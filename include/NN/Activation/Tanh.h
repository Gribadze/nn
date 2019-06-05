#ifndef NN_TANH_H
#define NN_TANH_H

#include <NN/Activation/ActivationBase.h>

namespace Activation {
    class Tanh : public ActivationBase {
    public:
        IActivation *clone() const override { return new Tanh(*this); }

        double operator()(double input) const override {
            return (1 - exp(-2 * input)) / (1 + exp(-2 * input));
        }
    };
}

#endif //NN_TANH_H
