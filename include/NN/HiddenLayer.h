#ifndef NN_HIDDEN_LAYER_H
#define NN_HIDDEN_LAYER_H

#include <NN/Layer.h>

class HiddenLayer : public Layer {
public:
    explicit HiddenLayer(unsigned long size);

    void print() const override;
};

#endif

