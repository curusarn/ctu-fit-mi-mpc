
#include <iostream>

class String {
    char * data_;
    bool sso_; 

    bool get_sso();

public:
    String() : data_(nullptr), sso_(false) {}
    String(const char * str);
    String(const String & str) = delete;
    String operator=(const String & str) = delete;
    friend std::ostream & operator<<(std::ostream & os, const String & str);
    ~String();
};
