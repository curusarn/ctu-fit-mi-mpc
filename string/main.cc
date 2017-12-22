
#include <iostream>
#include "string.h"

String move_test(String &&rhs) {
    return rhs;
}

int main() {
    String s0; 
    std::cout << s0 << std::endl; 
    auto s1 = String();
    std::cout << s1 << std::endl; 
    String s2;
    auto s3 = String("some-string");
    std::cout << s3 << std::endl; 
    s2 = s3; 
    std::cout << s2 << std::endl; 
    auto s4 = std::move(s3);
    std::cout << s4 << std::endl; 
    String s5;
    s5 = String("some-other-string");
    std::cout << s5 << std::endl; 
    String s6;
    s6 = std::move(s5);
    std::cout << s6 << std::endl; 
    return 0;
}
