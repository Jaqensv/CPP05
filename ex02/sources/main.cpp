/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-lang <mde-lang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 13:11:42 by mde-lang          #+#    #+#             */
/*   Updated: 2024/08/08 22:27:02 by mde-lang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
#include "../includes/Form.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << "NAME, GRADE, GRADE MODIFIER" << std::endl;
		return 0;
	}
	const std::string name = argv[1];
	int grade = atoi(argv[2]);
	int grade_modifier = atoi(argv[3]);
	try
	{
		Bureaucrat crat(name, grade);
		AForm* shrub = new ShrubberyCreationForm(name);
		AForm* robot = new RobotomyRequestForm(name);
		AForm* guilty = new PresidentialPardonForm(name);
		crat.gradeModifier(grade_modifier);
		std::cout << crat << std::endl;
		shrub->beSigned(crat);
		crat.executeForm(*shrub);
		std::cout << std::endl;
		robot->beSigned(crat);
		crat.executeForm(*robot);
		std::cout << std::endl;
		guilty->beSigned(crat);
		crat.executeForm(*guilty);
		delete shrub;
		delete robot;
		delete guilty;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	return 0;
}
