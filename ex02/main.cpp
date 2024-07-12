#include "identify.hpp"

int main()
{
    Base* b = generate();

    identify(b);
    identify(*b);

    delete b;
    return 0;
}
