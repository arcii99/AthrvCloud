//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#define ARRAY_SIZE 10 //set array size

//define node structure for linked lists
typedef struct node {
    int data;
    struct node *next;
} Node;

/*
 * This function will perform the bucket sort algorithm. Given an input array of integers,
 * it first creates an array of linked lists of size 10. It then iterates through the input array and
 * inserts each element into the appropriate linked list based on its value. Finally, it extracts
 * each element from the linked lists in order and places them back into the input array.
 */
void bucketSort(int arr[])
{
    int i, j;
    Node *temp;
    Node *bucket[10]; //array of linked lists

    //initialize buckets
    for (i = 0; i < 10; i++) {
        bucket[i] = NULL;
    }

    //insert elements into buckets
    for (i = 0; i < ARRAY_SIZE; i++) {
        temp = (Node*) malloc(sizeof(Node));
        temp->data = arr[i];
        temp->next = NULL;

        //calculate which bucket to place element in
        j = arr[i] / 10;
        if (bucket[j] == NULL) {
            bucket[j] = temp;
        }
        else {
            //insert element at head of linked list
            temp->next = bucket[j];
            bucket[j] = temp;
        }
    }

    //extract elements from buckets and place back into input array
    i = 0;
    for (j = 0; j < 10; j++) {
        temp = bucket[j];
        while (temp != NULL) {
            arr[i++] = temp->data;
            temp = temp->next;
        }
    }
}

int main()
{
    int array[ARRAY_SIZE] = { 50, 30, 20, 70, 80, 10, 90, 60, 40, 100 };

    printf("Unsorted array:\n");
    for (int i=0; i<ARRAY_SIZE; i++) {
        printf("%d ", array[i]);
    }

    bucketSort(array);

    printf("\nSorted array:\n");
    for (int i=0; i<ARRAY_SIZE; i++) {
        printf("%d ", array[i]);
    }

    return 0;
}