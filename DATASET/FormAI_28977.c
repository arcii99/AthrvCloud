//FormAI DATASET v1.0 Category: Dice Roller ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <stdbool.h>
#include <pthread.h>

#define ROLLS 5

// struct to hold async operation data
typedef struct AsyncData {
    bool is_active;
    int rolls_completed;
    int rolls[ROLLS];
} AsyncData;

// function to simulate dice roll
int roll_dice() {
    sleep(1); // wait 1 second to make it feel realistic
    return (rand() % 6) + 1;
}

// async function to roll dice
void* async_roll_dice(void* args) {
    AsyncData* async_data = (AsyncData*) args;

    while (async_data->is_active && async_data->rolls_completed < ROLLS) {
        async_data->rolls[async_data->rolls_completed++] = roll_dice();
    }

    pthread_exit(NULL);
}

int main() {
    // initialize random seed
    srand((unsigned int) time(NULL));

    // create async data and thread
    AsyncData async_data = {true, 0};
    pthread_t async_thread;
    pthread_create(&async_thread, NULL, async_roll_dice, &async_data);

    // display message and wait for user input before stopping async operation
    printf("Rolling dice...\n");
    getchar();

    async_data.is_active = false;
    pthread_join(async_thread, NULL);

    // display rolls
    printf("\nYou rolled: ");
    for (int i = 0; i < async_data.rolls_completed; i++) {
        printf("%d ", async_data.rolls[i]);
    }
    printf("\n");

    return 0;
}