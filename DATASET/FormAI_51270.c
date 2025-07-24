//FormAI DATASET v1.0 Category: Random ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    /* Initializing variables */
    int i, random_num;
    double random_fractional;

    /* Generating random seed from system time */
    srand(time(NULL));

    /* Generating 10 random numbers between 0 and 99 */
    printf("Generating 10 random numbers between 0 and 99:\n");
    for (i = 0; i < 10; i++) {
        random_num = rand() % 100; // Generating random number between 0 and 99
        printf("%d\n", random_num);
    }

    /* Generating a random double between 0 and 1 */
    printf("\nGenerating a random double between 0 and 1:\n");
    random_fractional = (double) rand() / RAND_MAX; // Generating a random double between 0 and 1
    printf("%0.2lf\n", random_fractional);

    /* Randomly shuffling a deck of cards */
    printf("\nRandomly shuffling a deck of cards:\n");
    char *suits[] = {"Hearts", "Diamonds", "Clubs", "Spades"};
    char *ranks[] = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King"};
    int deck[52];
    for (i = 0; i < 52; i++) {
        deck[i] = i;
    }
    for (i = 51; i >= 0; i--) {
        int random_index = rand() % (i + 1);
        int temp = deck[i];
        deck[i] = deck[random_index];
        deck[random_index] = temp;
    }
    for (i = 0; i < 52; i++) {
        int suit_index = deck[i] / 13;
        int rank_index = deck[i] % 13;
        printf("%s of %s\n", ranks[rank_index], suits[suit_index]);
    }

    return 0;
}