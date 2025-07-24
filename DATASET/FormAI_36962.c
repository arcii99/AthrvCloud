//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>

// Structures
typedef struct node {
    int value;
    struct node* next;
}node;

typedef struct queue {
    node* head;
    node* tail;
}queue;

// Function Declarations
void bucketSort(int arr[], int n, int numBuckets);
void enqueue(queue* q, int value);
int dequeue(queue* q);
void printArray(int arr[], int size);

// Main Function
int main() {
    int arr[] = {34, 12, 78, 90, 67, 54, 23, 56};
    int n = sizeof(arr)/sizeof(arr[0]);
    int numBuckets = 5;

    printf("Unsorted Array: ");
    printArray(arr, n);

    bucketSort(arr, n, numBuckets);

    printf("Sorted Array: ");
    printArray(arr, n);

    return 0;
}

// Function Definitions
void bucketSort(int arr[], int n, int numBuckets) {
    int i, j, k;
    int min = arr[0];
    int max = arr[0];
    queue* buckets = (queue*)malloc(numBuckets * sizeof(queue));

    // Find the minimum and maximum values in the array
    for (i = 1; i < n; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
        else if (arr[i] > max) {
            max = arr[i];
        }
    }

    // Assign values to the buckets
    float range = (float)(max - min + 1) / numBuckets;
    for (i = 0; i < numBuckets; i++) {
        buckets[i].head = NULL;
        buckets[i].tail = NULL;
    }

    for (i = 0; i < n; i++) {
        int bucketIndex = (int)((arr[i] - min) / range);
        enqueue(&buckets[bucketIndex], arr[i]);
    }

    // Sort the buckets individually and merge them
    k = 0;
    for (i = 0; i < numBuckets; i++) {
        node* current = buckets[i].head;
        int* tempArr = (int*)malloc((n+1) * sizeof(int));
        j = 0;
        while (current != NULL) {
            tempArr[j++] = dequeue(&buckets[i]);
            current = current->next;
        }

        // Insertion Sort on tempArr
        int size = j;
        int l, m, temp;
        for (l = 1; l < size; l++) {
            temp = tempArr[l];
            m = l - 1;
            while (m >= 0 && tempArr[m] > temp) {
                tempArr[m+1] = tempArr[m];
                m--;
            }
            tempArr[m+1] = temp;
        }

        // Merge the sorted bucket with the final array
        for (l = 0; l < size; l++) {
            arr[k++] = tempArr[l];
        }
        free(tempArr);
    }

    free(buckets);
    return;
}

void enqueue(queue* q, int value) {
    node* newNode = (node*)malloc(sizeof(node));
    newNode->value = value;
    newNode->next = NULL;
    if (q->tail == NULL) {
        q->head = newNode;
        q->tail = newNode;
    }
    else {
        q->tail->next = newNode;
        q->tail = newNode;
    }
    return;
}

int dequeue(queue* q) {
    if (q->head == NULL) {
        printf("Queue is empty!\n");
        return -1;
    }
    else {
        node* temp = q->head;
        int value = temp->value;
        q->head = q->head->next;
        if (q->head == NULL) {
            q->tail = NULL;
        }
        free(temp);
        return value;
    }
}

void printArray(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return;
}