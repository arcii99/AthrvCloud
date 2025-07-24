//FormAI DATASET v1.0 Category: Linked list operations ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>

// Define the structure for the Linked List Node
struct node
{
    int data;
    struct node *next;
};

// Function to create a new node
struct node *create_node(int data)
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Function to insert a node at the end of the Linked List
void insert_node_end(struct node **head_ref, int data)
{
    struct node *new_node = create_node(data);

    if (*head_ref == NULL)
    {
        *head_ref = new_node;
        return;
    }

    struct node *last_node = *head_ref;
    while (last_node->next != NULL)
    {
        last_node = last_node->next;
    }
  
    last_node->next = new_node;
}

// Function to delete a node from the Linked List
void delete_node(struct node **head_ref, int key)
{
    struct node *temp_node = *head_ref, *prev_node = NULL;

    if (temp_node != NULL && temp_node->data == key)
    {
        *head_ref = temp_node->next;
        free(temp_node);
        return;
    }

    while (temp_node != NULL && temp_node->data != key)
    {
        prev_node = temp_node;
        temp_node = temp_node->next;
    }

    if (temp_node == NULL)
    {
        printf("\n Element not present in Linked List");
        return;
    }

    prev_node->next = temp_node->next;
    free(temp_node);
}

// Function to display the Linked List
void display_list(struct node *head)
{
    struct node *temp_node = head;

    printf("\nLinked List: ");

    while (temp_node != NULL)
    {
        printf("%d ", temp_node->data);
        temp_node = temp_node->next;
    }
    printf("\n");
}

int main()
{
    // Initialize the head node
    struct node *head = NULL;

    // Insert 5 nodes at the end of the Linked List
    insert_node_end(&head, 1);
    insert_node_end(&head, 2);
    insert_node_end(&head, 3);
    insert_node_end(&head, 4);
    insert_node_end(&head, 5);

    // Display the Linked List
    display_list(head);

    // Delete the node with value 3 from the Linked List
    delete_node(&head, 3);

    // Display the Linked List after deleting the node
    display_list(head);

    // Delete the node with value 1 from the Linked List
    delete_node(&head, 1);

    // Display the Linked List after deleting the node
    display_list(head);

    return 0;
}