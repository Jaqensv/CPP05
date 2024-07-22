/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-lang <mde-lang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 13:11:42 by mde-lang          #+#    #+#             */
/*   Updated: 2024/07/22 18:23:45 by mde-lang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat crat("George Abitbol", 0);

	crat.downGrade();
	std::cout << std::endl;
	std::cout << crat.getName() << std::endl;
	std::cout << "grade : " << crat.getGrade() << std::endl;

	return 0;
}
