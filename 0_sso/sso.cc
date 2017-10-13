
#include "sso.h"
#include <cstring>

bool String::get_sso() const {
    return sso_;
}

String::String() : sso_(false) {
    data_.ptr = nullptr;
}

String::String(const char * str) {
    uint len = std::strlen(str);
    if (len < 8) {
        sso_ = true;
        std::strcpy(data_.str, str);
    } else {
        sso_ = false;
        data_.ptr = new char[len];
        std::strcpy(data_.ptr, str);
    }
}

String::~String() {
    if (!get_sso()) delete[] data_.ptr;
}

std::ostream & operator<<(std::ostream & os, const String & str) {
    if (str.get_sso()) 
        os << str.data_.str << "<stored in buffer>";
    else if (str.data_.ptr)
        os << str.data_.ptr << "<dynamicly allocated>";

    return os;
}
