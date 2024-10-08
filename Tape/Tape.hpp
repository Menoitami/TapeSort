#pragma once

#include <list>
#include <initializer_list>
#include <fstream>
#include <stdexcept>
#include <iostream>
#include <concepts>



namespace tape{

template <std::totally_ordered T>
class Tape {
public:
    Tape();                      
    
    T read();                 
    void write(T el);         
    void move(const int& i);
    void print();    //delete

private:
    std::list<T> data;                     
    std::list<T>::iterator iter;  

    int read_delay_ms;
    int write_delay_ms;
    int rewind_delay_ms;
    int move_delay_ms;         
};


template <std::totally_ordered T>
Tape<T>::Tape() {
    data = {};                       
    iter = data.end();             
}


template <std::totally_ordered T>
T Tape<T>::read() {
   
    return *iter;                
    
}

template <std::totally_ordered T>
void Tape<T>::write(T el) {

        *iter = el;      
   
    
}

template <std::totally_ordered T>
void Tape<T>::move(const int& i) {

    if (i == 0) return;

    if (i>0){
        for (int _=0; _<i; _++){

            if (iter!= --data.end())++iter;
            else{
                data.emplace_back(0);
                ++iter;
            }
        }
    }
    else{
        for (int _=0; _<-i; _++){

            if (iter!= data.begin()) --iter;
            else{
                data.emplace_front(0);
                --iter;
            }
        }
    }

}

template <std::totally_ordered T>
void Tape<T>::print(){

    for (auto dat : data){
        std::cout<<dat<<" ";

    }
}
} //namespace 