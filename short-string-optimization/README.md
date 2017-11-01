# Small string optimization

## Introduction
This solution implements SSO (small string optimization) where single pointer is used to store string (if it is short enough) or pointer pointing to allocated string (if it is too long) and flag that tells us if SSO is used.

It is important that 4 least significant bits in any pointer on x86 platform are always zero - I'm using one of them to store boolean value of "sso_flag".

In order to store "sso_flag" in the pointer itself I have defined `StringData` class that does the dirty work and `String` class that does regular string manipulation. 

### class String
This is the main string class. It does all the allocations, deallocations, copying and contains all the logic related to string manipulation itself.
It contains `StringData` class that holds the data.

### class StringData
This class takes care of the dirty work. It does all the casting and bitwise operations.
However it does not contain any advanced logic. The sole purpose of this class is to provide comfortable interface for data manipulation. 



