

#ifndef _RH_NEURON_INL_HPP
#define _RH_NEURON_INL_HPP
#include "RH_neuron.hpp"

/*==============================================================================================
 > Data Structure: Input Cell
==============================================================================================*/
template<typename D, typename W>  inline
InputCell<D,W>::InputCell          ( void ){
#ifdef RH_DEBUG
#endif
}

template<typename D, typename W>  inline
InputCell<D,W>::InputCell          ( D     data , W  coe ){
#ifdef RH_DEBUG
#endif
    this->data_in = data;
    this->coe     = coe;
}

template<typename D, typename W>  inline
InputCell<D,W>::~InputCell         ( void       ){
#ifdef RH_DEBUG
#endif
}


template<typename D, typename W>  inline
void  InputCell<D,W>::gain         ( W     coe  ){
#ifdef RH_DEBUG
#endif
    this->coe = coe;
}


template<typename D, typename W>  inline
void  InputCell<D,W>::input        ( D     data ){
#ifdef RH_DEBUG
#endif
    this->data_in = data;
}

template<typename D, typename W>  inline
D     InputCell<D,W>::run          ( void       ){
#ifdef RH_DEBUG
#endif
    this->out = this->data_in * coe;
    return (this->out);
}

template<typename D, typename W>  inline
D     InputCell<D,W>::output       ( void       ){
#ifdef RH_DEBUG
#endif
    return (this->out);
}



/*==============================================================================================
 > Data Structure: Hidden Cell
==============================================================================================*/
template<typename D, typename W, typename B>  inline
HiddenCell<D,W,B>::HiddenCell       ( std::vector<D>& data, std::vector<W>& weight, B bias ){
    this->data_in.assign( data.begin(), data.end() );
    this->weight.assign( weight.begin(), weight.end() );
    this->bias = bias;
}

template<typename D, typename W, typename B>  inline
void  HiddenCell<D,W,B>::setWeight  ( W               weight , int index ){
    this->weight[ index ] = weight;
}

template<typename D, typename W, typename B>  inline
void  HiddenCell<D,W,B>::setWeight  ( std::vector<W>& weight ){
    this->weight.assign( weight.begin(), weight.end() );
}

template<typename D, typename W, typename B>  inline
void  HiddenCell<D,W,B>::setBias    ( B          bias   ){
    this->bias = bias;
}

template<typename D, typename W, typename B>  inline
void  HiddenCell<D,W,B>::setActFunc ( D (*aFunc)( std::vector<D>& x, std::vector<W>& w, B b ) ){
#ifdef RH_DEBUG
    ASSERT( aFunc );
#endif
    this->aFunc = aFunc;
}

template<typename D, typename W, typename B>  inline
void  HiddenCell<D,W,B>::setActFunc ( E_NeuronActFunc_t func      ){
#ifdef RH_DEBUG
    ASSERT( func < kNUM_NeuronActFunc );
#endif
    switch (func) {
        case kNeuronActFunc_step:
            this->aFunc = actFunc_step;
            break;
        case kNeuronActFunc_sigmold:
            this->aFunc = actFunc_sigmold;
            break;
        default:
            while(1);
    }
    
}

template<typename D, typename W, typename B>  inline
void  HiddenCell<D,W,B>::input      ( std::vector<D>& data ){
#ifdef RH_DEBUG

#endif
    this->data_in.assign( data.begin(), data.end() );
}

template<typename D, typename W, typename B>  inline
D     HiddenCell<D,W,B>::run        ( void   ){
#ifdef RH_DEBUG
    ASSERT( this->data_in.size() == this->weight.size() );
    ASSERT( this->aFunc );
#endif
    this->out = (*(this->aFunc))( this->data_in, this->weight, this->bias );
    return this->out;
}

template<typename D, typename W, typename B>  inline
D     HiddenCell<D,W,B>::output     ( void   ){
    return this->out;
}





#endif

