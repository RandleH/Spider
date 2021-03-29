#ifndef _RH_LAYER_INL_HPP
#define _RH_LAYER_INL_HPP

#include "RH_common.hpp"

template<typename D, typename W> inline
InputLayer<D,W>::InputLayer( void ):_in(),_g(),_cell(),_out(){
#ifdef RH_DEBUG
    this->check();
#endif
}

template<typename D, typename W> inline
InputLayer<D,W>::InputLayer( const std::vector<D>& _in ):_g( _in.size(), 1 ),_cell(_in.size()),_out( _in.size(), 0 ){
#ifdef RH_DEBUG
    ASSERT( !_in.empty() );
#endif
    this->_in.assign( _in.begin(), _in.end() );
    //...//
#ifdef RH_DEBUG
    this->check();
#endif
}

template<typename D, typename W> inline
InputLayer<D,W>::InputLayer( const std::vector<D>& _in, const std::vector<W>& _g ){
#ifdef RH_DEBUG
    ASSERT( _in.size() == _g.size() );
#endif
    this->_in.assign( _in.begin(), _in.end() );
    this->_g.assign( _g.begin(), _g.end() );
    
    this->_cell.resize( _in.size() );
    
    this->assign();
    
#ifdef RH_DEBUG
    this->check();
#endif
}

template<typename D, typename W> inline
E_Status_t InputLayer<D,W>::check  ( void ){
#ifdef RH_DEBUG
    ASSERT( _cell.size()==_g.size() && _cell.size()==_in.size() && _cell.size()==_out.size() );
#endif
    return kStatus_Success;
}

template<typename D, typename W> inline
E_Status_t InputLayer<D,W>::assign  ( void ){
    typename std::vector<D              >::iterator iter_in   = this->_in.begin();
    typename std::vector<W              >::iterator iter_g    = this->_g.begin();
    typename std::vector<InputCell<D,W> >::iterator iter_cell = this->_cell.begin();
    
    for( ; iter_in < this->_in.end(); iter_in++, iter_g++, iter_cell++ ){
        (*iter_cell).gain   ( *iter_g  );
        (*iter_cell).input  ( *iter_in );
    }
    return kStatus_Success;
}


template<typename D, typename W> inline
size_t InputLayer<D,W>::size       ( void ){
#ifdef RH_DEBUG
    this->check();
#endif
    return _cell.size();
}

template<typename D, typename W> inline
size_t InputLayer<D,W>::length     ( void ){
    return this->size();
}

template<typename D, typename W> inline
void   InputLayer<D,W>::size       ( size_t size   ){
    this->_in.resize(size);
    this->_g.resize(size);
    this->_cell.resize(size);
    this->_out.resize(size);
}

template<typename D, typename W> inline
void   InputLayer<D,W>::length     ( size_t size   ){
    this->size(size);
}

template<typename D, typename W> inline
void   InputLayer<D,W>::gain       ( const std::vector<W> g ){
#ifdef RH_DEBUG
    ASSERT( g.size()==this->_cell.size() );
    this->check();
#endif
    this->_g.assign( g.begin(), g.end() );
    
    this->assign();
}

template<typename D, typename W> inline
void   InputLayer<D,W>::gain       ( const W              g , size_t index ){
#ifdef RH_DEBUG
    ASSERT( this->_cell.size() > index );
#endif
    this->_g[index] = g;
    this->_cell[index].gain( g );
}

template<typename D, typename W> inline
const std::vector<W>& InputLayer<D,W>::gain    ( void                   ){
#ifdef RH_DEBUG
    this->check();
#endif
    return this->_g;
}




#endif

