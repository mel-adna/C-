#include <iostream>
#include <exception>

class myexception: public std::exception {
    const char *what() const throw() {
        return "there was an exception";
    }
} myex;

int main () {
    try {
        throw myex;
    }
    catch (std::exception &e) {
        std::cout << e.what() << '\n';
    }
}