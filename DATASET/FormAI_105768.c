//FormAI DATASET v1.0 Category: Poker Game ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to shuffle the deck randomly
void shuffleDeck(int deck[]) {
    int i, j, temp;
    for (i = 0; i < 52; i++) {
        j = rand() % 52;
        temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

// Function to print the cards
void printCards(int cards[], int numCards) {
    int i;
    for (i = 0; i < numCards; i++) {
        switch (cards[i] / 13) {
            case 0:
                printf("Clubs ");
                break;
            case 1:
                printf("Diamonds ");
                break;
            case 2:
                printf("Hearts ");
                break;
            case 3:
                printf("Spades ");
                break;
        }
        switch (cards[i] % 13) {
            case 0:
                printf("Ace\n");
                break;
            case 10:
                printf("Jack\n");
                break;
            case 11:
                printf("Queen\n");
                break;
            case 12:
                printf("King\n");
                break;
            default:
                printf("%d\n", cards[i] % 13 + 1);
                break;
        }
    }
}

// Function to evaluate the hand and return the score
int evaluateHand(int cards[]) {
    int i, j, score = 0;
    // Count the number of cards of each rank and suit
    int rankCount[13] = {0};
    int suitCount[4] = {0};
    for (i = 0; i < 5; i++) {
        rankCount[cards[i] % 13]++;
        suitCount[cards[i] / 13]++;
    }
    // Check for a flush
    for (i = 0; i < 4; i++) {
        if (suitCount[i] == 5) {
            score += 6000000;
            break;
        }
    }
    // Check for a straight
    for (i = 0; i < 9; i++) {
        if (rankCount[i] && rankCount[i+1] && rankCount[i+2] && rankCount[i+3] && rankCount[i+4]) {
            score += 5000000 + (i+4)*1000000;
            break;
        }
    }
    // Check for four of a kind
    for (i = 0; i < 13; i++) {
        if (rankCount[i] == 4) {
            score += 8000000 + (i+1)*100000;
            break;
        }
    }
    // Check for a full house
    for (i = 0; i < 13; i++) {
        if (rankCount[i] == 3) {
            for (j = 0; j < 13; j++) {
                if (i != j && rankCount[j] == 2) {
                    score += 7000000 + (i+1)*100000 + (j+1)*10000;
                    break;
                }
            }
            break;
        }
    }
    // Check for a flush or a straight flush
    if (score > 0) {
        return score;
    }
    // Check for three of a kind
    for (i = 0; i < 13; i++) {
        if (rankCount[i] == 3) {
            score += 3000000 + (i+1)*100000;
            break;
        }
    }
    // Check for two pairs
    for (i = 0; i < 13; i++) {
        if (rankCount[i] == 2) {
            for (j = i+1; j < 13; j++) {
                if (rankCount[j] == 2) {
                    score += 2000000 + (j+1)*100000 + (i+1)*10000;
                    break;
                }
            }
            break;
        }
    }
    // Check for a pair
    for (i = 0; i < 13; i++) {
        if (rankCount[i] == 2) {
            score += 1000000 + (i+1)*100000;
            break;
        }
    }
    // Check for a high card
    if (score == 0) {
        score += (cards[4] % 13 + 1) * 10000 + (cards[3] % 13 + 1) * 1000 + (cards[2] % 13 + 1) * 100 + (cards[1] % 13 + 1) * 10 + (cards[0] % 13 + 1);
    }
    return score;
}

int main() {
    int deck[52], i, j;
    // Initialize the deck
    for (i = 0; i < 52; i++) {
        deck[i] = i;
    }
    // Seed the random number generator
    srand(time(NULL));
    // Shuffle the deck
    shuffleDeck(deck);
    // Deal the cards
    int hand1[5], hand2[5];
    for (i = 0; i < 5; i++) {
        hand1[i] = deck[i];
        hand2[i] = deck[i+5];
    }
    // Print the cards
    printf("Player 1's hand:\n");
    printCards(hand1, 5);
    printf("Player 2's hand:\n");
    printCards(hand2, 5);
    // Evaluate the hands and print the result
    int score1 = evaluateHand(hand1);
    int score2 = evaluateHand(hand2);
    if (score1 > score2) {
        printf("Player 1 wins!\n");
    }
    else if (score1 == score2) {
        printf("It's a tie!\n");
    }
    else {
        printf("Player 2 wins!\n");
    }
    return 0;
}