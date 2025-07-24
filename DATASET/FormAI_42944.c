//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: safe
#include <stdio.h>
#include <stdlib.h>

#define BUCKET_SIZE 10

typedef struct Node {
    int data;
    struct Node* next;
} Node;

void print_array(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void print_buckets(Node* buckets[]) {
    for (int i = 0; i < BUCKET_SIZE; i++) {
        printf("Bucket %d: ", i);
        Node* current = buckets[i];
        while (current != NULL) {
            printf("%d ", current->data);
            current = current->next;
        }
        printf("\n");
    }
}

void insert(Node** head, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

void delete(Node** head) {
    if (*head == NULL) {
        return;
    }
    Node* temp = *head;
    *head = (*head)->next;
    free(temp);
}

void bucket_sort(int arr[], int size) {
    Node* buckets[BUCKET_SIZE] = { NULL };
    for (int i = 0; i < size; i++) {
        int index = arr[i] / BUCKET_SIZE;
        insert(&buckets[index], arr[i]);
    }
    printf("Initial Buckets:\n");
    print_buckets(buckets);

    for (int i = 0; i < BUCKET_SIZE; i++) {
        Node* current = buckets[i];
        while (current != NULL) {
            int j = i;
            int data = current->data;
            while (j > 0 && data < buckets[j-1]->data) {
                buckets[j]->data = buckets[j-1]->data;
                j--;
            }
            insert(&buckets[j], data);
            delete(&current);
        }
    }

    printf("Sorted Array: ");
    int index = 0;
    for (int i = 0; i < BUCKET_SIZE; i++) {
        Node* current = buckets[i];
        while (current != NULL) {
            arr[index] = current->data;
            index++;
            current = current->next;
        }
    }
    print_array(arr, size);

    printf("Final Buckets:\n");
    print_buckets(buckets);
}

int main() {
    int arr[10] = { 22, 45, 12, 8, 10, 6, 72, 81, 33, 18 };
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Original Array: ");
    print_array(arr, size);

    bucket_sort(arr, size);

    return 0;
}