//FormAI DATASET v1.0 Category: Memory management ; Style: accurate
#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

typedef struct MemoryBlock {
    int size;
    int isFree;
} MemoryBlock;

MemoryBlock heap[SIZE];

void initializeHeap() {
    int i;
    for (i = 0; i < SIZE; i++) {
        heap[i].isFree = 1;
    }
}

void split(int index, int size) {
    MemoryBlock *left = &heap[index];
    MemoryBlock *right = &heap[index + size];

    right->size = left->size - size;
    right->isFree = 1;

    left->size = size;
}

int firstFit(int size) {
    int i, j;
    int start = -1;

    for (i = 0; i < SIZE; i++) {
        if (heap[i].isFree == 1 && heap[i].size >= size) {
            start = i;
            break;
        }
    }

    if (start != -1) {
        int end = start;

        for (j = start; j < SIZE; j++) {
            if (heap[j].isFree == 1) {
                if (heap[j].size >= size) {
                    end = j;
                }
                else {
                    break;
                }
            }
            else {
                break;
            }
        }

        int diff = end - start + 1;

        if (diff == 1) {
            heap[start].isFree = 0;
            return start;
        }
        else {
            int index = start;
            for (i = start; i <= end; i++) {
                if (heap[i].size >= size && heap[i].isFree == 1 && i - start < diff) {
                    index = i;
                    diff = i - start;
                }
            }

            heap[index].isFree = 0;

            if (diff == 0) {
                return index;
            }
            else {
                split(index, size);
                return index;
            }
        }
    }
    else {
        return -1;
    }
}

void freeMemory(int index) {
    if (heap[index].isFree == 0) {
        heap[index].isFree = 1;

        int leftIndex = index - 1;
        int rightIndex = index + 1;

        while (leftIndex >= 0) {
            if (heap[leftIndex].isFree == 1) {
                leftIndex--;
            }
            else {
                break;
            }
        }

        while (rightIndex < SIZE) {
            if (heap[rightIndex].isFree == 1) {
                rightIndex++;
            }
            else {
                break;
            }
        }

        if (rightIndex < SIZE && leftIndex >= 0) {
            if (heap[leftIndex].isFree == 1 && heap[rightIndex].isFree == 1) {
                int newSize = heap[leftIndex].size + heap[index].size + heap[rightIndex].size;
                heap[leftIndex].size = newSize;
                heap[rightIndex].isFree = 1;

                int i;
                for (i = index; i < SIZE - 1; i++) {
                    heap[i] = heap[i + 1];
                }

                heap[SIZE - 1].isFree = 1;
                heap[SIZE - 1].size = 0;
            }
        }
        else if (leftIndex >= 0 && rightIndex >= SIZE) {
            if (heap[leftIndex].isFree == 1) {
                int newSize = heap[leftIndex].size + heap[index].size;
                heap[leftIndex].size = newSize;

                int i;
                for (i = index; i < SIZE - 1; i++) {
                    heap[i] = heap[i + 1];
                }

                heap[SIZE - 1].isFree = 1;
                heap[SIZE - 1].size = 0;
            }
        }
        else if (leftIndex < 0 && rightIndex < SIZE) {
            if (heap[rightIndex].isFree == 1) {
                int newSize = heap[index].size + heap[rightIndex].size;
                heap[index].size = newSize;
                heap[rightIndex].isFree = 1;

                int i;
                for (i = index + 1; i < SIZE - 1; i++) {
                    heap[i] = heap[i + 1];
                }

                heap[SIZE - 1].isFree = 1;
                heap[SIZE - 1].size = 0;
            }
        }
    }
}

void printHeap() {
    int i;
    printf("Index\tSize\tFree\n");
    for (i = 0; i < SIZE; i++) {
        printf("%d\t%d\t%d\n", i, heap[i].size, heap[i].isFree);
    }
}

int main() {
    initializeHeap();

    int firstAddr = firstFit(20);
    printf("First Fit: Allocate block of size 20 at address %d\n", firstAddr);
    printHeap();

    int secondAddr = firstFit(10);
    printf("First Fit: Allocate block of size 10 at address %d\n", secondAddr);
    printHeap();

    int thirdAddr = firstFit(15);
    printf("First Fit: Allocate block of size 15 at address %d\n", thirdAddr);
    printHeap();

    freeMemory(secondAddr);
    printf("Free memory at address %d\n", secondAddr);
    printHeap();

    int fourthAddr = firstFit(30);
    printf("First Fit: Allocate block of size 30 at address %d\n", fourthAddr);
    printHeap();

    freeMemory(firstAddr);
    printf("Free memory at address %d\n", firstAddr);
    printHeap();

    freeMemory(thirdAddr);
    printf("Free memory at address %d\n", thirdAddr);
    printHeap();

    freeMemory(fourthAddr);
    printf("Free memory at address %d\n", fourthAddr);
    printHeap();

    return 0;
}