#ifndef NN_ACTIVATION_FACTORY_H
#define NN_ACTIVATION_FACTORY_H

#include <NN/Activation/Sigmoid.h>

namespace Activation {
    enum class ActivationType {
        Sigmoid, Tanh
    };

    class ActivationFactory {
    public:
        static IActivation *create(const ActivationType &activationType) {
            switch (activationType) {
                case ActivationType::Sigmoid:
                    return new Sigmoid();
                case ActivationType::Tanh:
                    return new Tanh();
                default:
                    throw;
            }
        }
    };

}

#endif //NN_ACTIVATION_FACTORY_H
