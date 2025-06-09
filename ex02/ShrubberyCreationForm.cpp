#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm()
	: AForm("ShrubberyCreationForm", "default", 145, 137) {
	std::cout << "ShrubberyCreationForm default constructor called." << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
	: AForm("ShrubberyCreationForm", target, 145, 137) {
	std::cout << "ShrubberyCreationForm constructed for target: " << target << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm& other)
	: AForm(other) {
	std::cout << "ShrubberyCreationForm copy constructor called." << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(ShrubberyCreationForm& other) {
	AForm::operator=(other);
	std::cout << "ShrubberyCreationForm assignment operator called." << std::endl;
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	std::cout << "ShrubberyCreationForm destructor called." << std::endl;
}

void ShrubberyCreationForm::execute(Bureaucrat const& executor) const {
	if (!getSignStatus())
		throw AForm::NotSignedException();
	if (executor.getGrade() > getExecutorGrade())
		throw AForm::GradeTooLowException();

	std::ofstream outFile((getTarget() + "_shrubbery").c_str());
	if (!outFile)
		return;

	outFile  <<"\n"
			<< "                                            ." << "\n"
			<< "                                    .         ;  " << "\n"
			<< "       .              .              ;%     ;;   " << "\n"
			<< "         ,           ,                :;%  %;   " << "\n"
			<< "          :         ;                   :;%;'     .,   " << "\n"
			<< " ,.        %;     %;            ;        %;'    ,;" << "\n"
			<< "   ;       ;%;  %%;        ,     %;    ;%;    ,%'" << "\n"
			<< "    %;       %;%;      ,  ;       %;  ;%;   ,%;' " << "\n"
			<< "     ;%;      %;        ;%;        % ;%;  ,%;'" << "\n"
			<< "      `%;.     ;%;     %;'         `;%%;.%;'" << "\n"
			<< "       `:;%.    ;%%. %@;        %; ;@%;%'" << "\n"
			<< "          `:%;.  :;bd%;          %;@%;'" << "\n"
			<< "            `@%:.  :;%.         ;@@%;'   " << "\n"
			<< "              `@%.  `;@%.      ;@@%;         " << "\n"
			<< "                `@%%. `@%%    ;@@%;        " << "\n"
			<< "                  ;@%. :@%%  %@@%;       " << "\n"
			<< "                    %@bd%%%bd%%:;     " << "\n"
			<< "                      #@%%%%%:;;" << "\n"
			<< "                      %@@%%%::;" << "\n"
			<< "                      %@@@%(o);  . '         " << "\n"
			<< "                      %@@@o%;:(.,'         " << "\n"
			<< "                  `.. %@@@o%::;         " << "\n"
			<< "                     `)@@@o%::;         " << "\n"
			<< "                      %@@(o)::;        " << "\n"
			<< "                     .%@@@@%::;         " << "\n"
			<< "                     ;%@@@@%::;.          " << "\n"
			<< "                    ;%@@@@%%:;;;. " << "\n"
			<< "                ...;%@@@@@%%:;;;;,..   " << std::endl;
	outFile.close();
}

