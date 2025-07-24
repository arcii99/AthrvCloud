//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>

// define a structure to hold a value and pointer to next node in linked list
struct node {
    int val;
    struct node* next;
};

void bucketSort(int arr[], int n) {
    // create 10 buckets for each digit from 0 to 9
    struct node* bucket[10];
    int i, j, k;
    
    for (i = 0; i < 10; i++)
        bucket[i] = NULL;
    
    // Add the array elements into the appropriate bucket 
    for (i = 0; i < n; i++) {
        struct node* newNode = (struct node*) malloc(sizeof(struct node));
        newNode->val = arr[i];
        newNode->next = NULL;
        
        // Determine the appropriate bucket 
        int bucketIndex = arr[i] / 10;
        if (bucket[bucketIndex] == NULL)
            bucket[bucketIndex] = newNode;
        else {
            struct node* current = bucket[bucketIndex];
            
            // Sort the elements within each bucket 
            if (newNode->val < current->val) {
                bucket[bucketIndex] = newNode;
                newNode->next = current;
            }
            else {
                while (current->next != NULL && newNode->val > current->next->val)
                    current = current->next;
                newNode->next = current->next;
                current->next = newNode;
            }
        }
    }
    
    // Combine the elements in the buckets into sorted array 
    k = 0;
    for (i = 0; i < 10; i++) {
        struct node* current = bucket[i];
        while (current != NULL) {
            arr[k++] = current->val;
            current = current->next;
        }
    }
}

int main() {
    int arr[] = {56, 23, 15, 72, 9, 84, 2, 54};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    printf("Original Array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    
    bucketSort(arr, n); // Perform bucket sort 
    
    printf("\nSorted Array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    
    return 0;
}