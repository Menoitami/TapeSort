#pragma once

#include <list>
#include <initializer_list>
#include <fstream>
#include <stdexcept>
#include <iostream>
#include <concepts>





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
