//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *metadata_parser(void *file_path)
{
    char *path = (char*) file_path;
    // Code to extract metadata from file at path
    printf("Metadata extracted from file at %s\n", path);
    pthread_exit(NULL);
}

int main()
{
    pthread_t threads[5];
    int i, rc;

    // Paths of 5 files to extract metadata from
    char *file_paths[5] = {"file1.txt", "file2.pdf", "file3.jpg", "file4.mp3", "file5.docx"};

    for(i=0; i<5; i++)
    {
        rc = pthread_create(&threads[i], NULL, metadata_parser, (void*) file_paths[i]);
        if (rc)
        {
            printf("Error: Unable to create thread %d\n", rc);
            exit(-1);
        }
    }

    // Wait for all threads to complete before exiting main
    for(i=0; i<5; i++)
    {
        pthread_join(threads[i], NULL);
    }

    printf("All metadata extraction tasks completed successfully.\n");

    return 0;
}