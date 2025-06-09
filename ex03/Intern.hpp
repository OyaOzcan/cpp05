#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include <string>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern {
public:
	Intern();
	Intern(const Intern& other);
	Intern& operator=(const Intern& other);
	~Intern();

	AForm* makeForm(std::string formType, std::string formTarget);

	class InvalidFormException : public std::exception {
	public:
		virtual const char* what() const throw();
	};
};

#endif
