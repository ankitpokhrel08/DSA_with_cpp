# Data Structures and Algorithms with C++

This repository contains implementations of various data structures and algorithms in C++. It serves as both a learning resource and a reference for common DSA concepts.

## Table of Contents

1. [Sorting Algorithms](#sorting-algorithms)
2. [Searching Algorithms](#searching-algorithms)
3. [Graph Algorithms](#graph-algorithms)
4. [Hash Tables](#hash-tables)
5. [Linked Lists](#linked-lists)
6. [Stacks and Queues](#stacks-and-queues)
7. [Trees](#trees)
8. [Recursion](#recursion)

## Sorting Algorithms

### Implemented Algorithms

- **Bubble Sort**: Simple comparison-based sorting algorithm

  - Time Complexity: O(n²)
  - Space Complexity: O(1)
  - File: `sorting/bubblesort.cpp`

- **Heap Sort**: Comparison-based sorting using a binary heap data structure

  - Time Complexity: O(n log n)
  - Space Complexity: O(1)
  - File: `sorting/heapsort.cpp`

- **Radix Sort**: Non-comparative integer sorting algorithm

  - Time Complexity: O(nk) where k is the number of digits
  - Space Complexity: O(n+k)
  - File: `sorting/radixsort.cpp`

- **Quick Sort**: Divide and conquer algorithm

  - Time Complexity: O(n log n) average, O(n²) worst
  - Space Complexity: O(log n)
  - File: `sorting/quicksort.cpp`

- **Merge Sort**: Divide and conquer algorithm

  - Time Complexity: O(n log n)
  - Space Complexity: O(n)
  - File: `sorting/mergesort.cpp`

- **Insertion Sort**: Simple sorting algorithm

  - Time Complexity: O(n²)
  - Space Complexity: O(1)
  - File: `sorting/insertionsort.cpp`

- **Selection Sort**: In-place comparison sort
  - Time Complexity: O(n²)
  - Space Complexity: O(1)
  - File: `sorting/selectionsort.cpp`

## Searching Algorithms

### Implemented Algorithms

- **Linear Search**: Sequential search algorithm

  - Time Complexity: O(n)
  - File: `searching/linearsearch.cpp`

- **Binary Search**:
  - Non-recursive implementation
    - Time Complexity: O(log n)
    - File: `searching/binarysearch.cpp`
  - Recursive implementation
    - Time Complexity: O(log n)
    - File: `searching/binarysearchrecursive.cpp`

## Graph Algorithms

### Implemented Algorithms

- **Dijkstra's Algorithm**: Finds shortest paths from a source vertex to all other vertices

  - Time Complexity: O((V+E)log V) with binary heap
  - File: `graph/dijkstraalgo.cpp`

- **Kruskal's Algorithm**: Finds a minimum spanning tree for a connected weighted graph

  - Time Complexity: O(E log E) where E is the number of edges
  - File: `graph/kruskalalgo.cpp`

- **Prim's Algorithm**: Finds a minimum spanning tree for a connected weighted graph
  - Time Complexity: O((V+E)log V) with binary heap
  - File: `graph/prismalgo.cpp`

## Hash Tables

### Implemented Techniques

- **Hashing Functions**: Various hashing techniques

  - Direct Hashing
  - Modulo Hashing
  - Multiplicative Hashing
  - Digit Extraction
  - Folding
  - Mid Square
  - File: `searching/hashingfuncn.cpp`

- **Collision Resolution**: Techniques to handle hash collisions
  - Linear Probing
  - Quadratic Probing
  - Double Hashing
  - Chaining with Linked Lists
  - File: `searching/collision.cpp`

## Linked Lists

### Dynamic Implementations

- **Singly Linear**: Simple linked list implementation

  - File: `linkedlist/dynamiclist/singly/singlylinear.cpp`

- **Singly Circular**: Singly linked list with circular connection

  - File: `linkedlist/dynamiclist/singly/singlycircular.cpp`

- **Doubly Linear**: Linked list with bidirectional traversal

  - File: `linkedlist/dynamiclist/doubly/doublylinear.cpp`

- **Doubly Circular**: Doubly linked list with circular connection
  - File: `linkedlist/dynamiclist/doubly/doublycircular.cpp`

### Applications

- **Stack Using Linked List**: Implementation of stack using singly linked list

  - File: `linkedlist/dynamiclist/singly/stack.cpp`

- **Queue Using Linked List**: Implementation of queue using singly linked list

  - File: `linkedlist/dynamiclist/singly/queue.cpp`

- **Polynomial Addition**: Adding polynomials using linked list
  - File: `linkedlist/dynamiclist/singly/polynomialadd.cpp`

### Array Implementations

- **List Operations**: Insert and delete operations in array-based list

  - File: `linkedlist/arrayimplementation/insertanddelete.cpp`

- **Queue as List**: Implementation of queue using array
  - File: `linkedlist/arrayimplementation/queueaslist.cpp`

## Stacks and Queues

### Stack Implementations and Applications

- **Stack**: Basic array-based stack implementation

  - File: `stacks/stacks.cpp`

- **Infix to Postfix**: Algorithm to convert infix to postfix expression

  - File: `stacks/infix2postfix.cpp`

- **Infix to Prefix**: Algorithm to convert infix to prefix expression

  - File: `stacks/infix2prefix.cpp`

- **Balanced Parentheses**: Check for balanced parentheses using stack

  - File: `stacks/balancedparenthesis.cpp`

- **Expression Evaluation**: Evaluate postfix and prefix expressions
  - File: `stacks/evaluatepostandprefix.cpp`

### Queue Implementations

- **Linear Queue**: Traditional queue implementation

  - File: `queue/linearqueue.cpp`

- **Circular Queue**: Space-efficient queue implementation
  - File: `queue/circularqueue.cpp`

## Trees

### Binary Trees

- **Binary Search Tree**: Basic BST implementation

  - File: `tree/binarysearchtree.cpp`

- **AVL Tree**: Self-balancing binary search tree

  - File: `tree/avltree.cpp`

- **Tree Traversals**: Different tree traversal techniques
  - File: `tree/orderoftrees.cpp`

## Recursion

### Recursive Algorithms

- **Tower of Hanoi**: Classic recursive problem

  - File: `recursion/TOH.cpp`

- **Prefix to Postfix**: Recursive conversion from prefix to postfix expression
  - File: `recursion/prefixtopostfix.cpp`

## Usage

To compile and run any of the programs, navigate to the appropriate directory and use:

```bash
g++ -o program_name file_name.cpp
./program_name
```

## Contributing

Contributions are welcome! Please feel free to submit a Pull Request.

## License

This project is licensed under the MIT License - see the LICENSE file for details.
