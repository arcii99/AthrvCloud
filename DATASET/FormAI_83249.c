//FormAI DATASET v1.0 Category: Data structures visualization ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ARR_SIZE 10

// A struct to represent a node in a binary search tree.
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// A struct to represent a node in a linked list.
struct ListNode {
    int data;
    struct ListNode* next;
};

// A function to create a new node for a binary search tree.
struct Node* newNode(int data) {
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// A function to insert a node into a binary search tree.
struct Node* insert(struct Node* root, int data) {
    // If the root is null, create a new node and return it.
    if (root == NULL) {
        return newNode(data);
    }
    // Otherwise, recursively insert the node into the correct spot in the tree.
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }
    return root;
}

// A function to create a new node for a linked list.
struct ListNode* newListNode(int data) {
    struct ListNode* node = (struct ListNode*) malloc(sizeof(struct ListNode));
    node->data = data;
    node->next = NULL;
    return node;
}

// A function to insert a node at the end of a linked list.
void insertListNode(struct ListNode** head, int data) {
    struct ListNode* node = newListNode(data);
    if (*head == NULL) {
        *head = node;
    } else {
        struct ListNode* curr = *head;
        while (curr->next != NULL) {
            curr = curr->next;
        }
        curr->next = node;
    }
}

// A function to print a binary search tree in order.
void printBST(struct Node* root) {
    if (root != NULL) {
        printBST(root->left);
        printf("%d ", root->data);
        printBST(root->right);
    }
}

// A function to print a linked list.
void printList(struct ListNode* head) {
    struct ListNode* curr = head;
    while (curr != NULL) {
        printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("\n");
}

int main() {
    // Initialize an array of random integers.
    int arr[ARR_SIZE];
    for (int i = 0; i < ARR_SIZE; i++) {
        arr[i] = rand() % 100;
    }

    // Insert the array elements into a binary search tree.
    struct Node* bst = NULL;
    for (int i = 0; i < ARR_SIZE; i++) {
        bst = insert(bst, arr[i]);
    }

    // Insert the array elements into a linked list.
    struct ListNode* head = NULL;
    for (int i = 0; i < ARR_SIZE; i++) {
        insertListNode(&head, arr[i]);
    }

    // Print the binary search tree and linked list.
    printf("Binary Search Tree: ");
    printBST(bst);
    printf("\n");
    printf("Linked List: ");
    printList(head);

    return 0;
}