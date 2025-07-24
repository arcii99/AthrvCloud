//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: random
#include <stdio.h>
#include <stdlib.h>

// Linked list node structure to store elements in the bucket
struct node {
    int value;
    struct node *next;
};

// Function to insert element into the linked list
void insert(struct node **head, int value) {
    struct node *new_node = (struct node*) malloc(sizeof(struct node));
    new_node->value = value;
    new_node->next = NULL;
    if (*head == NULL) {
        *head = new_node;
    } else {
        struct node *tmp = *head;
        while (tmp->next != NULL) {
            tmp = tmp->next;
        }
        tmp->next = new_node;
    }
}

// Function to perform Bucket Sort
void bucket_sort(int array[], int n) {
    struct node *buckets[10] = {NULL};
    // Inserting elements into the buckets
    for (int i = 0; i < n; i++) {
        int bucket_index = array[i] / 10; // dividing element value by 10
        insert(&buckets[bucket_index], array[i]);
    }
    // Sorting elements in each bucket using insertion sort
    for (int i = 0; i < 10; i++) {
        if (buckets[i] != NULL) {
            struct node *tmp = buckets[i];
            int bucket_array[10] = {0};
            while (tmp != NULL) {
                bucket_array[tmp->value % 10] = tmp->value;
                tmp = tmp->next;
            }
            // Insertion sort implementation for each bucket
            for (int j = 1; j < 10; j++) {
                int key = bucket_array[j];
                int k = j - 1;
                while (k >= 0 && bucket_array[k] > key) {
                    bucket_array[k + 1] = bucket_array[k];
                    k--;
                }
                bucket_array[k + 1] = key;
            }
            // Copying sorted elements back to the original array
            int j = 0;
            tmp = buckets[i];
            while (tmp != NULL) {
                tmp->value = bucket_array[j];
                j++;
                tmp = tmp->next;
            }
        }
    }
    // Copying all elements back to the original array after sorting
    int j = 0;
    for (int i = 0; i < 10; i++) {
        struct node *tmp = buckets[i];
        while (tmp != NULL) {
            array[j] = tmp->value;
            j++;
            tmp = tmp->next;
        }
    }
}

// Function to print the array elements
void display(int array[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

// Main function
int main() {
    int n = 10;
    int array[] = {73, 12, 5, 24, 32, 17, 85, 53, 90, 46};
    printf("Original array: ");
    display(array, n);
    bucket_sort(array, n);
    printf("Sorted array: ");
    display(array, n);
    return 0;
}