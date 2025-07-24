//FormAI DATASET v1.0 Category: Bitwise operations ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

typedef struct {
    unsigned int x : 4;
    unsigned int y : 4;
} ThreadArg;

void *BitwiseAND(void *arg) {
    ThreadArg *threadArg = (ThreadArg *)arg;
    unsigned int result = threadArg->x & threadArg->y;
    printf("Bitwise AND operation on %d and %d: %d\n", threadArg->x, threadArg->y, result);
    return NULL;
}

void *BitwiseOR(void *arg) {
    ThreadArg *threadArg = (ThreadArg *)arg;
    unsigned int result = threadArg->x | threadArg->y;
    printf("Bitwise OR operation on %d and %d: %d\n", threadArg->x, threadArg->y, result);
    return NULL;
}

void *BitwiseXOR(void *arg) {
    ThreadArg *threadArg = (ThreadArg *)arg;
    unsigned int result = threadArg->x ^ threadArg->y;
    printf("Bitwise XOR operation on %d and %d: %d\n", threadArg->x, threadArg->y, result);
    return NULL;
}

int main() {
    pthread_t t1, t2, t3;
    ThreadArg arg1 = {7, 2};
    ThreadArg arg2 = {8, 4};
    ThreadArg arg3 = {5, 1};

    pthread_create(&t1, NULL, BitwiseAND, (void *)&arg1);
    pthread_create(&t2, NULL, BitwiseOR, (void *)&arg2);
    pthread_create(&t3, NULL, BitwiseXOR, (void *)&arg3);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    pthread_join(t3, NULL);

    return 0;
}