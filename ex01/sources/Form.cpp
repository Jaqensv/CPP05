/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-lang <mde-lang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 17:54:39 by mde-lang          #+#    #+#             */
/*   Updated: 2024/07/29 16:38:17 by mde-lang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Form.hpp"

Form::Form() : _gts(150), _gte(150)
{
	this->_signed = false;
}

Form::~Form() {}

Form::Form(std::string name, const int gts, const int gte) : _name(name), _gts(gts), _gte(gte)
{
	this->_signed = false;
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

Form::Form(Form const &src) : _name(src._name), _signed(src._signed), _gts(src._gts), _gte(src._gte), _reason(src._reason)
{
	*this = src;
}

Form &Form::operator=(Form const &rhs)
{
	if (this != &rhs)
	{
		this->_signed = rhs._signed;
		this->_reason = rhs._reason;
	}
	return *this;	
}

const std::string Form::getName() const
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
	{
		this->form_err = true;
		throw GradeTooHighException("There is an error in the form.");
	}
	else if (gts > 150 || gte > 150)
	{
		this->form_err = true;
		throw GradeTooLowException("There is an error in the form.");
	}
}

void Form::beSigned(Bureaucrat &bureaucrat)
{
	try
	{
		if (bureaucrat.getGrade() <= this->_gts)
			this->_signed = true;
		else
		{
			if (this->form_err == false)
			{
				this->_reason = "his grade is too low.";
				throw GradeTooLowException("The bureaucrat doesn't have the right grade to sign the form.");
			}
		}
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	bureaucrat.signForm(*this);
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

Form::GradeTooHighException::GradeTooHighException(const char *error)
{
	std::cout << error << std::endl;
}

Form::GradeTooLowException::GradeTooLowException(const char *error)
{
	std::cout << error << std::endl;
}