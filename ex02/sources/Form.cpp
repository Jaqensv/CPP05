/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-lang <mde-lang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 17:54:39 by mde-lang          #+#    #+#             */
/*   Updated: 2024/07/29 12:18:23 by mde-lang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Form.hpp"

AForm::AForm() : _gts(150), _gte(150)
{
	this->_signed = false;
}

AForm::~AForm() {}

AForm::AForm(const std::string name, const int gts, const int gte) : _name(name), _gts(gts), _gte(gte)
{
	this->_signed = false;
	this->_signable = true;
	formGradeChecker(gts, gte);
}

AForm::AForm(AForm const &src) : _name(src._name), _signed(src._signed), _gts(src._gts), _gte(src._gte), _reason(src._reason)
{
	*this = src;
}

AForm &AForm::operator=(AForm const &rhs)
{
	if (this != &rhs)
	{
		this->_signed = rhs._signed;
		this->_reason = rhs._reason;
	}
	return *this;	
}

const std::string AForm::getName() const
{
	return this->_name;
}

bool AForm::getSigned() const
{
	return this->_signed;
}

bool AForm::getSignable() const
{
	return this->_signable;
}

bool AForm::signProcess(bool iss)
{
	this->_signed = iss;
	return this->_signed;
}

std::string AForm::reasonModifier(std::string reason)
{
	this->_reason = reason;
	return this->_reason;
}

int AForm::getGts() const
{
	return this->_gts;
}

int AForm::getGte() const
{
	return this->_gte;
}

std::string AForm::getReason() const
{
	return this->_reason;
}

std::string AForm::getTarget() const
{
	return this->_target;
}

void AForm::formGradeChecker(const int gts, const int gte)
{
	if ((gts < 1 || gte < 1) && this->_form_err == false)
	{
		this->_form_err = true;
		this->_signable = false;
		_reason = this->_target + " has a too high grade.";
		throw GradeTooHighException((std::string)this->_target + " has a too high grade");
	}
	else if ((gts > 150 || gte > 150) && this->_form_err == false)
	{
		this->_form_err = true;
		this->_signable = false;
		_reason = this->_target + " has a too low grade.";
		throw GradeTooLowException((std::string)this->_target + " has a too low grade");
	}
}
void AForm::beSigned(Bureaucrat &bureaucrat)
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

int AForm::execute(Bureaucrat const &executor) const
{
	try
	{
		if (this->getSigned() == true)
			execution(executor);
		else
		{
			std::cout << (std::string)this->getName() + " cannot be executed because it is not signed" << std::endl;
			return 1;
		}
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
		return 1;
	}
	return 0;
}

std::ostream &operator<<(std::ostream &o, AForm const &rhs) 
{
	std::string is_signed;

	if (rhs.getSigned() == true)
		is_signed = "signed";
	else
		is_signed = "unsigned";
	return (o << "Form " << rhs.getName() << ", with a needed grade to sign of " << rhs.getGts() << " and a needed grade to execute of " << rhs.getGte() << " is " << is_signed << "." << std::endl);
}

void AForm::monitor(Bureaucrat &executor, AForm &form) const
{
	try
	{
		form.beSigned(executor);
		form.execute(executor);
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}

AForm::WrongGradeException::WrongGradeException(std::string error) : _error(error) {}

AForm::GradeTooHighException::GradeTooHighException(std::string error) : _error(error) {}

AForm::GradeTooLowException::GradeTooLowException(std::string error) : _error(error) {}

AForm::WrongGradeException::WrongGradeException::~WrongGradeException() throw() {}

AForm::GradeTooHighException::GradeTooHighException::~GradeTooHighException() throw() {}

AForm::GradeTooLowException::GradeTooLowException::~GradeTooLowException() throw() {}