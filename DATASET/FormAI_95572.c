//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#define BUCKET_SIZE 10

/* A curious implementation of the bucket sort algorithm */

/* Create a struct to hold the data in each node */
typedef struct node {
    int data;
    struct node * next;
} Node;

/* Insert each element into the correct bucket */
void insert_element(int element, Node * buckets[]) {
    Node * new_node = (Node *) malloc(sizeof(Node)); // Allocate memory for the new node
    new_node->data = element;
    new_node->next = NULL;

    int bucket_number = element / BUCKET_SIZE; // Determine which bucket to insert into
    Node * current_bucket = buckets[bucket_number]; // Get the current bucket
    if (current_bucket == NULL) { // If the bucket is empty, insert the new node as the head
        buckets[bucket_number] = new_node;
    } else { // Otherwise, insert the new node at the end of the bucket
        while (current_bucket->next != NULL) {
            current_bucket = current_bucket->next;
        }
        current_bucket->next = new_node;
    }
}

/* Return the data stored in the given node */
int get_data(Node * node) {
    return node->data;
}

/* Sort each bucket and combine the results */
void bucket_sort(int input_array[], int n) {
    Node * buckets[BUCKET_SIZE] = {NULL}; // Create an array of buckets
    for (int i = 0; i < n; i++) {
        insert_element(input_array[i], buckets); // Insert each element into the correct bucket
    }

    int index = 0;
    for (int i = 0; i < BUCKET_SIZE; i++) { // Iterate through each bucket
        Node * current_bucket = buckets[i];
        while (current_bucket != NULL) { // Sort the elements in the bucket and insert them into the output array
            input_array[index] = get_data(current_bucket);
            index++;
            current_bucket = current_bucket->next;
        }
    }
}

/* Helper function to print an array */
void print_array(int array[], int n) {
    printf("[");
    for (int i = 0; i < n - 1; i++) {
        printf("%d, ", array[i]);
    }
    printf("%d]\n", array[n - 1]);
}

int main() {
    int array[] = {28, 89, 12, 45, 64, 27, 75, 34, 66, 9, 54, 0, 86, 42, 36, 99, 81, 72, 18, 63};
    int n = sizeof(array) / sizeof(array[0]);

    printf("The unsorted array is:\n");
    print_array(array, n);

    bucket_sort(array, n);

    printf("The sorted array is:\n");
    print_array(array, n);

    return 0;
}