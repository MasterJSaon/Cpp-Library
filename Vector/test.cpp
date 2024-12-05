#include "Vector.hpp"

using std::cout;
using std::endl;

int main() {
     Vector<int> vec;

     vec.push_back(10);
     vec.push_back(20);
     vec.push_back(30);
     vec.push_front(69);
     vec.push_front(71);
     vec.push_front(44);
    

     std::cout << "Vector elements: ";
     for (size_t i = 0; i < vec.get_size(); ++i) {
          std::cout << vec[i] << " ";
     }
     std::cout << "\n";

     vec.pop_back();
     std::cout << "After pop_back, size: " << vec.get_size() << " capacity: " << vec.get_capacity() << "\n";
     std::cout << "Vector elements: ";
     for (size_t i = 0; i < vec.get_size(); ++i) {
          std::cout << vec[i] << " ";
     }
     std::cout << "\n";
     return 0;
}