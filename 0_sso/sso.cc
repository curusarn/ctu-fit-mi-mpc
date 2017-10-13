
#include "sso.h"
#include <cstring>

bool String::get_sso() const {
    return sso_;
}

String::String() : sso_(false) {
    data_.ptr_ = nullptr;
}

String::String(const char * str) {
    uint len = std::strlen(str);
    if (len < 8) {
        sso_ = true;
        std::strcpy(data_.str_, str);
    } else {
        sso_ = false;
        data_.ptr_ = new char[len];
        std::strcpy(data_.ptr_, str);
    }
}

String::~String() {
    if (!get_sso()) delete[] data_.ptr_;
}

std::ostream & operator<<(std::ostream & os, const String & str) {
    if (str.get_sso()) 
        os << str.data_.str_ << "<stored in buffer>";
    else if (str.data_.ptr_)
        os << str.data_.ptr_ << "<dynamicly allocated>";

    return os;
}
