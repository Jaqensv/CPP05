/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-lang <mde-lang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 13:11:42 by mde-lang          #+#    #+#             */
/*   Updated: 2024/08/12 19:18:14 by mde-lang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
#include "../includes/Form.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/Intern.hpp"

int main(int argc, char **argv)
{
	if (argc != 5)
	{
		std::cout << "NAME, GRADE, GRADE MODIFIER, FORM NAME" << std::endl;
		return 0;
	}
	const std::string name = argv[1];
	int grade = atoi(argv[2]);
	int grade_modifier = atoi(argv[3]);
	const std::string form_name = argv[4];
	try
	{
		Bureaucrat crat(name, grade);
		Intern* intern = NULL;
		AForm* form = intern->makeForm(form_name, name);
		crat.gradeModifier(grade_modifier);
		std::cout << crat << std::endl;
		std::cout << std::endl;
		form->beSigned(crat);
		crat.executeForm(*form);
		delete form;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	return 0;
}
