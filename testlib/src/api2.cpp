#include "api2.h"
#include <iostream> 

API2Class::API2Class() {
    std::cout << "ctor of API2Class\n"; 
}

int func2(int c) {
    return c * 2; 
}
