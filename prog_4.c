#include <stdio.h>
#include <stdlib.h>

// node for double linked list
// has prev also because we need backward link
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

// function to make new node
struct Node* newNode(int x) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    if (temp == NULL) {
        printf("memory problem\n");
        return NULL;
    }
    temp->data = x;
    temp->next = NULL;
    temp->prev = NULL;
    return temp;
}


// assuming prev node is valid mostly
void insertAfter(struct Node* p, int val) {
    if (p == NULL) {
        printf("cannot insert, node is null\n");
        return;
    }

    struct Node* n = newNode(val);

    n->next = p->next;   
    p->next = n;         
    n->prev = p;        

    if (n->next != NULL) {
        n->next->prev = n;   
    }
}


void deleteNode(struct Node** head, struct Node* d) {
    if (*head == NULL || d == NULL)
        return;

    if (*head == d) {
        *head = d->next;   
    }

    if (d->next != NULL) {
        d->next->prev = d->prev;
    }

    if (d->prev != NULL) {
        d->prev->next = d->next;
    }

    free(d);   
}

void show(struct Node* h) {
    printf("list: ");
    while (h != NULL) {
        printf("%d ", h->data);
        h = h->next;
    }
    printf("\n");
}


// using this for creating initial list
void addFirst(struct Node** head, int v) {
    struct Node* n = newNode(v);

    n->next = *head;
    n->prev = NULL;

    if (*head != NULL) {
        (*head)->prev = n;
    }

    *head = n;
}

int main() {
    struct Node* head = NULL;

    // building  the list manually
    addFirst(&head, 2);
    addFirst(&head, 4);
    addFirst(&head, 8);
    addFirst(&head, 10);

    printf("before changes\n");
    show(head);

    // inserting 5 after 4
    // node known so directly used
    insertAfter(head->next->next, 5);

    printf("after insert\n");
    show(head);
    deleteNode(&head, head->next);
    printf("after delete\n");
    show(head);
    return 0;
}
