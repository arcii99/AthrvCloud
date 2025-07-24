//FormAI DATASET v1.0 Category: Word Count Tool ; Style: multi-threaded
#include <stdio.h>
#include <string.h>
#include <pthread.h>

#define MAX_THREADS 5

int total_word_count = 0;
pthread_mutex_t mutex_total_word_count;

void *count_words(void *file_name)
{
    char *file = (char *) file_name;
    FILE *fp = fopen(file, "r");
    int word_count = 0;
    if (fp != NULL)
    {
        char line[1024];
        while (fgets(line, 1024, fp))
        {
            char *token = strtok(line, " \n\t\r");
            while (token != NULL)
            {
                word_count++;
                token = strtok(NULL, " \n\t\r");
            }
        }
        fclose(fp);
    }

    pthread_mutex_lock(&mutex_total_word_count);
    total_word_count += word_count;
    printf("Thread %d counted %d words from file %s.\n", (int)pthread_self(), word_count, file);
    pthread_mutex_unlock(&mutex_total_word_count);
    pthread_exit(NULL);
}

int main(int argc, char *argv[])
{
    pthread_t threads[MAX_THREADS];
    int rc, i;

    if (argc < 2)
    {
        printf("Usage: %s [file1] [file2] ... [fileN]\n", argv[0]);
        return 1;
    }

    pthread_mutex_init(&mutex_total_word_count, NULL);

    for (i = 1; i < argc; i++)
    {
        rc = pthread_create(&threads[i-1], NULL, count_words, (void *) argv[i]);
        if (rc)
        {
            printf("Error: unable to create thread, %d\n", rc);
            return 1;
        }
    }

    for (i = 0; i < argc-1; i++)
    {
        rc = pthread_join(threads[i], NULL);
        if (rc)
        {
            printf("Error: unable to join thread, %d\n", rc);
            return 1;
        }
    }

    printf("Total word count = %d\n", total_word_count);

    pthread_mutex_destroy(&mutex_total_word_count);

    pthread_exit(NULL);
}