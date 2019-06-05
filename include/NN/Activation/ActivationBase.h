#ifndef NN_ACTIVATION_BASE_H
#define NN_ACTIVATION_BASE_H

#include <NN/Activation/IActivation.h>

namespace Activation {
    const double derivativeStep = 0.0001;

    class ActivationBase : public IActivation {
    public:
        double derivative(double input) const final {
            return (this->operator()(input + derivativeStep) - this->operator()(input - derivativeStep)) /
                   (2 * derivativeStep);
        }
    };
}

#endif //NN_ACTIVATION_BASE_H
