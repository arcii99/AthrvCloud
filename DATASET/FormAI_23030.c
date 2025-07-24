//FormAI DATASET v1.0 Category: Scientific ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *print_message(void *message);

int main()
{
    pthread_t thread1, thread2;
    char *message1 = "Hello World";
    char *message2 = "Goodbye World";
    int t1, t2;

    t1 = pthread_create(&thread1, NULL, print_message, (void *)message1);
    if (t1)
    {
        printf("Error - unable to start thread 1.\n");
        exit(EXIT_FAILURE);
    }

    t2 = pthread_create(&thread2, NULL, print_message, (void *)message2);
    if (t2)
    {
        printf("Error - unable to start thread 2.\n");
        exit(EXIT_FAILURE);
    }

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    printf("Both threads have completed.\n");

    exit(EXIT_SUCCESS);
}

void *print_message(void *message)
{
    char *msg;
    msg = (char *)message;
    int i;
    for (i = 0; i < 5; i++)
    {
        printf("%s\n", msg);
        sleep(1);
    }
    pthread_exit(NULL);
}