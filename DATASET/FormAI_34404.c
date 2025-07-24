//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: complex
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void bucketSort(int arr[], int n) {
    struct Node bucket[n];

    for (int i = 0; i < n; ++i) {
        bucket[i].data = 0;
        bucket[i].next = NULL;
    }

    for (int i = 0; i < n; ++i) {
        int index = n * arr[i] / (100 + 1);
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = arr[i];
        newNode->next = NULL;

        if (bucket[index].next == NULL) {
            bucket[index].next = newNode;
        } else {
            struct Node* currNode = bucket[index].next;

            while (currNode->next != NULL && currNode->next->data < arr[i]) {
                currNode = currNode->next;
            }

            newNode->next = currNode->next;
            currNode->next = newNode;
        }
    }

    for (int i = 0; i < n; ++i) {
        struct Node* currNode = bucket[i].next;

        while (currNode != NULL) {
            printf("%d ", currNode->data);
            currNode = currNode->next;
        }
    }
}

int main() {
    int arr[] = {29, 25, 3, 49, 9, 37, 21, 43};
    int n = sizeof(arr) / sizeof(arr[0]);

    bucketSort(arr, n);

    return 0;
}