//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: calm
#include <stdio.h>
#include <stdlib.h>

#define BUCKET_SIZE 10  // Bucket size is fixed to 10 for this example
#define ARRAY_SIZE 100  // Array size can be changed to test the program

typedef struct Node {
    int value;
    struct Node* next;
} Node;

void insert(Node** head, int value) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->value = value;
    new_node->next = NULL;

    if (*head == NULL) {
        *head = new_node;
    } else {
        Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
}

void print_bucket(Node* head) {
    while (head != NULL) {
        printf("%d ", head->value);
        head = head->next;
    }
}

void bucket_sort(int* array, int size) {
    Node** buckets = (Node**)malloc(BUCKET_SIZE * sizeof(Node*));
    
    int i;
    for (i = 0; i < BUCKET_SIZE; i++) {
        buckets[i] = NULL;
    }

    for (i = 0; i < size; i++) {
        int bucket_index = array[i] / BUCKET_SIZE;
        insert(&buckets[bucket_index], array[i]);
    }

    for (i = 0; i < BUCKET_SIZE; i++) {
        printf("Bucket %d: ", i);
        print_bucket(buckets[i]);
        printf("\n");
    }

    int index = 0;
    for (i = 0; i < BUCKET_SIZE; i++) {
        Node* current = buckets[i];
        while (current != NULL) {
            array[index] = current->value;
            current = current->next;
            index++;
        }
    }

    free(buckets);
}

int main() {
    int array[ARRAY_SIZE];
    int i;

    printf("Before sorting: ");
    for (i = 0; i < ARRAY_SIZE; i++) {
        array[i] = rand() % 100;
        printf("%d ", array[i]);
    }

    printf("\nAfter sorting:\n");
    bucket_sort(array, ARRAY_SIZE);

    printf("\nSorted array: ");
    for (i = 0; i < ARRAY_SIZE; i++) {
        printf("%d ", array[i]);
    }

    return 0;
}