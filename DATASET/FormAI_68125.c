//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: active
#include <stdio.h>
#include <stdlib.h>
#define N 10000 
#define m 10

// Define the linked list structure
struct Node {
    int data;
    struct Node* next;
} bucket[m];

// Bucket sort function
void bucketSort(int arr[]) 
{
    int i, j, k;
    struct Node *p;
    for (i = 0; i < m; i++) {
        bucket[i].next = NULL;
    }
    for (i = 0; i < N; i++) {
        p = (struct Node*)malloc(sizeof(struct Node));
        p->data = arr[i];
        p->next = bucket[arr[i] / m].next;
        bucket[arr[i] / m].next = p;
    }
    k = 0;
    for (i = 0; i < m; i++) {
        struct Node* head = &bucket[i];
        if (head->next != NULL) {
            p = head->next;
            int temp[m];
            for (j = 0; j < m; j++) {
                temp[j] = 0;
            }
            while (p) {
                temp[p->data % m]++;
                p = p->next;
            }
            for (j = 0; j < m; j++) {
                for (int k = 0; k < temp[j]; k++) {
                    arr[k++] = j + i * 10;
                }
            }
        }
    }
}

int main()
{
    int arr[N];
    srand(0);
    printf("Before Bucket Sort:\n");
    for (int i = 0; i < N; i++) {
        arr[i] = rand() % 10000 + 1;
        printf("%d ", arr[i]);
    }
    bucketSort(arr);
    printf("\nAfter Bucket Sort:\n");
    for (int i = 0; i < N; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}