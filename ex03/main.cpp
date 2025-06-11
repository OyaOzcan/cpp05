#include "Intern.hpp"
#include "Bureaucrat.hpp"

int main() {
	try {
		Intern intern;
		AForm* form;
		Bureaucrat bureaucrat("Bob", 1);

		// Robotomy Request
		form = intern.makeForm("robotomy request", "Bender");
		bureaucrat.signForm(*form);
		bureaucrat.executeForm(*form);
		delete form;

		// Shrubbery Creation
		form = intern.makeForm("shrubbery creation", "Garden");
		bureaucrat.signForm(*form);
		bureaucrat.executeForm(*form);
		delete form;

		// Presidential Pardon
		form = intern.makeForm("presidential pardon", "Harry");
		bureaucrat.signForm(*form);
		bureaucrat.executeForm(*form);
		delete form;

		// Geçersiz form denemesi
		form = intern.makeForm("invalid form", "Nowhere");
		delete form;

	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	return 0;
}
