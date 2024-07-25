/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-lang <mde-lang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 13:11:42 by mde-lang          #+#    #+#             */
/*   Updated: 2024/07/25 16:07:48 by mde-lang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	try
	{
		Bureaucrat crat("George Abitbol", 1);
		Form f("A38", 0, 2);
		//crat.downGrade();
		crat.upGrade();
		f.beSigned(crat);
	}
	catch(const std::exception &e) // a check
	{
		std::cerr << e.what() << std::endl;
		//return 1;
	}
	std::cout << std::endl;
	std::cout << crat << std::endl;
	std::cout << f << std::endl;
	crat.signForm(f);

	return 0;
}
