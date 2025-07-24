//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: Romeo and Juliet
/*
 * Library: Romeo and Juliet Threading Library
 * Author: Juliet
 */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void *romeo(void *arg)
{
    pthread_mutex_lock(&mutex);
    printf("Romeo: O, wilt thou leave me so unsatisfied?\n");
    printf("Romeo: What satisfaction canst thou have tonight?\n");
    printf("Romeo: The exchange of thy love's faithful vow for mine.\n");
    printf("Romeo: I gave thee mine before thou didst request it.\n");
    printf("Romeo: And yet I would it were to give again.\n");
    pthread_mutex_unlock(&mutex);
    
    return NULL;
}

void *juliet(void *arg)
{
    pthread_mutex_lock(&mutex);
    printf("Juliet: Good pilgrim, you do wrong your hand too much,\n");
    printf("Juliet: Which mannerly devotion shows in this;\n");
    printf("Juliet: For saints have hands that pilgrims' hands do touch,\n");
    printf("Juliet: And palm to palm is holy palmers' kiss.\n");
    pthread_mutex_unlock(&mutex);
    
    return NULL;
}

int main()
{
    pthread_t tid[2];

    if(pthread_create(&tid[0], NULL, &romeo, NULL) != 0)
    {
        fprintf(stderr, "Error creating thread 1\n");
        return 1;
    }

    if(pthread_create(&tid[1], NULL, &juliet, NULL) != 0)
    {
        fprintf(stderr, "Error creating thread 2\n");
        return 1;
    }

    if(pthread_join(tid[0], NULL) != 0)
    {
        fprintf(stderr, "Error joining thread 1\n");
        return 1;
    }

    if(pthread_join(tid[1], NULL) != 0)
    {
        fprintf(stderr, "Error joining thread 2\n");
        return 1;
    }

    return 0;
}