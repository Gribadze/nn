#ifndef NN_OUTPUT_LAYER_H
#define NN_OUTPUT_LAYER_H

#include <NN/Layer.h>

class OutputLayer: public Layer {
public:
    OutputLayer(int size);
    void print() const;
};

#endif

