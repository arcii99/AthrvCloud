//FormAI DATASET v1.0 Category: File handling ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX 1000

void *write_file(void *arg);
void *read_file(void *arg);

int input[MAX];
int output[MAX];

int main()
{
    pthread_t write_thread, read_thread;

    // Creating a file pointer
    FILE *fp;

    // Opening file to write data into it
    fp = fopen("input.txt", "w");

    // Checking if the file exists and is readable
    if (fp == NULL)
    {
        printf("Error opening file!\n");
        exit(1);
    }

    // Writing data into the file
    for (int i = 0; i < MAX; i++)
    {
        input[i] = i + 1;
        fprintf(fp, "%d\n", input[i]);
    }

    // Closing the file pointer
    fclose(fp);

    // Creating a thread to read data from the file
    if (pthread_create(&read_thread, NULL, &read_file, NULL) != 0)
    {
        printf("failed to create thread\n");
        exit(1);
    }

    // Creating a thread to write data into the file
    if (pthread_create(&write_thread, NULL, &write_file, NULL) != 0)
    {
        printf("failed to create thread\n");
        exit(1);
    }

    // Waiting for both the threads to complete execution
    pthread_join(write_thread, NULL);
    pthread_join(read_thread, NULL);

    // Printing the output
    for (int i = 0; i < MAX; i++)
    {
        printf("Output[%d] = %d\n", i, output[i]);
    }

    return 0;
}

void *write_file(void *arg)
{
    // Creating a file pointer
    FILE *fp;

    // Opening file to write data into it
    fp = fopen("output.txt", "w");

    // Checking if the file exists and is readable
    if (fp == NULL)
    {
        printf("Error opening file!\n");
        exit(1);
    }

    // Writing data into the file
    for (int i = 0; i < MAX; i++)
    {
        output[i] = input[i] * 2;
        fprintf(fp, "%d\n", output[i]);
    }

    // Closing the file pointer
    fclose(fp);
}

void *read_file(void *arg)
{
    // Creating a file pointer
    FILE *fp;

    // Opening file to read data from it
    fp = fopen("input.txt", "r");

    // Checking if the file exists and is readable
    if (fp == NULL)
    {
        printf("Error opening file!\n");
        exit(1);
    }

    // Reading data from the file
    for (int i = 0; i < MAX; i++)
    {
        fscanf(fp, "%d\n", &input[i]);
    }

    // Closing the file pointer
    fclose(fp);
}