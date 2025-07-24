//FormAI DATASET v1.0 Category: Poker Game ; Style: grateful
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    const int MIN_VALUE = 2;
    const int MAX_VALUE = 14;
    const int NUMBER_OF_CARDS = 5;
    int i, j, card, is_duplicate;
    int cards[NUMBER_OF_CARDS];
    char suit[4][10] = {"Spades", "Hearts", "Diamonds", "Clubs"};
    char face[13][10] = {"Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King", "Ace"};
    srand((unsigned)time(NULL));
    printf("Dealing 5 cards...\n\n");
    for(i=0; i<NUMBER_OF_CARDS; i++) {
        do {
            card = rand() % MAX_VALUE + MIN_VALUE;
            is_duplicate = 0;
            for(j=0; j<i; j++) {
                if(card == cards[j]) {
                    is_duplicate = 1;
                    break;
                }
            }
        } while(is_duplicate == 1);
        cards[i] = card;
        printf("Card %d: ", i+1);
        printf("%s of %s\n", face[card-2], suit[rand() % 4]);
    }
    printf("\n");
    return 0;
}