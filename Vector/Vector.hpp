#include <iostream>
#include <exception>

template <typename T>
class Vector {
private:
    T* data;              // Pointer to the dynamic array
    size_t size;          // Current size
    size_t capacity;      // Allocated capacity

    void resize(size_t new_capacity) {
        T* new_data = new T[new_capacity];
        for (size_t i = 0; i < size; i++) {
            new_data[i] = data[i];
        }
        delete[] data; // Free old memory
        data = new_data; // Assign new memory
        capacity = new_capacity;
    }

public:
    // Default constructor
    Vector() : data(nullptr), size(0), capacity(0) {}

    // Constructor with size
    explicit Vector(const size_t& n) : size(n), capacity(n) {
        data = new T[n]();
    }

    // Constructor with size and initial value
    Vector(const size_t& n, const T& value) : size(n), capacity(n) {
        data = new T[n];
        for (size_t i = 0; i < n; i++) {
            data[i] = value;
        }
    }

    // Copy constructor
    Vector(const Vector& other) : size(other.size), capacity(other.capacity) {
        data = new T[capacity];
        for (size_t i = 0; i < size; i++) {
            data[i] = other.data[i];
        }
    }

    // Destructor
    ~Vector() {
        delete[] data;
    }

    // Methods
     void push_back(const T& item) {
        if (size == capacity) {
            resize(capacity == 0 ? 1 : capacity * 2);
        }
        data[size++] = item;
     }

     void push_front(const T& item) {
        if (size == capacity) {
           resize(capacity == 0 ? 1 : capacity * 2);
        }
        T* new_data = new T[capacity];
        new_data[0] = item;
        for (size_t i = 0; i < size; i++) {
            new_data[i + 1] = data[i];
        }
        delete[] data;
        data = new_data;
        ++size;
    }

    void clear() {
        this -> size = 0;
    }

    void shrink_to_fit() {
        this -> capacity = this -> size;
    }

    void pop_back() {
        if (size == 0) {
            throw std::out_of_range("Vector is empty");
        }
        --size;
    }

    // Getters
    size_t get_size() const {
        return size;
    }

    size_t get_capacity() const {
        return capacity;
    }

    // Operators
    T& operator[](size_t index) {
        if (index >= capacity) {
            throw std::out_of_range("Index is out of range");
        }
        return data[index];
    }

    const T& operator[](size_t index) const {
        if (index >= capacity) {
            throw std::out_of_range("Index is out of range");
        }
        return data[index];
    }
};
