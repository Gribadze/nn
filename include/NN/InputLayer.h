#ifndef NN_INPUT_LAYER_H
#define NN_INPUT_LAYER_H

#include <NN/Layer.h>

class InputLayer : public Layer {
public:
    explicit InputLayer(unsigned long size);

    void print() const override;
};

#endif

