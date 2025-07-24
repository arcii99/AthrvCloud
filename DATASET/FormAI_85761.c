//FormAI DATASET v1.0 Category: String manipulation ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_BUFFER_SIZE 1024

char buffer[MAX_BUFFER_SIZE] = "Hello, World!";

void *reverse_string(void *arg)
{
    for(int i = 0; i < strlen(buffer) / 2; i++) {
        char temp = buffer[i];
        buffer[i] = buffer[strlen(buffer) - i - 1];
        buffer[strlen(buffer) - i - 1] = temp;
    }
    pthread_exit(NULL);
}

int main()
{
    pthread_t t;
    pthread_create(&t, NULL, reverse_string, NULL);
    pthread_join(t, NULL);
    
    printf("Reversed string: %s\n", buffer);
    
    return 0;
}