#include "Light_string.hpp"
#include <iostream>

int main() {
     Light_string test("sad");
     std::cout << test.length() << '\n';
     std::cout << test.c_str() << '\n';
}