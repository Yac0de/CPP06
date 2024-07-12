#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>

#if !defined(UINTPTR_MAX)
#if defined(_WIN64) || defined(_LP64)
typedef unsigned long long uintptr_t;
#else
typedef unsigned long uintptr_t;
#endif
#endif

class Serializer
{
private:
    Serializer();
    Serializer(const Serializer &src);
    ~Serializer();

    Serializer& operator=(const Serializer &rhs);
public:
    struct Data
    {
        std::string str;
        int i;
    };

    static uintptr_t serialize(Data* ptr);
    static Data* deserialize(uintptr_t raw);

};

#endif