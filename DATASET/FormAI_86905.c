//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MEM_MAX 32768 // maximum memory capacity
#define MIN 1024 // minimum memory usage
#define MAX 2048 // maximum memory usage

// function to simulate random memory usage
int random_usage(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

int main() {
    int memory_usage = 0;
    srand(time(NULL)); // seed the random number generator

    while (1) {
        memory_usage += random_usage(MIN, MAX);

        if (memory_usage > MEM_MAX) {
            printf("Error: Memory capacity exceeded.\n");
            break;
        }

        // print the current memory usage
        printf("Current memory usage: %d KB\n", memory_usage);

        // wait for a random amount of time before checking again
        int seconds = rand() % 5 + 1;
        sleep(seconds);
    }

    return 0;
}