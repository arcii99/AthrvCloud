//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

pthread_t tid[2];

void *print_message(void *ptr);

int main()
{
    int i = 0;
    int err;

    char *msg1 = "Thread 1";
    char *msg2 = "Thread 2";

    while (i < 2)
    {
        err = pthread_create(&(tid[i]), NULL, &print_message, (void *)msg1);
        if (err != 0)
            printf("\ncan't create thread :[%s]", strerror(err));
        else
            printf("\nThread created successfully\n");
        i++;
        
        err = pthread_create(&(tid[i]), NULL, &print_message, (void *)msg2);
        if (err != 0)
            printf("\ncan't create thread :[%s]", strerror(err));
        else
            printf("\nThread created successfully\n");
        i++;
    }

    pthread_join(tid[0], NULL);
    pthread_join(tid[1], NULL);

    return 0;
}

void *print_message(void *ptr)
{
    char *message;
    message = (char *)ptr;
    printf("%s\n", message);
    pthread_exit(NULL);
}