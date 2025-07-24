//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: protected
#include <stdio.h>
#include <stdlib.h>

// Define the structure of a bucket
typedef struct Node {
    int value;
    struct Node* next;
} BucketNode;

// Define the structure of the bucket sort
typedef struct {
    BucketNode **buckets;
    int num_buckets;
} BucketSort;

// Function to create a new node for the bucket
BucketNode* create_node(int value) {
    BucketNode* new_node = (BucketNode*) malloc(sizeof(BucketNode));
    new_node->value = value;
    new_node->next = NULL;
    return new_node;
}

// Function to insert a node into the bucket
void insert_node(BucketNode** head, int value) {
    if (*head == NULL) {
        *head = create_node(value);
    } else {
        BucketNode* curr = *head;
        while (curr->next != NULL) {
            curr = curr->next;
        }
        curr->next = create_node(value);
    }
}

// Function to print the sorted array
void print_array(int* arr, int len) {
    printf("[");
    for (int i = 0; i < len; i++) {
        printf("%d", arr[i]);
        if (i < len - 1) printf(", ");
    }
    printf("]\n");
}

// Function to perform the bucket sort
void bucket_sort(int* arr, int len, int num_buckets) {
    // Create a new bucket sort structure
    BucketSort* bs = (BucketSort*) malloc(sizeof(BucketSort));
    bs->num_buckets = num_buckets;

    // Allocate memory for the buckets
    bs->buckets = (BucketNode**) malloc(num_buckets * sizeof(BucketNode*));
    for (int i = 0; i < num_buckets; i++) {
        bs->buckets[i] = NULL;
    }
    
    // Loop through the input array and insert each value into the appropriate bucket
    for (int i = 0; i < len; i++) {
        int bucket_index = arr[i] / num_buckets;
        insert_node(&bs->buckets[bucket_index], arr[i]);
    }

    // Loop through the buckets and retrieve the sorted array
    int index = 0;
    for (int i = 0; i < num_buckets; i++) {
        BucketNode* curr = bs->buckets[i];
        while (curr != NULL) {
            arr[index++] = curr->value;
            BucketNode* temp = curr;
            curr = curr->next;
            free(temp);
        }
    }
    
    // Free allocated memory
    free(bs->buckets);
    free(bs);
}

int main() {
    int arr[] = {34, 12, 76, 45, 1, 23, 67, 89, 5, 42};
    int len = sizeof(arr) / sizeof(int);
    int num_buckets = 5;
    
    printf("Unsorted array: ");
    print_array(arr, len);

    bucket_sort(arr, len, num_buckets);

    printf("Sorted array:   ");
    print_array(arr, len);

    return 0;
}