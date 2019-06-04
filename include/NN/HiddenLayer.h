#ifndef NN_HIDDEN_LAYER_H
#define NN_HIDDEN_LAYER_H

#include <NN/Layer.h>

class HiddenLayer: public Layer {
public:
    HiddenLayer(int size);
    void print() const;
};
#endif

