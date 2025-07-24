//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: romantic
#include <stdio.h>
#include <stdlib.h>

// Definition of linked list node
typedef struct Node
{
    float value;
    struct Node* next;
} Node;

// Definition of the function to insert a value into a linked list
void Insert(Node** head, float value)
{
    // Allocate memory for a new node
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->value = value;
    new_node->next = NULL;

    // If the list is empty
    if (*head == NULL)
    {
        *head = new_node;
    }
    else
    {
        // Find the right position to insert the node
        Node* current_node = *head;
        Node* prev_node = NULL;
        while (current_node != NULL && current_node->value <= value)
        {
            prev_node = current_node;
            current_node = current_node->next;
        }

        // Insert the node at the right position
        if (prev_node == NULL)
        {
            new_node->next = *head;
            *head = new_node;
        }
        else
        {
            new_node->next = prev_node->next;
            prev_node->next = new_node;
        }
    }
}

// Definition of the Bucket Sort function
void BucketSort(float array[], int n)
{
    // Create an array of linked lists
    Node* buckets[n];
    for (int i = 0; i < n; i++)
    {
        buckets[i] = NULL;
    }

    // Insert each value into the right bucket
    for (int i = 0; i < n; i++)
    {
        int bucket_index = (int)(array[i] * n);
        Insert(&buckets[bucket_index], array[i]);
    }

    // Merge all the linked lists into the sorted array
    int index = 0;
    for (int i = 0; i < n; i++)
    {
        Node* current_node = buckets[i];
        while (current_node != NULL)
        {
            array[index] = current_node->value;
            index++;
            current_node = current_node->next;
        }
    }
}

// Definition of the main function
int main()
{
    // Declare an unsorted array
    float array[] = {0.14, 0.48, 0.28, 0.57, 0.61, 0.33, 0.75, 0.12, 0.46, 0.22};

    // Calculate the size of the array
    int n = sizeof(array) / sizeof(float);

    // Sort the array using Bucket Sort
    BucketSort(array, n);

    // Print the sorted array
    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%.2f ", array[i]);
    }
    printf("\n");

    // Return 0 to indicate successful completion
    return 0;
}