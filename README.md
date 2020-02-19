# ArrayList Class - List ADT implemented with dynamic array


You are given an implementation of the integer list ADT using dynamic array and a client. S

Your task is to complete the implementation of the following member functions for the `ArrayList` class:

1. **void elimOdds()**: removes the odd integers from the list. For example if L contains  `(5, 23, 10, 17, 8)`, after calling `L.elimOdds()` the content of L will be `(10, 8)`. Your algorithm should be worst case *O(n)* where *n* is the length of the list. Honor points if you can design an *in-place* algorithm.

2. **void reverse()**: reverses the list **in place**. For example if `L` contains  `(1, 2, 3, 4)`,  calling `L.reverse()` will change the list to `(4, 3, 2, 1)`. Your algorithm should be **in-place**. It should be *O(n)* in the worst case.

3. **int mode() const**: returns the *mode* of the list, i.e. the most repeated element. You may assume that the list contains only positive numbers in the range of 1 to 1000. If there is no mode, the member function will return -1. Your algorithm should be *O(n)* in the worst case.

   Examples:

   1. If the list `L` contains `(1, 2, 1, 1)`, `L.mode()` will return `1`.
   1. If the list `L` contains `(1, 2, 2, 1)`, `L.mode()` will return `-1` because the list has no mode, i.e. there are two or more numbers that repeat the same number of times.
   1. If the list `L` contains `(33,22,44)`, `L.mode()` will return `-1` because the list has no mode, i.e. there are two or more numbers that repeat the same number of times.

The `main.cpp` contains tests for all functions, including the ones that are already implemented. Please do not change the tests. Just implement correctly the required member functions.


Please include the name of the programmers at the beginning of the file. Also provide comments before each of the functions.  You should follow good programming practices such as:

* good variable names
* appropriate indentation
* modularity
* readability