#include <memory>
#include <iostream>
#include <string.h>

class String {
public:
  String() : data_(std::unique_ptr<char[]>{}) {}                 // default constructor
  String(const String &rhs) : data_(std::unique_ptr<char[]>{}) { // copy constructor
    if (rhs.data_) {
      //data_ = new char[strlen(rhs.data_) + 1];
      data_ = std::make_unique<char[]>(strlen(rhs.data_.get()) + 1);
      strcpy(data_.get(), rhs.data_.get());
    }
  }
  String(String &&rhs) noexcept = default; // move constructor
  String &operator=(const String &rhs) { // copy assignment operator
    String temp(rhs);
    swap(temp);
    return *this;
  }
  String &operator=(String &&rhs) noexcept = default; // move assignment operator
  String(const char *arg) { // converting constructor
    data_ = std::make_unique<char[]>(strlen(arg) + 1);
    strcpy(data_.get(), arg);
  }
  ~String() = default; // destructor
  void swap(String &rhs) noexcept { std::swap(data_, rhs.data_); }
  friend std::ostream &operator<<(std::ostream &str, const String &arg) {
    if (arg.data_)
      str << arg.data_.get();

     // for (int i = 0; arg.data_[i]; i++ )
     //   str.put(arg.data_[i]);
    return str;
  }

private:
  std::unique_ptr<char[]> data_; // String data: pointer to null-terminated byte string
};
