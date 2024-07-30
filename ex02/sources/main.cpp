/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-lang <mde-lang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 13:11:42 by mde-lang          #+#    #+#             */
/*   Updated: 2024/07/30 17:08:39 by mde-lang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
#include "../includes/Form.hpp"
#include "../includes/ShrubberyCreationForm.hpp"

int main()
{
	std::cout << std::endl;

	Bureaucrat crat("George Abitbol", 1);
	//AForm f("A38", 2, 2);
	Bureaucrat cratos(crat);
	AForm* shrub = new ShrubberyCreationForm();
	//crat.downGrade();
	//crat.upGrade();
	//f.beSigned(crat);
	//std::cout << crat << std::endl;
	//std::cout << f << std::endl;
	std::cout << cratos << std::endl;
	//std::cout << shrub->getName() << std::endl;
	shrub->execute(cratos);



	return 0;
}
