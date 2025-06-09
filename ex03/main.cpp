#include "Intern.hpp"
#include "Bureaucrat.hpp"

int main() {
	try {
		Intern intern;
		AForm* form;

		form = intern.makeForm("robotomy request", "Bender");
		delete form;

		form = intern.makeForm("shrubbery creation", "Garden");
		delete form;

		form = intern.makeForm("presidential pardon", "Harry");
		delete form;

		// Geçersiz form denemesi
		form = intern.makeForm("invalid form", "Nowhere");
		delete form;

	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	return 0;
}
