# OOP-Assignment2-MoizAhmed-i235508
Overview

This repository contains five C++ programs implementing key data structures and algorithmic concepts.
Each question focuses on a different structure — recursion, linked lists, stacks, queues, and algorithm analysis — designed around real-world simulation scenarios.

All programs are written with:

No camel casing

No comments inside the code (for simplicity)

Use of only <iostream>

Clean, minimal logic and output clarity

 Question 1 – Recursion: Change Location in Char Array

File: q1_changelocation.cpp

Concept

This program demonstrates recursion by reversing a portion of a character array between two given indices.

Example

Input array:
C O M P U T E R
Boundaries: 3 and 7

Output array:
C O E P U T M R

Explanation

The recursive function:

Swaps the elements at the boundary indices.

Moves inward until both pointers cross.
This simulates recursive reversal of part of an array.

 Question 1(b) – Recursive Number Partition Pattern

File: q1b_pattern.cpp

Concept

A recursive function that prints all possible integer partitions of a number (ways to sum up to it).

Example

For n = 4, output is:

4
3 1
2 2
2 1 1
1 1 1 1

Explanation

At each step:

Choose a number ≤ remaining sum.

Subtract it and recurse.
When the remainder is 0, print the current combination.

 Question 2 – Singly Linked List (NASA Geospatial Features)

File: q2_singlylinkedlist.cpp

Concept

Implements a singly linked list to store land and water features captured by satellites.

Features

Feature base class (abstract)

LandFeature and WaterFeature derived classes

SinglyLinkedList class with:

insertAtEnd

deleteByID

displayAll

reverseList

Simulation

Adds, deletes, and reverses features (e.g., forests, rivers, lakes) while calling analyze() for each feature.

 Question 3 – Doubly Linked List (Library System)

File: q3_doublylinkedlist.cpp

Concept

A doubly linked list managing a library’s books, supporting traversal in both directions.

Features

Add books:

at beginning

at end

at specific position

Delete book by ID

Display list forward and backward

Iterator support to use range-based for loops.

Example

Displays books, deletes one by ID, and prints list both forward and reverse.

Question 4 – Queue (Movie Ticket Booking System)

File: q4_queue.cpp

Concept

Implements both:

A normal queue (FIFO) for customers

A priority queue where customers requesting more tickets are served first.

Features

enqueue() to add a customer

dequeue() to serve a customer

display() to show the current queue

Example

Simulates ticket booking where customers enter and leave the queue in proper order.

 Question 5 – Stack Implementations & Algorithm Analysis

File: q5_stacks.cpp

Concept

Implements two stacks:

Linked-list-based stack

Array-based stack

Then applies both stacks to:

Reverse a part of a character array (from Question 1)

Generate the number partition pattern (from Question 1b)

Features

Iterative solutions replacing recursion using both stack types.

Each stack tracks recursive function calls manually.

Runtime Analysis
Operation	Linked List Stack	Array Stack
Push / Pop	O(1)	O(1)
Memory Use	Higher (extra pointers)	Lower
Speed	Slightly slower	Faster
Flexibility	Grows dynamically	Fixed size
Summary

Both stacks achieve constant-time operations.

Array-based stack is faster but limited in size.

Linked-list stack is more flexible and memory-safe.

⚙ Technologies Used

Language: C++

Compiler: Any standard C++11+ compiler

Libraries: <iostream> only

 How to Run

Clone the repository

git clone https://github.com/yourusername/data-structures-assignment.git


Compile a question file

g++ q1_changelocation.cpp -o q1
./q1


Repeat for other questions.

 Learning Outcomes

By completing this assignment, you understand:

How recursion can be replaced with stacks (manual call tracking)

How linked lists and queues manage dynamic data

How to design class-based modular systems in C++

Algorithmic performance trade-offs between dynamic and static structures
