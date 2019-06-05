#ifndef NN_IACTIVATION_H
#define NN_IACTIVATION_H

namespace Activation {
    class IActivation {
    public:
        virtual ~IActivation() = default;

        virtual IActivation *clone() const = 0;

        virtual double operator()(double input) const = 0;

        virtual double derivative(double input) const = 0;
    };
}

#endif //NN_IACTIVATION_H
