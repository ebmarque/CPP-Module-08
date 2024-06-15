/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebmarque <ebmarque@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 11:44:14 by ebmarque          #+#    #+#             */
/*   Updated: 2024/06/15 18:21:59 by ebmarque         ###   ########.fr       */
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


	try
	{
		int containerSize = 1000000;
		// std::cout << "Enter the size of the container: ";
		// std::cin >> containerSize;

		Span lst_test(containerSize);

		int min_nbr = -432343;
		// std::cout << "Enter the minimum number (min_nbr): ";
		// std::cin >> min_nbr;

		int max_nbr = 1234341;
		// std::cout << "Enter the maximum number (max_nbr): ";
		// std::cin >> max_nbr;
		max_nbr += std::abs(min_nbr) + 1;
		int numElements = 1000000;
		// std::cout << "Enter the number of elements to insert: ";
		// std::cin >> numElements;
		
		for (int i = 0; i < numElements; i++)
		{
			lst_test.addNumber(min_nbr + (rand() % max_nbr));
		}

		std::cout << BLUE << "\n\nShortest Span: " 
				<< lst_test.shortestSpan() 
				<< RESET << std::endl << std::endl; 

		std::cout << BLUE << "Longest Span: " 
				<< lst_test.longestSpan() 
				<< RESET << std::endl << std::endl; 
		
		std::cout << GREEN << "---------------------------------------------" << RESET << std::endl;
		// lst_test.print();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}	

	return (0);
}


