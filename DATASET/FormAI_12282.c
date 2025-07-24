//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_THREADS 10

pthread_t threads[MAX_THREADS];
int num_threads = 0;

void *convert_hex(void *number) {
    int decimal = *((int *) number);
    char hex_num[10];
    sprintf(hex_num, "%x", decimal);
    printf("Decimal %d is %s in hexadecimal.\n", decimal, hex_num);
    pthread_exit(NULL);
}

int main() {
    int decimal_nums[MAX_THREADS];
    for (int i = 0; i < MAX_THREADS; i++) {
        decimal_nums[i] = rand() % 100;
        printf("Creating thread %d for decimal number %d.\n", i+1, decimal_nums[i]);
        if (pthread_create(&threads[i], NULL, convert_hex, &decimal_nums[i]) != 0) {
            printf("Error creating thread.\n");
            exit(1);
        }
        num_threads++;
    }

    for (int i = 0; i < num_threads; i++) {
        if (pthread_join(threads[i], NULL) != 0) {
            printf("Error joining thread.\n");
            exit(1);
        }
    }

    printf("All threads completed.\n");

    return 0;
}