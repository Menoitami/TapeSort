#include <iostream>
#include "Tape.h"




int main(){

    std::cout<<"the program has started\n";

    Tape<int> tape;
    tape.move(2);
    tape.write(3);
    tape.move(-5);
    tape.write(1);


    tape.print();
    return 0;
}