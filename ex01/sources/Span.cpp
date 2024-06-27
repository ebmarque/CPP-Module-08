/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebmarque <ebmarque@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 13:21:39 by ebmarque          #+#    #+#             */
/*   Updated: 2024/06/27 16:08:14 by ebmarque         ###   ########.fr       */
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

Span::Span(const Span &other) : store(other.store)
{
	LOG("[SPAN]: Copy constructor called.", BLUE);
	this->size = other.size;
}

Span &Span::operator=(const Span &other)
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
		this->store.push_back(value);
	else
		throw std::out_of_range("No space left in the container.");
}

void Span::addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	// std::cout << "TAMANHO DO VETOR DE ELEMENTOS: " << std::distance(begin, end) << std::endl;
	if (static_cast<size_t>(this->store.size() + std::distance(begin, end)) <= this->size)
		this->store.insert(this->store.end(), begin, end);
	else
		throw std::out_of_range("No space left in the container.");
}

unsigned int Span::shortestSpan(void)
{
	if (this->store.size() < 2)
		throw std::out_of_range("No Span: not enough elements.");

	this->store.sort();
	typedef std::list<int>::const_iterator lst_it;
	// lst_it next = store.begin();
	// next++;
	unsigned int shortest = UINT_MAX;
	for (lst_it previous = store.begin(), next = ++(store.begin()); next != store.end(); previous++, next++)
	{
		unsigned int diff = *next - *previous;
		if (diff < shortest)
			shortest = diff;
	}

	return (shortest);
}

unsigned int Span::longestSpan(void)
{
	if (this->store.size() < 2)
		throw std::out_of_range("No Span: not enough elements.");

	this->store.sort();
	typedef std::list<int>::const_iterator lst_it;
	lst_it it = store.begin();
	int lowest = *it;
	it = store.end();
	it--;
	int biggest = *it;
	return (biggest - lowest);
}