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
    String(const String & str) = delete; // not a part of this task - make sure none calls this
    String operator=(const String & str) = delete; // not a part of this task - make sure none calls this
    friend std::ostream & operator<<(std::ostream & os, const String & str);
    ~String();
    void swap(String & str);
};

#endif //SSO_H
