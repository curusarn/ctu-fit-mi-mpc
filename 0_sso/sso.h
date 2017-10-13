
#include <iostream>

union StringData {
    char * ptr;
    char str[7];
};

class String {
    StringData data_;
    bool sso_; 

    bool get_sso() const;

public:
    String(); 
    String(const char * str);
    String(const String & str) = delete;
    String operator=(const String & str) = delete;
    friend std::ostream & operator<<(std::ostream & os, const String & str);
    ~String();
};
