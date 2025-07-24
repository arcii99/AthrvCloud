//FormAI DATASET v1.0 Category: Database Indexing System ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct for database records
typedef struct Record {
    int id;
    char name[20];
    char email[50];
    double balance;
} Record;

// Define a struct for the binary search tree node
typedef struct Node {
    Record data;
    struct Node* left;
    struct Node* right;
} Node;

// Function to create a new Node
Node* createNode(Record rec) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = rec;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a new record into the binary search tree
void insert(Node** root, Record rec) {
    if (*root == NULL) {
        *root = createNode(rec);
    } else if (rec.balance < (*root)->data.balance) {
        insert(&(*root)->left, rec);
    } else {
        insert(&(*root)->right, rec);
    }
}

// Function to search for a record in the binary search tree
Record* search(Node* root, int id) {
    if (root == NULL || root->data.id == id) {
        return &root->data;
    } else if (id < root->data.id) {
        return search(root->left, id);
    } else {
        return search(root->right, id);
    }
}

int main() {
    Node* root = NULL;
    Record rec;

    // Insert sample records into the binary search tree
    rec.id = 1001;
    strcpy(rec.name, "John");
    strcpy(rec.email, "john@abc.com");
    rec.balance = 1000.50;
    insert(&root, rec);

    rec.id = 1002;
    strcpy(rec.name, "Mary");
    strcpy(rec.email, "mary@abc.com");
    rec.balance = 5000.20;
    insert(&root, rec);

    rec.id = 1003;
    strcpy(rec.name, "Mike");
    strcpy(rec.email, "mike@abc.com");
    rec.balance = 2000.75;
    insert(&root, rec);

    // Search for a record using its ID
    int searchId = 1002;
    Record* result = search(root, searchId);
    if (result != NULL) {
        printf("Record found:\n");
        printf("ID: %d\n", result->id);
        printf("Name: %s\n", result->name);
        printf("Email: %s\n", result->email);
        printf("Balance: %.2f\n", result->balance);
    } else {
        printf("Record not found.\n");
    }

    return 0;
}