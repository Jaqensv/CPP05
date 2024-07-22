/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-lang <mde-lang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 13:44:59 by mde-lang          #+#    #+#             */
/*   Updated: 2024/07/22 18:22:38 by mde-lang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("unknown"), _grade(150)
{
	
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade)
{
	
}

Bureaucrat::~Bureaucrat() {}

void Bureaucrat::upGrade()
{
	try 
	{
		this->_grade -= 1;
		if (this->_grade < 1)
			throw std::exception();
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;	
	}
}

void Bureaucrat::downGrade()
{
	this->_grade += 1;
}

std::string Bureaucrat::getName() const
{
	return this->_name;
}

int Bureaucrat::getGrade() const
{
	return this->_grade;
}

// Bureaucrat &Bureaucrat::operator=(Bureaucrat const &rhs)
// {
// 	this->_grade = rhs.getGrade();
// 	return *this;
// }