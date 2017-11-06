
#include "sso.h"
#include <cstring>


class String::Data {
    // kind of like Union
    // dumb storage class that enables access to overlapping attributes
    // no validity checks are performed
    
    char * data_;

public:
    Data() : data_(nullptr) {};
    char * & ptr() { return data_; };
    char * str() { return (char *)(&data_); };
    const char * ptr() const { return data_; };
    const char * str() const { return (char *)(&data_); };
    bool get_sso() const { return SSO_MASK & str()[7]; };
    void set_sso(bool);
};

void String::Data::set_sso(bool b) {
    if (b) 
        str()[7] |= SSO_MASK;
    else
        str()[7] &= ~(SSO_MASK);
}


class String::Impl {

    Data data_;

public:
    Impl(); 
    Impl(const char * str);
    Impl(const Impl & str);
    Impl & operator=(const Impl & str) = delete;
    // sanity check - String::op= does not use String::Impl::op=
    std::ostream & ostreamFunc_noOperator_iGiveUp(std::ostream & os) const; 
    // is it even possible to do this with operator<< ??
    ~Impl();
    const char * c_str() const;
};

String::Impl::Impl() {
    data_.ptr() = nullptr;
    data_.set_sso(false);
}

String::Impl::Impl(const char * str) {
    uint len = std::strlen(str);
    if (!len) {
        data_.ptr() = nullptr;
        data_.set_sso(false);
    } else if (len < 8) {
        data_.set_sso(true);
        std::strcpy(data_.str(), str);
    } else {
        data_.set_sso(false);
        data_.ptr() = new char[len+1];
        std::strcpy(data_.ptr(), str);
    }
}

String::Impl::Impl(const Impl & str) : Impl(str.c_str()) {} 
String::Impl::~Impl() {
    if (!data_.get_sso()) delete[] data_.ptr();
}
const char * String::Impl::c_str() const {
    if (data_.get_sso()) 
        return data_.str();
    if (data_.ptr())
        return data_.ptr();
    return "";
}

std::ostream & String::Impl::ostreamFunc_noOperator_iGiveUp(std::ostream & os) const {
    // I would use String::Impl::c_str() to simplify this function
    //      but I want to keep the "<special debugging outputs>"
    if (data_.get_sso()) 
        os << data_.str() << "<stored in buffer>";
    else if (data_.ptr())
        os << data_.ptr() << "<dynamically allocated>";
    else
        os << "<empty string>";

    return os;
}


String::String() : pimpl_(new Impl()) {} 
String::String(const char * str) : pimpl_(new Impl(str)) {}
String::String(const String & str) : pimpl_(new Impl(*(str.pimpl_))) {}
String & String::operator=(const String & str) {
    String tmp(str);
    swap(tmp);
    return *this;
}
std::ostream & operator<<(std::ostream & os, const String & str) {
    return str.pimpl_->ostreamFunc_noOperator_iGiveUp(os);
}
String::~String() { delete pimpl_; }
void String::swap(String & str) { std::swap(pimpl_, str.pimpl_); }
const char * String::c_str() const { return pimpl_->c_str(); }

