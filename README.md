# BTS Store Buying Simulation

This project is a school assignment that implements a simulation of the process where BTS (The Benny Travis Shop) buys stores with their available wealth. The simulation includes functionality for managing a stack of store prices, sorting store prices, and determining how many stores BTS can afford to buy before they become the richest among the stores

## Files in the Repository

- `main.c`: The main source file containing the implementation of the simulation.
- `README.md`: This file, providing an overview and instructions for the project.

## Input and Execution

The program expects input in the following format:

- An integer `shops`, representing the number of stores.
- An integer `wealth`, representing the initial wealth of BTS.
- An array of integers representing the price of each store.

Example Input:

```
6 5
6
3
5
10
4
9
```
Example Output:

```
2
```

## Code Explanation

### Data Structures

- **Node**

  ```c
  typedef struct node {
      int price;
      struct node *next;
  } node;
  ```

  Represents a store price in the stack.

- **Stack**

  ```c
  typedef struct stack {
      node *head;
  } stack;
  ```

  A stack to manage store prices that BTS can afford.

### Functions

- **Node Creation and Manipulation**

  - `node* createNode(int value)`: Creates a new node with the given price.
  - `node* insertHead(node* head, int price)`: Inserts a node at the head of the list.
  - `node* removeHead(node* head)`: Removes the head node from the list.

- **Stack Operations**

  - `stack* initStack()`: Initializes an empty stack.
  - `void push(stack* stk, int price)`: Pushes a price onto the stack.
  - `void pop(stack* stk)`: Pops the top price from the stack.
  - `int top(stack* stk)`: Returns the top price from the stack.

- **Utility Functions**

  - `void mergeSort(int* arr, int len)`: Sorts an array of prices using merge sort.
  - `int updateStk(stack* stk, int arr[], int index, int shops, int wealth)`: Updates the stack with prices BTS can afford.
  - `int buyStore(stack* stk, int max, int wealth, int* count)`: Simulates BTS buying a store and updates wealth.

### Main Function

The `main` function orchestrates the simulation by:

1. Reading the number of shops and initial wealth.
2. Reading the prices of the stores.
3. Sorting the prices.
4. Simulating the process of BTS buying stores until they become the richest.
