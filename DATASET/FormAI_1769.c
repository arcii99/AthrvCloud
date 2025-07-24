//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: modular
#include <stdio.h>
#include <stdlib.h>

#define BUCKET_RANGE 10  // the bucket range

/* create a node struct to store the data */
typedef struct Node {
    int data;
    struct Node *next;
} Node;

/* create a bucket struct to store the nodes */
typedef struct Bucket {
    Node *head;
} Bucket;

/* implementation of the bucket sort */
void bucket_sort(int *arr, int size) {
    int i, j;
    int max_val = arr[0];
    Bucket bucket[BUCKET_RANGE];
    /* create B empty buckets */
    for (i = 0; i < BUCKET_RANGE; i++) {
        bucket[i].head = NULL;
    }
    /* determine the max_val in the array */
    for (i = 1; i < size; i++) {
        if (arr[i] > max_val) {
            max_val = arr[i];
        }
    }
    /* put the elements into the appropriate bucket */
    for (i = 0; i < size; i++) {
        int index = BUCKET_RANGE * arr[i] / (max_val + 1);
        /* create a new node */
        Node *new_node = (Node*)malloc(sizeof(Node));
        new_node->data = arr[i];
        new_node->next = NULL;
        /* insert the new node at the head */
        if (bucket[index].head == NULL) {
            bucket[index].head = new_node;
        } else {
            Node *node = bucket[index].head;
            if (new_node->data < node->data) {
                /* insert new_node at the head */
                new_node->next = node;
                bucket[index].head = new_node;
            } else {
                while (node->next != NULL && new_node->data > node->next->data) {
                    node = node->next;
                }
                /* insert new_node at the tail */
                new_node->next = node->next;
                node->next = new_node;
            }
        }
    }
    /* copy the elements back into the array */
    int k = 0;
    for (i = 0; i < BUCKET_RANGE; i++) {
        Node *node = bucket[i].head;
        while (node != NULL) {
            arr[k++] = node->data;
            node = node->next;
        }
    }
}

/* main function */
int main() {
    int arr[] = {3, 5, 2, 8, 4, 7, 1, 9, 6};
    int size = sizeof(arr) / sizeof(arr[0]);
    printf("Before sorting:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    bucket_sort(arr, size);

    printf("After sorting:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}