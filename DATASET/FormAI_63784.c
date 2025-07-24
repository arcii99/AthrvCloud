//FormAI DATASET v1.0 Category: Data structures visualization ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define MAX_HEAP_SIZE 100
#define PARENT(i) i / 2
#define LEFT_CHILD(i) i * 2
#define RIGHT_CHILD(i) i * 2 + 1

void heapify(int heap[], int size) {
    for (int i = size / 2; i >= 1; i--) {
        int j = i;
        while (j <= size / 2) {
            if (RIGHT_CHILD(j) > size && LEFT_CHILD(j) <= size) {
                if (heap[j] < heap[LEFT_CHILD(j)]) {
                    int temp = heap[j];
                    heap[j] = heap[LEFT_CHILD(j)];
                    heap[LEFT_CHILD(j)] = temp;
                }
                break;
            } else if (LEFT_CHILD(j) <= size && RIGHT_CHILD(j) <= size) {
                int max_child = heap[LEFT_CHILD(j)] > heap[RIGHT_CHILD(j)] ? LEFT_CHILD(j) : RIGHT_CHILD(j);
                if (heap[j] < heap[max_child]) {
                    int temp = heap[j];
                    heap[j] = heap[max_child];
                    heap[max_child] = temp;
                    j = max_child;
                } else {
                    break;
                }
            } else {
                break;
            }
        }
    }
}

void print_heap(int heap[], int size) {
    for (int i = 1; i <= size; i++) {
        printf("%d ", heap[i]);
    }
    printf("\n");
    fflush(stdout);
}

int main() {
    srand(time(NULL));
    int heap[MAX_HEAP_SIZE];
    int heap_size = 0;
    while (1) {
        // Add random numbers to heap
        if (heap_size < MAX_HEAP_SIZE) {
            heap_size++;
            heap[heap_size] = rand() % 100;
            heapify(heap, heap_size);
        }
        // Print heap
        printf("Heap: ");
        print_heap(heap, heap_size);
        // Wait for random amount of time
        usleep((rand() % 300 + 300) * 1000);
    }
    return 0;
}