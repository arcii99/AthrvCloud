//FormAI DATASET v1.0 Category: Scientific ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

void getData(int seconds);
void process(int seconds);
void printData(int seconds);

int main()
{
    time_t t;
    srand((unsigned) time(&t)); 
    int seconds = rand() % 10 + 1; 

    printf("Starting program...\n");

    getData(seconds); 

    printf("Program execution complete.\n");

    return 0;
}

void getData(int seconds)
{
    printf("Getting data...\n");

    // Create a child process to handle the processing of data asynchronously
    pid_t pid = fork();

    if (pid == -1) 
    {
        printf("Error: Failed to create child process.\n");
        exit(1);
    } 
    else if (pid == 0) 
    {
        // Child process - process data asynchronously
        process(seconds); 
    } 
    else 
    {
        // Parent process - continue getting data asynchronously
        sleep(seconds); 
        printf("Data received.\n");
        printData(seconds); 
    }
}

void process(int seconds)
{
    printf("Processing data...\n");
    sleep(seconds);
    printf("Data processed.\n");
}

void printData(int seconds)
{
    printf("Printing data...\n");
    sleep(seconds);
    printf("Data printed.\n");
}