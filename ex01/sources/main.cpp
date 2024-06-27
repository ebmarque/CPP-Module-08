/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebmarque <ebmarque@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 11:44:14 by ebmarque          #+#    #+#             */
/*   Updated: 2024/06/27 16:09:02 by ebmarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Span.hpp"
#include <cmath>
#include <string>

/**
 * Logs a message with a specified color.
 *
 * @param message The message to log.
 * @param color The color code for the message.
 */
void LOG(const std::string &message, const std::string &color)
{
	std::cout << color << message << RESET << std::endl;
}

void test1(void)
{
	std::cout << GREEN << "--------- TEST 1: adding 1 MILION random numbers to Span ---------" << RESET << std::endl;

	Span sp(1000000);

	std::vector<int> numbersToAdd(1000000);
	std::generate(numbersToAdd.begin(), numbersToAdd.end(), rand);
	sp.addNumber(numbersToAdd.begin(), numbersToAdd.end());
	std::cout << BLUE << "\n\nShortest Span: "
			  << sp.shortestSpan()
			  << RESET << std::endl
			  << std::endl;

	std::cout << BLUE << "Longest Span: "
			  << sp.longestSpan()
			  << RESET << std::endl
			  << std::endl;
}
void test2(void)
{
	std::cout << GREEN << "--------- TEST 2: Trying to add to an empty span ---------" << RESET << std::endl;

	Span sp(0);

	std::vector<int> numbersToAdd(10);
	std::generate(numbersToAdd.begin(), numbersToAdd.end(), rand);
	try
	{
		sp.addNumber(numbersToAdd.begin(), numbersToAdd.end());
		std::cout << BLUE << "\n\nShortest Span: "
				<< sp.shortestSpan()
				<< RESET << std::endl
				<< std::endl;

		std::cout << BLUE << "Longest Span: "
				<< sp.longestSpan()
				<< RESET << std::endl
				<< std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << "EXCEPTION CAPTURED IN TEST2: " << RESET <<  e.what() << '\n';
	}
	
}

void test3(void)
{
	LOG("\n\n--------- TEST 3: Adding negative and positive numbers ---------", GREEN);
	Span sp(10);
	sp.addNumber(5);
	sp.addNumber(-5);
		
	std::cout << BLUE << "\n\nShortest Span: "
			  << sp.shortestSpan()
			  << RESET << std::endl
			  << std::endl;

	std::cout << BLUE << "Longest Span: "
			  << sp.longestSpan()
			  << RESET << std::endl
			  << std::endl;
}

void test4(void)
{
	LOG("\n\n--------- TEST 4: Adding numbers with the maximum integer range ---------", GREEN);
	Span sp(2);
	sp.addNumber(INT_MIN);
	sp.addNumber(INT_MAX);
	
	std::cout << BLUE << "\n\nShortest Span: "
			  << sp.shortestSpan()
			  << RESET << std::endl
			  << std::endl;

	std::cout << BLUE << "Longest Span: "
			  << sp.longestSpan()
			  << RESET << std::endl
			  << std::endl;
}

void test5(void)
{
	LOG("\n\n--------- TEST 5: Adding numbers and trying to exceed the Span size ---------", GREEN);
	try
	{
		Span sp(1);
		sp.addNumber(1);
		sp.addNumber(2); // This should throw an exception
	}
	catch (const std::exception &e)
	{
		LOG(e.what(), RED);
	}
}

void test6(void)
{
	LOG("\n\n--------- TEST 6: Adding a large range of numbers using addNumber with iterators ---------", GREEN);
	Span sp(10000);
	std::vector<int> largeRange(10000);
	for (int i = 0; i < 10000; i++)
		largeRange[i] = i;
	
	sp.addNumber(largeRange.begin(), largeRange.end());
	
	std::cout << BLUE << "\n\nShortest Span: "
			  << sp.shortestSpan()
			  << RESET << std::endl
			  << std::endl;

	std::cout << BLUE << "Longest Span: "
			  << sp.longestSpan()
			  << RESET << std::endl
			  << std::endl;
}

void test7(void)
{
	LOG("\n\n--------- TEST 7: Checking for shortest and longest span in a single-element Span ---------", GREEN);
	try
	{
		Span sp(1);
		sp.addNumber(42);
		sp.shortestSpan(); // This should throw an exception
	}
	catch (const std::exception &e)
	{
		LOG(e.what(), RED);
	}
	try
	{
		Span sp(1);
		sp.addNumber(42);
		sp.longestSpan(); // This should also throw an exception
	}
	catch (const std::exception &e)
	{
		LOG(e.what(), RED);
	}
}

void test8(void)
{
	LOG("\n\n--------- TEST 8: Adding numbers and checking spans after sorting ---------", GREEN);
	Span sp(6);
	sp.addNumber(5);
	sp.addNumber(1);
	sp.addNumber(8);
	sp.addNumber(3);
	sp.addNumber(200);
	sp.addNumber(201);
	

	std::cout << BLUE << "\n\nShortest Span: "
			  << sp.shortestSpan()
			  << RESET << std::endl
			  << std::endl;

	std::cout << BLUE << "Longest Span: "
			  << sp.longestSpan()
			  << RESET << std::endl
			  << std::endl;
}

void test9(void)
{
	LOG("\n\n--------- TEST 9: Attempting to add an out of range value ---------", GREEN);
	try
	{
		Span sp(1);
		sp.addNumber(static_cast<long long int>(INT_MAX) + 1); // This should throw an exception
	}
	catch (const std::exception &e)
	{
		LOG(e.what(), RED);
	}
}

void test10(void)
{
	LOG("\n\n--------- TEST 10: Filling Span with random numbers and finding spans ---------", GREEN);
	Span sp(100);
	for (int i = 0; i < 100; ++i)
	{
		sp.addNumber(std::rand() % 1000); // Add random numbers between 0 and 999
	}
	
	std::cout << BLUE << "\n\nShortest Span: "
			  << sp.shortestSpan()
			  << RESET << std::endl
			  << std::endl;

	std::cout << BLUE << "Longest Span: "
			  << sp.longestSpan()
			  << RESET << std::endl
			  << std::endl;
}

int main(void)
{
	srand(time(NULL));
	try
	{
		test1();
		std::cout << GREEN << "------------------------------------------------------------------" << RESET << std::endl;
		test2();
		std::cout << GREEN << "------------------------------------------------------------------" << RESET << std::endl;
		test3();
		std::cout << GREEN << "------------------------------------------------------------------" << RESET << std::endl;
		test4();
		std::cout << GREEN << "------------------------------------------------------------------" << RESET << std::endl;
		test5();
		std::cout << GREEN << "------------------------------------------------------------------" << RESET << std::endl;
		test6();
		std::cout << GREEN << "------------------------------------------------------------------" << RESET << std::endl;
		test7();
		std::cout << GREEN << "------------------------------------------------------------------" << RESET << std::endl;
		test8();
		std::cout << GREEN << "------------------------------------------------------------------" << RESET << std::endl;
		test9();
		std::cout << GREEN << "------------------------------------------------------------------" << RESET << std::endl;
		test10();
		std::cout << GREEN << "------------------------------------------------------------------" << RESET << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << RED << e.what() << RESET << '\n';
	}

	return (0);
}
