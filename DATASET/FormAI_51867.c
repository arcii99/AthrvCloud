//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>

/* Node definition for our linked list */
struct Node {
    int data;
    struct Node* next;
};

/* Function to insert nodes into the linked list in ascending order */
void insert(struct Node** head_ref, int value) {
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->data = value;
    new_node->next = NULL;

    struct Node* current_node = *head_ref;
    struct Node* previous_node = NULL;

    while (current_node != NULL && current_node->data < value) {
        previous_node = current_node;
        current_node = current_node->next;
    }

    if (previous_node == NULL) {
        new_node->next = *head_ref;
        *head_ref = new_node;
    } else {
        new_node->next = current_node;
        previous_node->next = new_node;
    }
}

/* Function to perform bucket sort on an array of integers */
void bucket_sort(int array[], int size) {
    int num_buckets = 10; // We have 10 buckets, each of size 10

    /* Initialize linked lists for each bucket */
    struct Node* buckets[num_buckets];
    for (int i = 0; i < num_buckets; i++) {
        buckets[i] = NULL;
    }

    /* Insert each element of the input array into the appropriate bucket */
    for (int i = 0; i < size; i++) {
        int bucket_index = array[i] / num_buckets;
        insert(&buckets[bucket_index], array[i]);
    }

    /* Traverse each bucket and copy its elements back into the input array */
    int index = 0;
    for (int i = 0; i < num_buckets; i++) {
        struct Node* current_node = buckets[i];
        while (current_node != NULL) {
            array[index++] = current_node->data;
            current_node = current_node->next;
        }
    }
}

/* Driver code to test bucket_sort function */
int main() {
    int array[] = {34, 12, 76, 23, 80, 56, 57, 48};
    int size = sizeof(array) / sizeof(array[0]);

    bucket_sort(array, size);

    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    return 0;
}