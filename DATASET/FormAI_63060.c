//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: active
#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void insert(struct Node** head_ref, int data) {
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = NULL;
    struct Node* last = *head_ref;
    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = new_node;
}

void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

void bucketSort(float arr[], int n) {
    int i, j;

    struct Node** bucket;
    bucket = (struct Node**) malloc(n * sizeof(struct Node*));

    for (i = 0; i < n; i++) {
        bucket[i] = NULL;
    }

    for (i = 0; i < n; i++) {
        int index = n * arr[i];
        insert(&bucket[index], arr[i]);
    }

    for (i = 0; i < n; i++) {
        printList(bucket[i]);
    }
}

int main() {
    float arr[] = {0.88, 0.25, 0.76, 0.34, 0.99, 0.48};
    int n = sizeof(arr) / sizeof(arr[0]);
    bucketSort(arr, n);
    return 0;
}