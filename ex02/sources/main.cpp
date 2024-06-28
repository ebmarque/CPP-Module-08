/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebmarque <ebmarque@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 18:55:02 by ebmarque          #+#    #+#             */
/*   Updated: 2024/06/28 11:11:16 by ebmarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/MutantStack.hpp"
#include <iostream>
#include <list>
#include <stack>
#define GREEN "\033[32m"
#define RESET "\033[0m"

void testList()
{
	std::cout << GREEN << "\n\nTEST 1: USING STD::LIST" << RESET << std::endl;
	std::list<int> mlist;
	mlist.push_back(5);
	mlist.push_back(17);
	mlist.push_back(3);
	mlist.push_back(5);
	mlist.push_back(737);
	mlist.push_back(0);
	for (std::list<int>::iterator it = mlist.begin(); it != mlist.end(); ++it)
	{
		std::cout << "List element: " << *it << std::endl;
	}
	std::cout << "List size after additions: " << mlist.size() << std::endl;
}

void testMutantStack()
{
	std::cout << GREEN << "\n\nTEST 2: USING MUTANTSTACK" << RESET << std::endl;
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << "Top element after pushes: " << mstack.top() << std::endl;
	mstack.pop();
	std::cout << "Size after pop: " << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
}

void enhancedTestListAndMutantStack()
{
	std::cout << GREEN << "\n\nENHANCED TEST FOR STD::LIST AND MUTANTSTACK"
			  << RESET << std::endl;
	std::list<int> lst;
	lst.push_back(42);
	lst.push_back(21);
	lst.pop_back();
	std::cout << YELLOW << "\n\nTesting std::list - Size after pop_back: "
			  << lst.size() << RESET << std::endl;
	MutantStack<int> mstack;
	mstack.push(42);
	mstack.push(21);
	mstack.pop();
	std::cout << YELLOW << "\n\nTesting MutantStack - Size after pop: "
			  << mstack.size() << RESET << std::endl;
	MutantStack<int> copiedStack(mstack);
	MutantStack<int> assignedStack;
	assignedStack = mstack;
	std::cout << YELLOW << "\n\nTesting Copy and Assignment - Sizes: Copied: "
			  << copiedStack.size() << ", Assigned: "
			  << assignedStack.size() << RESET << std::endl;
}

void testIterators()
{
	std::list<int> lst;
	lst.push_back(5);
	lst.push_back(17);
	lst.push_back(3);
	lst.push_back(5);
	lst.push_back(737);
	lst.push_back(0);
	std::cout << GREEN << "\n\nIterating through std::list" << RESET << std::endl;
	for (std::list<int>::iterator it = lst.begin(); it != lst.end(); ++it)
	{
		std::cout << "List element: " << *it << std::endl;
	}

	std::cout << GREEN << "\n\nIterating through MutantStack" << RESET << std::endl;
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it)
	{
		std::cout << "Stack element: " << *it << std::endl;
	}
}

int main()
{
	enhancedTestListAndMutantStack();
	testMutantStack();
	testIterators();
	return 0;
}