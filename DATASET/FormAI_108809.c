//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>

// Define the number of buckets 
#define NUM_BUCKETS 5 

// Define a struct for the buckets 
struct node {
    int value;
    struct node *next;
};

// Define a function to insert a value into a bucket 
void insert(struct node **bucket, int value) {
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    new_node->value = value;
    new_node->next = *bucket;
    *bucket = new_node;
}

// Define a function to sort the buckets 
void sort_buckets(struct node **bucket) {
    struct node *temp;
    int value, i, j;

    for (i = 0; i < NUM_BUCKETS; i++) {
        temp = bucket[i];

        // Sort each bucket using Insertion Sort 
        for (j = 1; temp != NULL && j < NUM_BUCKETS; j++) {
            value = temp->value;
            struct node *prev = temp;
            while (prev->next != NULL && prev->next->value < value) {
                prev = prev->next;
            }
            temp = temp->next;

            // Insert the value into its proper sorted location 
            if (prev == temp) {
                continue;
            }
            struct node *tmp = prev->next;
            prev->next = (struct node*)malloc(sizeof(struct node));
            prev->next->value = value;
            prev->next->next = tmp;
        }
    }
}

// Define a function to perform Bucket Sort 
void bucket_sort(int *array, int size) {
    // Create the buckets 
    struct node **bucket = (struct node**)malloc(sizeof(struct node*) * NUM_BUCKETS);
    int i, j;
    for (i = 0; i < NUM_BUCKETS; i++) {
        bucket[i] = NULL;
    }

    // Insert each element from the array into its corresponding bucket 
    for (i = 0; i < size; i++) {
        insert(&bucket[array[i] / NUM_BUCKETS], array[i]);
    }

    // Sort each bucket 
    sort_buckets(bucket);

    // Combine the sorted buckets back into the original array 
    j = 0;
    for (i = 0; i < NUM_BUCKETS; i++) {
        struct node *temp = bucket[i];
        while (temp != NULL) {
            array[j++] = temp->value;
            temp = temp->next;
        }
    }

    // Free memory 
    for (i = 0; i < NUM_BUCKETS; i++) {
        struct node *temp = bucket[i];
        while (temp != NULL) {
            struct node *delete_node = temp;
            temp = temp->next;
            free(delete_node);
        }
    }
    free(bucket);
}

// Define a function to print an array 
void print_array(int *array, int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main() {
    int array[10] = {23, 55, 12, 42, 7, 98, 65, 31, 17, 76};
    int size = 10;

    printf("Original array: ");
    print_array(array, size);

    bucket_sort(array, size);

    printf("Sorted array: ");
    print_array(array, size);

    return 0;
}