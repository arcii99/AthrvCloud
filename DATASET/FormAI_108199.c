//FormAI DATASET v1.0 Category: Binary Converter ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void* convert(void* arg);

int main() {
    pthread_t thread;
    char input[50];
    printf("Enter a decimal number: ");
    scanf("%s", input);
    int* decimal_ptr = (int*)malloc(sizeof(int));
    *decimal_ptr = atoi(input);
    pthread_create(&thread, NULL, convert, decimal_ptr);
    pthread_join(thread, NULL);
    free(decimal_ptr);
    return 0;
}

void* convert(void* arg) {
    int decimal = *(int*)arg;
    int binary[32];
    int index = 0;
    while (decimal > 0) {
        binary[index++] = decimal % 2;
        decimal /= 2;
    }
    printf("Binary: ");
    for (int i = index - 1; i >= 0; i--) {
        printf("%d", binary[i]);
    }
    printf("\n");
    pthread_exit(NULL);
}