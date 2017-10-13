
#include "sso.h"
#include <cstring>


void StringData::set_sso(bool b) {
    if (b) 
        str()[7] |= SSO_MASK;
    else
        str()[7] &= ~(SSO_MASK);
}



String::String() {
    data_.ptr() = nullptr;
    set_sso(false);
}

String::String(const char * str) {
    uint len = std::strlen(str);
    if (len < 8) {
        set_sso(true);
        std::strcpy(data_.str(), str);
    } else {
        set_sso(false);
        data_.ptr() = new char[len+1];
        std::strcpy(data_.ptr(), str);
    }
}

String::~String() {
    if (!get_sso()) delete[] data_.ptr();
}

std::ostream & operator<<(std::ostream & os, const String & str) {
    if (str.get_sso()) 
        os << str.data_.str() << "<stored in buffer>";
    else if (str.data_.ptr())
        os << str.data_.ptr() << "<dynamically allocated>";
    else
        os << "<empty string>";

    return os;
}
