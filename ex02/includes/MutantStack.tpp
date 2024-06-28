/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebmarque <ebmarque@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 19:06:09 by ebmarque          #+#    #+#             */
/*   Updated: 2024/06/27 19:10:22 by ebmarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_TPP
# define MUTANTSTACK_TPP

#include "MutantStack.hpp"

static void	LOG(std::string msg, const char* color)
{
	std::cout << color << msg << RESET << std::endl;
}

template<typename T>
MutantStack<T>::MutantStack() : std::stack<T>()
{
	LOG("[MutantStack]: Object created.", GREEN);
	return ;
}

template<typename T>
MutantStack<T>::~MutantStack()
{
	LOG("[MutantStack]: Object deleted.", RED);
	return ;
}

template<typename T>
MutantStack<T>::MutantStack(const MutantStack<T> &other) : std::stack<T>()
{
	LOG("[MutantStack]: Copy constructor called.", RED);
	std::stack<T>::operator=(other);
}

template<typename T>
MutantStack<T> &MutantStack<T>::operator=(const MutantStack<T> &other)
{
	LOG("[MutantStack]: Copy assignment operator called.", RED);
	if (this != &other)
		std::stack<T>::operator=(other);
	return (*this);
}

/**
 * @brief Returns an iterator pointing to the first element of the MutantStack.
 * 
 * @tparam T The type of elements stored in the MutantStack.
 * @return typename std::stack<T>::container_type::iterator An iterator pointing to the first element of the MutantStack.
 */
template<typename T>
typename std::stack<T>::container_type::iterator MutantStack<T>::begin(void)
{
	return (std::stack<T>::c.begin());
}

/**
 * @brief Returns an iterator pointing to the end of the MutantStack.
 * 
 * @tparam T The type of elements stored in the MutantStack.
 * @return typename std::stack<T>::container_type::iterator An iterator pointing to the end of the MutantStack.
 */
template<typename T>
typename std::stack<T>::container_type::iterator MutantStack<T>::end(void)
{
	return (std::stack<T>::c.end());
}

/**
 * @brief Returns an iterator pointing to the first element in the MutantStack.
 * 
 * @tparam T The type of elements held in the MutantStack.
 * @return typename std::stack<T>::container_type::const_iterator An iterator pointing to the first element in the MutantStack.
 */
template<typename T>
typename std::stack<T>::container_type::const_iterator MutantStack<T>::begin(void) const
{
	return (std::stack<T>::c.begin());
}

/**
 * Returns an iterator pointing to the element following the last element of the MutantStack.
 *
 * @tparam T The type of elements stored in the MutantStack.
 * @return An iterator pointing to the element following the last element of the MutantStack.
 */
template<typename T>
typename std::stack<T>::container_type::const_iterator MutantStack<T>::end(void) const
{
	return (std::stack<T>::c.end());
}

#endif // MUTANTSTACK_TPP

