/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-lang <mde-lang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 13:44:59 by mde-lang          #+#    #+#             */
/*   Updated: 2024/08/07 14:56:28 by mde-lang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("unknown"), _grade(150) {}

Bureaucrat::~Bureaucrat() {}

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name), _grade(grade)
{
	try
	{
		gradeChecker(this->_grade);
	}
	catch (const GradeTooHighException &e)
	{
		std::cerr << e.what() << std::endl;
		std::exit(EXIT_FAILURE);
	}
	catch (const GradeTooLowException &e)
	{
		std::cerr << e.what() << std::endl;
		std::exit(EXIT_FAILURE);
	}
}

Bureaucrat::Bureaucrat(Bureaucrat const &src) : _name(src._name)
{
	*this = src;
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &rhs)
{
	if (this != &rhs)
		this->_grade = rhs._grade;
	return *this;
}

void Bureaucrat::gradeModifier(int modifier)
{
	int i = 0;
	try
	{
		if (modifier < 0)
		{
			while (i++ < (modifier * -1))
				downGrade();
		}
		else
		{
			while (i++ < modifier)
				upGrade();
		}
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}

void Bureaucrat::gradeChecker(int grade)
{
	if (grade < 1)
		throw GradeTooHighException("The bureaucrat's grade is too high!");
	else if (grade > 150)
		throw GradeTooLowException("The bureaucrat's grade is too low!");
}

void Bureaucrat::upGrade()
{
	if (this->_grade == 1)
		throw GradeTooHighException("The bureaucrat's grade is too high to be increased");
	else
		this->_grade -= 1;
}

void Bureaucrat::downGrade()
{
	if (this->_grade == 150)
		throw GradeTooLowException("The bureaucrat's grade is too low to be reduced");
	else
		this->_grade += 1;
}

const std::string Bureaucrat::getName() const
{
	return this->_name;
}

int Bureaucrat::getGrade() const
{
	return this->_grade;
}

std::ostream &operator<<(std::ostream &o, Bureaucrat const &rhs) 
{
	return (o << rhs.getName() << ", grade " << rhs.getGrade());
}

void Bureaucrat::signForm(Form &form) const
{
	if (form.getSigned() == true)
		std::cout << this->_name << " signed " << form.getName() << std::endl;
	else
		std::cout << this->_name << " couldn't sign " << form.getName() << " form, because " << form.getReason() << std::endl;
}

Bureaucrat::GradeTooHighException::GradeTooHighException(const char *error)
{
	std::cout << error << std::endl;
}

Bureaucrat::GradeTooLowException::GradeTooLowException(const char *error)
{
	std::cout << error << std::endl;
}