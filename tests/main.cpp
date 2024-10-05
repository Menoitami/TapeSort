#include <iostream>
#include <cassert> // Подключаем заголовочный файл для assert

void testEquality() {
    int a = 5;
    int b = 5;
    assert(a == b);
}

void testInequality() {
    int a = 5;
    int c = 10;
    assert(c != a);
}

void testSum() {
    int a = 5;
    int b = 5;
    assert(a + b ==10);
}

int main() {

    testEquality();
    testInequality();
    testSum();



    return 0;
}
