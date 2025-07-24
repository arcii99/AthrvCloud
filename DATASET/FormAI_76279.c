//FormAI DATASET v1.0 Category: Poker Game ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define Card structure
typedef struct Card {
    int value;
    char suit;
} Card;

// Define player structure
typedef struct Player {
    Card hand[2];
    int score;
} Player;

// Function to generate a random card
Card drawCard() {
    Card c;
    c.value = rand() % 13 + 1;
    int suitInt = rand() % 4;
    switch(suitInt) {
        case 0:
            c.suit = 'H';
            break;
        case 1:
            c.suit = 'D';
            break;
        case 2:
            c.suit = 'C';
            break;
        case 3:
            c.suit = 'S';
            break;
    }
    return c;
}

// Function to display a card
void printCard(Card c) {
    switch(c.value) {
        case 1:
            printf("A");
            break;
        case 11:
            printf("J");
            break;
        case 12:
            printf("Q");
            break;
        case 13:
            printf("K");
            break;
        default:
            printf("%d", c.value);
            break;
    }
    printf("%c", c.suit);
}

// Function to calculate the value of a hand
int handValue(Card hand[2], Card table[5]) {
    int value = 0;
    int numAces = 0;
    for(int i = 0; i < 2; i++) {
        if(hand[i].value == 1) {
            numAces++;
            value += 11;
        } else if(hand[i].value >= 10) {
            value += 10;
        } else {
            value += hand[i].value;
        }
    }
    for(int i = 0; i < 5; i++) {
        if(table[i].value == 1) {
            numAces++;
            value += 11;
        } else if(table[i].value >= 10) {
            value += 10;
        } else {
            value += table[i].value;
        }
    }
    while(numAces > 0 && value > 21) {
        value -= 10;
        numAces--;
    }
    return value;
}

int main() {
    srand(time(NULL)); // Seed the random number generator
    Player p1, p2;
    Card table[5];
    int numPlayers = 2;
    printf("Welcome to poker!\n");
    printf("Dealing cards...\n");
    // Deal cards
    for(int i = 0; i < 2; i++) {
        p1.hand[i] = drawCard();
        p2.hand[i] = drawCard();
    }
    for(int i = 0; i < 5; i++) {
        table[i] = drawCard();
    }
    printf("Your hand: ");
    printCard(p1.hand[0]);
    printf(" ");
    printCard(p1.hand[1]);
    printf("\n");
    printf("Table: ");
    for(int i = 0; i < 5; i++) {
        printCard(table[i]);
        printf(" ");
    }
    printf("\n");
    // Calculate player scores
    p1.score = handValue(p1.hand, table);
    p2.score = handValue(p2.hand, table);
    // Determine winner
    if(p1.score > p2.score) {
        printf("You win!\n");
    } else if(p1.score < p2.score) {
        printf("You lose!\n");
    } else {
        printf("Tie game!\n");
    }
    return 0;
}