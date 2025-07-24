//FormAI DATASET v1.0 Category: Binary Converter ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <math.h>

#define MAX_SIZE 128

void binary_converter(void *arg) {
    char *str = (char*)arg;
    int num = atoi(str);
    int binary[MAX_SIZE], i = 0;
    while (num > 0) {
        binary[i] = num % 2;
        num /= 2;
        i++;
    }
    printf("Binary representation of %s: ", str);
    for (int j = i - 1; j >= 0; j--) {
        printf("%d", binary[j]);
    }
    printf("\n");
}

int main(int argc, char *argv[]) {
    pthread_t tid;
    if (argc == 1) {
        printf("Error: Please enter a number to be converted\n");
        exit(1);
    } else if (argc > 2) {
        printf("Error: Only one argument is accepted\n");
        exit(1);
    }
    if (pthread_create(&tid, NULL, &binary_converter, (void*)argv[1]) != 0) {
        printf("Error: Failed to create thread\n");
        exit(1);
    }
    pthread_join(tid, NULL);
    return 0;
}