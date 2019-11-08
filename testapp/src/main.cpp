#include <iostream> 

#include "include/api1.h"
#include "include/api2.h"

int main() {
    std::cout << "hello world\n"; 
    std::cout << func1(1, 2) << "\n";
    API2Class a;
    std::cout << func2(3) << "\n";
}
