#ifndef _RH_NEURON_H
#define _RH_NEURON_H

#include "RH_common.hpp"

using namespace std;

template<class D>
class InputCell {
private:
    D     data_in;
    D     out;
    float coe;
public:
    InputCell        ( D     data , float coe = 1.0 );
    ~InputCell<D>    ( void       );
    
    void  setAmplify ( float coe  );
    
    void  input      ( D     data );
    D     run        ( void       );
    D     output     ( void       );
};


template<class D, class W, class B>
class HiddenCell {
private:
    vector<D>    data_in;
    vector<W>    weight;
    B            bias;
    D            out;
public:
    HiddenCell       ( vector<D>& data, vector<W>& weight, B bias );
    ~HiddenCell      ( void           );
    
    void  setWeight  ( W          weight , int index );
    void  setWeight  ( vector<W>& weight );
    void  setBias    ( B          bias   );
    
    void  input      ( vector<D>& data );
    D     run        ( void   );
    D     output     ( void   );
};




#endif


