//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>

#define BUCKET_SIZE 10

// Node structure for linked list in bucket
struct node {
    int data;
    struct node *next;
};

// Function to insert a node at the end of linked list in bucket
struct node *insertNode(struct node *head, int data) {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        struct node *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    return head;
}

// Function to get maximum value in array
int getMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

// Function to perform bucket sort
void bucketSort(int arr[], int n) {
    // Create and initialize the buckets
    struct node *buckets[BUCKET_SIZE] = {NULL};

    // Get the maximum value in array
    int max = getMax(arr, n);

    // Divide each element by the maximum value and put in corresponding bucket
    for (int i = 0; i < n; i++) {
        int index = arr[i] * BUCKET_SIZE / (max + 1);
        buckets[index] = insertNode(buckets[index], arr[i]);
    }

    // Sort each bucket individually using insertion sort
    for (int i = 0; i < BUCKET_SIZE; i++) {
        struct node *head = buckets[i];
        if (head != NULL) {
            // Convert the linked list to array
            int size = 0;
            while (head != NULL) {
                arr[size++] = head->data;
                head = head->next;
            }

            // Sort the array using insertion sort
            for (int j = 1; j < size; j++) {
                int key = arr[j];
                int k = j - 1;
                while (k >= 0 && arr[k] > key) {
                    arr[k + 1] = arr[k];
                    k--;
                }
                arr[k + 1] = key;
            }
        }
    }
}

// Driver code
int main() {
    int arr[] = {80, 30, 90, 40, 50, 70, 10, 60, 20};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Unsorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    bucketSort(arr, n);

    printf("Array sorted using bucket sort: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}