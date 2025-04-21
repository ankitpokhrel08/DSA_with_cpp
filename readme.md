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
8. [Dynamic Programming](#dynamic-programming)

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
