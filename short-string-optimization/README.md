# Short string optimization

## Introduction
This solution implements SSO (short string optimization) where single pointer is used to store the string itself (if it is short enough) or pointer pointing to allocated string (if it is too long) and flag that tells us if SSO is used.

It is important that 4 least significant bits in any pointer on x86 platform are always zero - I'm using one of them to store boolean value of "sso_flag".

In order to store "sso_flag" in the pointer itself I have defined `String::Data` class that does the dirty work and `String::Impl` class that does regular string manipulation.

I'm using [PIMPL idiom](http://en.cppreference.com/w/cpp/language/pimpl) for my `String` class.

### class String
This is the main string class that serves as an public interface. It contains two private subclasses. `String::Impl` class that contains implementation and `String::Data` class that serves as a "smarter" [union](http://en.cppreference.com/w/cpp/language/union). `String` class contains pointer to `String::Impl`. `String::Impl` contains `String::Data` class that holds the actual data. 

### class String::Impl
This class does all the allocations, deallocations, copying and contains all the logic related to string manipulation itself.
It contains `String::Data` class that holds the data.

### class String::Data
This class takes care of the dirty work. It does all the casting and bitwise operations.
However it does not contain any advanced logic. The sole purpose of this class is to provide comfortable interface for data manipulation. 



