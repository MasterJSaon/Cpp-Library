#include "Vector.hpp"
#include <vector>
#include <chrono>

using std::cout;
using std::endl;

int main() {
     // ========================================== SPEED TEST (Vecotor)  ========================================== 
     auto start = std::chrono::high_resolution_clock::now();
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
     std::cout << "\n\n\n";

     auto end = std::chrono::high_resolution_clock::now();

     auto elapsed_ns = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();

     std::cout << "Time elapsed: " << elapsed_ns << " nanoseconds\n";
     double elapsed_ms = elapsed_ns * 0.000001;  // Convert nanoseconds to milliseconds
     std::cout << "Elapsed time: " << elapsed_ms << " milliseconds\n\n\n";

     // ========================================== SPEED TEST (std::vecotor)  ========================================== 

     start = std::chrono::high_resolution_clock::now();
     std::vector<int> vec2;

     vec2.push_back(10);
     vec2.push_back(20);
     vec2.push_back(30);
     vec2.insert(vec2.begin(), 69);
     vec2.insert(vec2.begin(), 71);
     vec2.insert(vec2.begin(), 44);

     
     std::cout << "Vector elements: ";
     for (size_t i = 0; i < vec2.size(); ++i) {
          std::cout << vec2[i] << " ";
     }
     std::cout << "\n";

     vec2.pop_back();

     std::cout << "After pop_back, size: " << vec2.size() << " capacity: " << vec2.capacity() << "\n";
     std::cout << "Vector elements: ";
     for (size_t i = 0; i < vec2.size(); ++i) {
          std::cout << vec2[i] << " ";
     }
     std::cout << "\n\n\n";


     end = std::chrono::high_resolution_clock::now();

     elapsed_ns = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();

     std::cout << "Time elapsed: " << elapsed_ns << " nanoseconds\n";
     elapsed_ms = elapsed_ns * 0.000001;  // Convert nanoseconds to milliseconds
     std::cout << "Elapsed time: " << elapsed_ms << " milliseconds\n";
     // ========================================== SPEED END TEST (vecotor)  ========================================== 

     // here i tried to test time of shrinkin what has no sense (but why no) - result: 0 ns, 0ms :vvv
     
     start = std::chrono::high_resolution_clock::now();
     // vec2.clear();
     vec2.shrink_to_fit();
     std::cout << "After pop_back, size: " << vec2.size() << " capacity: " << vec2.capacity() << "\n";
     for (size_t i = 0; i < vec2.capacity(); ++i) {
          std::cout << vec2[i] << " ";
     }

     end = std::chrono::high_resolution_clock::now();

     elapsed_ns = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();

     std::cout << "shrinking vector - Time elapsed: " << elapsed_ns << " nanoseconds\n";
     elapsed_ms = elapsed_ns * 0.000001;  // Convert nanoseconds to milliseconds
     std::cout << "Elapsed time: " << elapsed_ms << " milliseconds\n";

     
     start = std::chrono::high_resolution_clock::now();

     vec.shrink_to_fit();
     std::cout << "After pop_back, size: " << vec.get_size() << " capacity: " << vec.get_capacity() << "\n";
     for (size_t i = 0; i < vec.get_capacity(); ++i) {
          std::cout << vec[i] << " ";
     }

     end = std::chrono::high_resolution_clock::now();

     elapsed_ns = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();

     std::cout << "shrinking Vector - Time elapsed: " << elapsed_ns << " nanoseconds\n";
     elapsed_ms = elapsed_ns * 0.000001;  // Convert nanoseconds to milliseconds
     std::cout << "Elapsed time: " << elapsed_ms << " milliseconds\n";

     return 0;
}