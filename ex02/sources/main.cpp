/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-lang <mde-lang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 13:11:42 by mde-lang          #+#    #+#             */
/*   Updated: 2024/08/01 17:22:56 by mde-lang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
#include "../includes/Form.hpp"
#include "../includes/ShrubberyCreationForm.hpp"

int main()
{
	try
	{
		std::cout << std::endl;

		Bureaucrat crat("George Abitbol", 150);
		Bureaucrat cratos(crat);
		AForm* shrub = new ShrubberyCreationForm();
		//AForm f("A38", 2, 2);
		//crat.downGrade();
		//crat.upGrade();
		//shrub.beSigned(crat);
		//std::cout << crat << std::endl;
		//std::cout << f << std::endl;
		//std::cout << cratos << std::endl;
		//std::cout << shrub->getName() << std::endl;
		//shrub->execute(cratos);
		delete shrub;
	}
	catch (std::exception &e)
	{
		std::cout << "test" << std::endl;
		std::cout << e.what() << std::endl;
	}

	return 0;
}
