//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

// Define the structure of a bucket node.
typedef struct bucket_node {
    int data;
    struct bucket_node *next;
} BucketNode;

void bucket_sort(int arr[], int n, int max_value) {
    // Create an array of n empty bucket nodes.
    BucketNode *buckets[n];
    for (int i = 0; i < n; i++) {
        buckets[i] = NULL;
    }
    
    // Distribute the elements of the input array into the buckets.
    for (int i = 0; i < n; i++) {
        int idx = (arr[i] * n) / (max_value + 1);
        BucketNode *new_node = (BucketNode *) malloc(sizeof(BucketNode));
        new_node->data = arr[i];
        new_node->next = buckets[idx];
        buckets[idx] = new_node;
    }
    
    // Sort each bucket individually.
    for (int i = 0; i < n; i++) {
        BucketNode *head = buckets[i];
        BucketNode *tail = buckets[i];
        while (tail != NULL && tail->next != NULL) {
            tail = tail->next;
        }
        if (head != NULL) {
            bucket_sort_helper(&head, tail);
            buckets[i] = head;
        }
    }
    
    // Merge the sorted buckets back into the input array.
    int idx = 0;
    for (int i = 0; i < n; i++) {
        BucketNode *cur = buckets[i];
        while (cur != NULL) {
            arr[idx++] = cur->data;
            cur = cur->next;
        }
    }
}

// Helper function to sort a bucket in place using insertion sort.
void bucket_sort_helper(BucketNode **head_ref, BucketNode *tail) {
    if (*head_ref == tail) {
        return;
    }
    BucketNode *last_sorted_node = *head_ref;
    BucketNode *cur_node = last_sorted_node->next;
    while (cur_node != NULL) {
        if (cur_node->data < (*head_ref)->data) {
            last_sorted_node->next = cur_node->next;
            cur_node->next = *head_ref;
            *head_ref = cur_node;
            cur_node = last_sorted_node->next;
        } else if (cur_node->data >= tail->data) {
            last_sorted_node = tail;
            cur_node = tail->next;
        } else {
            BucketNode *prev_node = *head_ref;
            while (prev_node != last_sorted_node && cur_node->data >= prev_node->next->data) {
                prev_node = prev_node->next;
            }
            if (prev_node != last_sorted_node) {
                last_sorted_node->next = cur_node->next;
                cur_node->next = prev_node->next;
                prev_node->next = cur_node;
                cur_node = last_sorted_node->next;
            } else {
                last_sorted_node = cur_node;
                cur_node = cur_node->next;
            }
        }
    }
}

int main() {
    int arr[] = {8, 2, 5, 9, 3, 7, 1, 4, 6, 0};
    int n = sizeof(arr) / sizeof(int);
    int max_value = 9;
    printf("Original array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    bucket_sort(arr, n, max_value);
    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}