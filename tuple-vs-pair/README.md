# Tuple vs pair (across stadards)

## Assignment


This is OK in C++11, C++14, and C++17
```
std::pair<int, int> quot_and_rem(int a, int b)
{ return { a / b, a % b }; } // OK in C++11, C++14, and C++17
```

This causes compilation ERROR in C++11 and C++14 but compiles in C++17. WHY???
```
std::tuple<int, int> quot_and_rem(int a, int b)
{ return { a / b, a % b }; } // ERROR in C++11 and C++14, OK in C++17. WHY???

```

Compilation output (using g++ 5.1.0):
```
>>> g++ prog.cc -std=c++11 
prog.cc: In function 'std::tuple<int, int> quot_and_rem(int, int)':
prog.cc:5:25: error: converting to 'std::tuple<int, int>' from initializer list would use explicit constructor 'constexpr std::tuple<_T1, _T2>::tuple(_U1&&, _U2&&) [with _U1 = int; _U2 = int; <template-parameter-2-3> = void; _T1 = int; _T2 = int]'
 { return { a / b, a % b }; }
                         ^
```

