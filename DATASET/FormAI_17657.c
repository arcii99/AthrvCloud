//FormAI DATASET v1.0 Category: Poker Game ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void shuffleDeck(int deck[]) {
    // shuffles the deck of cards using Fisher-Yates shuffle algorithm
    srand(time(NULL));
    for (int i = 51; i > 0; i--) {
        int j = rand() % (i+1);
        int temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

void printCard(int card) {
    // prints the card value and suit using ASCII art
    if (card == 53) {
        printf("  _____\n");
        printf(" |Joker|\n");
        printf(" |     |\n");
        printf(" |     |\n");
        printf(" |Joker|\n");
        printf("  -----");
    }
    else {
        int value = (card % 13) + 1;
        int suit = card / 13;
        printf(" _______\n");
        if (value == 1) printf("|A      |\n");
        else if (value == 10) printf("|10     |\n");
        else if (value == 11) printf("|J      |\n");
        else if (value == 12) printf("|Q      |\n");
        else if (value == 13) printf("|K      |\n");
        else printf("|%d      |\n", value);
        if (suit == 0) printf("|♠     |\n");
        else if (suit == 1) printf("|♥     |\n");
        else if (suit == 2) printf("|♦     |\n");
        else if (suit == 3) printf("|♣     |\n");
        printf("|       |\n|       |\n|       |\n|       |\n");
        if (value == 1) printf("|      A|\n");
        else if (value == 10) printf("|     10|\n");
        else if (value == 11) printf("|      J|\n");
        else if (value == 12) printf("|      Q|\n");
        else if (value == 13) printf("|      K|\n");
        else printf("|      %d|\n", value);
        if (suit == 0) printf("|     ♠|\n");
        else if (suit == 1) printf("|     ♥|\n");
        else if (suit == 2) printf("|     ♦|\n");
        else if (suit == 3) printf("|     ♣|\n");
        printf(" -------");
    }
}

int getHandValue(int hand[]) {
    // determines the value of the hand
    int values[13] = {0};
    int suits[4] = {0};
    int numPairs = 0;
    int numMatching = 1;
    int straight = 0, flush = 0, straightFlush = 0, royalFlush = 0;
    int ace = 0, king = 0, queen = 0, jack = 0, ten = 0;
    for (int i = 0; i < 5; i++) {
        int value = (hand[i] % 13) + 1;
        int suit = hand[i] / 13;
        values[value-1]++;
        suits[suit]++;
        if (value == 1) ace++;
        else if (value == 11) jack++;
        else if (value == 12) queen++;
        else if (value == 13) king++;
        else if (value == 10) ten++;
    }
    for (int i = 0; i < 4; i++) {
        if (suits[i] == 5) flush = 1;
    }
    for (int i = 0; i < 13; i++) {
        if (values[i] == 4) return 8;
        if (values[i] == 3) numMatching = 3;
        if (values[i] == 2) numPairs++;
        if (values[i] == 1 && numMatching == 3) numMatching = 4;
        if (values[i] == 1 && numMatching == 2) numMatching = 3;
        if (values[i] == 1 && numMatching == 1) numMatching = 2;
        straight = (numMatching == 5 || (numMatching == 4 && ace && king && queen && jack && ten)) ? 1 : 0;
    }
    straightFlush = (straight && flush) ? 1 : 0;
    royalFlush = (straightFlush && ace && king) ? 1 : 0;
    if (royalFlush) return 10;
    if (straightFlush) return 9;
    if (numMatching == 4) return 8;
    if (numMatching == 3 && numPairs == 1) return 7;
    if (flush) return 6;
    if (straight) return 5;
    if (numMatching == 3) return 4;
    if (numPairs == 2) return 3;
    if (numPairs == 1) return 2;
    return 1;
}

int main() {
    printf("Welcome to Irregular Poker!\n\n");
    printf("This game is played with a standard deck of 52 cards plus 2 jokers.\n");
    printf("The value of the jokers is determined by the dealer at the beginning of each round.\n");
    printf("The player with the highest hand wins.\n\n");

    int deck[54] = {0};
    for (int i = 0; i < 54; i++) deck[i] = i;
    int numJokers = 2, jokerValue = 0;
    while (numJokers > 0) {
        printf("How much do you want the joker to be worth? (1-13): ");
        scanf("%d", &jokerValue);
        if (jokerValue < 1 || jokerValue > 13) {
            printf("Invalid value.\n");
            continue;
        }
        numJokers--;
        deck[numJokers*27 + jokerValue-1] = 52 + numJokers;
    }
    shuffleDeck(deck);
    printf("Deck shuffled.\n\n");

    int hands[4][5] = {0};
    for (int i = 0; i < 4; i++) {
        printf("Player %d's Hand:\n", i+1);
        for (int j = 0; j < 5; j++) {
            hands[i][j] = deck[i*5+j];
            printCard(hands[i][j]);
            printf("\n");
        }
        printf("\n");
    }

    int scores[4] = {0};
    for (int i = 0; i < 4; i++) {
        scores[i] = getHandValue(hands[i]);
    }

    int maxScore = 0, winner = -1;
    for (int i = 0; i < 4; i++) {
        printf("Player %d's score: %d\n", i+1, scores[i]);
        if (scores[i] > maxScore) {
            maxScore = scores[i];
            winner = i;
        }
    }

    printf("\nThe winner is Player %d with a score of %d!\n", winner+1, maxScore);

    return 0;
}