//FormAI DATASET v1.0 Category: Dice Roller ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int rollDice() {
    return rand() % 6 + 1;
}

int main() {
    srand(time(NULL));

    printf("Welcome to the Dice Roller program!\n");

    int numDice = 0;
    printf("How many dice would you like to roll? ");
    scanf("%d", &numDice);

    if(numDice <= 0) {
        printf("ERROR: Must be at least 1 dice.\n");
        return 0;
    }

    int* results = (int*)calloc(numDice, sizeof(int));

    int i;
    for(i = 0; i < numDice; i++) {
        results[i] = rollDice();
    }

    printf("\nResults:\n");
    for(i = 0; i < numDice; i++) {
        printf("Dice %d: %d\n", i+1, results[i]);
    }

    free(results);
    return 0;
}