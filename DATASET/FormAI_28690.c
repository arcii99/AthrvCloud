//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: safe
#include<stdio.h>
#include<stdlib.h>
#define COMPILE_OK 0
#define BUCKET_SIZE 10

struct Node {
    int data;
    struct Node* next;
};

void BucketSort(int arr[], int n) {
    struct Node* buckets[BUCKET_SIZE];
    int i, j, k;

    // Initialize empty buckets
    for (i = 0; i < BUCKET_SIZE; ++i) {
        buckets[i] = NULL;
    }

    // Fill the buckets with respective elements
    for (i = 0; i < n; ++i) {
        struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
        newNode->data = arr[i];
        newNode->next = NULL;

        j = arr[i] / BUCKET_SIZE;
        if (buckets[j] == NULL) {
            buckets[j] = newNode;
        } else {
            struct Node* temp = buckets[j];
            while (temp->next != NULL && temp->next->data < arr[i]) {
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }

    // Sort the elements within the buckets
    for (i = 0; i < BUCKET_SIZE; ++i) {
        struct Node* head = buckets[i];
        while (head != NULL) {
            arr[k] = head->data;
            head = head->next;
            k++;
        }
    }

    // Free the memory allocated for nodes in the buckets
    for (i = 0; i < BUCKET_SIZE; ++i) {
        struct Node* head = buckets[i];
        while (head != NULL) {
            struct Node* temp = head;
            head = head->next;
            free(temp);
        }
    }

}

int main() {
    int arr[] = {4, 15, 6, 3, 8, 1, 11, 7, 2, 9, 10, 5, 12, 14, 13, 18, 17, 19, 16, 20};
    int n = sizeof(arr)/sizeof(arr[0]);

    BucketSort(arr, n);

    printf("Sorted array : ");
    for (int i = 0; i < n; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return COMPILE_OK;
}