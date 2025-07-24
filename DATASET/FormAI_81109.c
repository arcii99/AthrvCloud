//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: standalone
#include <stdio.h>
#include <stdlib.h>

// define a linked list node for bucket
typedef struct node {
    int value;
    struct node* next;
} Node;

// function to create a new node in the bucket
Node* createNode(int value) {
    Node* node = (Node*) malloc(sizeof(Node));
    node->value = value;
    node->next = NULL;
    return node;
}

// function to insert a node to the bucket
void insert(Node* bucket[], int index, int value) {
    Node* newNode = createNode(value);
    Node* current = bucket[index];
    if (current == NULL) {
        bucket[index] = newNode;
    } else {
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

// function to print the sorted array
void printArray(int array[], int size) {
    printf("Sorted array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
}

// function to implement bucket sort algorithm
void bucketSort(int array[], int size, int bucketSize) {
    Node* bucket[bucketSize];
    for (int i = 0; i < bucketSize; i++) {
        bucket[i] = NULL;
    }
    for (int i = 0; i < size; i++) {
        int index = (array[i] / bucketSize);
        insert(bucket, index, array[i]);
    }
    int j = 0;
    for (int i = 0; i < bucketSize; i++) {
        Node* current = bucket[i];
        int tempArray[bucketSize];
        int k = 0;
        while (current != NULL) {
            tempArray[k++] = current->value;
            current = current->next;
        }
        for (int n = 0; n < k; n++) {
            for (int m = n + 1; m < k; m++) {
                if (tempArray[n] > tempArray[m]) {
                    int temp = tempArray[n];
                    tempArray[n] = tempArray[m];
                    tempArray[m] = temp;
                }
            }
        }
        for (int p = 0; p < k; p++) {
            array[j++] = tempArray[p];
        }
    }
    printArray(array, size);
}

// main function to test the bucket sort
int main() {
    int array[] = {87, 68, 92, 75, 55, 82, 99, 46};
    int size = sizeof(array) / sizeof(int);
    int bucketSize = 10;
    bucketSort(array, size, bucketSize);
    return 0;
}