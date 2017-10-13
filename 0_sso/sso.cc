
#include "sso.h"
#include <cstring>

bool String::get_sso() {
    return sso_;
}

String::String(const char * str) {
    sso_ = false;
    data_ = new char[std::strlen(str)];
    std::strcpy(data_, str);
}

String::~String() {
    delete[] data_;
}

std::ostream & operator<<(std::ostream & os, const String & str) {
    if (str.data_) os << str.data_;
    return os;
}
