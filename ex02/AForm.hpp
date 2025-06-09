#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>
#include <exception>

class Bureaucrat; // forward declaration

class AForm {
private:
	const std::string _name;
	const std::string _target;
	bool _isSigned;
	const int _gradeToSign;
	const int _gradeToExecute;

public:
	AForm(const std::string& name, const std::string& target, int gradeToSign, int gradeToExecute);
	AForm(const AForm& other);
	AForm& operator=(const AForm& other);
	virtual ~AForm();

	const std::string& getName() const;
	const std::string& getTarget() const;
	bool getSignStatus() const;
	int getSignGrade() const;
	int getExecutorGrade() const;

	void beSigned(const Bureaucrat& bureaucrat);
	void executeCheck(const Bureaucrat& executor) const;
	virtual void execute(const Bureaucrat& executor) const = 0;

	class GradeTooHighException : public std::exception {
	public:
		const char* what() const throw();
	};

	class GradeTooLowException : public std::exception {
	public:
		const char* what() const throw();
	};

	class NotSignedException : public std::exception {
	public:
		const char* what() const throw();
	};
};

std::ostream& operator<<(std::ostream& os, const AForm& form);

#endif
