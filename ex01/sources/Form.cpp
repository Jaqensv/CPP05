/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-lang <mde-lang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 17:54:39 by mde-lang          #+#    #+#             */
/*   Updated: 2024/08/07 14:55:48 by mde-lang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Form.hpp"

Form::Form() : _gts(150), _gte(150)
{
	this->_signed = false;
}

Form::~Form() {}

Form::Form(const std::string name, const int gts, const int gte) : _name(name), _gts(gts), _gte(gte)
{
	this->_signed = false;
	this->_signable = true;
	formGradeChecker(gts, gte, name);
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

bool Form::getSignable() const
{
	return this->_signable;
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

bool Form::signProcess(bool iss)
{
	this->_signed = iss;
	return this->_signed;
}

std::string Form::reasonModifier(std::string reason)
{
	this->_reason = reason;
	return this->_reason;
}

void Form::formGradeChecker(const int gts, const int gte, std::string name)
{
	if ((gts < 1 || gte < 1) && this->_form_err == false)
	{
		this->_form_err = true;
		this->_signable = false;
		_reason = name + " has a too high grade.";
		throw GradeTooHighException((std::string)name + " has a too high grade");
	}
	else if ((gts > 150 || gte > 150) && this->_form_err == false)
	{
		this->_signable = false;
		_reason = name + " has a too low grade.";
		this->_form_err = true;
		throw GradeTooLowException((std::string)name + " has a too low grade");
	}
}

void Form::beSigned(Bureaucrat &bureaucrat)
{
	try
	{
		if (this->_signable == true)
		{
			if (bureaucrat.getGrade() <= this->getGts())
				this->signProcess(true);
			else
			{
				if (this->_form_err == false)
				{
					this->reasonModifier("his grade is too low.");
					throw GradeTooLowException((std::string)"The bureaucrat does not have the right grade to sign the " + this->getName());
				}
			}
		}
		else
			throw WrongGradeException((std::string)this->_name + " cannot be signed because there is a problem in the form");
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
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

Form::WrongGradeException::WrongGradeException(std::string error) : _error(error) {}

Form::GradeTooHighException::GradeTooHighException(std::string error) : _error(error) {}

Form::GradeTooLowException::GradeTooLowException(std::string error) : _error(error) {}

Form::WrongGradeException::WrongGradeException::~WrongGradeException() throw() {}

Form::GradeTooHighException::GradeTooHighException::~GradeTooHighException() throw() {}

Form::GradeTooLowException::GradeTooLowException::~GradeTooLowException() throw() {}