/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebmarque <ebmarque@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 11:44:14 by ebmarque          #+#    #+#             */
/*   Updated: 2024/06/16 16:22:55 by ebmarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Span.hpp"
#include <cmath>

void	test1(void)
{
		std::cout << GREEN << "--------- TEST 1: adding 1 MILION random numbers to Span ---------" << RESET << std::endl;

		int containerSize = 1000000;
		Span lst_test(containerSize);

		std::vector<int> numbersToAdd(100);
		std::generate(numbersToAdd.begin(), numbersToAdd.end(), rand);
		lst_test.addNumber(numbersToAdd.begin(), numbersToAdd.end());
		std::cout << BLUE << "\n\nShortest Span: " 
				<< lst_test.shortestSpan() 
				<< RESET << std::endl << std::endl; 

		std::cout << BLUE << "Longest Span: " 
				<< lst_test.longestSpan() 
				<< RESET << std::endl << std::endl; 
		lst_test.print();
		// std::cout << GREEN << "------------------------------------------------------------------" << RESET << std::endl;
}
void	test2(void)
{
		std::cout << GREEN << "--------- TEST 2: Trying to add to a full span ---------" << RESET << std::endl;

		int containerSize = 0;
		Span lst_test(containerSize);

		std::vector<int> numbersToAdd(100);
		std::generate(numbersToAdd.begin(), numbersToAdd.end(), rand);
		lst_test.addNumber(numbersToAdd.begin(), numbersToAdd.end());
		std::cout << BLUE << "\n\nShortest Span: " 
				<< lst_test.shortestSpan() 
				<< RESET << std::endl << std::endl; 

		std::cout << BLUE << "Longest Span: " 
				<< lst_test.longestSpan() 
				<< RESET << std::endl << std::endl; 
		lst_test.print();
		// std::cout << GREEN << "------------------------------------------------------------------" << RESET << std::endl;
}


int	main(void)
{

	std::srand(time(NULL));

	try
	{
		test1();
		std::cout << GREEN << "------------------------------------------------------------------" << RESET << std::endl;
		test2();
		std::cout << GREEN << "------------------------------------------------------------------" << RESET << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	return (0);
}


