//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_LENGTH 1000

void* convertToHex(void* arg)
{
    char* input = (char*) arg;
    int decimal = atoi(input);
    char hex[MAX_LENGTH];

    snprintf(hex, MAX_LENGTH, "%X", decimal);

    printf("Hexadecimal equivalent of %d is %s\n", decimal, hex);
}

int main()
{
    pthread_t thread_id;
    char input[MAX_LENGTH];

    printf("Enter decimal number: ");
    fgets(input, MAX_LENGTH, stdin);

    pthread_create(&thread_id, NULL, convertToHex, input);
    pthread_join(thread_id, NULL);

    return 0;
}