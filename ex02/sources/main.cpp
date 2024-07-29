/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-lang <mde-lang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 13:11:42 by mde-lang          #+#    #+#             */
/*   Updated: 2024/07/29 16:40:32 by mde-lang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
#include "../includes/Form.hpp"

int main()
{
	std::cout << std::endl;

	Bureaucrat crat("George Abitbol", 2);
	//AForm f("A38", 2, 2);
	Bureaucrat cratos(crat);
	//crat.downGrade();
	//crat.upGrade();
	f.beSigned(crat);
	std::cout << std::endl;
	std::cout << crat << std::endl;
	std::cout << f << std::endl;
	std::cout << cratos << std::endl;

	return 0;
}
