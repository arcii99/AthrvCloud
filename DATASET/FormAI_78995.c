//FormAI DATASET v1.0 Category: Memory Game ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // game setup
    srand(time(NULL));
    int cards[16];
    int revealed[16] = {0};
    int first_card = -1, second_card = -1;
    int matches = 0, attempts = 0;

    printf("Welcome to the memory game!\n");
    printf("There are 16 cards face down. Match them in pairs to win.\n");
    printf("Press ENTER to begin...\n");
    getchar();

    // initialize cards with random values
    for (int i = 0; i < 16; i++) {
        while (1) {
            int value = rand() % 8 + 1;
            int unique = 1;
            for (int j = 0; j < i; j++) {
                if (cards[j] == value) {
                    unique = 0;
                    break;
                }
            }
            if (unique) {
                cards[i] = value;
                break;
            }
        }
    }

    // game loop
    while (matches < 8) {
        printf("\n");
        for (int i = 0; i < 16; i++) {
            if (revealed[i]) {
                printf("%2d ", cards[i]);
            } else {
                printf(" * ");
            }
            if (i % 4 == 3) {
                printf("\n");
            }
        }

        printf("Enter two card numbers to reveal (1-16): ");
        scanf("%d %d", &first_card, &second_card);

        if (first_card < 1 || first_card > 16 ||
            second_card < 1 || second_card > 16 ||
            revealed[first_card-1] || revealed[second_card-1] ||
            first_card == second_card) {
            printf("Invalid cards. Please try again.\n");
            continue;
        }

        attempts++;

        if (cards[first_card-1] == cards[second_card-1]) {
            revealed[first_card-1] = 1;
            revealed[second_card-1] = 1;
            matches++;
            printf("Cards match!\n");
        } else {
            printf("Cards do not match.\n");
        }
    }

    printf("\nCongratulations! You won in %d attempts.\n", attempts);

    return 0;
}