//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: multiplayer
#include<stdio.h>
#include<stdlib.h>

#define N 10

typedef struct node {
    int data;
    struct node* next;
} Node;

void BucketSort(int arr[]) {
    int pos, i;
    Node *head[N], *temp;

    for (i = 0; i < N; i++) {
        head[i] = NULL;
    }

    for (i = 0; i < N; i++) {
        temp = (Node*)malloc(sizeof(Node));
        temp->data = arr[i];
        temp->next = head[(int)(arr[i]/10)];
        head[(int)(arr[i]/10)] = temp;
    }

    for (i = 0; i < N; i++) {
        Node *ptr = head[i];
        while (ptr != NULL) {
            printf("%d ", ptr->data);
            ptr = ptr->next;
        }
    }
}

int main() {
    int arr[N] = {54, 46, 83, 66, 95, 92, 43, 21, 70, 30};
    BucketSort(arr);
    return 0;
}