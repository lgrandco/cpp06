#include "colors.hpp"

std::string get_color(std::ostream& os, int bold) {
    if (bold > 0 && isatty(STDOUT_FILENO)) os << ANSI_BOLD;
    static unsigned int state = static_cast<unsigned int>(std::time(NULL));
    state = state * 1103515245 + 12345;
    std::string color = colors[state % 6];
    if (isatty(STDOUT_FILENO)) os << color;
    return color;
}

void print_color(std::string text, std::ostream& os, int bold, bool endl) {
    if (&os == &std::cerr) {
        if (bold == -1 && &os == &std::cerr && isatty(STDOUT_FILENO)) os << ANSI_BOLD;
        if (isatty(STDOUT_FILENO)) os << ANSI_COLOR_RED;
    } else get_color(os, bold);
    os << text;
    if (isatty(STDOUT_FILENO)) os << ANSI_RESET;
    if (endl) os << std::endl;
}

std::string print_sep() {
    std::string
        sep = "----------------------------------------------------------------------------";
    std::cout << get_color(std::cout, 1) << sep << ANSI_RESET << std::endl;
    return "";
}
