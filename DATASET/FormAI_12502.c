//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#define NUM_BUCKETS 10

struct Node {
    int data;
    struct Node* next;
};

typedef struct Node node;

node* createNode(int data) {
    node* newNode = (node*)malloc(sizeof(node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

node* insert(node* head, int data) {
    node* newNode = createNode(data);
    if (head == NULL) {
        head = newNode;
    } else {
        newNode->next = head;
        head = newNode;
    }
    return head;
}

void printBucket(node* head) {
    node* temp = head;
    printf("\n");
    while (temp != NULL) {
        printf("%d", temp->data);
        if (temp->next != NULL) printf(", ");
        temp = temp->next;
    }
}

void printBuckets(node* buckets[NUM_BUCKETS]) {
    for (int i = 0; i < NUM_BUCKETS; i++) {
        printf("Bucket %d: ", i);
        printBucket(buckets[i]);
    }
}

void bucketSort(int arr[], int n) {
    node* buckets[NUM_BUCKETS];

    for (int i = 0; i < NUM_BUCKETS; i++) {
        buckets[i] = NULL;
    }

    for (int i = 0; i < n; i++) {
        int bucketIdx = arr[i] / 10;
        buckets[bucketIdx] = insert(buckets[bucketIdx], arr[i]);
    }

    printBuckets(buckets);
}

int main() {
    int arr[] = {13, 25, 4, 39, 16, 12, 17, 35};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original Array:");
    for (int i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if (i != n - 1) printf(", ");
    }

    bucketSort(arr, n);

    return 0;
}