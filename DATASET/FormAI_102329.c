//FormAI DATASET v1.0 Category: Benchmarking ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 1000000
#define ROUNDS 5
#define NUM_PLAYERS 4

// Function to initialize the array with random integers
void initialize_array(int* arr) {
    srand(time(NULL));
    for(int i = 0; i < SIZE; i++) {
        arr[i] = rand() % 100;
    }
}

// Function to find the sum of all elements in the array
int sum(int* arr) {
    int sum = 0;
    for(int i = 0; i < SIZE; i++) {
        sum += arr[i];
    }
    return sum;
}

int main() {
    // Initializing the array
    int arr[SIZE];
    initialize_array(arr);

    // Creating an array of player scores
    int scores[NUM_PLAYERS] = {0};

    /* 
    Each player will take turns finding the sum of all elements in the array.
    The player with the highest score after 5 rounds wins.
    */

    for(int i = 0; i < ROUNDS; i++) {
        printf("Round %d\n", i+1);
        for(int j = 0; j < NUM_PLAYERS; j++) {
            printf("Player %d's turn\n", j+1);
            int player_sum = sum(arr);
            printf("Player %d's score: %d\n", j+1, player_sum);
            scores[j] += player_sum;
        }
    }

    // Finding the winner
    int max_score = 0;
    int winner;
    for(int i = 0; i < NUM_PLAYERS; i++) {
        if(scores[i] > max_score) {
            max_score = scores[i];
            winner = i+1;
        }
    }

    printf("\nPlayer %d wins with a score of %d\n", winner, max_score);

    return 0;
}