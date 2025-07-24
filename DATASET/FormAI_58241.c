//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>

// Define the number of buckets
#define BUCKET_NUM 10

// Define the structure of a linked list node 
struct node {
    int data;
    struct node *next;
};

// Function to perform the bucket sort algorithm
void bucket_sort(int arr[], int n) {
    int i, j;
    // Create an array of linked lists as buckets
    struct node *bucket[BUCKET_NUM];
    // Initialize all the buckets to NULL
    for (i = 0; i < BUCKET_NUM; i++) {
        bucket[i] = NULL;
    }
    // Create the linked lists by inserting the elements into the appropriate bucket
    for (i = 0; i < n; i++) {
        // Calculate the index of the bucket where the element should be inserted
        int index = (arr[i] / BUCKET_NUM);
        // Create a new node and insert it into the appropriate bucket
        struct node *new_node = (struct node*)malloc(sizeof(struct node));
        new_node->data = arr[i];
        new_node->next = bucket[index];
        bucket[index] = new_node;
    }
    // Traverse each bucket, sort the elements and merge them into the original array
    int k = 0;
    for (i = 0; i < BUCKET_NUM; i++) {
        struct node *temp = bucket[i];
        // Sort the elements in the current bucket using insertion sort
        for (j = 1; j < BUCKET_NUM && temp != NULL; j++) {
            struct node *current = temp;
            int val = current->data;
            while (current->next != NULL && val > current->next->data) {
                current->data = current->next->data;
                current = current->next;
            }
            current->data = val;
            temp = temp->next;
        }
        // Merge the sorted elements into the original array
        while (temp != NULL) {
            arr[k++] = temp->data;
            temp = temp->next;
        }
    }
}

int main() {
    int arr[] = { 37, 1, 47, 17, 27, 13, 29, 19, 7, 11, 5, 3 };
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Array before sorting: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    // Call the bucket_sort function to sort the array
    bucket_sort(arr, n);
    printf("Array after sorting: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}