//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>

// Node structure for bucket
struct Node {
    int data;
    struct Node* next;
};

// Function to insert node into the bucket
void insert(struct Node** head_ref, int value) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = value;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

// Function to sort the buckets using insertion sort
void sort_bucket(struct Node** head_ref) {
    struct Node* prev, *current, *temp;
    prev = NULL;
    current = (*head_ref);

    // Insertion sort
    while (current != NULL) {
        temp = current->next;
        while (temp != NULL && temp->data < current->data) {
            prev = temp;
            temp = temp->next;
        }
        if (temp != current->next) {
            prev->next = current;
            current->next = temp;
        }
        else {
            prev = current;
        }
        current = temp;
    }
}

// Bucket Sort function
void bucket_sort(int arr[], int n) {
    int i, j;
    struct Node** buckets;

    // Create n buckets
    buckets = (struct Node**)calloc(n, sizeof(struct Node*));

    // Insert elements into the buckets
    for (i = 0; i < n; i++) {
        int index = n * arr[i];
        insert(&buckets[index], arr[i]);
    }

    // Sort the buckets using insertion sort
    for (i = 0; i < n; i++) {
        sort_bucket(&buckets[i]);
    }

    // Merge the buckets to obtain the sorted array
    j = 0;
    for (i = 0; i < n; i++) {
        struct Node* current = buckets[i];
        while (current != NULL) {
            arr[j++] = current->data;
            current = current->next;
        }
    }

    // Free allocated memory
    for (i = 0; i < n; i++) {
        free(buckets[i]);
    }
    free(buckets);
}

// Driver code
int main() {
    int arr[] = { 0.89, 0.65, 0.12, 0.45, 0.35, 0.21, 0.76 };
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Before sorting: ");
    for (int i = 0; i < n; i++) {
        printf("%.2f ", arr[i]);
    }
    printf("\n");

    bucket_sort(arr, n);

    printf("After sorting: ");
    for (int i = 0; i < n; i++) {
        printf("%.2f ", arr[i]);
    }
    printf("\n");

    return 0;
}