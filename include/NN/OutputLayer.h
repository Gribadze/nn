#ifndef NN_OUTPUT_LAYER_H
#define NN_OUTPUT_LAYER_H

#include <NN/Layer.h>

class OutputLayer : public Layer {
public:
    explicit OutputLayer(unsigned long size);

    void print() const override;
};

#endif

