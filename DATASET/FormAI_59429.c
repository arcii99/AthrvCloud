//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
 
typedef struct node Node;
struct node {
    int data;
    Node* next;
};
 
void countSort(int arr[], int n) {
    // Create buckets
    Node** buckets = (Node**) malloc(n * sizeof(Node*));
    for (int i = 0; i < n; ++i) {
        buckets[i] = NULL;
    }
 
    // Add elements to buckets
    for (int i = 0; i < n; ++i) {
        int index = arr[i] / n;
        Node* node = (Node*) malloc(sizeof(Node));
        node->data = arr[i];
        node->next = NULL;
        if (buckets[index] == NULL) {
            buckets[index] = node;
        } else {
            Node* curr = buckets[index];
            while (curr->next != NULL) {
                curr = curr->next;
            }
            curr->next = node;
        }
    }
 
    // Sort elements in buckets
    for (int i = 0; i < n; ++i) {
        Node* curr = buckets[i];
        while (curr != NULL) {
            int index = curr->data / n;
            arr[index++] = curr->data;
            Node* temp = curr;
            curr = curr->next;
            free(temp);
        }
    }
 
    // Free bucket memory
    free(buckets);
}
 
void printArray(int arr[], int n) {
    printf("[");
    for (int i = 0; i < n; ++i) {
        printf("%d", arr[i]);
        if (i != n-1) {
            printf(", ");
        }
    }
    printf("]\n");
}
 
int main() {
    int arr[] = {5, 2, 9, 5, 2, 3, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
 
    printf("Original array: ");
    printArray(arr, n);
 
    countSort(arr, n);
 
    printf("Sorted array: ");
    printArray(arr, n);
 
    return 0;
}