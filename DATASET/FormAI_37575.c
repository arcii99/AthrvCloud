//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *thread_function(void *arg);

int main()
{
    int t1=1, t2=2, t3=3;
    pthread_t thread1, thread2, thread3;

    //Creating threads
    if(pthread_create(&thread1, NULL, thread_function, (void *)&t1) != 0) 
       printf("Error: Thread1 creation failed!\n");
    if(pthread_create(&thread2, NULL, thread_function, (void *)&t2) != 0) 
       printf("Error: Thread2 creation failed!\n");
    if(pthread_create(&thread3, NULL, thread_function, (void *)&t3) != 0) 
       printf("Error: Thread3 creation failed!\n");

    //Joining threads
    if(pthread_join(thread1, NULL) != 0) 
       printf("Error: Thread1 join failed!\n");
    if(pthread_join(thread2, NULL) != 0) 
       printf("Error: Thread2 join failed!\n");
    if(pthread_join(thread3, NULL) != 0) 
       printf("Error: Thread3 join failed!\n");

    printf("All threads have completed execution.\n");
    exit(0);
}

void *thread_function(void *arg) 
{
    int *thread_num = (int *)arg;
    int i;
    
    printf("Thread %d started execution...\n", *thread_num);

    for (i=0; i<10; i++) {
        printf("Thread %d loop iteration %d.\n", *thread_num, i);
        sleep(1);
    }

    printf("Thread %d completed execution.\n", *thread_num);
    pthread_exit(NULL);
}