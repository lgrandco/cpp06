#include "ScalarConverter.hpp"

#include <iomanip>
#include <limits>

void print_pseudo_literal(std::string s) {
    print_color("char : impossible");
    print_color("int : impossible");
    print_color("float : " + s + "f");
    print_color("char : " + s);
}

void print_char_info(char c) {
    std::cout << get_color() << "char : '" << c << "'" << ANSI_RESET << std::endl;
    std::cout << get_color() << "int : " << static_cast<int>(c) << ANSI_RESET << std::endl;
    std::cout << get_color() << "float : " << static_cast<float>(c) << ".0f" << ANSI_RESET
              << std::endl;
    std::cout << get_color() << "double : " << static_cast<double>(c) << ".0" << ANSI_RESET
              << std::endl;
}

void ScalarConverter::convert(std::string s) {

    bool _int = true, _float = true, _double = true;
    int dot_count = 0, digit_count = 0, plus_count = 0, minus_count = 0, f_count = 0;

    for (int i = 0; s[i]; i++) {
        if ((s[i] != '+' && s[i] != '-' && !std::isdigit(s[i])) ||
            (s[i] == '+' && (plus_count++ || digit_count)) ||
            (s[i] == '-' && (minus_count++ || digit_count))) {
            if (s[i] == '.' && dot_count++) _double = false, _float = false;
            if (s[i] == 'f' && (f_count++ || s[i + 1])) _float = false;
            if (s[i] == 'f') _double = false;
            _int = false;
        }
    }
    if (!dot_count) _float = false, _double = false;
    if (!f_count) _float = false;
    if (s == "-inf" || s == "+inf" || s == "nan") print_pseudo_literal(s);
    else if (s.length() == 3 && s[0] == s[2]) print_char_info(s[1]);
    else if (_int || _float || _double) {
        double original = std::atof(s.c_str());
        double copy;
        if (_float) copy = static_cast<float>(original);
        else if (_int) copy = static_cast<int>(original);
        else copy = original;
        if (static_cast<long long int>(original) == original)
            std::cout << std::fixed << std::setprecision(1);
        else std::cout << std::fixed << std::setprecision(50);
        if (original < -std::numeric_limits<char>::max() ||
            original > std::numeric_limits<char>::max())
            print_color("char: Overflow error");
        else if (!isprint(original)) print_color("char: Non displayable");
        else
            std::cout << get_color() << "char: '" << static_cast<char>(original) << "'"
                      << ANSI_RESET << std::endl;
        if (original < -std::numeric_limits<int>::max() ||
            original > std::numeric_limits<int>::max())
            print_color("int: Overflow error");
        else
            std::cout << get_color() << "int: " << static_cast<int>(copy) << ANSI_RESET
                      << std::endl;
        if (original < -std::numeric_limits<float>::max() ||
            original > std::numeric_limits<float>::max())
            print_color("float: Overflow error");
        else
            std::cout << get_color() << "float: " << static_cast<float>(copy) << "f" << ANSI_RESET
                      << std::endl;
        std::cout << get_color() << "double: " << static_cast<double>(copy) << ANSI_RESET
                  << std::endl;
    } else print_color("invalid literal");
};
