#include "ScalarConverter.hpp"

int main(int argc, char const *argv[])
{
    if(argc != 2)
    {
        std::cerr   << "Error: Invalid parameters" << std::endl
                    << "Usage: " << argv[0] << " [value]" << std::endl;
        return 1;
    }
    ScalarConverter::convert(argv[1]);
    return 0;
}
