#ifndef SCALAR_CONVERTER_HPP
#define SCALAR_CONVERTER_HPP

#include <string>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cerrno>
#include <climits>

class ScalarConverter
{
private:
    ScalarConverter();
    ScalarConverter(const ScalarConverter &src);
    ~ScalarConverter();

    ScalarConverter& operator=(const ScalarConverter &rhs);
public:
    static void convert(const std::string& value);
};

#endif