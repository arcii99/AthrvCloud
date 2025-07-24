//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>

#define NUM_BUCKETS 10

typedef struct node {
    int value;
    struct node *next;
} Node;

void print_array(int array[], int size) {
    for(int i=0; i<size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void print_buckets(Node *buckets[]) {
    for(int i=0; i<NUM_BUCKETS; i++) {
        printf("Bucket %d: ", i);
        Node *current = buckets[i];
        while(current != NULL) {
            printf("%d ", current->value);
            current = current->next;
        }
        printf("\n");
    }
}

void bucket_sort(int array[], int size) {
    // Create buckets
    Node *buckets[NUM_BUCKETS] = {NULL};

    // Insert elements into their respective buckets
    for(int i=0; i<size; i++) {
        int bucket_index = array[i] / NUM_BUCKETS;
        Node *new_node = (Node*) malloc(sizeof(Node));
        new_node->value = array[i];
        new_node->next = buckets[bucket_index];
        buckets[bucket_index] = new_node;
    }

    // Sort individual buckets
    for(int i=0; i<NUM_BUCKETS; i++) {
        Node *current = buckets[i];
        int *bucket_array = (int*) malloc(sizeof(int) * size);
        int bucket_size = 0;
        while(current != NULL) {
            bucket_array[bucket_size++] = current->value;
            current = current->next;
        }
        for(int j=0; j<bucket_size-1; j++) {
            for(int k=j+1; k<bucket_size; k++) {
                if(bucket_array[j] > bucket_array[k]) {
                    int temp = bucket_array[j];
                    bucket_array[j] = bucket_array[k];
                    bucket_array[k] = temp;
                }
            }
        }

        current = buckets[i];
        for(int j=0; j<bucket_size; j++) {
            current->value = bucket_array[j];
            current = current->next;
        }

        free(bucket_array);
    }

    // Merge buckets
    int index = 0;
    for(int i=0; i<NUM_BUCKETS; i++) {
        Node *current = buckets[i];
        while(current != NULL) {
            array[index++] = current->value;
            current = current->next;
        }
    }
}

int main() {
    int array[] = {97, 13, 9, 0, 91, 80, 54, 34, 27, 76, 55, 21, 44, 82, 66, 39};
    int size = sizeof(array) / sizeof(int);

    printf("Unsorted Array: ");
    print_array(array, size);

    bucket_sort(array, size);

    printf("Sorted Array: ");
    print_array(array, size);

    return 0;
}