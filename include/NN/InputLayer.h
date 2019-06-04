#ifndef NN_INPUT_LAYER_H
#define NN_INPUT_LAYER_H

#include <vector>
#include <NN/Layer.h>

class InputLayer: public Layer {
public:
    InputLayer(int size);
    void print() const;
};
#endif

