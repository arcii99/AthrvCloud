//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

#define BUCKET_SIZE 10 // number of buckets

struct node {
    int value;
    struct node *next;
};

void bucket_sort(int array[], int size) {
    // create buckets
    struct node *buckets[BUCKET_SIZE] = { NULL };
    
    // insert values into buckets
    for (int i = 0; i < size; i++) {
        struct node *new_node = malloc(sizeof(struct node));
        new_node->value = array[i];
        new_node->next = NULL;
        
        // calculate bucket index
        int bucket_index = array[i] / BUCKET_SIZE;
        if (buckets[bucket_index] == NULL) {
            buckets[bucket_index] = new_node;
        } else {
            // insert node at the end of the bucket
            struct node *curr = buckets[bucket_index];
            while (curr->next != NULL) {
                curr = curr->next;
            }
            curr->next = new_node;
        }
    }
    
    // sort each bucket using bubble sort
    for (int i = 0; i < BUCKET_SIZE; i++) {
        struct node *curr = buckets[i];
        while (curr != NULL) {
            struct node *next = curr->next;
            while (next != NULL) {
                if (next->value < curr->value) {
                    int temp = next->value;
                    next->value = curr->value;
                    curr->value = temp;
                }
                next = next->next;
            }
            curr = curr->next;
        }
    }
    
    // output sorted array
    printf("Sorted array:\n");
    for (int i = 0; i < BUCKET_SIZE; i++) {
        struct node *curr = buckets[i];
        while (curr != NULL) {
            printf("%d ", curr->value);
            curr = curr->next;
        }
    }
}

int main() {
    int array[] = {23, 45, 12, 56, 78, 34, 10, 6, 99, 88};
    int size = sizeof(array) / sizeof(int);
    
    printf("Original array:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
    
    bucket_sort(array, size);
    
    return 0;
}