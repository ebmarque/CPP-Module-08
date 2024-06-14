/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebmarque <ebmarque@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 21:54:59 by ebmarque          #+#    #+#             */
/*   Updated: 2024/06/14 22:20:28 by ebmarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/easyFind.hpp"
#include <deque>
#include <set>

template <typename T>
void	runTest(T &container, int value, const std::string &testName)
{
	std::cout << "\033[1;34mRunning test: " << testName << "\033[0m\n";
	try
	{
		typename T::iterator it = easyfind(container, value);
		std::cout << "\033[1;32mSuccess: Found " << *it << " in container.\033[0m\n";
	}
	catch (const std::exception &e)
	{
		std::cout << "\033[1;31mFailure: " << e.what() << "\033[0m\n";
	}
	std::cout << "\n";
}

int	main(void)
{
	std::vector<int> vec;
	std::list<int> lst;
	std::deque<int> deq;
	std::set<int> set;

	for (int i = 1; i <= 10; ++i)
	{
		vec.push_back(i);
		lst.push_back(i);
		deq.push_back(i);
		set.insert(i);
	}

	runTest(vec, 5, "Vector, value exists");
	runTest(vec, 15, "Vector, value does not exist");
	runTest(lst, 5, "List, value exists");
	runTest(lst, 15, "List, value does not exist");
	runTest(deq, 5, "Deque, value exists");
	runTest(deq, 15, "Deque, value does not exist");
	runTest(set, 5, "Set, value exists");
	runTest(set, 15, "Set, value does not exist");

	return (0);
}
