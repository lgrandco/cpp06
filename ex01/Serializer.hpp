#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP
#include "Data.hpp"
#include "colors.hpp"
#include <stdint.h>

class Serializer {
private:
    Serializer();
    ~Serializer();
    Serializer(Serializer&);
    Serializer& operator=(Serializer&);

public:
    static uintptr_t serialize(Data* ptr);
    static Data* deserialize(uintptr_t raw);
};

#endif
