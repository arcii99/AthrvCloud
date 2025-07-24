//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>

// Definition of a linked list node
struct node {
    int val;
    struct node *next;
};

// Function to create a new node with given value
struct node *new_node(int val) {
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->val = val;
    temp->next = NULL;
    return temp;
}

// Function to insert a node at the beginning of the linked list
void insert_node(struct node **head, int val) {
    struct node *temp = new_node(val);
    temp->next = *head;
    *head = temp;
}

// Function to sort the given array using bucket sort algorithm
void bucket_sort(int arr[], int n, int num_buckets) {
    // Create an array of linked lists as buckets
    struct node *buckets[num_buckets];
    for (int i = 0; i < num_buckets; i++) {
        buckets[i] = NULL;
    }

    // Insert elements into respective buckets
    for (int i = 0; i < n; i++) {
        int bucket_num = arr[i] / num_buckets;
        insert_node(&buckets[bucket_num], arr[i]);
    }

    // Sort each bucket using insertion sort algorithm
    for (int i = 0; i < num_buckets; i++) {
        struct node *current = buckets[i];
        while (current != NULL) {
            // Re-insert node in the correct order after sorting
            struct node *prev = NULL;
            struct node *temp = current->next;
            while (temp != NULL && temp->val < current->val) {
                prev = temp;
                temp = temp->next;
            }
            if (prev == NULL) {
                buckets[i] = current->next;
            } else {
                prev->next = current->next;
            }
            insert_node(&buckets[i], current->val);

            current = temp;
        }
    }

    // Replace original array with sorted elements from buckets
    int index = 0;
    for (int i = 0; i < num_buckets; i++) {
        struct node *current = buckets[i];
        while (current != NULL) {
            arr[index] = current->val;
            index++;
            current = current->next;
        }
    }
}

// Function to print the elements of an array
void print_array(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Example usage of bucket sort
int main() {
    int arr[] = {34, 12, 17, 23, 20, 43, 7, 29, 31, 18};
    int n = sizeof(arr) / sizeof(arr[0]);
    int num_buckets = 5;

    printf("Original array: ");
    print_array(arr, n);

    bucket_sort(arr, n, num_buckets);

    printf("Sorted array: ");
    print_array(arr, n);

    return 0;
}