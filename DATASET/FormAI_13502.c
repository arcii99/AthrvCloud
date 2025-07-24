//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 20
#define BUCKET_SIZE 5

// Define the structure of a linked list node to use in the buckets
typedef struct Node 
{
    int value;
    struct Node* next;
} Node;

// Print the elements of a bucket
void printBucket(Node* bucket) 
{
    Node* current = bucket;
    while (current != NULL) 
    {
        printf("%d ", current->value);
        current = current->next;
    }
}

// Insert a node into a bucket
void insertNode(Node** bucket, int value)
{
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = NULL;

    if (*bucket == NULL)
    {
        *bucket = newNode;
    } 
    else 
    {
        Node* current = *bucket;
        while (current->next != NULL) 
        {
            current = current->next;
        }
        current->next = newNode;
    }
}

// Remove and free all nodes from a bucket
void emptyBucket(Node** bucket)
{
    while (*bucket != NULL) 
    {
        Node* node = *bucket;
        *bucket = node->next;
        free(node);
    }
}

// Sort the array using bucket sort
void bucketSort(int array[])
{
    // Initialize an array of Buckets
    Node* Buckets[BUCKET_SIZE] = {NULL};

    // Insert each element into its respective Bucket
    for (int i = 0; i < ARRAY_SIZE; i++) 
    {
        int bucketIndex = array[i] / BUCKET_SIZE;
        insertNode(&Buckets[bucketIndex], array[i]);
    }

    // Print the Buckets as they are before sorting
    printf("Before Sorting: \n");
    for (int i = 0; i < BUCKET_SIZE; i++) 
    {
        printf("Bucket %d: ", i);
        printBucket(Buckets[i]);
        printf("\n");
    }

    // Sort each Bucket individually using insertion sort
    for (int i = 0; i < BUCKET_SIZE; i++) 
    {
        Node* bucket = Buckets[i];
        while (bucket != NULL) 
        {
            int current = bucket->value;
            Node* prev = bucket;
            Node* next = bucket->next;
            while (next != NULL) 
            {
                if (next->value < current) 
                {
                    prev->next = next->next;
                    next->next = bucket;
                    bucket = next;
                    current = next->value;
                    next = prev->next;
                } 
                else 
                {
                    prev = next;
                    next = next->next;
                }
            }
            bucket = bucket->next;
        }
    }

    // Replace the original array with the sorted elements from the Buckets
    int index = 0;
    for (int i = 0; i < BUCKET_SIZE; i++) 
    {
        Node* bucket = Buckets[i];
        while (bucket != NULL) 
        {
            array[index++] = bucket->value;
            bucket = bucket->next;
        }
        emptyBucket(&Buckets[i]);
    }
    
    // Print the Buckets as they are after sorting
    printf("After Sorting: \n");
    for (int i = 0; i < BUCKET_SIZE; i++) 
    {
        printf("Bucket %d: ", i);
        printBucket(Buckets[i]);
        printf("\n");
    }
}

// Test the implementation
int main()
{
    int array[ARRAY_SIZE] = {32, 75, 23, 54, 13, 46, 16, 17, 89, 28, 90, 67, 49, 81, 52, 30, 10, 38, 62, 8};

    // Print the array before sorting
    printf("Before Sorting: ");
    for (int i = 0; i < ARRAY_SIZE; i++) 
    {
        printf("%d ", array[i]);
    }
    printf("\n");

    // Sort the array using bucket sort
    bucketSort(array);

    // Print the array after sorting
    printf("After Sorting: ");
    for (int i = 0; i < ARRAY_SIZE; i++) 
    {
        printf("%d ", array[i]);
    }
    printf("\n");

    return 0;
}