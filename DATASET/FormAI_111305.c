//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: shocked
#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 10

struct node {
    int data;
    struct node *next;
};

void bucket_sort(int array[], int n) {
    int i, j;
    struct node *temp;
    struct node **buckets = (struct node **) malloc(n * sizeof(struct node *));

    for (i = 0; i < n; i++) {
        buckets[i] = NULL;
    }

    for (i = 0; i < n; i++) {
        temp = (struct node *) malloc(sizeof(struct node));
        temp->data = array[i];
        temp->next = NULL;

        j = (array[i] * n) / (ARRAY_SIZE + 1);
        if (buckets[j] == NULL) {
            buckets[j] = temp;
        } else {
            struct node *p = buckets[j];
            struct node *q = NULL;

            while (p != NULL && p->data <= temp->data) {
                q = p;
                p = p->next;
            }

            if (q == NULL) {
                temp->next = buckets[j];
                buckets[j] = temp;
            } else {
                temp->next = q->next;
                q->next = temp;
            }
        }
    }

    for (i = 0; i < n; i++) {
        struct node *p = buckets[i];
        j = 0;

        while (p != NULL) {
            array[j++] = p->data;
            struct node *temp = p;
            p = p->next;
            free(temp);
        }
    }

    free(buckets);
}

int main() {
    int array[ARRAY_SIZE] = {51, 22, 13, 4, 7, 8, 29, 13, 29, 44};
    int i;

    printf("Unsorted array: ");
    for (i = 0; i < ARRAY_SIZE; i++) {
        printf("%d ", array[i]);
    }

    bucket_sort(array, ARRAY_SIZE);

    printf("\nSorted array: ");
    for (i = 0; i < ARRAY_SIZE; i++) {
        printf("%d ", array[i]);
    }

    printf("\n");

    return 0;
}