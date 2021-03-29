#ifndef _RH_NEURON_H
#define _RH_NEURON_H

#ifndef __cplusplus
#error "C++ compiler is needed."
#endif

#include "RH_common.hpp"

typedef enum{
    kNeuronActFunc_step      ,
    kNeuronActFunc_sigmold   ,
    kNeuronActFunc_tanh      ,
    kNeuronActFunc_ReLU      ,
    kNeuronActFunc_softmax   ,
    kNUM_NeuronActFunc

}E_NeuronActFunc_t;

template<class D, class W, class B>
static D  actFunc_step    ( std::vector<D>& x, std::vector<W>& w, B b ){
    D result = 0;

    typename std::vector<D>::iterator iter_x = x.begin();
    typename std::vector<W>::iterator iter_w = w.begin();
    for( ; iter_x != x.end(); iter_x++ ){
        result += (*iter_w)*(*iter_x);
    }
    result += b;
    
    return (result>0) ;
}

template<class D, class W, class B>
static D  actFunc_sigmold ( std::vector<D>& x, std::vector<W>& w, B b ){
    D result = 0;

    typename std::vector<D>::iterator iter_x = x.begin();
    typename std::vector<W>::iterator iter_w = w.begin();
    for( ; iter_x != x.end(); iter_x++ ){
        result += (*iter_w)*(*iter_x);
    }
    result += b;
    
    return (D)((1.0)/(1.0+exp(-result))) ;
}

/*==============================================================================================
 > Data Structure: Input Cell
==============================================================================================*/
template<class D,class W>
class InputCell {
private:
    D     data_in;
    D     out;
    W     coe;
public:
    InputCell<D,W>     ( void       );
    InputCell<D,W>     ( D     data , W  coe );
    ~InputCell<D,W>    ( void       );
    
    void  gain         ( W     coe  );
    
    void  input        ( D     data );
    D     run          ( void       );
    D     output       ( void       );
};

/*==============================================================================================
 > Data Structure: Hidden Cell
==============================================================================================*/
template<class D, class W, class B>
class HiddenCell {
private:
    std::vector<D>    data_in;
    std::vector<W>    weight;
    B            bias;
    D            out;
    D            (*aFunc)( std::vector<D>& x, std::vector<W>& w, B b );
public:
    HiddenCell       ( void                 ){}
    HiddenCell       ( std::vector<D>& data, std::vector<W>& weight, B bias );
    ~HiddenCell      ( void                 ){}
    
    void  setWeight  ( W               weight , int index );
    void  setWeight  ( std::vector<W>& weight );
    void  setBias    ( B               bias   );
    
    void  setActFunc ( D (*aFunc)( std::vector<D>& x, std::vector<W>& w, B b ) );
    void  setActFunc ( E_NeuronActFunc_t func      );
    
    void  input      ( std::vector<D>& data );
    D     run        ( void   );
    D     output     ( void   );
};

/*==============================================================================================
 > Data Structure: Output Cell
==============================================================================================*/
template<class D, class W, class B>
class OutputCell {
private:
    std::vector<D>    data_in;
    std::vector<W>    weight;
    B            bias;
    D            out;
public:
    OutputCell       ( std::vector<D>& data, std:: vector<W>& weight, B bias );
    ~OutputCell      ( void                );
    
    void  setWeight  ( W               weight , int index );
    void  setWeight  ( std::vector<W>& weight );
    void  setBias    ( B               bias   );
    
    void  input      ( std::vector<D>& data );
    D     run        ( void   );
    D     output     ( void   );
};


#include "RH_neuron.inl.hpp"

#endif


