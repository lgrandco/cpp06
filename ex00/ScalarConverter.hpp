#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include "colors.hpp"
#include <iostream>

class ScalarConverter {
private:
    ScalarConverter();
    ~ScalarConverter() {};
    ScalarConverter(ScalarConverter&);
    ScalarConverter& operator=(const ScalarConverter&);

public:
    void static convert(const std::string&);
};

#endif
