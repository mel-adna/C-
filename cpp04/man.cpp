#include <iostream>

class Base {
public:
    virtual void hello() = 0; // pure virtual
};

class Derived : public Base {

public:
    // Did NOT implement hello()
    void hello() {
        std::cout << "hello" << std::endl;
    }
};

int main() {
    Derived d; // ❌ ERROR: Derived is abstract
    d.hello();
}
