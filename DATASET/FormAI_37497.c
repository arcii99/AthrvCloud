//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: innovative
#include <stdio.h>
#include <stdlib.h>

// Define the maximum value and the number of buckets
#define MAX_VALUE 1000
#define NUM_BUCKETS 10

// Define the structure of a node in the linked list
struct Node {
    int value;
    struct Node* next;
};
typedef struct Node Node;

// Define the structure of a single bucket
struct Bucket {
    Node* head;
    Node* tail;
};
typedef struct Bucket Bucket;

// Define the data structure that holds all the buckets
struct BucketArray {
    Bucket* buckets;
};
typedef struct BucketArray BucketArray;

// Initialize a new empty linked list
Node* create_list() {
    Node* list = NULL;
    return list;
}

// Insert a new node with the given value at the tail of the linked list
void insert(Node** head, Node** tail, int value) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->value = value;
    new_node->next = NULL;
    if (*head == NULL) {
        *head = new_node;
        *tail = new_node;
    } else {
        (*tail)->next = new_node;
        *tail = new_node;
    }
}

// Append the second linked list to the first linked list
void append(Node** head1, Node** tail1, Node** head2, Node** tail2) {
    if (*head1 == NULL) {
        *head1 = *head2;
        *tail1 = *tail2;
    } else {
        (*tail1)->next = *head2;
        *tail1 = *tail2;
    }
    *head2 = NULL;
    *tail2 = NULL;
}

// Print the elements of the linked list
void print(Node* head) {
    while (head != NULL) {
        printf("%d ", head->value);
        head = head->next;
    }
}

// Initialize a new empty bucket
Bucket create_bucket() {
    Bucket bucket;
    bucket.head = NULL;
    bucket.tail = NULL;
    return bucket;
}

// Initialize a new empty array of buckets
BucketArray create_bucket_array() {
    BucketArray arr;
    arr.buckets = (Bucket*)malloc(NUM_BUCKETS * sizeof(Bucket));
    for (int i = 0; i < NUM_BUCKETS; i++) {
        arr.buckets[i] = create_bucket();
    }
    return arr;
}

// Insert a new value into the appropriate bucket based on the key
void insert_into_bucket(Bucket* bucket, int key) {
    insert(&(bucket->head), &(bucket->tail), key);
}

// Sort the given array using bucket sort
void bucket_sort(int* arr, int n) {
    // Create an array of empty buckets
    BucketArray bucket_array = create_bucket_array();

    // Insert each element of the input array into the appropriate bucket
    for (int i = 0; i < n; i++) {
        int key = arr[i] / (MAX_VALUE / NUM_BUCKETS);
        insert_into_bucket(&(bucket_array.buckets[key]), arr[i]);
    }

    // Concatenate all the buckets in the array
    Node* sorted_list = NULL;
    Node* sorted_list_tail = NULL;
    for (int i = 0; i < NUM_BUCKETS; i++) {
        append(&sorted_list, &sorted_list_tail, &(bucket_array.buckets[i].head), &(bucket_array.buckets[i].tail));
    }

    // Copy the sorted list back into the input array
    int i = 0;
    while (sorted_list != NULL) {
        arr[i] = sorted_list->value;
        i++;
        sorted_list = sorted_list->next;
    }
}

int main() {
    int arr[] = {56, 23, 94, 12, 78, 34, 67, 89, 43, 21, 84, 37, 65, 50, 99, 77, 88, 55, 29, 48};
    int n = sizeof(arr) / sizeof(int);

    printf("Original array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    bucket_sort(arr, n);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}