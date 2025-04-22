#include "Serializer.hpp"

int main() {
    Data my_data;
    my_data.i = 42;
    my_data.c = 'c';
    my_data.f = 3.14;
    my_data.d = 3.15;
    std::cout << get_color() << "adress of my data structure:" << &my_data << std::endl;
    std::cout << get_color() << "integer in my data:" << my_data.i << std::endl;
    std::cout << get_color() << "char in my data:" << my_data.c << std::endl;
    std::cout << get_color() << "float in my data:" << my_data.f << std::endl;
    std::cout << get_color() << "double in my data:" << my_data.d << std::endl;
    print_color("\nserializing...\n", std::cout, 1);
    uintptr_t ptr_to_my_data = Serializer::serialize(&my_data);
    print_color("deserializing...\n", std::cout, 1);
    Data* pointed_adress = Serializer::deserialize(ptr_to_my_data);

    std::cout << get_color() << "adress of my data structure:" << &my_data << std::endl;
    std::cout << get_color() << "adress of my data structure:" << pointed_adress << std::endl;
    std::cout << get_color() << "integer in my data:" << pointed_adress->i << std::endl;
    std::cout << get_color() << "char in my data:" << pointed_adress->c << std::endl;
    std::cout << get_color() << "float in my data:" << pointed_adress->f << std::endl;
    std::cout << get_color() << "double in my data:" << pointed_adress->d << std::endl;

    return 0;
}
