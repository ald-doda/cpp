#include <iostream>
#include "red.h"

Red::Red(int n){
    this->n = n;
    this-> data = new int[n];
    this-> pop = 0;
}
Red::Red(const Red& drugi){
    this->n = drugi.n;
    this->data = new int[n];
    for(int i=0; i<n; i++){
        this->data[i] = drugi.data[i];
    }
    this->pop = drugi.pop;
}
Red::~Red(){
    delete[] data;
}
void Red::push(int x){
    if(!is_full()){
        data[pop] = x;
        pop++;
    }
}
int Red::front(){
    if(!is_empty()){
        return data[0];
    }
    return -1; 
}
bool Red::is_full(){
    return pop == n;

}
void Red::remove(){
    if(!is_empty()){
        for(int i=0; i<pop-1; i++){
            data[i] = data[i+1];
        }
        pop--;
    }

}
int Red::get_popunjenost(){
    return pop;
}

bool Red::is_empty(){
    return pop == 0;
}