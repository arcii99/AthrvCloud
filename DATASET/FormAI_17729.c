//FormAI DATASET v1.0 Category: Dice Roller ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int num_rolls;
    printf("How many times do you want to roll the dice? ");
    scanf("%d", &num_rolls);
    printf("\n");

    int results[6] = {0, 0, 0, 0, 0, 0};

    for (int i = 0; i < num_rolls; i++) {
        int roll = rand() % 6 + 1;
        results[roll - 1]++;
    }

    printf("Results:\n");

    for (int i = 0; i < 6; i++) {
        printf("%d: %d\n", i+1, results[i]);
    }

    int max_index = 0;
    int max_value = results[0];

    for (int i = 1; i < 6; i++) {
        if (results[i] > max_value) {
            max_value = results[i];
            max_index = i;
        }
    }

    printf("\n");
    printf("The most common result was %d, with %d occurrences.\n", max_index+1, max_value);

    return 0;
}