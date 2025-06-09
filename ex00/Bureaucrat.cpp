#include "Bureaucrat.hpp"
#include <iostream>

// Default constructor
Bureaucrat::Bureaucrat() : _name("default"), _grade(150) {
    std::cout << "Default constructor called" << std::endl;
}

// Parametrik constructor
Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name) {
    if (grade < 1)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException();
    _grade = grade;
    std::cout << "Parameterized constructor called" << std::endl;
}

// Copy constructor
Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name), _grade(other._grade) {
    std::cout << "Copy constructor called" << std::endl;
}

// Assignment operator
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
    std::cout << "Assignment operator called" << std::endl;
    if (this != &other)
        _grade = other._grade;
    return *this;
}

// Destructor
Bureaucrat::~Bureaucrat() {
    std::cout << "Destructor called" << std::endl;
}

// Getters
const std::string& Bureaucrat::getName() const { return _name; }
int Bureaucrat::getGrade() const { return _grade; }

// Grade operations
void Bureaucrat::incrementGrade() {
    if (_grade <= 1)
        throw GradeTooHighException();
    _grade--;
}

void Bureaucrat::decrementGrade() {
    if (_grade >= 150)
        throw GradeTooLowException();
    _grade++;
}

// Exception what()
const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return "Grade too high!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return "Grade too low!";
}

// Output stream overload
std::ostream& operator<<(std::ostream& os, const Bureaucrat& b) {
    os << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
    return os;
}
