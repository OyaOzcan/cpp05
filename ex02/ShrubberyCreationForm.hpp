#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <fstream>
#include "Bureaucrat.hpp"

class ShrubberyCreationForm : public AForm {
private:
	ShrubberyCreationForm(void);

public:
	ShrubberyCreationForm(std::string target);
	ShrubberyCreationForm(ShrubberyCreationForm &other);
	ShrubberyCreationForm &operator=(ShrubberyCreationForm &other);
	~ShrubberyCreationForm(void);

	void execute(Bureaucrat const &executor) const;
};

std::ostream &operator<<(std::ostream &o, ShrubberyCreationForm &other);

#endif
