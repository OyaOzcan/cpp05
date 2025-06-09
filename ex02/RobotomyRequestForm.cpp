#include "RobotomyRequestForm.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm()
	: AForm("RobotomyRequestForm", "default", 72, 45) {
	std::cout << "RobotomyRequestForm default constructor called." << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target)
	: AForm("RobotomyRequestForm", target, 72, 45) {
	std::cout << "RobotomyRequestForm constructed for target: " << target << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm& other)
	: AForm(other) {
	std::cout << "RobotomyRequestForm copy constructor called." << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(RobotomyRequestForm& other) {
	AForm::operator=(other);
	std::cout << "RobotomyRequestForm assignment operator called." << std::endl;
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {
	std::cout << "RobotomyRequestForm destructor called." << std::endl;
}

void RobotomyRequestForm::execute(Bureaucrat const& executor) const {
	if (!getSignStatus())
		throw AForm::NotSignedException();
	if (executor.getGrade() > getExecutorGrade())
		throw AForm::GradeTooLowException();

	std::cout << "* drilling noises *" << std::endl;
	std::srand(std::time(0));
	if (std::rand() % 2)
		std::cout << getTarget() << " has been robotomized successfully." << std::endl;
	else
		std::cout << "Robotomy failed for " << getTarget() << "." << std::endl;
}
