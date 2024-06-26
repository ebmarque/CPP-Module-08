/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebmarque <ebmarque@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 19:50:47 by ebmarque          #+#    #+#             */
/*   Updated: 2024/06/26 14:18:35 by ebmarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/MutantStack.hpp"
#include <list>

int main()
{
	// Create a MutantStack of integers
	MutantStack<int> mStack;

	// Push elements onto the stack
	for (int i = 1; i <= 10; ++i)
	{
		mStack.push(i * 10);
		std::cout << "Pushed " << i * 10 << " onto the stack.\n";
	}

	// Access the top element
	std::cout << "Top element of the stack: " << mStack.top() << "\n";

	// Size of the stack
	std::cout << "Size of the stack: " << mStack.size() << "\n";

	// Pop an element
	mStack.pop();
	std::cout << "Popped the top element. New top: " << mStack.top() << "\n";

	// Use the iterator to print all elements
	std::cout << "All elements in the stack from bottom to top: ";
	for (MutantStack<int>::iterator it = mStack.begin(); it != mStack.end(); ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << "\n";

	// Copy the stack
	MutantStack<int> mStackCopy = mStack;
	std::cout << "Copied the stack. Top element of the copied stack: " << mStackCopy.top() << "\n";

	// Compare the top elements of the original and copied stacks
	if (mStack.top() == mStackCopy.top())
	{
		std::cout << "Top elements of the original and copied stacks are equal.\n";
	}
	else
	{
		std::cout << "Top elements of the original and copied stacks are not equal.\n";
	}

	std::cout << "/ ***** MutantStack ***** /" << std::endl;

	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);

	std::cout << mstack.top() << std::endl;

	mstack.pop();
	std::cout << mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;

	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);

	/* -------------------------------------------------------------------- */

	std::cout << std::endl;
	std::cout << "/ ***** List ***** /" << std::endl;

	std::list<int> lst;

	lst.push_back(5);
	lst.push_back(17);

	std::cout << lst.back() << std::endl;

	lst.pop_back();
	std::cout << lst.size() << std::endl;

	lst.push_back(3);
	lst.push_back(5);
	lst.push_back(737);
	//[...]
	lst.push_back(0);

	std::list<int>::iterator lst_it = lst.begin();
	std::list<int>::iterator lst_ite = lst.end();
	++it;
	--it;
	while (lst_it != lst_ite)
	{
		std::cout << *lst_it << std::endl;
		++lst_it;
	}
	std::list<int> l(lst);
	return (0);
}