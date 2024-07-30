/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-lang <mde-lang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 14:32:45 by mde-lang          #+#    #+#             */
/*   Updated: 2024/07/30 19:06:05 by mde-lang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 0)
{
	try
	{
		AForm::formGradeChecker(this->getGts(), this->getGte(), this->_target);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
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

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	try
	{
		execution(executor);
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}

void ShrubberyCreationForm::execution(Bureaucrat const &executor) const
{
	if (executor.getGrade() <= this->getGte())
	{
		std::string filename = this->_target + "_shrubbery";
		std::ofstream outfile(filename.c_str());

		outfile << " /\\_/\\" << std::endl; 
		outfile << "( o.o )" << std::endl; 
		outfile << " > ^ <" << std::endl;
		outfile.close();
	
		std::ifstream infile(filename.c_str());
		std::string line;

		while (std::getline(infile, line))
		{
			std::cout << line << std::endl;
		}
		infile.close();
	}
	else
		throw GradeTooLowException("Bureaucrate grade is too low to execute Shrubbery");
		
}

