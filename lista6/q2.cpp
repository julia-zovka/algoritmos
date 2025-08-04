#include <vector>
#include <iostream>
#include <climits>
using namespace std;


int main(){
    int l_original, l_new, cost_in, cost_rem, cost_mod, cost;
    cin>> l_original>> l_new>>cost_in>>cost_rem>> cost_mod;

    string ogP, newP;
    cin>>ogP>>newP;
    //capital and lower are different

    cost=0;
    //checar se a p
    for(int i=0;i<l_original;i++){
       
        //nova menor 
        if(i<l_new){// se ainda [e um indice validona nova, pode ter removido letras
            if(ogP[i]!=newP[i]){//mudou letra
                cost+=cost_mod;
            }
        }
        
        //o indice da antiga extrapolou a da pavra nova == inserting letras
        else{
            cost+=cost_in;
        }
    }
    if(l_original>l_new){cost+=cost_rem(l_new-l_original)}

}   