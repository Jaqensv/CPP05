/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-lang <mde-lang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 17:54:39 by mde-lang          #+#    #+#             */
/*   Updated: 2024/07/25 16:01:32 by mde-lang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() {}

Form::~Form() {}

Form::Form(std::string name, int gts, int gte) : _name(name), _gts(gts), _gte(gte)
{
	try
	{
		formGradeChecker(this->_gts, this->_gte);
	}
	catch (const GradeTooHighException &e)
	{
		std::cerr << e.what() << std::endl;
		_reason = "there is an error in the form.";
	}
	catch (const GradeTooLowException &e)
	{
		std::cerr << e.what() << std::endl;
		_reason = "there is an error in the form.";
	}
}

Form::Form(Form const &src)
{
	*this = src;
}

Form &Form::operator=(Form const &src)
{
	this->_name = src._name;
	this->_signed = src._signed;
	this->_gts = src._gts;
	this->_gte = src._gte;
	this->_reason = src._reason;
	return *this;	
}

std::string Form::getName() const
{
	return this->_name;
}

bool Form::getSigned() const
{
	return this->_signed;
}

int Form::getGts() const
{
	return this->_gts;
}

int Form::getGte() const
{
	return this->_gte;
}

std::string Form::getReason() const
{
	return this->_reason;
}

void Form::formGradeChecker(int gts, int gte)
{
	if (gts < 1 || gte < 1)
		throw GradeTooHighException();
	else if (gts > 150 || gte > 150)
		throw GradeTooLowException();
}

void Form::beSigned(Bureaucrat bureaucrat)
{
	if (bureaucrat.getGrade() <= this->_gts)
		this->_signed = true;
	else
	{
		this->_reason = "his grade is too low.";
		throw GradeTooLowException();
	}
}

std::ostream &operator<<(std::ostream &o, Form const &rhs) 
{
	std::string is_signed;

	if (rhs.getSigned() == true)
		is_signed = "signed";
	else
		is_signed = "unsigned";
	return (o << "Form " << rhs.getName() << ", with a needed grade to sign of " << rhs.getGts() << " and a needed grade to execute of " << rhs.getGte() << " is " << is_signed << "." << std::endl);
}