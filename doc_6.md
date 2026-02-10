# Heap Data Structure Implementation

This project implements a Max Heap and a Min Heap using C. It demonstrates how to transform an arbitrary array of integers into a max-heap (where each parent node is greater than or equal to its children) and a min-heap (where each parent node is less than or equal to its children). The program takes user input for the array size and elements, then processes and displays the heaps.

### (a) Explanation of how the data structures are defined
The program uses standard integer arrays to represent the heap data structures, utilizing the properties of a complete binary tree:
*   **Array Representation:** The heap is stored in an array `data[]` of size `n`.
*   **Index Relationships:** For any node at index `i`:
    *   The **left child** is at index `2 * i + 1`.
    *   The **right child** is at index `2 * i + 2`.
    *   The **parent** is at index `(i - 1) / 2`.
*   **Max Heap Property:** For every node `i`, `data[i]` is greater than or equal to its children.
*   **Min Heap Property:** For every node `i`, `data[i]` is less than or equal to its children.

### (b) Description of the Functions Implemented
The program implements the following functions:

**1. `void swapNum(int *x, int *y)`**
*   **Purpose:** Swaps the values of two integers.
*   **Logic:** Uses pointers to exchange values at two memory addresses using a temporary variable `tmp`.

**2. `void fixMaxHeap(int data[], int size, int pos)`**
*   **Purpose:** Maintains the Max Heap property for a subtree rooted at `pos` (often called heapify).
*   **Logic:**
    *   Identifies the largest value among the root (`pos`), left child, and right child.
    *   If the root is not the largest, it swaps the root with the largest child.
    *   Recursively calls `fixMaxHeap` on the affected subtree to propagate the change down.

**3. `void createMaxHeap(int data[], int size)`**
*   **Purpose:** Builds a Max Heap from an arbitrary array.
*   **Logic:**
    *   Iterates from the last non-leaf node up to the root.
    *   Calls `fixMaxHeap` for each node to ensure the heap property is satisfied bottom-up.

**4. `void fixMinHeap(int data[], int size, int pos)`**
*   **Purpose:** Maintains the Min Heap property for a subtree rooted at `pos`.
*   **Logic:**
    *   Identifies the smallest value among the root (`pos`), left child, and right child.
    *   If the root is not the smallest, it swaps the root with the smallest child.
    *   Recursively calls `fixMinHeap` on the affected subtree.

**5. `void createMinHeap(int data[], int size)`**
*   **Purpose:** Builds a Min Heap from an arbitrary array.
*   **Logic:**
    *   Similar to `createMaxHeap`, it iterates from the last non-leaf node up to the root, calling `fixMinHeap`.

**6. `void showArray(int data[], int size)`**
*   **Purpose:** Displays the elements of the array.
*   **Logic:** Iterates through the array indices and prints each element followed by a space.

### (c) An Overview of How the `main()` Method is Organized
The `main()` function serves as the driver for the program:
*   **Input Handling:**
    *   Prompts the user to enter the number of elements `n`.
    *   Reads `n` integers into the `maxArr` array.
    *   Copies the input data into `minArr` to allow demonstrating both heap types independently.
*   **Original Data Display:** Prints the array as initially entered.
*   **Max Heap Processing:**
    *   Calls `createMaxHeap(maxArr, n)` to transform the array into a Max Heap.
    *   Prints the resulting Max Heap.
*   **Min Heap Processing:**
    *   Calls `createMinHeap(minArr, n)` to transform `minArr` into a Min Heap.
    *   Prints the resulting Min Heap.

### (d) A Sample Output of a Complete Run of the Program
```text
Enter number of elements: 6
Enter 6 values: 12 11 13 5 6 7 

Original array:
12 11 13 5 6 7 

Max heap array:
13 11 12 5 6 7 

Min heap array:
5 6 7 11 12 13 
```
