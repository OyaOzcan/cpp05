#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(const std::string& name, const std::string& target, int gradeToSign, int gradeToExecute)
	: _name(name), _target(target), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (_gradeToSign < 1 || _gradeToExecute < 1)
		throw GradeTooHighException();
	if (_gradeToSign > 150 || _gradeToExecute > 150)
		throw GradeTooLowException();
	std::cout << "AForm constructor called for: " << _name << std::endl;
}

AForm::AForm(const AForm& other)
	: _name(other._name), _target(other._target), _isSigned(other._isSigned),
	  _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute)
{
	std::cout << "AForm copy constructor called for: " << _name << std::endl;
}

AForm& AForm::operator=(const AForm& other) {
	if (this != &other)
		_isSigned = other._isSigned;
	std::cout << "AForm assignment operator called for: " << _name << std::endl;
	return *this;
}


AForm::~AForm()
{
	std::cout << "AForm destructor called for: " << _name << std::endl;
}

const std::string& AForm::getName() const {
	return _name;
}

const std::string& AForm::getTarget() const {
	return _target;
}

bool AForm::getSignStatus() const {
	return _isSigned;
}

int AForm::getSignGrade() const {
	return _gradeToSign;
}

int AForm::getExecutorGrade() const {
	return _gradeToExecute;
}

void AForm::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > _gradeToSign)
		throw GradeTooLowException();
	_isSigned = true;
}

void AForm::executeCheck(const Bureaucrat& executor) const
{
	if (!_isSigned)
		throw NotSignedException();
	if (executor.getGrade() > _gradeToExecute)
		throw GradeTooLowException();
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return "Grade too high!";
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return "Grade too low!";
}

const char* AForm::NotSignedException::what() const throw()
{
	return "Form not signed!";
}

std::ostream& operator<<(std::ostream& os, const AForm& form)
{
	os << "Form: " << form.getName()
	   << ", Target: " << form.getTarget()
	   << ", Signed: " << (form.getSignStatus() ? "Yes" : "No")
	   << ", Sign Grade: " << form.getSignGrade()
	   << ", Execute Grade: " << form.getExecutorGrade();
	return os;
}
