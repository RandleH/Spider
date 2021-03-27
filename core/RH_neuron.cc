
#include "RH_neuron.hpp"

/*==============================================================================================
 > Data Structure: Input Cell
==============================================================================================*/
template<class D>
InputCell<D>::InputCell        ( D data , float coe ){
    this->data_in = data;
    this->coe     = coe;
}

template<class D>
InputCell<D>::~InputCell       ( void   ){
    
}
template<class D>
void InputCell<D>::setAmplify  ( float coe  ){
    this->coe = coe;
}

template<class D>
D    InputCell<D>::run         ( void   ){
    this->out = this->data_in * coe;
    return (this->out);
}

template<class D>
D    InputCell<D>::output      ( void   ){
    return (this->out);
}


/*==============================================================================================
 > Data Structure: Input Cell
==============================================================================================*/
template<class D, class W, class B>
HiddenCell<D,W,B>::HiddenCell( vector<D>& data, vector<W>& weight, B bias ){
    
}



