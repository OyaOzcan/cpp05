#include "Form.hpp"

// Default constructor
Form::Form() : _name("default"), _isSigned(false), _gradeToSign(150), _gradeToExecute(150) {
    std::cout << "Form default constructor called" << std::endl;
}

// Parametrik constructor
Form::Form(const std::string& name, int gradeToSign, int gradeToExecute)
    : _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
    if (_gradeToSign < 1 || _gradeToExecute < 1)
        throw GradeTooHighException();
    if (_gradeToSign > 150 || _gradeToExecute > 150)
        throw GradeTooLowException();
    std::cout << "Form parameterized constructor called" << std::endl;
}

// Copy constructor
Form::Form(const Form& other)
    : _name(other._name), _isSigned(other._isSigned),
      _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute) {
    std::cout << "Form copy constructor called" << std::endl;
}

// Assignment operator
Form& Form::operator=(const Form& other) {
    std::cout << "Form assignment operator called" << std::endl;
    if (this != &other)
        _isSigned = other._isSigned;
    return *this;
}

// Destructor
Form::~Form() {
    std::cout << "Form destructor called" << std::endl;
}

// Getters
const std::string& Form::getName() const { return _name; }
bool Form::getIsSigned() const { return _isSigned; }
int Form::getGradeToSign() const { return _gradeToSign; }
int Form::getGradeToExecute() const { return _gradeToExecute; }

// beSigned
void Form::beSigned(const Bureaucrat& b) {
    if (b.getGrade() > _gradeToSign)
        throw GradeTooLowException();
    _isSigned = true;
}

// Exceptions
const char* Form::GradeTooHighException::what() const throw() {
    return "Form: grade too high";
}

const char* Form::GradeTooLowException::what() const throw() {
    return "Form: grade too low";
}

// Output stream
std::ostream& operator<<(std::ostream& os, const Form& f) {
    os << "Form Name       : " << f.getName() << "\n"
       << "Signed          : " << (f.getIsSigned() ? "yes" : "no") << "\n"
       << "Grade to Sign   : " << f.getGradeToSign() << "\n"
       << "Grade to Execute: " << f.getGradeToExecute();
    return os;
}

