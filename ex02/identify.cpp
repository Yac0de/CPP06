#include "identify.hpp"
#include "Base.hpp"

Base* generate()
{
    srand(time(NULL));
    int r = rand() % 3;
    switch (r)
    {
		case 0:
			std::cout << "Class A has been generated" << std::endl;
			return new A;
		case 1:
			std::cout << "Class B has been generated" << std::endl;
			return new B;
		case 2:
			std::cout << "Class C has been generated" << std::endl;
			return new C;
	}
    std::cerr << "Impossible to generate a class" << std::endl;
    return NULL;
}

void identify(Base* p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "Class A has been identified" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "Class B has been identified" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "Class C has been identified" << std::endl;
    else
            std::cerr << "Impossible to identify a class" << std::endl;

}

void identify(Base& p)
{
    try
    {
        A& a = dynamic_cast<A&>(p);
        (void)a;
        std::cout << "Class A has been identified" << std::endl;
        return;
    }
    catch (...) {}

    try
    {
        B& b = dynamic_cast<B&>(p);
        (void)b;
        std::cout << "Class B has been identified" << std::endl;
        return;
    }
    catch (...) {}

    try
    {
        C& c = dynamic_cast<C&>(p);
        (void)c;
        std::cout << "Class C has been identified" << std::endl;
        return;
    }
    catch (...) {}

    std::cerr << "Impossible to identify a class" << std::endl;
}
