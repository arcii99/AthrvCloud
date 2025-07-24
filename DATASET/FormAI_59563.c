//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

#define NUM_BUCKETS 10

/* Define a node for a bucket */
typedef struct Node {
    int val;
    struct Node* next;
} Node;

/* Insert a value into its corresponding bucket */
void bucket_insert(Node** bucket, int val) {
    Node* new_node = malloc(sizeof(Node));
    new_node->val = val;
    new_node->next = NULL;
    if (*bucket == NULL) {
        *bucket = new_node;
    } else {
        Node* curr = *bucket;
        Node* prev = NULL;
        while (curr != NULL && curr->val < val) {
            prev = curr;
            curr = curr->next;
        }
        if (prev == NULL) {
            new_node->next = *bucket;
            *bucket = new_node;
        } else {
            new_node->next = curr;
            prev->next = new_node;
        }
    }
}

/* Sort an array of integers using bucket sort */
void bucket_sort(int* arr, int n) {
    Node* buckets[NUM_BUCKETS] = {NULL};
    for (int i = 0; i < n; i++) {
        bucket_insert(&buckets[arr[i] / NUM_BUCKETS], arr[i]);
    }
    int index = 0;
    for (int i = 0; i < NUM_BUCKETS; i++) {
        Node* curr = buckets[i];
        while (curr != NULL) {
            arr[index++] = curr->val;
            curr = curr->next;
        }
    }
}

/* Test the bucket sort implementation */
int main() {
    int arr[] = {5, 3, 7, 4, 2, 8, 1, 9, 6, 0};
    int n = sizeof(arr) / sizeof(int);
    printf("Before Bucket Sort:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    bucket_sort(arr, n);
    printf("After Bucket Sort:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}