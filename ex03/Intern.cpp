#include "Intern.hpp"
#include <algorithm>

Intern::Intern() {
	std::cout << "Intern default constructor called." << std::endl;
}

Intern::Intern(const Intern& other) {
	std::cout << "Intern copy constructor called." << std::endl;
	*this = other;
}

Intern& Intern::operator=(const Intern& other) {
	std::cout << "Intern assignment operator called." << std::endl;
	(void)other;
	return *this;
}

Intern::~Intern() {
	std::cout << "Intern destructor called." << std::endl;
}

const char* Intern::InvalidFormException::what() const throw() {
	return "Form not created: Unknown form type!";
}

static void normalizeFormType(std::string& str) {
	for (size_t i = 0; i < str.length(); ++i)
		str[i] = std::tolower(str[i]);
	str.erase(std::remove(str.begin(), str.end(), ' '), str.end());
}

static AForm* ifPresidential(std::string type, std::string target, AForm* form) {
	if (form == NULL && type == "presidentialpardonform")
		return new PresidentialPardonForm(target);
	return form;
}

static AForm* ifRobotomy(std::string type, std::string target, AForm* form) {
	if (form == NULL && type == "robotomyrequestform")
		return new RobotomyRequestForm(target);
	return form;
}

static AForm* ifShrubbery(std::string type, std::string target, AForm* form) {
	if (form == NULL && type == "shrubberycreationform")
		return new ShrubberyCreationForm(target);
	return form;
}

AForm* Intern::makeForm(std::string formType, std::string formTarget) {
	normalizeFormType(formType);

	AForm* form = NULL;
	form = ifPresidential(formType, formTarget, form);
	form = ifRobotomy(formType, formTarget, form);
	form = ifShrubbery(formType, formTarget, form);

	if (!form)
		throw InvalidFormException();

	std::cout << "Intern creates form: " << form->getName()
	          << " with target: " << form->getTarget() << std::endl;
	return form;
}
