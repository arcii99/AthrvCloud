//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

// Define the structure of a bucket node
struct bucket_node {
    int value;
    struct bucket_node* next;
};

// Bucket Sort function
void bucket_sort(int arr[], int n) {
    int i, j, max_val=0;
    struct bucket_node* bucket_arr[n];

    // Initialize all the buckets as empty
    for(i=0; i<n; i++) {
        bucket_arr[i] = NULL;
    }

    // Find the maximum value in the array
    for(i=0; i<n; i++) {
        if(arr[i] > max_val) {
            max_val = arr[i];
        }
    }

    // Calculate the width of each bucket
    float width = (float) (max_val+1) / n;

    // Add values to the appropriate buckets
    for(i=0; i<n; i++) {
        int bucket_num = (int) (arr[i] / width);
        struct bucket_node* new_node = (struct bucket_node*) malloc(sizeof(struct bucket_node));
        new_node->value = arr[i];
        new_node->next = bucket_arr[bucket_num];
        bucket_arr[bucket_num] = new_node;
    }

    // Sort each bucket using Insertion Sort
    for(i=0; i<n; i++) {
        struct bucket_node* curr = bucket_arr[i];
        struct bucket_node* prev = NULL;
        while(curr != NULL) {
            struct bucket_node* next = curr->next;
            if(prev == NULL || prev->value <= curr->value) {
                prev = curr;
            }
            else {
                prev->next = next;
                struct bucket_node* temp = bucket_arr[i];
                if(curr->value < temp->value) {
                    curr->next = temp;
                    bucket_arr[i] = curr;
                }
                else {
                    while(temp->next->value < curr->value) {
                        temp = temp->next;
                    }
                    curr->next = temp->next;
                    temp->next = curr;
                }
            }
            curr = next;
        }
    }

    // Copy the sorted values back into the original array
    int idx = 0;
    for(i=0; i<n; i++) {
        struct bucket_node* curr = bucket_arr[i];
        while(curr != NULL) {
            arr[idx++] = curr->value;
            curr = curr->next;
        }
    }
}

int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original Array:\n");
    for(int i=0; i<n; i++) {
        printf("%d ", arr[i]);
    }

    bucket_sort(arr, n);

    printf("\n\nSorted Array:\n");
    for(int i=0; i<n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}