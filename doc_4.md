# Documentation for Balanced Parentheses Checker

## (a) Explanation of how the data structures are defined
The program utilizes a **Stack** data structure, implemented using a static array, to manage the opening brackets found in the expression.
 **`MAX`**: it tells us that the size of stack and input shouldnt be greater than `100`

 **`stack[MAX]`**: A global character array that serves as the storage for the stack elements. It stores opening brackets `(`, `{`, `[` as they are encountered.
 *   **`top`**: A global integer variable initialized to `-1`. It acts as the stack pointer, tracking the index of the most recently inserted element.
    *   `top == -1` indicates that the stack is empty.
    *   `top == MAX - 1` indicates that the stack is full (overflow condition).
*   **`bool`**: A custom macro defined as `int` to represent boolean values (though not strictly used in the final logic, `isBalanced` is an integer).

## (b) Description of the functions implemented

The program implements the following functions to manage and display the doubly linked list:

**1. `struct Node* newNode(int x)`**
*   **Purpose:** Allocates memory for a new node.
*   **Logic:**
    *   Allocates memory using `malloc(sizeof(struct Node))`.
    *   Checks for allocation failure and prints an error if so.
    *   Initializes `data` with value `x`, and sets `next` and `prev` pointers to `NULL`.
    *   Returns the pointer to the new node.

**2. `void addFirst(struct Node** head, int v)`**
*   **Purpose:** Adds a new node at the beginning of the list.
*   **Logic:**
    *   Creates a new node using `newNode(v)`.
    *   Sets the new node's `next` pointer to the current head.
    *   If the current head is not `NULL`, updates its `prev` pointer to the new node.
    *   Updates the head pointer to point to the new node.

**3. `void insertAfter(struct Node* p, int val)`**
*   **Purpose:** Inserts a new node after a given node `p`.
*   **Logic:**
    *   Checks if the given node `p` is `NULL`.
    *   Creates a new node `n` using `newNode(val)`.
    *   Adjusts pointers so `n` fits between `p` and `p->next`.
    *   If `n->next` is not `NULL`, updates its `prev` pointer to `n`.

**4. `void deleteNode(struct Node** head, struct Node* d)`**
*   **Purpose:** Deletes a specific node `d` from the list.
*   **Logic:**
    *   Checks if head or the node to delete is `NULL`.
    *   If `d` is the head, updates `*head` to the next node.
    *   Updates the `next` pointer of the previous node (if it exists) to bypass `d`.
    *   Updates the `prev` pointer of the next node (if it exists) to bypass `d`.
    *   Frees the memory of `d`.

**5. `void show(struct Node* h)`**
*   **Purpose:** Displays the list elements.
*   **Logic:**
    *   Traverses the list starting from the given node `h`.
    *   Prints the `data` of each node followed by a space.
    *   Continues until the end of the list (`NULL`) is reached, then prints a newline.

## (c) An overview of how the `main()` method is organized

The `main()` function shows the logic for checking balanced parentheses:

The `main()` function serves as the driver for the linked list operations:
*   **Initialization:** Initializes the `head` pointer to `NULL`.
*   **Population:** Uses `addFirst` four times to build the list. Since `addFirst` adds to the front, adding 2, 4, 8, 10 results in the list: `10 -> 8 -> 4 -> 2`.
*   **Initial Display:** Calls `show(head)` to print the initial state of the list.
*   **Insertion:** Calls `insertAfter` to insert the value `5` after the node with value `4` (accessed via `head->next->next`).
*   **Post-Insertion Display:** Prints the list again to reflect the insertion.
*   **Deletion:** Calls `deleteNode` to remove the second node in the list (the node after head).
*   **Final Display:** Prints the final state of the list after deletion.

## (d) A sample output of a complete run of the program
```text
before changes
list: 10 8 4 2 
after insert
list: 10 8 4 5 2 
after delete
list: 10 4 5 2 
```




