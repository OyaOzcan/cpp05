#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"
#include "Bureaucrat.hpp"

class PresidentialPardonForm : public AForm {
private:
	PresidentialPardonForm(void);

public:
	PresidentialPardonForm(std::string target);
	PresidentialPardonForm(PresidentialPardonForm &other);
	PresidentialPardonForm &operator=(PresidentialPardonForm &other);
	~PresidentialPardonForm(void);

	void execute(Bureaucrat const &executor) const;
};

#endif
