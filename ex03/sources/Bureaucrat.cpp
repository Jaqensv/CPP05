/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-lang <mde-lang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 13:44:59 by mde-lang          #+#    #+#             */
/*   Updated: 2024/08/08 22:07:46 by mde-lang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Unknown"), _grade(150) {}

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

void Bureaucrat::signForm(AForm &form) const
{
	if (form.getSigned() == true)
		std::cout << form.getTarget() << " signed " << form.getName() << std::endl;
	else
		std::cout << form.getTarget() << " couldn't sign " << form.getName() << std::endl;
}

void Bureaucrat::executeForm(AForm const & form)
{
	if (form.execute(*this) == 0)
		std::cout << form.getTarget() + " executed " + form.getName() << std::endl;
}

Bureaucrat::GradeTooHighException::GradeTooHighException(std::string error) : _error(error) {}

Bureaucrat::GradeTooLowException::GradeTooLowException(std::string error) : _error(error) {}

Bureaucrat::GradeTooHighException::GradeTooHighException::~GradeTooHighException() throw() {}

Bureaucrat::GradeTooLowException::GradeTooLowException::~GradeTooLowException() throw() {}
