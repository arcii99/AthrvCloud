//FormAI DATASET v1.0 Category: Game ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));

    int romeo_health = 100;
    int juliet_health = 100;

    printf("Welcome to 'The Duel of Love'\n");
    printf("Player 1 is Romeo, Player 2 is Juliet\n");

    while (romeo_health > 0 && juliet_health > 0) {
        int romeo_strike = rand() % 10 + 1;
        int juliet_strike = rand() % 10 + 1;

        romeo_health -= juliet_strike;
        juliet_health -= romeo_strike;

        printf("Romeo strikes Juliet with %d damage. Juliet has %d health left\n", romeo_strike, juliet_health);
        printf("Juliet strikes Romeo with %d damage. Romeo has %d health left\n", juliet_strike, romeo_health);
    }

    if (romeo_health <= 0 && juliet_health <= 0) {
        printf("It's a tie! Romeo and Juliet have both fallen in love and are now reunited in the afterlife\n");
    } else if (romeo_health <= 0) {
        printf("Juliet wins! She has won Romeo's heart and they will live happily ever after\n");
    } else {
        printf("Romeo wins! He has won Juliet's heart and they will live happily ever after\n");
    }

    return 0;
}