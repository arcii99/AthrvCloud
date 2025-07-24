//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct for holding bucket and linked-list info
typedef struct bucket_node {
    int data;
    struct bucket_node* next;
} bucket_node;

// Define a struct for holding bucket size and pointer to head
typedef struct bucket {
    int size;
    bucket_node* head;
} bucket;

// Function to initialize a new bucket with a size of 0 and head set to NULL
void init_bucket(bucket* b) {
    b->size = 0;
    b->head = NULL;
}

// Function to insert a node into a bucket in ascending order
void insert_sorted(bucket* b, int data) {
    bucket_node* new_node = (bucket_node*)malloc(sizeof(bucket_node));
    new_node->data = data;
    new_node->next = NULL;
    
    if (b->head == NULL || data < b->head->data) {
        new_node->next = b->head;
        b->head = new_node;
    }
    else {
        bucket_node* curr_node = b->head;
        while (curr_node->next != NULL && data > curr_node->next->data) {
            curr_node = curr_node->next;
        }
        new_node->next = curr_node->next;
        curr_node->next = new_node;    
    }
    b->size++;
}

// Function to print out the contents of a bucket
void print_bucket(bucket* b) {
    bucket_node* curr_node = b->head;
    while (curr_node != NULL) {
        printf("%d ", curr_node->data);
        curr_node = curr_node->next;
    }
}

// Function to free all memory associated with a bucket
void free_bucket(bucket* b) {
    bucket_node* curr_node = b->head;
    while (curr_node != NULL) {
        bucket_node* temp_node = curr_node;
        curr_node = curr_node->next;
        free(temp_node);
    }
}

// Function to bucket sort an array of integers
void bucket_sort(int* arr, int size, int num_buckets) {
    bucket* buckets = (bucket*)malloc(num_buckets*sizeof(bucket));
    
    // Initialize each bucket with a size of 0 and head set to NULL
    for (int i = 0; i < num_buckets; i++) {
        init_bucket(&buckets[i]);
    }
    
    // Insert each element of the array into its corresponding bucket
    for (int i = 0; i < size; i++) {
        int bucket_index = arr[i] / num_buckets;
        insert_sorted(&buckets[bucket_index], arr[i]);
    }
    
    // Concatenate the sorted buckets back into the original array
    int arr_index = 0;
    for (int i = 0; i < num_buckets; i++) {
        bucket_node* curr_node = buckets[i].head;
        while (curr_node != NULL) {
            arr[arr_index] = curr_node->data;
            curr_node = curr_node->next;
            arr_index++;
        }
    }
    
    // Free memory associated with each bucket
    for (int i = 0; i < num_buckets; i++) {
        free_bucket(&buckets[i]);
    }
    
    // Free memory associated with the array of buckets
    free(buckets);
}

int main() {
    int arr[] = {42, 28, 15, 7, 63, 18, 30, 36, 25, 40};
    int size = sizeof(arr)/sizeof(arr[0]);
    int num_buckets = 5;
    
    printf("Unsorted array:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    bucket_sort(arr, size, num_buckets);
    
    printf("Sorted array:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    return 0;
}