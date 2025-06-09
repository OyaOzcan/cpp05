#include "PresidentialPardonForm.hpp"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm()
	: AForm("PresidentialPardonForm", "default", 25, 5) {
	std::cout << "PresidentialPardonForm default constructor called." << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target)
	: AForm("PresidentialPardonForm", target, 25, 5) {
	std::cout << "PresidentialPardonForm constructed for target: " << target << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm& other)
	: AForm(other) {
	std::cout << "PresidentialPardonForm copy constructor called." << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(PresidentialPardonForm& other) {
	AForm::operator=(other);
	std::cout << "PresidentialPardonForm assignment operator called." << std::endl;
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {
	std::cout << "PresidentialPardonForm destructor called." << std::endl;
}

void PresidentialPardonForm::execute(Bureaucrat const& executor) const {
	if (!getSignStatus())
		throw AForm::NotSignedException();
	if (executor.getGrade() > getExecutorGrade())
		throw AForm::GradeTooLowException();

	std::cout << getTarget() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
