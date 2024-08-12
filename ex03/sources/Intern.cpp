/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-lang <mde-lang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 15:22:39 by mde-lang          #+#    #+#             */
/*   Updated: 2024/08/12 19:18:01 by mde-lang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Intern.hpp"

Intern::Intern() {}

Intern::~Intern() {}

Intern::Intern(Intern const &src)
{
	*this = src;
}

Intern &Intern::operator=(Intern const &rhs)
{
	(void)rhs;
	return *this;
}

AForm* Intern::makeForm(std::string form_name, std::string target)
{
	AForm* new_form_list[3] = {new ShrubberyCreationForm(target), new RobotomyRequestForm(target), new PresidentialPardonForm(target)};
	std::string new_form[3] = {"ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm"};
	int i = 0;
	while (i < 3)
	{
		if (form_name == new_form[i])
		{
			AForm *form = new_form_list[i];
			i = 0;
			while (i < 3)
			{
				if (new_form_list[i]->getName() != form_name)	
					delete new_form_list[i++];
				else
					i++;
			}
			std::cout << "Intern created " + form_name << std::endl << std::endl;
			return (form);
		}
		i++;
	}
	throw NoFormCreated((std::string)form_name + " does not exist, the intern cannot create it.");
}

Intern::NoFormCreated::NoFormCreated(std::string error) : _error(error) {}

Intern::NoFormCreated::NoFormCreated::~NoFormCreated() throw() {}