//FormAI DATASET v1.0 Category: Log analysis ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

#define NUM_THREADS 5 // number of threads to spawn

void *analyze_logs(void *thread_id)
{
    int i;
    int *id = (int *)thread_id;
    printf("Thread %d is analyzing logs...\n", *id);

    // read log file
    FILE *fp;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    fp = fopen("logs.txt", "r");

    if (fp == NULL)
    {
        printf("Error opening log file...\n");
        pthread_exit(NULL);
    }

    // analyze log file
    while ((read = getline(&line, &len, fp)) != -1)
    {
        if (strstr(line, "ERROR") != NULL)
        {
            printf("Thread %d found an error in log: %s", *id, line);
        }
    }

    // cleanup
    free(line);
    fclose(fp);
    pthread_exit(NULL);
}

int main()
{
    int i;
    pthread_t threads[NUM_THREADS];
    int thread_ids[NUM_THREADS];

    // spawn threads
    for (i = 0; i < NUM_THREADS; i++)
    {
        thread_ids[i] = i + 1;
        pthread_create(&threads[i], NULL, analyze_logs, (void *)&thread_ids[i]);
    }

    // join threads
    for (i = 0; i < NUM_THREADS; i++)
    {
        pthread_join(threads[i], NULL);
    }

    // exit program
    pthread_exit(NULL);
}