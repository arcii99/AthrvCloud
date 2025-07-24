//FormAI DATASET v1.0 Category: Calculator ; Style: multi-threaded
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

int sum = 0;

// Function to calculate sum of numbers
void* add(void* arg) {
    int n = *(int*)arg;
    for(int i=1; i<=n; i++)
        sum += i;
    pthread_exit(NULL);
}

int main(int argc, char const *argv[]) {
    int n;

    printf("Enter a number to calculate the sum of all numbers upto it: ");
    scanf("%d", &n);

    pthread_t thread;
    pthread_create(&thread, NULL, add, &n);

    pthread_join(thread, NULL);

    printf("The sum of all numbers upto %d is %d\n", n, sum);

    return 0;
}