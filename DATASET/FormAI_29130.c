//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *print_msg(void *ptr);

int main()
{
    int i;
    pthread_t thread[5];
    char *messages[5] = {"Hello, World!", "How are you?", "Nice to meet you!", "Goodbye!", "Have a nice day!"};

    for (i = 0; i < 5; i++)
    {
        pthread_create(&thread[i], NULL, print_msg, (void *) messages[i]);
    }

    for (i = 0; i < 5; i++)
    {
        pthread_join(thread[i], NULL);
        printf("Thread %d finished\n", i + 1);
    }

    printf("All threads have finished\n");

    return 0;
}

void *print_msg(void *ptr)
{
    char *message;
    message = (char *) ptr;
    printf("%s\n", message);
    pthread_exit(NULL);
}