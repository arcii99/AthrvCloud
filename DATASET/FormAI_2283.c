//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: automated
#include <stdio.h>
#include <stdlib.h>

// Define our bucket
#define BUCKET_SIZE 10 

// Define the structure of bucket (a linked list of integers)
struct node {
    int data;
    struct node* next;
};

typedef struct node* Bucket;

// Print function to print the array
static void printArray(int* arr, const int size)
{
    for (int i = 0; i < size; ++i)
        printf("%d ", arr[i]);

    printf("\n");
}

// Function to insert an integer into a given bucket
static Bucket insert(Bucket head, const int data)
{
    Bucket node = (Bucket)malloc(sizeof(struct node));
    node->data = data;

    if (head == NULL || data < head->data) {
        node->next = head;
        return node;
    }

    Bucket current = head;
    while (current->next != NULL && current->next->data <= data)
        current = current->next;

    node->next = current->next;
    current->next = node;

    return head;
}

// The main bucket sort function
void bucketSort(int* arr, const int size)
{
    Bucket buckets[BUCKET_SIZE] = { NULL };

    // Insert elements into appropriate buckets
    for (int i = 0; i < size; ++i) {
        const int bucketIdx = arr[i] / BUCKET_SIZE;
        buckets[bucketIdx] = insert(buckets[bucketIdx], arr[i]);
    }

    // Merge the buckets
    int i = 0;
    for (int bucketIdx = 0; bucketIdx < BUCKET_SIZE; ++bucketIdx) {
        Bucket current = buckets[bucketIdx];
        while (current != NULL) {
            arr[i++] = current->data;
            current = current->next;
        }
    }
}

// Driver code to test implementation
int main()
{
    int arr[] = { 1, 3, 5, 9, 8, 7, 2, 4, 6, 0 };
    const int size = sizeof(arr) / sizeof(int);

    printf("Unsorted array: ");
    printArray(arr, size);

    bucketSort(arr, size);

    printf("Sorted array: ");
    printArray(arr, size);

    return 0;
}