/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebmarque <ebmarque@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 13:21:39 by ebmarque          #+#    #+#             */
/*   Updated: 2024/06/15 18:22:17 by ebmarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Span.hpp"

void LOG(std::string txt, const char *color)
{
	std::cout << color << txt << RESET << std::endl;
};

void Span::print(void) 
{
	std::cout << YELLOW << "[SPAN]: Print method called, elements present in the sore:" 
			  << RESET << std::endl;
	typedef std::list<int>::const_iterator lst_it;
	for (lst_it it = store.begin(); it != store.end(); it++)
	{
		std::cout << CYAN << *it << RESET << std::endl;
	}
}

Span::Span() 
{
	LOG("[SPAN]: Default constructor called.", GREEN);
}

Span::Span(unsigned int _size) : size(_size) 
{
	LOG("[SPAN]: Default constructor called.", GREEN);
}

Span::Span(const Span& other)  : store(other.store)
{
	LOG("[SPAN]: Copy constructor called.", BLUE);
	this->size = other.size;
}

Span& Span::operator=(const Span& other) 
{
	if (this != &other) 
	{
		LOG("[SPAN]: Copy assignment operator called.", BLUE);
		this->size = other.size;
		this->store = other.store;
	}
	return (*this);
}

Span::~Span() 
{
	LOG("[SPAN]: Object deleted.", RED);
}

void Span::addNumber(long long int value) 
{
	if (value < INT_MIN || value > INT_MAX)
		throw std::out_of_range("Element value is out of Integer limits.");
	if (this->size > this->store.size())
	{
		// std::cout << YELLOW << "[SPAN]: " << value << " ADDED." << std::string(10, char(256)) << "\r" << RESET;
		this->store.push_back(value);
	}
	else
		throw std::out_of_range("No space left in the container.");
}

int Span::shortestSpan(void) 
{
	if (this->store.size() < 2)
		throw std::out_of_range("No Span: not enough elements.");
	
	this->store.sort();
	typedef std::list<int>::const_iterator lst_it;
	lst_it it = store.begin();
	int	lowest = *it;
	it++;
	int	next_lowest = *it;
	return (next_lowest - lowest);
}

int Span::longestSpan(void) 
{
	if (this->store.size() < 2)
		throw std::out_of_range("No Span: not enough elements.");
	
	this->store.sort();
	typedef std::list<int>::const_iterator lst_it;
	lst_it it = store.begin();
	int	lowest = *it;
	it = store.end();
	it--;
	int	biggest = *it;
	return (biggest - lowest);
}