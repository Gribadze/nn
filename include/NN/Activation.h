#ifndef NN_ACTIVATION_H
#define NN_ACTIVATION_H

#include <iostream>
#include <cmath>

namespace Activation {
    class IActivation {
    public:
        virtual ~IActivation() = default;
        virtual double operator()(double input) const = 0;
        virtual double derivative(double input) const = 0;
    };
  
    class Step : public IActivation {
    public:
        double operator()(double input) const {
            return (input > 0) ? 1 : 0;
        }
        double derivative(double input) const {
            return 0;
        }
    };

    class Linear : public IActivation {
    public:
        Linear(double t_c): m_c(t_c) {}
        double operator()(double input) const {
            return m_c * input;
        }
        double derivative(double input) const {
            return m_c;
        }

    private:
        const double m_c;
    };

    class Sigmoid : public IActivation {
    public:
        double operator()(double input) const {
            std::cout << input << std::endl;
            return 1 / (1 + exp(-input));
        }
        double derivative(double input) const {
            return exp(-input) / ((1 + exp(-input)) * (1 + exp(-input)));
        }
    };

    class Tanh : public IActivation {
    public: 
        double operator()(double input) const {
            return (1 - exp(-2 * input)) / (1 + exp(-2 * input));
        }
        double derivative(double input) const {
            return (4 * exp(-2 * input)) / ((1 + exp(-2 * input)) * (1 + exp(-2 * input)));
        }
    };

    class ReLu : public IActivation {
    public: 
        double operator()(double input) const {
            return std::max(0.0, input);
        }
        double derivative(double input) const {
            return input > 0.0 ? 1 : 0;
        }
    };

    class LeakyReLu : public IActivation {
    public:
        LeakyReLu(double t_c) : m_c(t_c) {}
        double operator()(double input) const {
            return std::max(m_c * input, input);
        }
        double derivative(double input) const {
            return input > m_c * input ? 1 : m_c;
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
        double derivative(double input) const {
            return input >= 0 ? 1 : m_c * exp(input);
        }
    private:
        const double m_c;
    };
};

#endif
