//FormAI DATASET v1.0 Category: Database Indexing System ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 50
#define MAX_AGE 200

// Structure to hold information about an individual
struct person {
    char name[MAX_NAME_LEN];
    int age;
};

// Structure to hold a node in the linked list
struct node {
    struct person *data;
    struct node *next;
};

// Function to create a new node
struct node* new_node(struct person* data) {
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Function to insert a new node into the linked list
void insert_node(struct node** head_ref, struct node* new_node) {
    // If the list is empty, make the new node the head
    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }
    // If the new node's value is less than the head, make it the new head
    if (strcmp(new_node->data->name, (*head_ref)->data->name) < 0) {
        new_node->next = *head_ref;
        *head_ref = new_node;
        return;
    }
    struct node* current;
    // Traverse the list to find the appropriate place for the new node
    for (current = *head_ref; current->next != NULL; current = current->next) {
        if (strcmp(new_node->data->name, current->next->data->name) < 0) {
            new_node->next = current->next;
            current->next = new_node;
            return;
        }
    }
    // If it hasn't been inserted yet, add it to the end of the list
    current->next = new_node;
}

// Function to print a node
void print_node(struct node* node) {
    printf("Name: %s, Age: %d\n", node->data->name, node->data->age);
}

// Function to print the entire linked list
void print_list(struct node* head) {
    struct node* current;
    for (current = head; current != NULL; current = current->next) {
        print_node(current);
    }
}

int main() {
    // Create some sample data
    struct person bob = {"Bob", 25};
    struct person alice = {"Alice", 35};
    struct person carol = {"Carol", 18};
    struct person dave = {"Dave", 42};
    struct person eve = {"Eve", 28};
    
    // Create a linked list
    struct node* head = NULL;
    
    // Insert the data into the linked list
    insert_node(&head, new_node(&bob));
    insert_node(&head, new_node(&alice));
    insert_node(&head, new_node(&carol));
    insert_node(&head, new_node(&dave));
    insert_node(&head, new_node(&eve));
    
    // Print the entire linked list
    printf("Initial List:\n");
    print_list(head);
    
    // Remove Dave from the linked list
    struct node* current;
    for (current = head; current->next != NULL; current = current->next) {
        if (strcmp(current->next->data->name, "Dave") == 0) {
            current->next = current->next->next;
            free(current->next);
            break;
        }
    }
    
    // Print the updated linked list
    printf("\nList after removing Dave:\n");
    print_list(head);
    
    return 0;
}