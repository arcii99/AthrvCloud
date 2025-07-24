//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: real-life
#include<stdio.h>
#include<stdlib.h>

void bucketSort(float arr[], int size) {

    // Step 1: Create number of Buckets and initialize all Buckets Elements as Empty Lists
    int i, j;
    const int BUCKET_COUNT = 10;
    typedef struct node {
        float data;
        struct node* next;
    } node;

    // Create 10 buckets and initialize each to Null
    node* Bucket[BUCKET_COUNT];
    for (i = 0; i < BUCKET_COUNT; ++i) {
        Bucket[i] = NULL;
    }

    // Step 2: Put Elements into the Buckets
    // Create nodes for the given values
    for (i = 0; i < size; ++i) {
        node* newNode = (node*)malloc(sizeof(node));
        newNode->data = arr[i];
        newNode->next = NULL;

        // Find bucket index for this element         
        int bucketIdx = arr[i] * BUCKET_COUNT;
        if (Bucket[bucketIdx] == NULL) {
            Bucket[bucketIdx] = newNode;
        }
        else {
            node* temp = Bucket[bucketIdx];
            while(temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    // Step 3: Sort the Buckets
    // Sort and assign on the given array.
    int k = 0;
    for (i = 0; i < BUCKET_COUNT; ++i) {
        // Sort array of the current bucket
        node* head = Bucket[i];
        for (j = 1; head != NULL && j<i; j++){
            head = head->next;
        }
        // sort linkedlist
        int swapped;
        do{
            swapped = 0;
            node* curr;
            for (curr = head; curr->next != NULL; curr = curr->next) {
                if (curr->data > curr->next->data) {
                    //Swap adjacent nodes
                    float temp = curr->data;
                    curr->data = curr->next->data;
                    curr->next->data = temp;
                    swapped = 1;
                }
            }
        } while (swapped);

        // Assign the sorted Bucket Elements to output array
        node* temp = Bucket[i];
        while (temp != NULL) {
            arr[k++] = temp->data;
            temp = temp->next;
        }
    }
}

/* Display the contents of an array */
void printArray(float arr[], int n) {
    int i;
    for (i = 0; i < n; i++)
        printf("%f ", arr[i]);
    printf("\n");
}

/* Driver program to test Bucket Sort */
int main() {
    float arr[] = { 0.897, 0.565, 0.656, 0.1234, 0.665, 0.3434 };
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Input Array: ");
    printArray(arr, n);

    bucketSort(arr, n);

    printf("Sorted Array: ");
    printArray(arr, n);
    return 0;
}