# cpp-module-08

## Overview

The cpp-module-08 project from School 42 focuses on templated containers, iterators, and algorithms in C++. This module provides an in-depth look at these advanced features, their syntax, and their practical applications in C++ programming.


![Data Structures](DataStructures.png)

## Table of Contents

- [cpp-module-08](#cpp-module-08)
	- [Overview](#overview)
	- [Table of Contents](#table-of-contents)
	- [Introduction to Templated Containers](#introduction-to-templated-containers)
		- [Key Concepts](#key-concepts)
	- [Vector](#vector)
		- [Syntax](#syntax)
		- [Benefits](#benefits)
	- [List](#list)
		- [Syntax](#syntax-1)
		- [Benefits](#benefits-1)
	- [Map](#map)
		- [Benefits](#benefits-2)
	- [Set](#set)
		- [Benefits](#benefits-3)
	- [Iterators](#iterators)
		- [Example: Iterating through a Vector](#example-iterating-through-a-vector)
	- [Algorithms](#algorithms)
		- [Example: Sorting a Vector](#example-sorting-a-vector)
		- [Example: Finding an Element in a List](#example-finding-an-element-in-a-list)
		- [Example: Using std::map with Algorithms](#example-using-stdmap-with-algorithms)
	- [Resources](#resources)
	- [Conclusion](#conclusion)

## Introduction to Templated Containers

Templated containers in C++ are generic classes that store collections of objects. The Standard Template Library (STL) provides a rich set of templated containers such as vector, list, map, and set.

### Key Concepts

- **Containers**: Data structures that store objects.
- **Generic Types**: Containers can store any data type.
- **STL Containers**: Standardized and highly optimized containers provided by the C++ Standard Library.

## Vector

Vectors are dynamic arrays that can resize automatically when new elements are added.

### Syntax

```cpp
#include <vector>
#include <iostream>

int main() {
    std::vector<int> vec = {1, 2, 3, 4, 5};
    for (int i : vec) {
        std::cout << i << " ";
    }
    return 0;
}
```

### Benefits

   - Dynamic Sizing: Automatically resizes as elements are added or removed.
   - Random Access: Provides constant time access to elements.
   - Memory Efficiency: Typically uses contiguous memory storage.

## List

Lists are doubly linked lists that allow efficient insertion and deletion of elements.

### Syntax

```cpp
#include <list>
#include <iostream>

int main() {
    std::list<int> lst = {1, 2, 3, 4, 5};
    for (int i : lst) {
        std::cout << i << " ";
    }
    return 0;
}
```

### Benefits

   - Efficient Insertions/Deletions: Provides constant time insertions and deletions at both ends.
   - Bidirectional Iteration: Supports traversal in both directions.
   - Non-Contiguous Memory: Stores elements in non-contiguous memory locations, reducing overhead from reallocations.

## Map

Maps are associative containers that store key-value pairs, with unique keys.
Syntax

```cpp
#include <map>
#include <iostream>

int main() {
    std::map<int, std::string> mp = {{1, "one"}, {2, "two"}, {3, "three"}};
    for (const auto& [key, value] : mp) {
        std::cout << key << ": " << value << " ";
    }
    return 0;
}
```

### Benefits

   - Key-Value Storage: Allows fast retrieval based on keys.
   - Ordered: Elements are stored in sorted order by key.
   - Efficient Lookup: Provides logarithmic time complexity for search, insertion, and deletion.

## Set

Sets are containers that store unique elements in a specific order.
Syntax

```cpp
#include <set>
#include <iostream>

int main() {
    std::set<int> st = {1, 2, 3, 4, 5};
    for (int i : st) {
        std::cout << i << " ";
    }
    return 0;
}
```

### Benefits

  - Unique Elements: Automatically ensures all elements are unique.
  - Ordered: Elements are stored in a specific order.
  - Efficient Lookup: Provides logarithmic time complexity for search, insertion, and deletion.

## Iterators

Iterators are objects that allow traversing through the elements of a container. They provide a common interface for different types of containers.
Key Concepts

  - Traversal: Access elements of a container sequentially.
  - Types of Iterators: Input, output, forward, bidirectional, and random access iterators.
  - Iterator Functions: begin(), end(), rbegin(), rend(), etc.

### Example: Iterating through a Vector

```cpp
#include <vector>
#include <iostream>

int main() {
    std::vector<int> vec = {1, 2, 3, 4, 5};
    for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it) {
        std::cout << *it << " ";
    }
    return 0;
}
```

## Algorithms

Algorithms in C++ are a set of functions provided by the STL that perform operations on containers. They are generic and work with any container type.
Key Concepts

  -  Algorithm Functions: Sort, search, modify, and manipulate container elements.
  -  Generic Algorithms: Operate on any container type that supports the necessary operations.
  -  Efficiency: Highly optimized for performance.

### Example: Sorting a Vector

```cpp
#include <vector>
#include <algorithm>
#include <iostream>

int main() {
    std::vector<int> vec = {5, 3, 1, 4, 2};
    std::sort(vec.begin(), vec.end());
    for (int i : vec) {
        std::cout << i << " ";
    }
    return 0;
}
```

### Example: Finding an Element in a List

```cpp
#include <list>
#include <algorithm>
#include <iostream>

int main() {
    std::list<int> lst = {1, 2, 3, 4, 5};
    auto it = std::find(lst.begin(), lst.end(), 3);
    if (it != lst.end()) {
        std::cout << "Element found: " << *it << std::endl;
    } else {
        std::cout << "Element not found" << std::endl;
    }
    return 0;
}
```

### Example: Using std::map with Algorithms

While algorithms do not directly work with associative containers like std::map due to their unique structure, they can still be used with the help of iterators. For instance, one can copy the keys or values to a vector and then apply algorithms.

```cpp
#include <map>
#include <vector>
#include <algorithm>
#include <iostream>

int main() {
    std::map<int, std::string> mp = {{1, "one"}, {2, "two"}, {3, "three"}};
    std::vector<int> keys;

    for (const auto& [key, value] : mp) {
        keys.push_back(key);
    }

    std::sort(keys.begin(), keys.end());

    for (int key : keys) {
        std::cout << key << " ";
    }
    return 0;
}
```

## Resources

   - C++ Documentation
   - Effective STL by Scott Meyers
   - The C++ Standard Library: A Tutorial and Reference by Nicolai M. Josuttis

## Conclusion

Templated containers, iterators, and algorithms are fundamental components of modern C++ programming. Mastering these features enhances the ability to write efficient and generic code that can handle a wide variety of tasks and data structures*.