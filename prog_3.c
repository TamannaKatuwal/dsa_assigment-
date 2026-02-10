#include <stdio.h>
#include <stdlib.h>

struct Node {
    int value;
    struct Node* next;
};

struct Node* makeNode(int val) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    if (node == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }

    node->value = val;
    node->next = NULL; 
    return node;
}

// ADDS NODE IN END OF GIVEN LIST
void appendNode(struct Node** headRef, int val) {
    struct Node* newNode = makeNode(val);

    if (*headRef == NULL) {
        *headRef = newNode;
        return;
    }

    struct Node* temp = *headRef;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
}

void printList(struct Node* head) {
    printf("Original List: ");
    while (head != NULL) {
        printf("%d -> ", head->value);
        head = head->next;
    }
    printf("NULL\n"); // to mark end of list
}

void printReverse(struct Node* node) {
    if (node == NULL) {
        return; 
    }

    printReverse(node->next);

    printf("%d ", node->value);
}

// Frees all the allocated memory 
void freeList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    struct Node* head = NULL; 

    appendNode(&head, 1);
    appendNode(&head, 2);
    appendNode(&head, 3);
    appendNode(&head, 4);
    appendNode(&head, 5);

    printList(head);

    printf("Reverse Traversal: ");
    printReverse(head);
    printf("\n");

    // Frees up the memory before finishing
    freeList(head);

    return 0;
}
