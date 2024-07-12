#include "Serializer.hpp"

int main()
{
    Serializer::Data originalData;
    originalData.i = 42;
    originalData.str = "test";

    uintptr_t serialized = Serializer::serialize(&originalData);

    Serializer::Data* deserializedData = Serializer::deserialize(serialized);

    std::cout << "Original Data: " << originalData.i << ", " << originalData.str << std::endl;
    std::cout << "Serialized : " << serialized << std::endl;
    std::cout << "Deserialized Data: " << deserializedData->i << ", " << originalData.str << std::endl;

    return 0;
}
