#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <stdexcept>

class Bureaucrat {
private:
    const std::string _name;
    int _grade;

public:
    Bureaucrat(); // default
    Bureaucrat(const std::string& name, int grade); // parametreli
    Bureaucrat(const Bureaucrat& other); // copy ctor
    Bureaucrat& operator=(const Bureaucrat& other); // assignment
    ~Bureaucrat(); // destructor

    const std::string& getName() const;
    int getGrade() const;

    void incrementGrade();
    void decrementGrade();

    class GradeTooHighException : public std::exception {
    public:
        const char* what() const throw();
    };

    class GradeTooLowException : public std::exception {
    public:
        const char* what() const throw();
    };
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);

#endif
