//FormAI DATASET v1.0 Category: Poker Game ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define DECK_SIZE 52
#define HAND_SIZE 5

typedef enum Suit {
    HEARTS,
    SPADES,
    CLUBS,
    DIAMONDS
} Suit;

typedef struct Card {
    Suit suit;
    int value;
} Card;

typedef struct Hand {
    Card cards[HAND_SIZE];
} Hand;

void shuffleDeck(Card* deck) {
    srand(time(NULL));
    for (int i = 0; i < DECK_SIZE; i++) {
        int j = rand() % DECK_SIZE;
        Card temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

void dealHands(Card* deck, Hand* playerHand, Hand* computerHand) {
    for (int i = 0; i < HAND_SIZE; i++) {
        playerHand->cards[i] = deck[i];
        computerHand->cards[i] = deck[i+HAND_SIZE];
    }
}

void printCard(Card* card) {
    switch (card->value) {
        case 1:
            printf("Ace");
            break;
        case 11:
            printf("Jack");
            break;
        case 12:
            printf("Queen");
            break;
        case 13:
            printf("King");
            break;
        default:
            printf("%d", card->value);
            break;
    }

    printf(" of ");

    switch (card->suit) {
        case HEARTS:
            printf("hearts");
            break;
        case SPADES:
            printf("spades");
            break;
        case CLUBS:
            printf("clubs");
            break;
        case DIAMONDS:
            printf("diamonds");
            break;
    }
}

void printHand(Hand* hand) {
    for (int i = 0; i < HAND_SIZE; i++) {
        printCard(&(hand->cards[i]));
        printf("\n");
    }
}

void swapCards(Card* card1, Card* card2) {
    Card temp = *card1;
    *card1 = *card2;
    *card2 = temp;
}

int evaluateHand(Hand* hand) {
    int values[13] = {0};
    int suits[4] = {0};
    int hasPair = 0;
    int hasTwoPair = 0;
    int hasThree = 0;
    int hasStraight = 0;
    int hasFlush = 0;
    int hasFullHouse = 0;
    int hasFour = 0;
    int hasStraightFlush = 0;
    int hasRoyalFlush = 0;

    // calculate number of each value of card and each suit
    for (int i = 0; i < HAND_SIZE; i++) {
        values[hand->cards[i].value-1]++;
        suits[hand->cards[i].suit]++;
    }

    // check for pair(s) and three of a kind
    for (int i = 0; i < 13; i++) {
        if (values[i] == 2) {
            if (hasPair) {
                hasTwoPair = 1;
            }
            hasPair = 1;
        } else if (values[i] == 3) {
            hasThree = 1;
            if (hasPair) {
                hasFullHouse = 1;
            }
        } else if (values[i] == 4) {
            hasFour = 1;
        }
    }

    // check for straight
    for (int i = 0; i < 9; i++) {
        if (values[i] == 1 && values[i+1] == 1 && values[i+2] == 1 && values[i+3] == 1 && values[i+4] == 1) {
            hasStraight = 1;
        }
    }

    // check for flush
    for (int i = 0; i < 4; i++) {
        if (suits[i] == 5) {
            hasFlush = 1;
        }
    }

    // check for straight flush and royal flush
    for (int i = 0; i < 4; i++) {
        if (suits[i] >= 5) {
            for (int j = 0; j < 9; j++) {
                if (values[j] == 1 && values[j+1] == 1 && values[j+2] == 1 && values[j+3] == 1 && values[j+4] == 1) {
                    hasStraightFlush = 1;
                }
            }
            if (values[0] == 1 && values[9] == 1 && values[10] == 1 && values[11] == 1 && values[12] == 1) {
                hasRoyalFlush = 1;
            }
        }
    }

    // determine hand rank
    if (hasRoyalFlush) {
        return 10;
    } else if (hasStraightFlush) {
        return 9;
    } else if (hasFour) {
        return 8;
    } else if (hasFullHouse) {
        return 7;
    } else if (hasFlush) {
        return 6;
    } else if (hasStraight) {
        return 5;
    } else if (hasThree) {
        return 4;
    } else if (hasTwoPair) {
        return 3;
    } else if (hasPair) {
        return 2;
    } else {
        return 1;
    }
}

void playGame() {
    Card deck[DECK_SIZE];
    for (int i = 0; i < 13; i++) {
        deck[i] = (Card) {HEARTS, i+1};
        deck[i+13] = (Card) {SPADES, i+1};
        deck[i+26] = (Card) {CLUBS, i+1};
        deck[i+39] = (Card) {DIAMONDS, i+1};
    }

    shuffleDeck(deck);

    Hand playerHand;
    Hand computerHand;

    dealHands(deck, &playerHand, &computerHand);

    printf("Your hand:\n");
    printHand(&playerHand);

    printf("Computer's hand:\n");
    printHand(&computerHand);

    printf("Do you want to swap any cards? (y/n): ");
    char response[10];
    fgets(response, 10, stdin);
    if (strcmp(response, "y\n") == 0) {
        printf("Enter the indices of the cards you want to swap (e.g. 1 4 5): ");
        int cardIndices[HAND_SIZE];
        for (int i = 0; i < HAND_SIZE; i++) {
            scanf("%d", &cardIndices[i]);
        }
        for (int i = 0; i < HAND_SIZE; i++) {
            if (cardIndices[i] != i+1) {
                swapCards(&(playerHand.cards[i]), &(playerHand.cards[cardIndices[i]-1]));
            }
        }

        printf("Your new hand:\n");
        printHand(&playerHand);
    }

    int playerRank = evaluateHand(&playerHand);
    int computerRank = evaluateHand(&computerHand);

    if (playerRank > computerRank) {
        printf("Congratulations, you win!\n");
    } else if (playerRank < computerRank) {
        printf("Sorry, you lose.\n");
    } else {
        printf("It's a tie!\n");
    }
}

int main() {
    printf("Welcome to Poker!\n");

    while (1) {
        playGame();

        printf("Do you want to play again? (y/n): ");
        char response[10];
        fgets(response, 10, stdin);
        if (strcmp(response, "n\n") == 0) {
            break;
        }
    }

    return 0;
}