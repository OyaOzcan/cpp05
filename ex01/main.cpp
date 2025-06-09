#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    std::cout << "\n--- Form1: Valid Sign Test ---" << std::endl;
    try {
        Bureaucrat harry("Harry", 42);
        std::cout << harry << std::endl;
        
        Form form1("Form1", 100, 50);
        std::cout << form1 << std::endl;


        harry.signForm(form1); // grade yeterli → imzalanmalı

        std::cout << form1 << std::endl;

    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "\n--- Form2: Invalid Sign (Grade too low) ---" << std::endl;
    try {
        Bureaucrat ron("Ron", 150);
        Form form2("Form2", 50, 50);

        std::cout << ron << std::endl;
        std::cout << form2 << std::endl;

        ron.signForm(form2); // grade yetersiz → hata
        std::cout << form2 << std::endl;
    } catch (const std::exception& e) {
        std::cerr <<  e.what() << std::endl;
    }

    std::cout << "\n--- Form3: Invalid Form Construction ---" << std::endl;
    try {
        Form form3("Form3", 0, 160); // Geçersiz grade'ler
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "\n--- Form4-5-6: Copy and Assignment ---" << std::endl;
    try {
        Form form4("Form4", 30, 40);
        Form form5 = form4;            // Copy constructor
        Form form6("TempForm", 100, 100);
        form6 = form4;                 // Assignment

        std::cout << "Form4: " << form4 << std::endl;
        std::cout << "Form5 (copy): " << form5 << std::endl;
        std::cout << "Form6 (assigned): " << form6 << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
