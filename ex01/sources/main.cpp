/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-lang <mde-lang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 13:11:42 by mde-lang          #+#    #+#             */
/*   Updated: 2024/07/26 17:24:20 by mde-lang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
#include "../includes/Form.hpp"

int main()
{
	std::cout << std::endl;

	Bureaucrat crat("George Abitbol", 2);
	Form f("A38", 1, 2);
	//crat.downGrade();
	crat.upGrade();
	f.beSigned(crat);
	std::cout << std::endl;
	std::cout << crat << std::endl;
	std::cout << f << std::endl;

	return 0;
}
