#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter &src) { *this = src; }
ScalarConverter::~ScalarConverter() {}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter &rhs) { (void)rhs; return *this; }

void ScalarConverter::convert(const std::string& value)
{
    char c;
    int i;
    float f;
    double d;

    std::string specialValuesFloat[3] = { "nanf", "+inff", "-inff" };
    bool isSpecialValuesFloat = false;
    for (int j = 0; j < 3; ++j)
    {
        if (specialValuesFloat[j] == value)
        {
            isSpecialValuesFloat = true;
            break;
        }
    }
    std::string specialValuesDouble[3] = { "nan", "+inf", "-inf" };
    bool isSpecialValuesDouble = false;
    for (int j = 0; j < 3; ++j)
    {
        if (specialValuesDouble[j] == value)
        {
            isSpecialValuesDouble = true;
            break;
        }
    }

    if (isSpecialValuesFloat || isSpecialValuesDouble)
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: " << value << (isSpecialValuesDouble ? "f" : "") << std::endl;
        std::cout << "double: " << (isSpecialValuesFloat ? value.substr(0, value.size() - 1) : value) << std::endl;
        return;
    }

    if (value.length() == 1 && std::isprint(value[0]) && !std::isdigit(value[0]))
    {
        c = value[0];
        std::cout << "char: '" << c << "'" << std::endl;
        std::cout << "int: " << static_cast<int>(c) << std::endl;
        std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
        std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
        return;
    }

    std::cout << "char: impossible" << std::endl;

    char* end;
    errno = 0;
    long l = std::strtol(value.c_str(), &end, 10);
    if (errno == ERANGE || *end != '\0' || l < INT_MIN || l > INT_MAX)
        std::cout << "int: impossible" << std::endl;
    else
    {
        i = static_cast<int>(l);
        std::cout << "int: " << i << std::endl;
    }

    errno = 0;
    f = std::strtof(value.c_str(), &end);
    if (errno == ERANGE || *end != '\0')
        std::cout << "float: impossible" << std::endl;
    else
    {
        if (static_cast<int>(f) == f)
            std::cout << "float: " << f << ".0f" << std::endl;
        else
            std::cout << "float: " << f << "f" << std::endl;
    }

    errno = 0;
    d = std::strtod(value.c_str(), &end);
    if (errno == ERANGE || *end != '\0')
        std::cout << "double: impossible" << std::endl;
    else
    {
        if (static_cast<int>(d) == d)
            std::cout << "double: " << d << ".0" << std::endl;
        else
            std::cout << "double: " << d << std::endl;
    }
}
