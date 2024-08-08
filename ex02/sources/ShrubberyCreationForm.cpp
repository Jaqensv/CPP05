/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-lang <mde-lang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 14:32:45 by mde-lang          #+#    #+#             */
/*   Updated: 2024/08/08 21:43:27 by mde-lang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137)
{
	AForm::formGradeChecker(this->getGts(), this->getGte());
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137)
{
	AForm::formGradeChecker(this->getGts(), this->getGte());
	this->_target = target;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &src) : AForm("ShrubberyCreationForm", 145, 137)
{
	*this = src;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &rhs)
{
	if (this != &rhs)
		this->_target = rhs._target;
	return *this;
}

void ShrubberyCreationForm::execution(Bureaucrat const &executor) const
{
	if (executor.getGrade() > this->getGte())
		throw GradeTooLowException((std::string)executor.getName() + "'s grade is too low to execute the ShrubberyCreationForm");
	std::string filename = this->_target + "_shrubbery";
	std::ofstream outfile(filename.c_str());

	outfile << std::endl;
	outfile << " /\\_/\\" << std::endl; 
	outfile << "( o.o )" << std::endl; 
	outfile << " > ^ <" << std::endl;
	outfile << std::endl;
	outfile.close();

	std::ifstream infile(filename.c_str());
	std::string line;

	while (std::getline(infile, line))
	{
		std::cout << line << std::endl;
	}
	infile.close();
}
