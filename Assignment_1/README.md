# Assignment 1 – Stacks and Queues
**CSC 300 - Data Structures**  
**Spring 2026**  
**Due:** Friday, Feb 13, 11:59 pm  

## Overview
This assignment focuses on implementing fundamental data structures - stacks and queues - using linked lists, along with their applications in solving computational problems.

## Tasks

### Task 1: Stack Implementation (20 points)
Complete the `push()` and `pop()` functions for Stack using linked list implementation.

**Requirements:**
- Handle edge cases (empty stack, single element)
- Maintain proper memory management
- Include error handling for underflow conditions

### Task 2: Queue Implementation (20 points)
Complete the `enqueue()` and `dequeue()` functions for Queue using linked list implementation.

**Requirements:**
- Handle edge cases (empty queue, single element)
- Maintain proper front and rear pointers
- Include error handling for underflow conditions

### Task 3: Dijkstra's Two Stack Algorithm (20 points)
Implement Dijkstra's two stack algorithm to evaluate fully parenthesized arithmetic expressions.

**Supported Operators:**
- Addition (`+`)
- Subtraction (`-`)
- Multiplication (`*`)
- Division (`/`)
- Exponentiation (`^`)

**Requirements:**
- Handle operator precedence correctly
- Process fully parenthesized expressions
- Include error handling for invalid expressions
- Support multi-digit numbers

### Task 4: Josephus Problem (20 points)
Solve the Josephus problem with N soldiers.

**Problem Description:**
- N soldiers standing in a circle
- Every k-th soldier is eliminated until one remains
- Find the position of the last surviving soldier

**Requirements:**
- Use queue data structure for the solution
- Handle input validation
- Return the winning position

### Task 5: Deques Research (10 points)
Research and write about Deques (double-ended queues) implementation in different programming languages.

**Research Requirements:**
- Select at least two programming languages
- Compare their deque implementations
- Include conceptual diagrams
- Analyze efficiency and design choices
- Compare with our stack/queue implementations

**Discussion Post Requirements:**
- Post on D2L discussion board
- Reply to at least two peer posts

## Grading Breakdown

| Component | Points |
|-----------|--------|
| Task 1 - Stack Implementation | 20 |
| Task 2 - Queue Implementation | 20 |
| Task 3 - Dijkstra's Algorithm | 20 |
| Task 4 - Josephus Problem | 20 |
| Task 5 - Deques Research | 10 |
| Proper Code Commenting | 5 |
| GitHub Availability | 5 |
| **Total** | **100** |

## Deliverables

### Code Files
- All C++ source files (`.cpp`)
- All header files (`.h`)
- `README.md` (this file)

### Documentation
- `Task5_Deques_Research.pdf` - Research paper on deques implementation
- Screenshots showing all functions working correctly

### Submission Format
- Zipped folder named `A1.zip`
- Published to GitHub repository (instructor as collaborator)

## File Structure
```
A1/
├── README.md                    # This file
├── Task5_Deques_Research.pdf    # Research paper
├── screenshots/                 # Function demonstration
│   ├── stack_operations.png
│   ├── queue_operations.png
│   ├── dijkstra_algorithm.png
│   └── josephus_problem.png
├── src/                         # Source code
│   ├── Stack.h
│   ├── Stack.cpp
│   ├── Queue.h
│   ├── Queue.cpp
│   ├── DijkstraCalculator.h
│   ├── DijkstraCalculator.cpp
│   ├── JosephusSolver.h
│   ├── JosephusSolver.cpp
│   └── main.cpp                 # Test driver
└── tests/                       # Test cases (optional)
    ├── test_stack.cpp
    ├── test_queue.cpp
    ├── test_dijkstra.cpp
    └── test_josephus.cpp
```

## Development Notes

### Memory Management
- Use proper `new` and `delete` operations
- Handle memory leaks carefully
- Consider using smart pointers where appropriate

### Error Handling
- Check for null pointers
- Handle empty data structure operations
- Validate input parameters

### Testing Strategy
- Test edge cases (empty, single element)
- Test typical cases
- Test error conditions
- Document test cases in code

## GitHub Setup
1. Create repository for CSC 300 assignments
2. Add instructor as collaborator
3. Create `A1` folder in repository
4. Push all files before deadline
5. Ensure repository is public (as required)

## Resources
- Course lecture slides on D2L
- Base code templates from D2L
- Textbook chapters on stacks and queues
- Online documentation for STL stack and queue

## Timeline
- **Week 1:** Download base code, complete Tasks 1-2
- **Week 2:** Complete Tasks 3-4, start Task 5 research
- **Week 3:** Finish Task 5, create documentation, submit

---

**Last Updated:** February 5, 2026
