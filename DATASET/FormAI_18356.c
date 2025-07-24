//FormAI DATASET v1.0 Category: Memory management ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

int main() {
    printf("It was a cold, foggy morning in London. I woke up to find myself seated at my desk, surrounded by piles of papers and notes.\n");
    printf("I glanced at my watch and saw that it was already past 10 o'clock.\n");
    printf("I rubbed my eyes, took a deep breath and began to work on my latest case.\n\n");

    char* memory_block = (char*) malloc(sizeof(char) * MAX_SIZE);
    
    if (memory_block == NULL) {
        printf("I searched through my pockets but found no answer to my memory allocation problem.\n");
        printf("I must have made a mistake somewhere along the way...\n");
        printf("Without proper memory allocation, this program will not run as expected.\n");
        exit(1);
    }
    
    printf("I decided to investigate the memory block to see if it could hold any clues for this case.\n");
    printf("I began by filling it with the letter 'H', as it seemed like a good starting point.\n\n");

    for (int i = 0; i < MAX_SIZE; i++) {
        *(memory_block + i) = 'H';
    }

    printf("As I was examining the memory block, I noticed a strange pattern.\n");
    printf("Every other character had been overwritten by the letter 'T'.\n\n");

    for (int i = 1; i < MAX_SIZE; i+=2) {
        *(memory_block + i) = 'T';
    }

    printf("But why would someone do such a thing, I wondered.\n");
    printf("There was only one way to find out - by using the realloc function to increase the size of the memory block and see what else was hidden inside.\n\n");

    char* new_memory_block = (char*) realloc(memory_block, sizeof(char) * (MAX_SIZE + 5));

    if (new_memory_block == NULL) {
        printf("My suspicions were growing stronger. Was there some sort of foul play involved in this memory management case?\n");
        printf("Without enough memory, I would never be able to get to the bottom of this mystery.\n");
        exit(1);
    }

    printf("With the increased memory size, I was able to see that the mystery writer had left behind a message.\n");
    printf("It read: 'The culprit is hiding in the heap!'\n");

    free(memory_block);
    free(new_memory_block);

    printf("As I closed the case, I couldn't help but feel a sense of satisfaction.\n");
    printf("Thanks to my knowledge of memory management, I was able to solve yet another mystery.\n");

    return 0;
}