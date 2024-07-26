/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-lang <mde-lang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 13:11:42 by mde-lang          #+#    #+#             */
/*   Updated: 2024/07/26 16:53:12 by mde-lang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
#include "../includes/Form.hpp"

int main()
{
	std::cout << std::endl;
	try
	{
		Bureaucrat crat("George Abitbol", 5);
		Form f("A38", 5, 2);
		crat.downGrade();
		//crat.upGrade();
		f.beSigned(crat);
		std::cout << std::endl;
		std::cout << crat << std::endl;
		std::cout << f << std::endl;
		crat.signForm(f);
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	

	return 0;
}
