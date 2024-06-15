/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebmarque <ebmarque@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 11:44:14 by ebmarque          #+#    #+#             */
/*   Updated: 2024/06/15 15:39:34 by ebmarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Span.hpp"
#include <cmath>


int	main(int argc, char *argv[], char *envp[])
{
	(void)argc;
	(void)argv;
	(void)envp;

	std::srand(time(NULL));
	Span lst_test(5000000);
	for (int i = 0; i < 5000000; i++)
	{
		lst_test.addNumber((rand() % 2000000) - 1000000);
	}

	std::cout << BLUE << "\n\nShortest Span: " 
			  << lst_test.shortestSpan() 
			  << RESET << std::endl << std::endl; 

	std::cout << BLUE << "Longest Span: " 
			  << lst_test.longestSpan() 
			  << RESET << std::endl << std::endl; 

	// lst_test.print();
	std::cout << "\r\r\r\r" << std::endl;
	return (0);
}



