//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: authentic
#include <stdio.h>
#include <stdlib.h>

#define NUM_BUCKETS 10

typedef struct node {
    int value;
    struct node* next;
} Node;

void bucketsort(int arr[], int n) {
    // Create buckets
    Node* buckets[NUM_BUCKETS] = {NULL};

    // Insert elements into buckets
    int i, j;
    for (i = 0; i < n; i++) {
        int index = arr[i] / NUM_BUCKETS;

        // Create new node
        Node* newNode = malloc(sizeof(Node));
        newNode->value = arr[i];
        newNode->next = NULL;

        // Insert node into bucket
        if (buckets[index] == NULL) {
            buckets[index] = newNode;
        } else {
            Node* curr = buckets[index];
            while (curr->next != NULL && curr->value <= arr[i]) {
                curr = curr->next;
            }
            if (curr == buckets[index] && curr->value > arr[i]) {
                newNode->next = curr;
                buckets[index] = newNode;
            } else {
                newNode->next = curr->next;
                curr->next = newNode;
            }
        }
    }

    // Concatenate buckets into sorted array
    j = 0;
    for (i = 0; i < NUM_BUCKETS; i++) {
        Node* curr = buckets[i];
        while (curr != NULL) {
            arr[j++] = curr->value;
            curr = curr->next;
        }
    }
}

int main() {
    // Test bucketsort
    int arr[] = {29, 25, 3, 49, 9, 37, 21, 43, 5, 47};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    bucketsort(arr, n);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}