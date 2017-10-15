#include <iostream>
#define SSO_MASK 0x01

class StringData {
    // kind of like Union
    // dumb storage class that enables access to overlapping attributes
    // no validity checks are performed
    
    char * data_;

public:
    StringData() : data_(nullptr) {};
    char * & ptr() { return data_; };
    char * str() { return (char *)(&data_); };
    const char * ptr() const { return data_; };
    const char * str() const { return (char *)(&data_); };
    bool get_sso() const { return SSO_MASK & str()[7]; };
    void set_sso(bool);
};


class String {
    StringData data_;

    bool get_sso() const { return data_.get_sso(); };
    void set_sso(bool b) { data_.set_sso(b); };

public:
    String(); 
    String(const char * str);
    String(const String & str) = delete; // not a part of this task - make sure none calls this
    String operator=(const String & str) = delete; // not a part of this task - make sure none calls this
    friend std::ostream & operator<<(std::ostream & os, const String & str);
    ~String();
};
