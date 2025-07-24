//FormAI DATASET v1.0 Category: Unit converter ; Style: multi-threaded
#include <stdio.h>
#include <pthread.h>

void* converter(void* arg);

int main() {
    pthread_t tid[4];
    int input[4];
    printf("Enter values in Celsius: ");
    for (int i = 0; i < 4; i++) {
        scanf("%d", &input[i]);
    }

    for (int i = 0; i < 4; i++) {
        pthread_create(&(tid[i]), NULL, &converter, &(input[i]));
    }

    for (int i = 0; i < 4; i++) {
        void* result;
        pthread_join(tid[i], &result);
        printf("Converted Fahrenheit value is: %d\n", *(int*) result);
    }
    return 0;
}

void* converter(void* arg) {
    int* input = (int*) arg;
    int fahrenheit = (*input * 9 / 5) + 32;
    int* result = malloc(sizeof(int));
    *result = fahrenheit;
    return (void*) result;
}