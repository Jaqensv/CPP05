/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-lang <mde-lang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 17:44:13 by mde-lang          #+#    #+#             */
/*   Updated: 2024/08/08 21:57:28 by mde-lang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45)
{
	AForm::formGradeChecker(this->getGts(), this->getGte());
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45)
{
	AForm::formGradeChecker(this->getGts(), this->getGte());
	this->_target = target;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &src) : AForm("RobotomyRequestForm", 72, 45)
{
	*this = src;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &rhs)
{
	if (this != &rhs)
		this->_target = rhs._target;
	return *this;
}

void RobotomyRequestForm::execution(Bureaucrat const &executor) const
{
	srand(time(0)); 
	if (executor.getGrade() > this->getGte())
		throw GradeTooLowException((std::string)_target + "'s grade is too low to execute the RobotomyRequestForm");
	if (rand() % 2 == 0)
		std::cout << "*Drilling noises* " << this->_target << " has been robotomized successfully" << std::endl;
	else
		std::cout << "*Drilling noises* " << "The robotomy failed" << std::endl;
}
