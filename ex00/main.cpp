#include "Bureaucrat.hpp"

int main() {
    // Harry - normal oluşturma ve işlem
    try {
        Bureaucrat harry("Harry", 2);
        std::cout << harry << std::endl;

        harry.decrementGrade(); // grade = 3
        std::cout << harry << std::endl;

        harry.incrementGrade(); // grade = 2
        std::cout << harry << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    // Hermonie - invalid grade: 0
    try {
        Bureaucrat hermonie("Hermonie", 0);
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    // Ron - invalid grade: 151
    try {
        Bureaucrat ron("Ron", 151);
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    // Copy constructor - Draco
    try {
        Bureaucrat draco("Draco", 10);
		Bureaucrat b2= draco;
        Bureaucrat b3(draco);

		std::cout << draco << std::endl;
  		std::cout << b2 << std::endl;
        std::cout << b3 << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    // Assignment operator - Luna = Neville
    try {
        Bureaucrat b4("Dumbledore", 1);
		Bureaucrat b5;

		b5 = b4;
		b5.decrementGrade();
    } catch (const std::exception& e) {
        std::cerr <<  e.what() << std::endl;
    }

    return 0;
}
