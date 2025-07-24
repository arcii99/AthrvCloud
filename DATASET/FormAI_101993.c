//FormAI DATASET v1.0 Category: Poker Game ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_SUITS 4
#define NUM_RANKS 13
#define NUM_CARDS 52

typedef enum {HEARTS, DIAMONDS, CLUBS, SPADES} Suit;
typedef enum {ACE = 1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING} Rank;

typedef struct {
    Suit suit;
    Rank rank;
} Card;

void shuffleDeck(Card deck[]) {
    srand(time(NULL));
    for (int i = NUM_CARDS - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        Card temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

void printCard(Card card) {
    char suitChar;
    switch (card.suit) {
        case HEARTS: suitChar = 'H'; break;
        case DIAMONDS: suitChar = 'D'; break;
        case CLUBS: suitChar = 'C'; break;
        case SPADES: suitChar = 'S'; break;
    }

    char rankChar;
    switch (card.rank) {
        case ACE: rankChar = 'A'; break;
        case TEN: rankChar = 'T'; break;
        case JACK: rankChar = 'J'; break;
        case QUEEN: rankChar = 'Q'; break;
        case KING: rankChar = 'K'; break;
        default: rankChar = card.rank + '0'; break;
    }

    printf("%c%c ", rankChar, suitChar);
}

void printHand(Card hand[], int numCards) {
    for (int i = 0; i < numCards; i++) {
        printCard(hand[i]);
    }
    printf("\n");
}

int getHandValue(Card hand[], int numCards) {
    int value = 0;
    int numAces = 0;

    for (int i = 0; i < numCards; i++) {
        Rank rank = hand[i].rank;
        if (rank == ACE) {
            numAces++;
            value += 11;
        } else if (rank >= TEN) {
            value += 10;
        } else {
            value += rank;
        }
    }

    while (numAces > 0 && value > 21) {
        value -= 10;
        numAces--;
    }

    return value;
}

int main() {
    Card deck[NUM_CARDS];
    int numCards = 2;
    int playerValue, dealerValue;

    for (int suit = HEARTS; suit <= SPADES; suit++) {
        for (int rank = ACE; rank <= KING; rank++) {
            int index = suit * NUM_RANKS + (rank - 1);
            deck[index].suit = suit;
            deck[index].rank = rank;
        }
    }

    shuffleDeck(deck);

    Card playerHand[10];
    playerHand[0] = deck[0];
    playerHand[1] = deck[1];
    printf("Your hand: ");
    printHand(playerHand, numCards);
    playerValue = getHandValue(playerHand, numCards);
    printf("Value: %d\n", playerValue);

    Card dealerHand[10];
    dealerHand[0] = deck[2];
    dealerHand[1] = deck[3];
    printf("Dealer's hand: ");
    printCard(dealerHand[0]);
    printf("?\n");
    dealerValue = getHandValue(dealerHand, numCards);
    printf("Value: ?\n");

    while (1) {
        char input;
        printf("Hit (h) or Stand (s)? ");
        scanf(" %c", &input);

        if (input == 'h') {
            playerHand[numCards] = deck[numCards+1];
            numCards++;
            printf("Your hand: ");
            printHand(playerHand, numCards);
            playerValue = getHandValue(playerHand, numCards);
            printf("Value: %d\n", playerValue);

            if (playerValue > 21) {
                printf("Bust!\n");
                return 0;
            }
        } else if (input == 's') {
            printf("Dealer's hand: ");
            printHand(dealerHand, numCards);
            dealerValue = getHandValue(dealerHand, numCards);
            printf("Value: %d\n", dealerValue);

            while (dealerValue < 17) {
                dealerHand[numCards] = deck[numCards+1];
                numCards++;
                printf("Dealer hits. Hand: ");
                printHand(dealerHand, numCards);
                dealerValue = getHandValue(dealerHand, numCards);
                printf("Value: %d\n", dealerValue);
            }

            if (dealerValue > 21) {
                printf("Dealer busts. You win!\n");
                return 0;
            } else if (dealerValue == 21) {
                printf("Dealer has 21. You lose.\n");
                return 0;
            } else if (dealerValue >= playerValue) {
                printf("Dealer wins.\n");
                return 0;
            } else {
                printf("You win!\n");
                return 0;
            }
        } else {
            printf("Invalid input.\n");
        }
    }
}