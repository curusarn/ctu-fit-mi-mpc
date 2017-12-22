#include <iostream>

class Lambda {
public:
    Lambda(int & a, int b) : a_(a), b_(b) {}
    void operator()(int param) {
        a_ += b_ + param;
    }

  private:
    int & a_; 
    const int b_; 
};

int main() {
  int a = 0, b = 1, c = 2;
  auto lambda = Lambda(a, b);
  lambda(c);
  std::cout << a << std::endl; // prints out "3"
}

//int main() {
//  int a = 0, b = 1, c = 2;
//  auto lambda = [&a, b](int param) { a += b + param; };
//  lambda(c);
//  std::cout << a << std::endl; // prints out "3"
//}
