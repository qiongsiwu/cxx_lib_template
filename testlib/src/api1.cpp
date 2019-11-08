#include "api1.h"
#include <iostream> 

int func1(int a, int b) {
    std::cout << "calling func1 in api1\n";
    return a + b; 
}
