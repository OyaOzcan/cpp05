#include <iostream>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
    try {
        Bureaucrat harry("Harry", 1);
        Bureaucrat hermione("Hermione", 45);
        Bureaucrat ron("Ron", 140);
        Bureaucrat dumbledore("Dumbledore", 150);

        std::cout << "\n--- ShrubberyCreationForm Test ---\n";
        ShrubberyCreationForm shrubbery("Hogwarts Garden");

        ron.signForm(shrubbery);           // grade 140 -> should succeed
        ron.executeForm(shrubbery);        // grade 140 -> fail (needs 137)
        harry.executeForm(shrubbery);      // should succeed

        std::cout << "\n--- RobotomyRequestForm Test ---\n";
        RobotomyRequestForm robotomy("Draco Malfoy");

        hermione.signForm(robotomy);       // grade 45 -> can sign (needs 72)
        hermione.executeForm(robotomy);    // grade 45 -> can execute (needs 45)

        std::cout << "\n--- PresidentialPardonForm Test ---\n";
        PresidentialPardonForm pardon("Sirius Black");

        harry.signForm(pardon);            // grade 1 -> can sign (needs 25)
        harry.executeForm(pardon);         // grade 1 -> can execute (needs 5)

        std::cout << "\n--- Failure Case Test (Not Signed) ---\n";
        PresidentialPardonForm pardon2("Bellatrix Lestrange");
        hermione.executeForm(pardon2);   // should throw NotSignedException

    } catch (const std::exception& e) {
        std::cerr <<  e.what() << std::endl;
    }

    return 0;
}
