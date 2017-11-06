
#include <iostream>
#include "sso.h"

#define uint unsigned int

int main() {
    std::cout << std::endl << "BASIC_TEST" << std::endl;
    String s1("hello");
    String s2("hello_hello_hello_hello");
    String s3, s4;

    std::cout << s1 << std::endl;
    std::cout << s2 << std::endl;
    std::cout << s3 << std::endl;
    
    std::cout << std::endl << "OPERATOR=_TEST" << std::endl;
    s4 = s1;
    std::cout << s4 << std::endl;
    s4 = s2;
    std::cout << s4 << std::endl;
    s4 = s3;
    std::cout << s4 << std::endl;

    std::cout << std::endl << "COPY_CTOR_TEST" << std::endl;
    String s5(s1);
    std::cout << s5 << std::endl;
    String s6(s2);
    std::cout << s6 << std::endl;
    String s7(s3);
    std::cout << s7 << std::endl;

    std::cout << std::endl << "SWAP_TEST" << std::endl;
    s1.swap(s3);
    std::cout << s1 << std::endl;
    std::cout << s3 << std::endl;

    s6.swap(s7);
    std::cout << s6 << std::endl;
    std::cout << s7 << std::endl;
}
