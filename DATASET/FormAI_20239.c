//FormAI DATASET v1.0 Category: Binary Converter ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void* convertToBinary(void* arg);

int main() {
    int n;
    printf("Enter a number to convert to binary: ");
    scanf("%d", &n);

    int* numPtr = malloc(sizeof(int));
    *numPtr = n;

    pthread_t tid;
    pthread_create(&tid, NULL, convertToBinary, numPtr);

    pthread_join(tid, NULL);
    free(numPtr);

    return 0;
}

void* convertToBinary(void* arg) {
    int n = *((int*) arg);
    free(arg);

    int binary[32];
    int i = 0;
    while (n > 0) {
        binary[i++] = n % 2;
        n /= 2;
    }

    for (int j = i - 1; j >= 0; j--) {
        printf("%d", binary[j]);
    }
    printf("\n");

    pthread_exit(NULL);
}