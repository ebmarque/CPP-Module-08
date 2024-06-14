/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyFind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebmarque <ebmarque@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 20:27:13 by ebmarque          #+#    #+#             */
/*   Updated: 2024/06/14 22:15:06 by ebmarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <algorithm>
#include <iostream>
#include <exception>
#include <vector>
#include <string>
#include <list>


template<typename T>
typename T::iterator easyfind(T &container, int value)
{
	typename T::iterator element = std::find(container.begin(), container.end(), value);
	if (element != container.end())
		return (element);
	throw std::out_of_range("No such element exists in this container.");
}

#endif // EASYFIND_HPP