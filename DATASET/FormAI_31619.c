//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>

// Define a linked list node to hold each element in a bucket
struct node {
    float data;
    struct node* next;
};

void bucketSort(float arr[], int n) {
    // Create an array of bucket pointers
    struct node* bucket[n];

    // Initialize each bucket to be empty
    for (int i = 0; i < n; i++) {
        bucket[i] = NULL;
    }

    // Insert each element of arr into its appropriate bucket
    for (int i = 0; i < n; i++) {
        int bucketIndex = n * arr[i];
        struct node* newNode = (struct node*) malloc(sizeof(struct node));
        newNode->data = arr[i];
        newNode->next = NULL;

        if (bucket[bucketIndex] == NULL) {
            bucket[bucketIndex] = newNode;
        } else {
            struct node* curr = bucket[bucketIndex];

            if (newNode->data < curr->data) {
                newNode->next = curr;
                bucket[bucketIndex] = newNode;
            } else {
                while (curr->next != NULL && newNode->data > curr->next->data) {
                    curr = curr->next;
                }

                newNode->next = curr->next;
                curr->next = newNode;
            }
        }
    }

    // Traverse each bucket, adding its elements to arr in order
    int index = 0;

    for (int i = 0; i < n; i++) {
        struct node* curr = bucket[i];

        while (curr != NULL) {
            arr[index] = curr->data;
            index++;
            curr = curr->next;
        }
    }
}

int main() {
    float arr[] = {0.23, 0.84, 0.12, 0.45, 0.67, 0.93, 0.28, 0.56};
    int n = sizeof(arr) / sizeof(arr[0]);

    bucketSort(arr, n);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%.2f ", arr[i]);
    }
    printf("\n");

    return 0;
}