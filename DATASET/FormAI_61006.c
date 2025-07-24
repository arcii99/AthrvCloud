//FormAI DATASET v1.0 Category: Sorting ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

#define SIZE 100000

int arr[SIZE];

void* bubbleSort(void* args) {
    int i, j, temp;
    for (i = 0; i < SIZE - 1; i++) {
        for (j = 0; j < SIZE - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    pthread_exit(NULL);
}

void* quickSort(void* args) {
    int *arr = (int*) args;
    int n = SIZE;

    if (n < 2) {
        pthread_exit(NULL);
    }

    int pivot = arr[n / 2];

    int i, j, temp;
    for (i = 0, j = n - 1;; i++, j--) {
        while (arr[i] < pivot) i++;
        while (arr[j] > pivot) j--;

        if (i >= j) break;

        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    pthread_t tid[2];
    pthread_attr_t attr;

    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);

    int halfSize = n / 2;
    int *args1 = malloc(halfSize * sizeof(int));
    int *args2 = malloc((n - halfSize) * sizeof(int));

    for (int i = 0; i < halfSize; i++) {
        args1[i] = arr[i];
    }

    for (int i = halfSize; i < n; i++) {
        args2[i - halfSize] = arr[i];
    }

    pthread_create(&tid[0], &attr, quickSort, (void*) args1);
    pthread_create(&tid[1], &attr, quickSort, (void*) args2);

    pthread_join(tid[0], NULL);
    pthread_join(tid[1], NULL);

    int *tempArr = malloc(n * sizeof(int));
    i = 0;
    j = halfSize;

    for (int k = 0; k < n; k++) {
        if (i >= halfSize) {
            tempArr[k] = arr[j++];
        } else if (j >= n) {
            tempArr[k] = arr[i++];
        } else if (arr[i] < arr[j]) {
            tempArr[k] = arr[i++];
        } else {
            tempArr[k] = arr[j++];
        }
    }

    for (int i = 0; i < n; i++) {
        arr[i] = tempArr[i];
    }
    free(args1);
    free(args2);
    free(tempArr);
    pthread_attr_destroy(&attr);
    pthread_exit(NULL);
}

void printArray() {
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", arr[i]);
        if (i != 0 && i % 10 == 0) {
            printf("\n");
        }
    }
}

int main() {
    srand(time(NULL));
    for (int i = 0; i < SIZE; i++) {
        arr[i] = rand() % 1000;
    }

    pthread_t tid[2];
    pthread_attr_t attr;

    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);

    clock_t start = clock();
    pthread_create(&tid[0], &attr, bubbleSort, NULL);
    pthread_join(tid[0], NULL);
    pthread_create(&tid[1], &attr, quickSort, (void*) arr);
    pthread_join(tid[1], NULL);
    clock_t end = clock();

    printf("Execution time for sorting: %f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

    printf("Array after sorting:\n");
    printArray();

    pthread_attr_destroy(&attr);
    pthread_exit(NULL);
}