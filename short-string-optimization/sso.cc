
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
    Impl(const Impl & str) = delete; // not a part of this task - make sure none calls this
    Impl operator=(const Impl & str) = delete; // not a part of this task - make sure none calls this
    std::ostream & ostreamFunc_noOperator_iGiveUp(std::ostream & os) const; 
    // is it even possible to do this with operator<< ??
    ~Impl();
};

String::Impl::Impl() {
    data_.ptr() = nullptr;
    data_.set_sso(false);
}

String::Impl::Impl(const char * str) {
    uint len = std::strlen(str);
    if (len < 8) {
        data_.set_sso(true);
        std::strcpy(data_.str(), str);
    } else {
        data_.set_sso(false);
        data_.ptr() = new char[len+1];
        std::strcpy(data_.ptr(), str);
    }
}

String::Impl::~Impl() {
    if (!data_.get_sso()) delete[] data_.ptr();
}

std::ostream & String::Impl::ostreamFunc_noOperator_iGiveUp(std::ostream & os) const {
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
std::ostream & operator<<(std::ostream & os, const String & str) {
    return str.pimpl_->ostreamFunc_noOperator_iGiveUp(os);
}
String::~String() { delete pimpl_; }
void String::swap(String & str) { std::swap(pimpl_, str.pimpl_); }
