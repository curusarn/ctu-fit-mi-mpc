
#include "sso.h"
#include <cstring>

bool String::get_sso() {
    return sso_;
}

String::String(const char * str) {
    uint len = std::strlen(str);
    if (len < 8) {
        sso_ = true;
        std::strcpy(data_.str_, str);
    } else {
        sso_ = false;
        data_.ptr_ = new char[];
        std::strcpy(data_, str);
    }
}

String::~String() {
    if (!get_sso()) delete[] data_;
}

std::ostream & operator<<(std::ostream & os, const String & str) {
    if (get_sso()) 
        os << str.data_.str_;
    else if (str.data_)
        os << str.data_.ptr_;

    return os;
}
