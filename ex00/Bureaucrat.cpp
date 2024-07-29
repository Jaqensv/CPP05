/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-lang <mde-lang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 13:44:59 by mde-lang          #+#    #+#             */
/*   Updated: 2024/07/29 16:39:24 by mde-lang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

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

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &rhs)
{
	if (this != &rhs)
		this->_grade = rhs._grade;
	return *this;
}

void Bureaucrat::gradeChecker(int grade)
{
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
}

void Bureaucrat::upGrade()
{
	if (this->_grade == 1)
		throw GradeTooHighException();
	this->_grade -= 1;
}

void Bureaucrat::downGrade()
{
	if (this->_grade == 150)
		throw GradeTooLowException();
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
	return (o << rhs.getName() << ", bureaucrat grade " << rhs.getGrade());
}
