//FormAI DATASET v1.0 Category: Error handling ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

pthread_t thread1, thread2;

void *thread1_handler(void* args) {
    printf("Thread1 is starting\n");
    char *str = NULL;
    int num = atoi(str); // Create an error by passing NULL to atoi()
    printf("Thread1: Number: %d\n", num);
    pthread_exit(NULL);
}

void *thread2_handler(void* args) {
    printf("Thread2 is starting\n");
    FILE *fp = fopen("example.txt", "r");
    if (fp == NULL) { // Check for file opening error
        perror("Error opening file");
        pthread_exit(NULL);
    }
    char str[50];
    int i = 0;
    while (fgets(str, 50, fp)) { // Read lines from the file
        i++;
        printf("Thread2: Line %d: %s", i, str);
    }
    fclose(fp);
    pthread_exit(NULL);
}

int main() {
    printf("Main thread is starting\n");
    int ret1 = pthread_create(&thread1, NULL, thread1_handler, NULL);
    int ret2 = pthread_create(&thread2, NULL, thread2_handler, NULL);
    if (ret1 || ret2) { // Check for thread creation error
        perror("Error creating thread");
        return 1;
    }
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    printf("Ending main thread\n");
    return 0;
}