/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-lang <mde-lang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 13:11:42 by mde-lang          #+#    #+#             */
/*   Updated: 2024/08/07 18:07:43 by mde-lang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
#include "../includes/Form.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"

int main()
{
	try
	{
		Bureaucrat crat("George Abitbol", 140);
		Bureaucrat cratos(crat);
		AForm* shrub = new ShrubberyCreationForm("Igor");
		AForm* robot = new RobotomyRequestForm("Bob");
		AForm* guilty = new PresidentialPardonForm("Greg");
		cratos.gradeModifier(+50);
		//std::cout << cratos << std::endl;
		shrub->beSigned(cratos);
		shrub->execute(cratos);
		robot->beSigned(cratos);
		robot->execute(cratos);
		guilty->beSigned(cratos);
		guilty->execute(cratos);
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
