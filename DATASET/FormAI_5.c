//FormAI DATASET v1.0 Category: Dice Roller ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int dice[6] = {1, 2, 3, 4, 5, 6}; // An array containing the six possible dice values
    srand(time(0)); // Initialize the random number generator with the current time
    char choice;

    do {
        int random_index = rand() % 6; // Generate a random index between 0 and 5
        printf("Rolling the dice...\n");
        printf("The result is: %d\n", dice[random_index]);

        printf("Do you want to roll again? (y/n)\n");
        scanf(" %c", &choice); // Space before %c to consume the newline character

    } while (choice == 'y' || choice == 'Y');

    printf("Exiting the program...\n");

return 0;
}