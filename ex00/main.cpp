#include "ScalarConverter.hpp"

int main(int ac, char** av) {

    if (ac == 2) ScalarConverter::convert(std::string(av[1]));
    else print_color("Usage: ./Scalar <literal>", std::cerr);
}
