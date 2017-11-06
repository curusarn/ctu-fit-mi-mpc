#ifndef SSO_H
#define SSO_H
#include <iostream>
#include <iosfwd>
#define SSO_MASK 0x01

class String {

    class Impl;
    class Data;
    Impl *pimpl_;

public:
    String(); 
    String(const char * str);
    String(const String & str);
    String & operator=(const String & str);
    friend std::ostream & operator<<(std::ostream & os, const String & str);
    ~String();
    void swap(String & str);
    const char * c_str() const;
};

#endif //SSO_H
