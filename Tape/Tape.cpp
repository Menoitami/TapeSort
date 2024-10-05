#include <Tape.h>

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