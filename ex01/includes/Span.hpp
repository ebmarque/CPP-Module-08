/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebmarque <ebmarque@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 11:47:21 by ebmarque          #+#    #+#             */
/*   Updated: 2024/06/16 15:47:35 by ebmarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define CYAN    "\033[36m"

#include <iostream>
#include <algorithm>
#include <exception>
#include <list>
#include <limits.h>
#include <vector>

class Span
{
	private:
	std::list<int> 	store;
	unsigned int	size;
	
	public:

		void	print(void);	
		void	addNumber(long long int value);
		void	addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end);
		int 	shortestSpan(void);
		int 	longestSpan(void);
		
		
		Span();
		Span(unsigned int _size);
		Span(const Span& other);
		Span& operator=(const Span& other);
		~Span();
};


#endif // SPAN_HPP