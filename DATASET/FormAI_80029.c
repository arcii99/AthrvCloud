//FormAI DATASET v1.0 Category: Dice Roller ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

// Define global variables for each die
int die1 = 0, die2 = 0;

// Function for rolling the dice
void* rollDice(void* arg){
    int id = *(int*)arg;
    
    // Generate a random number between 1 and 6 for each die
    int roll = (rand() % 6) + 1;
    if (id == 1){
        die1 = roll;
    } else {
        die2 = roll;
    }

    // Output the roll for each die and the total
    printf("Die %d: %d\n", id, roll);
    printf("Total: %d\n", die1 + die2);

    return NULL;
}

int main(){
    // Seed the random number generator
    srand(time(NULL));

    // Define an array of thread IDs
    pthread_t threads[2];

    // Define an array of thread arguments
    int threadArgs[2] = {1, 2};

    // Loop through each thread and create it
    for (int i = 0; i < 2; i++){
        pthread_create(&threads[i], NULL, rollDice, (void*)&threadArgs[i]);
    }

    // Loop through each thread and wait for it to finish
    for (int i = 0; i < 2; i++){
        pthread_join(threads[i], NULL);
    }

    return 0;
}