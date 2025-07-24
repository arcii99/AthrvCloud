//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>

// Node for bucket (linked list)
typedef struct node {
    int data;
    struct node* next;
} Node;

// Bucket sort function
void bucketSort(int arr[], int n, int max_val) {
    // Create buckets (linked lists)
    Node** buckets = (Node**) malloc(sizeof(Node*) * max_val);
    for (int i = 0; i < max_val; i++) {
        buckets[i] = NULL;
    }

    // Add elements to buckets
    for (int i = 0; i < n; i++) {
        int index = (arr[i] * max_val) / (max_val + 1);
        Node* new_node = (Node*) malloc(sizeof(Node));
        new_node->data = arr[i];
        new_node->next = buckets[index];
        buckets[index] = new_node;
    }

    // Sort each bucket using insertion sort
    for (int i = 0; i < max_val; i++) {
        Node* curr = buckets[i];
        Node* sorted = NULL;
        while (curr != NULL) {
            Node* temp = curr;
            curr = curr->next;

            // Insert node into sorted list
            if (sorted == NULL || temp->data < sorted->data) {
                temp->next = sorted;
                sorted = temp;
            } else {
                Node* curr2 = sorted;
                while (curr2->next != NULL && curr2->next->data < temp->data) {
                    curr2 = curr2->next;
                }
                temp->next = curr2->next;
                curr2->next = temp;
            }
        }
        buckets[i] = sorted;
    }

    // Combine buckets into final array
    int index = 0;
    for (int i = 0; i < max_val; i++) {
        Node* curr = buckets[i];
        while (curr != NULL) {
            arr[index++] = curr->data;
            curr = curr->next;
        }
    }

    // Free memory
    for (int i = 0; i < max_val; i++) {
        Node* curr = buckets[i];
        while (curr != NULL) {
            Node* temp = curr;
            curr = curr->next;
            free(temp);
        }
    }
    free(buckets);
}

// Main function
int main() {
    int n = 10;
    int arr[] = {8, 4, 2, 0, 3, 9, 7, 5, 1, 6};
    int max_val = 10;

    printf("Original array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Sort array using bucket sort
    bucketSort(arr, n, max_val);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}