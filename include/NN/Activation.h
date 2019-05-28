#ifndef NN_ACTIVATION_H
#define NN_ACTIVATION_H

#include <iostream>
#include <cmath>

namespace Activation {
    class IActivation {
        public:
            auto operator=(const IActivation &rhs) {
                std::cout << "IActivation assignment\n";
            }
            virtual ~IActivation() = default;
            virtual double operator()(double input) const = 0;
    };

    class Step : public IActivation {
        public:
            static Step create() {
                Step newStep;
                return newStep;
            }
            double operator()(double input) const {
                return (input > 0) ? 1 : 0;
            }
    };

    class Linear : public IActivation {
        public:
            Linear(double t_c): m_c(t_c) {}
            double operator()(double input) const {
                return m_c * input;
            }
        private:
            const double m_c;
    };

    class Sigmoid : public IActivation {
        public:
            double operator()(double input) const {
                return 1 / (1 + exp(-input));
            }
    };

    class Tanh : public IActivation {
        public: 
            double operator()(double input) const {
                return (1 - exp(-2 * input)) / (1 + exp(-2 * input));
            }
    };

    class ReLu : public IActivation {
        public: 
            double operator()(double input) const {
                return std::max(0.0, input);
            }
    };

    class LeakyReLu : public IActivation {
        public:
            LeakyReLu(double t_c) : m_c(t_c) {}
            double operator()(double input) const {
                return std::max(m_c * input, input);
            }
        private:
            const double m_c;
    };

    class ELU : public IActivation {
        public:
            ELU(double t_c) : m_c(t_c) {}
            double operator()(double input) const {
                return (input >= 0) ? input : m_c * (exp(input) - 1);
            }
        private:
            const double m_c;
    };
};

#endif
