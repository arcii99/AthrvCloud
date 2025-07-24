//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

// Define the bucket data structure
typedef struct node {
    int data;
    struct node* next;
} bucket_t;

// Define the bucket sort function
void bucket_sort(int arr[], int n, int m) {
    // Create an array of buckets
    bucket_t* bucket[m];
    for(int i = 0; i < m; i++) {
        bucket[i] = NULL;
    }

    // Insert array elements into the appropriate buckets
    for(int i = 0; i < n; i++) {
        int index = arr[i] / m;
        bucket_t* temp = (bucket_t*)malloc(sizeof(bucket_t));
        temp->data = arr[i];
        temp->next = NULL;

        // If the bucket is empty, insert the element at the head
        if(bucket[index] == NULL) {
            bucket[index] = temp;
        }

        // Otherwise, insert the element at the end of the list
        else {
            bucket_t* curr = bucket[index];
            while(curr->next != NULL) {
                curr = curr->next;
            }
            curr->next = temp;
        }
    }

    // Sort each bucket individually (using insertion sort)
    for(int i = 0; i < m; i++) {
        bucket_t* curr = bucket[i];
        while(curr != NULL) {
            bucket_t* temp = curr->next;
            int val = curr->data;
            int j = i;
            while(j > 0 && val < bucket[j-1]->data) {
                bucket[j]->data = bucket[j-1]->data;
                j--;
            }
            bucket[j]->data = val;
            curr = temp;
        }
    }

    // Gather the sorted elements back into the original array
    int index = 0;
    for(int i = 0; i < m; i++) {
        bucket_t* curr = bucket[i];
        while(curr != NULL) {
            arr[index++] = curr->data;
            curr = curr->next;
        }
    }
}

// Test the bucket sort function
int main() {
    int arr[] = {29, 25, 3, 49, 9, 37, 21, 43};
    int n = sizeof(arr) / sizeof(arr[0]);
    int m = 10;
    bucket_sort(arr, n, m);

    printf("Sorted array: \n");
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}