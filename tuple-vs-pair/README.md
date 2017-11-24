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



