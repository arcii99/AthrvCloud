//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <pthread.h>

#define MAX_INPUT 20

volatile bool running = true;

void *conversion_thread(void *args) {
    unsigned int decimal;
    char hex[MAX_INPUT] = {'\0'};
    while (running) {
        printf("\nEnter a decimal number to convert to hexadecimal: ");
        scanf("%u", &decimal);
        sprintf(hex, "%X", decimal);
        printf("Hexadecimal representation: 0x%s\n", hex);
    }
    return NULL;
}

int main() {
    pthread_t thread_id;

    if (pthread_create(&thread_id, NULL, conversion_thread, NULL)) {
        fprintf(stderr, "Error creating thread\n");
        return 1;
    }

    char input[MAX_INPUT];
    while (running) {
        printf("Enter 'quit' to stop the program\n> ");
        fgets(input, MAX_INPUT, stdin);
        input[strcspn(input, "\n")] = '\0';
        if (strcmp(input, "quit") == 0) {
            running = false;
        }
    }

    pthread_join(thread_id, NULL);
    printf("Program has ended\n");

    return 0;
}