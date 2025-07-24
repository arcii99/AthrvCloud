//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: innovative
#include<stdio.h>
#include<stdlib.h>

/* A structure representing a node in the linked list */
struct Node {
    int value;
    struct Node* next;
};

/* Function to perform bucket sort on an array of integers */
void bucketSort(int arr[], int n) {

    int i, j;
    int numBuckets = 10; /* Number of buckets set to 10 */
    
    /* Create an array of pointers to nodes */
    struct Node** bucket = (struct Node**) malloc(numBuckets * sizeof(struct Node*));

    /* Initialize all the elements in the array to NULL */
    for (i = 0; i < numBuckets; i++) {
        bucket[i] = NULL;
    }

    /* Place the elements in the input array into the corresponding buckets */
    for (i = 0; i < n; i++) {
        int index = (numBuckets * arr[i]) / 100; /* Calculate the index using the formula */
        
        /* Create a new node */
        struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
        newNode->value = arr[i];
        newNode->next = NULL;
        
        /* Insert the node at the head of the corresponding bucket */
        if (bucket[index] == NULL) {
            bucket[index] = newNode;
        }
        else {
            newNode->next = bucket[index];
            bucket[index] = newNode;
        }
    }

    /* Traverse the array of buckets and sort each linked list using insertion sort */
    for (i = 0; i < numBuckets; i++) {
        struct Node* current = bucket[i];
        
        /* Sort the linked list using insertion sort */
        while (current != NULL) {
            struct Node* temp = current->next;
            struct Node* prev = NULL;
            int value = current->value;

            while (temp != NULL && temp->value < value) {
                prev = temp;
                temp = temp->next;
            }

            /* If a node with a smaller value is found, swap the values */
            if (temp != NULL && temp->value == value) {
                prev = temp;
                temp = temp->next;
            }

            /* Remove the current node from its current position */
            current->next = temp;

            if (prev == NULL) {
                bucket[i] = current;
            }
            else {
                prev->next = current;
            }
            prev = current;
            current = temp;
        }
    }

    /* Copy the elements of the sorted buckets back into the input array */
    int k = 0;
    for (i = 0; i < numBuckets; i++) {
        struct Node* current = bucket[i];

        while (current != NULL) {
            arr[k++] = current->value;
            current = current->next;
        }
    }

    /* Free the memory allocated to the nodes and the array of pointers */
    for (i = 0; i < numBuckets; i++) {
        struct Node* current = bucket[i];

        while (current != NULL) {
            struct Node* temp = current;
            current = current->next;
            free(temp);
        }
    }
    free(bucket);
}

/* Function to print an array of integers */
void printArray(int arr[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

/* Main function to test the implementation */
int main() {
    int arr[] = { 78, 17, 39, 26, 72, 94, 21, 12, 23, 68 };
    int n = sizeof(arr) / sizeof(int);
    printf("Input array: ");
    printArray(arr, n);
    bucketSort(arr, n);
    printf("Sorted array: ");
    printArray(arr, n);
    return 0;
}