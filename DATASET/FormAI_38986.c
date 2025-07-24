//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: shocked
#include<stdio.h>
#include<stdlib.h>

// Define the maximum number of buckets
#define MAX_BUCKET 10

// Define the structure of each bucket
typedef struct node {
    int value;
    struct node* next;
} Node;

// Function to create a new node
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Error: Memory allocation failed.\n");
        exit(1);
    }
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a value into a bucket
void insertIntoBucket(Node** bucket, int value) {
    Node* newNode = createNode(value);
    newNode->next = *bucket;
    *bucket = newNode;
}

// Function to free the memory used by a bucket
void freeBucket(Node* bucket) {
    while (bucket != NULL) {
        Node* temp = bucket;
        bucket = bucket->next;
        free(temp);
    }
}

// Function to print the contents of a bucket
void printBucket(Node* bucket) {
    while (bucket != NULL) {
        printf("%d ", bucket->value);
        bucket = bucket->next;
    }
}

// Bucket sort function
void bucketSort(int arr[], int n) {
    Node* buckets[MAX_BUCKET] = { NULL };
    int max = arr[0];
    int min = arr[0];

    // Find the maximum and minimum values in the array
    for (int i = 1; i < n; i++) {
        if (arr[i] > max)
            max = arr[i];
        if (arr[i] < min)
            min = arr[i];
    }

    // Determine the size of each bucket
    double bucketSize = (double)(max - min + 1) / MAX_BUCKET;

    // Insert each element of the array into its corresponding bucket
    for (int i = 0; i < n; i++) {
        int bucketIndex = (arr[i] - min) / bucketSize;
        insertIntoBucket(&buckets[bucketIndex], arr[i]);
    }

    // Sort the elements in each bucket
    for (int i = 0; i < MAX_BUCKET; i++) {
        Node* curr = buckets[i];
        while (curr != NULL) {
            Node* temp = curr->next;
            while (temp != NULL) {
                if (temp->value < curr->value) {
                    int tempValue = temp->value;
                    temp->value = curr->value;
                    curr->value = tempValue;
                }
                temp = temp->next;
            }
            curr = curr->next;
        }
    }

    // Copy the elements from the buckets back into the array
    int index = 0;
    for (int i = 0; i < MAX_BUCKET; i++) {
        Node* curr = buckets[i];
        while (curr != NULL) {
            arr[index] = curr->value;
            curr = curr->next;
            index++;
        }
        // Free the memory used by the bucket
        freeBucket(buckets[i]);
    }
}

int main() {
    int arr[] = { 3, 6, 1, 8, 4, 2, 10, 5, 9, 7 };
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Before sorting: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    bucketSort(arr, n);

    printf("After sorting: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}