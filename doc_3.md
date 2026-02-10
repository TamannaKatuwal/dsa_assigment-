# Documentation for Singly Linked List Traversal

## (a) Explanation of how the data structures are defined
The program implements a **Singly Linked List**, which is a linear data structure where elements are not stored at contiguous memory locations.
 **struct Node:** It is fundamental building block of the list. It contains two members:

**value:** An integer that stores the actual data.

**next:** A pointer of type struct Node* that holds the memory address of the next node in the sequence.

**Dynamic Memory:** Unlike a static array, this structure grows at runtime using malloc(), allowing for flexible memory management.

**NULL Pointer:** Used to signify the end of the list, ensuring the program knows when to stop traversing.

## (b) Description of the functions implemented

The program implements the following core functions to manipulate the stack:

### 1. `struct Node* makeNode(int val)`
*   **Purpose**: Creates a new node in the heap memory.
*   **Logic**:
    Allocates memory using malloc.
    Checks if memory allocation was successful (exits if NULL).
    Initializes the value with the provided integer and sets the next pointer to NULL.

### 2. `void appendNode(struct Node** headRef, int val)`
*   **Purpose**:Adds a new element to the very end of the list..
*   **Logic**:
    *   If the list is empty **(*headRef == NULL),** the new node becomes the head..
    *   Otherwise, retrieves the character at `stack[top]`, decrements `top` by 1 to effectively remove the item, and returns the retrieved character.

## (c) An overview of how the `main()` method is organized

The `main()` function serves as the driver for the linked list operations:
1.  **Initialization**: A pointer `head` is initialized to `NULL` to represent an empty list.
*   **Population:** The `appendNode` function is called five times to insert values 1 through 5 into the list.
*   **Forward Printing:** Calls `printList` to show the sequence as it exists in memory ($1 \to 2 \to 3 \to 4 \to 5$).
*   **Reverse Printing:** Calls `printReverse` to demonstrate recursive traversal, printing the values from $5$ down to $1$.
*   **Memory Cleanup:** Before the program terminates, it calls `freeList` to iterate through the nodes and deallocate memory using `free()`, preventing memory leaks.

## (d) A sample output of a complete run of the program
```text
Linked List: 1 -> 2 -> 3 -> 4 -> 5 -> NULL
Reversed List: 5 4 3 2 1



