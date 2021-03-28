//
//  main.cpp
//  Xcode_12
//
//  Created by Randle.Helmslay on 2021/3/27.
//

#include <iostream>

#include <vector>
#include "RH_common.hpp"
#include "RH_neuron.hpp"

using namespace std;
int main(int argc, const char * argv[]) {
    // insert code here...
   
    vector<float> in (10, 9.32);
    vector<float> w  (10, 0.33333);
    HiddenCell<float,float,float> c( in, w, -31 );
    
    c.setActFunc(kNeuronActFunc_sigmold);
    
    cout<<c.run()<<endl;
    
    return 0;
}
