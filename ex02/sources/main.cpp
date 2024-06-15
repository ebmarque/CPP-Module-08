/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebmarque <ebmarque@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 19:50:47 by ebmarque          #+#    #+#             */
/*   Updated: 2024/06/15 19:53:25 by ebmarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/MutantStack.hpp"

int main()
{
	// Create a MutantStack of integers
	MutantStack<int> mStack;

	std::cout << "MutantStack of integers has been created.\n";

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

	return 0;
}