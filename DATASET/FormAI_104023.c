//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>

#define NUM_THREADS 5

pthread_t tid[NUM_THREADS];
char *fortunes[] = {"You will find success in your future endeavors.", 
                    "A surprise gift is coming your way soon.", 
                    "Be cautious of those around you.",
                    "You will face a difficult decision soon.",
                    "Good things come to those who wait.",
                    "An important opportunity will present itself soon.",
                    "Trust your instincts in the coming days.",
                    "Financial success is in your future.",
                    "A loved one will bring you great joy soon.",
                    "Travel will bring you great fulfillment."};

void *tellFortune(void *arg)
{
    srand(time(NULL)); // initialize random seed
    int randomIndex = rand() % 10; // generate random number between 0 and 9
    char *fortune = fortunes[randomIndex]; // select a random fortune from the array
    pthread_t id = pthread_self(); // get the current thread id
    printf("Thread %lu says: %s\n", id, fortune); // print the fortune for this thread
    pthread_exit(NULL);
}

int main()
{
    int i;
    int err;
    for (i = 0; i < NUM_THREADS; i++)
    {
        err = pthread_create(&(tid[i]), NULL, &tellFortune, NULL);
        if (err != 0)
            printf("Error creating thread %d: %d\n", i, err);
    }
    sleep(1); // wait for all threads to finish
    return 0;
}