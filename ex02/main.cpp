#include "Base.hpp"

Base* generate(void) {
    std::srand(time(NULL));

    int i = std::rand() % 3;
    if (i == 0) return new A();
    else if (i == 1) return new B();
    return new C();
}

void identify(Base* p) {
    if (dynamic_cast<A*>(p)) print_color("It's a pointer to a A object");
    else if (dynamic_cast<B*>(p)) print_color("Its a pointer to a B object");
    else if (dynamic_cast<C*>(p)) print_color("Its a pointer to a C object");
    else if (p == NULL) print_color("Null pointer");
    else print_color("Unidentified pointer");
}

void identify(Base& p) {
    try {
        A a = dynamic_cast<A&>(p);
        print_color("It's a reference to a A object", std::cout, true);

    } catch (std::exception& e) {
        try {
            B b = dynamic_cast<B&>(p);
            print_color("It's a reference to a B object", std::cout, true);
        } catch (std::exception& e) {
            try {
                C c = dynamic_cast<C&>(p);
                print_color("It's a reference to a C object", std::cout, true);
            } catch (std::exception& e) { print_color("Unidentified reference", std::cerr, true); }
        }
    }
}

int main() {
    print_color("Creating a pointer to either A, B or C");
    Base* ptr = generate();
    identify(ptr);
    delete ptr;

    A a;
    print_color("\nCreating an A object");
    identify(a);

    B b;
    print_color("\nCreating an B object");
    identify(b);

    C c;
    print_color("\nCreating an C object");
    identify(c);
}
