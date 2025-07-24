//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: safe
#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 1000 // size of input array
#define BUCKET_SIZE 10 // size of each bucket for bucket sort

// node in the linked list
typedef struct Node {
    int value;
    struct Node* next;
} Node;

// function to insert a node at the end of a linked list
void insertNode(Node** head, int value) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = NULL;
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node* curr = *head;
    while (curr->next != NULL) {
        curr = curr->next;
    }
    curr->next = newNode;
}

// function to print the values in a linked list
void printLinkedList(Node* head) {
    while (head != NULL) {
        printf("%d ", head->value);
        head = head->next;
    }
    printf("\n");
}

// function to sort an array using bucket sort
void bucketSort(int* arr, int n) {
    // create an array of buckets
    Node** buckets = (Node**) malloc(BUCKET_SIZE * sizeof(Node*));
    for (int i = 0; i < BUCKET_SIZE; i++) {
        buckets[i] = NULL;
    }
    // insert each element into the appropriate bucket
    for (int i = 0; i < n; i++) {
        int bucketIndex = arr[i] / BUCKET_SIZE;
        insertNode(&buckets[bucketIndex], arr[i]);
    }
    // sort each bucket individually (using insertion sort)
    for (int i = 0; i < BUCKET_SIZE; i++) {
        Node* head = buckets[i];
        while (head != NULL) {
            int value = head->value;
            Node* curr = head->next;
            // find the correct position for the current value in the sorted bucket
            while (curr != NULL && curr->value < value) {
                curr = curr->next;
            }
            // insert the current value at the correct position
            head->next = curr;
            head = curr;
        }
        // print the sorted bucket for debugging purposes
        printf("Bucket %d: ", i);
        printLinkedList(buckets[i]);
    }
    // copy the values back into the original array
    int index = 0;
    for (int i = 0; i < BUCKET_SIZE; i++) {
        Node* head = buckets[i];
        while (head != NULL) {
            arr[index] = head->value;
            head = head->next;
            index++;
        }
    }
}

// test the bucket sort implementation
int main() {
    int arr[ARRAY_SIZE];
    // initialize the input array with random values between 0 and 99
    for (int i = 0; i < ARRAY_SIZE; i++) {
        arr[i] = rand() % 100;
    }
    // print the input array for debugging purposes
    printf("Input array: ");
    for (int i = 0; i < ARRAY_SIZE; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    // sort the input array using bucket sort
    bucketSort(arr, ARRAY_SIZE);
    // print the sorted array for debugging purposes
    printf("Sorted array: ");
    for (int i = 0; i < ARRAY_SIZE; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}