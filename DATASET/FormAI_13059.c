//FormAI DATASET v1.0 Category: Pattern printing ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void printPattern(int rows)
{
    int i, j, k;

    // Print upper half
    for (i = 1; i <= rows; i++)
    {
        // Print spaces
        for (j = i; j < rows; j++)
        {
            printf(" ");
        }

        // Print first half
        for (k = 1; k <= i; k++)
        {
            printf("* ");
        }

        // Move to new line
        printf("\n");
    }

    // Print lower half
    for (i = 1; i < rows; i++)
    {
        // Print spaces
        for (j = 1; j <= i; j++)
        {
            printf(" ");
        }

        // Print second half
        for (k = i; k < rows; k++)
        {
            printf("* ");
        }

        // Move to new line
        printf("\n");
    }
}

void* printPatternAsync(void* arg) {
  
  int* rows = (int*) arg;
  printPattern(*rows);
  
  return NULL;
}

int main() {

    pthread_t thread;
    int rows = 5; // Set the number of rows
    
    // Create a thread to start printing pattern asynchronously
    if(pthread_create(&thread, NULL, printPatternAsync, &rows)) {
        fprintf(stderr, "Error creating thread\n");
        return 1;
    }
    
    // Wait for the thread to finish printing pattern
    pthread_join(thread, NULL);

    return 0;
}