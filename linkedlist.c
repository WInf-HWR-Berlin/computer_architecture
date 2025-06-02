#include <stdio.h>
#include <stdlib.h>

// Definition of the node structure
// So, a linked list is a recursive data set, which is either NULL or consists of data and a pointer
// to the next element.
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    // alternatively: (*newNode).data = data;
    // (*newNode).next = NULL;
    return newNode;
}

// Function to append a node at the end of the list
// why Node** head?
// So, head contains an address, which points to a first element (also a pointer) of a linked list.
// We could just use Node* head, and this would be directly the first element. However, if we want to remove that?
// So, we point to the pointer, which is the linked list, and always keep this in "our hand", even if
// the first element gets removed (in which case *head would point to NULL or a different element of the linked list),
// which would then be accessible in *head
void appendNode(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    struct Node* last = *head;
    
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    
    while (last->next != NULL) {
        last = last->next;
    }
    
    last->next = newNode;
}

// Function to delete a node with a specific key
void deleteNode(struct Node** head, int key) {
    struct Node* temp = *head;
    struct Node* prev = NULL;
    
    if (temp != NULL && temp->data == key) {
        *head = temp->next;
        free(temp);
        return;
    }
    
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }
    
    if (temp == NULL) return;
    
    prev->next = temp->next;
    free(temp);
}

// Function to print the linked list along with addresses
void printList(struct Node* node) {
    while (node != NULL) {
        printf("Address: %p, Data: %d -> ", (void*)node, node->data);
        node = node->next;
    }
    printf("NULL\n");
}

// Main function to test the linked list implementation
int main() {
    struct Node* head = NULL;
    
    appendNode(&head, 1);
    appendNode(&head, 2);
    appendNode(&head, 3);
    appendNode(&head, 4);
    
    printf("Linked list:\n");
    printList(head);
    
    deleteNode(&head, 3);
    
    printf("Linked list after deletion of 3:\n");
    printList(head);
    
    return 0;
}
