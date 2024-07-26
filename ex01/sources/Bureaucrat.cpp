/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-lang <mde-lang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 13:44:59 by mde-lang          #+#    #+#             */
/*   Updated: 2024/07/26 17:23:54 by mde-lang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("unknown"), _grade(150) {}

Bureaucrat::~Bureaucrat() {}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade)
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

Bureaucrat::Bureaucrat(Bureaucrat const &src)
{
	*this = src;
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &src)
{
	this->_grade = src._grade;
	this->_name = src._name;
	return *this;
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
	try
	{
		if (this->_grade == 1)
			throw GradeTooHighException("The bureaucrat's grade is too high to be increased");
		this->_grade -= 1;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		std::exit(EXIT_FAILURE);
	}
}

void Bureaucrat::downGrade()
{
	try
	{
		if (this->_grade == 150)
			throw GradeTooLowException("The bureaucrat's grade is too high to be reduced");
		this->_grade += 1;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		std::exit(EXIT_FAILURE);
	}
}

std::string Bureaucrat::getName() const
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

void Bureaucrat::signForm(Form &form)
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