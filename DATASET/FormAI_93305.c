//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

void BucketSort(int arr[], int n) {
    int i, j;
    struct node **buckets;

    buckets = (struct node **) malloc(sizeof(struct node *) * n);

    for (i = 0; i < n; i++) {
        buckets[i] = NULL;
    }

    for (i = 0; i < n; i++) {
        struct node *new_node = (struct node *) malloc(sizeof(struct node));
        new_node->data = arr[i];
        new_node->next = buckets[(arr[i]/10)];
        buckets[(arr[i]/10)] = new_node;
    }

    for (i = 0; i < n; i++) {
        struct node *bucket = buckets[i];
        while (bucket != NULL) {
            printf("%d ", bucket->data);
            bucket = bucket->next;
        }
    }
}

int main() {
    int arr[10] = {78, 92, 56, 31, 82, 64, 8, 75, 11, 61};

    BucketSort(arr, 10);

    return 0;
}