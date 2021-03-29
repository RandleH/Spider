#ifndef _RH_LAYER_HPP
#define _RH_LAYER_HPP

#include "RH_common.hpp"
#include "RH_neuron.hpp"

template<typename D, typename W>
class InputLayer {
private:
    std::vector<D>                  _in;
    std::vector<W>                  _g;
    std::vector<InputCell<D,W> >    _cell;
    std::vector<D>                  _out;
    E_Status_t check  ( void );//
    E_Status_t assign ( void );//
public:
    InputLayer        ( void );
    InputLayer        ( const std::vector<D>& data_in );
    InputLayer        ( const std::vector<D>& data_in, const std::vector<W>& gains );
    
    size_t size       ( void );
    size_t length     ( void );
    void   size       ( size_t size   );
    void   length     ( size_t length );
    
    void                  gain    ( const std::vector<W> g );
    void                  gain    ( const W              g , size_t index );
    const std::vector<W>& gain    ( void                   );
    
    void                  input   ( const std::vector<D>& data_in );//
    void                  input   ( const D               data_in , size_t index );//
    const std::vector<D>& input   ( void );//
    
    const std::vector<D>& run     ( void );//
    const std::vector<D>& output  ( void );//
    
};




#include "RH_layer.inl.hpp"

#endif
