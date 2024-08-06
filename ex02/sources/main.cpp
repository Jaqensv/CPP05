/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-lang <mde-lang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 13:11:42 by mde-lang          #+#    #+#             */
/*   Updated: 2024/08/06 19:28:22 by mde-lang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
#include "../includes/Form.hpp"
#include "../includes/ShrubberyCreationForm.hpp"

int main()
{
	try
	{
		Bureaucrat crat("George Abitbol", 145);
		Bureaucrat cratos(crat);
		AForm* shrub = new ShrubberyCreationForm();
		//AForm f("A38", 2, 2);
		//crat.downGrade();
		//crat.upGrade();
		//shrub.beSigned(crat);
		//std::cout << crat << std::endl;
		//std::cout << f << std::endl;
		std::cout << cratos << std::endl;
		//std::cout << shrub->getName() << std::endl;
		shrub->beSigned(cratos);
		shrub->execute(cratos);
		delete shrub;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	return 0;
}
