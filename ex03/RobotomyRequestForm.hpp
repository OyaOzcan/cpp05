#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <cstdlib>
#include <ctime>
#include "Bureaucrat.hpp"

class RobotomyRequestForm : public AForm {
private:
	RobotomyRequestForm(void);

public:
	RobotomyRequestForm(std::string target);
	RobotomyRequestForm(RobotomyRequestForm &other);
	RobotomyRequestForm &operator=(RobotomyRequestForm &other);
	~RobotomyRequestForm(void);

	void execute(Bureaucrat const &executor) const;
};

#endif
