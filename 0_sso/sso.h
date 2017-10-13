
#include <iostream>

union StringData {
    char * ptr_;
    char str_[7];
};

class String {
    StringData data_;
    bool sso_; 

    bool get_sso();

public:
    String() : data_.ptr_(nullptr), sso_(false) {}
    String(const char * str);
    String(const String & str) = delete;
    String operator=(const String & str) = delete;
    friend std::ostream & operator<<(std::ostream & os, const String & str);
    ~String();
};
