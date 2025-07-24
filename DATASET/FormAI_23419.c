//FormAI DATASET v1.0 Category: Dice Roller ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

// Function executed by the thread to roll the dice
void* roll_dice(void* arg) {
    int* dice_value = malloc(sizeof(int));
    *dice_value = rand() % 6 + 1;
    pthread_exit(dice_value);
}

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Create an array of threads to roll the dice
    pthread_t threads[4];

    // Roll the dice using each thread and get the result
    int i, *dice_result, sum = 0;
    for (i = 0; i < 4; i++) {
        pthread_create(&threads[i], NULL, roll_dice, NULL);
    }

    // Wait for the threads to finish and collect the dice results
    for (i = 0; i < 4; i++) {
        pthread_join(threads[i], (void**) &dice_result);
        printf("Dice Roll %d: %d\n", i+1, *dice_result);
        sum += *dice_result;
        free(dice_result);
    }

    // Print the total sum of dice rolls
    printf("Total: %d\n", sum);

    return 0;
}