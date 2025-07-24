//FormAI DATASET v1.0 Category: Poker Game ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    char card_suits[4][10] = {"Spades", "Diamonds", "Clubs", "Hearts"};
    char card_rank[13][10] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King", "Ace"};
    int deck[52];
    int i, j, temp;

    srand(time(NULL));
    
    // Shuffle deck
    for (i = 0; i < 52; i++) {
        deck[i] = i;
    }

    for (i = 0; i < 52; i++) {
        j = rand() % 52;
        temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
    
    // Deal Cards
    printf("Your Hand:\n");
    for (i = 0; i < 5; i++) {
        printf("%s of %s\n", card_rank[deck[i] % 13], card_suits[deck[i] / 13]);
    }

    return 0;
}