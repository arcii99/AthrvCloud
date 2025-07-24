//FormAI DATASET v1.0 Category: Poker Game ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Function to generate a random number between start and end values */
int generateRandomNumber(int start, int end) {
    int randomNumber;
    srand(time(0));
    randomNumber = (rand() % (end - start + 1)) + start;
    return randomNumber;
}

/* Function to create a new deck of cards */
void createDeck(int *deck) {
    int i, j, cardValue;

    for (i = 0; i < 52; i++) {
        j = i % 13;
        cardValue = j + 2;
        if (cardValue > 10) {
            cardValue = 10;
        }
        deck[i] = cardValue;
    }
}

/* Function to print a card */
void printCard(int cardValue) {
    if (cardValue < 11) {
        printf("%d", cardValue);
    } else if (cardValue == 11) {
        printf("J");
    } else if (cardValue == 12) {
        printf("Q");
    } else if (cardValue == 13) {
        printf("K");
    } else {
        printf("A");
    }
}

/* Function to calculate score of a hand */
int calculateHandScore(int *hand, int numCards) {
    int i, handScore = 0, numAces = 0;

    for (i = 0; i < numCards; i++) {
        if (hand[i] == 1) {
            numAces++;
        }
        handScore += hand[i];
    }

    while (handScore <= 11 && numAces > 0) {
        handScore += 10;
        numAces--;
    }

    return handScore;
}

/* Function to print a hand */
void printHand(int *hand, int numCards) {
    int i;
    for (i = 0; i < numCards; i++) {
        printCard(hand[i]);
        printf(" ");
    }
}

int main() {
    int deck[52], playerHand[10], dealerHand[10];
    int playerScore = 0, dealerScore = 0, numPlayerCards = 0, numDealerCards = 0;
    char userInput;

    /* Create the deck and shuffle it */
    createDeck(deck);
    for (int i = 0; i < 1000; i++) {
        int random1 = generateRandomNumber(0, 51);
        int random2 = generateRandomNumber(0, 51);
        int temp = deck[random1];
        deck[random1] = deck[random2];
        deck[random2] = temp;
    }

    /* Deal the initial cards */
    playerHand[numPlayerCards++] = deck[0];
    dealerHand[numDealerCards++] = deck[1];
    playerHand[numPlayerCards++] = deck[2];
    dealerHand[numDealerCards++] = deck[3];

    /* Print the hands */
    printf("Dealer's hand: ");
    printCard(dealerHand[0]);
    printf(" X\n");
    printf("Your hand: ");
    printHand(playerHand, numPlayerCards);
    printf("\n");

    /* Get player input until they choose to stand */
    printf("Do you want to (h)it or (s)tand?\n");
    scanf(" %c", &userInput);
    while (userInput == 'h') {
        playerHand[numPlayerCards++] = deck[numPlayerCards + numDealerCards - 1];
        printf("Your hand: ");
        printHand(playerHand, numPlayerCards);
        printf("\n");
        playerScore = calculateHandScore(playerHand, numPlayerCards);
        if (playerScore > 21) {
            printf("Bust! You lose.\n");
            return 0;
        }
        printf("Do you want to (h)it or (s)tand?\n");
        scanf(" %c", &userInput);
    }

    /* Dealer's turn */
    dealerScore = calculateHandScore(dealerHand, numDealerCards);
    printf("Dealer's hand: ");
    printHand(dealerHand, numDealerCards);
    printf("\n");
    while (dealerScore < 17) {
        dealerHand[numDealerCards++] = deck[numPlayerCards + numDealerCards - 1];
        dealerScore = calculateHandScore(dealerHand, numDealerCards);
        printf("Dealer's hand: ");
        printHand(dealerHand, numDealerCards);
        printf("\n");
    }

    /* Determine winner */
    if (dealerScore > 21) {
        printf("Dealer bust! You win.\n");
    } else if (dealerScore > playerScore) {
        printf("Dealer wins.\n");
    } else if (dealerScore == playerScore) {
        printf("It's a tie.\n");
    } else {
        printf("You win!\n");
    }

    return 0;
}