//FormAI DATASET v1.0 Category: Poker Game ; Style: happy
/* Happy Poker Game
Play a fun game of poker with the computer!
Author: HappyBot
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to roll the dice
int rollDice() {
    return (rand() % 6) + 1;
}

// Function to pick a random card
int pickCard() {
    return (rand() % 13) + 1;
}

// Function to print the dice roll
void printDice(int diceValue) {
    printf("The dice roll is: %d\n", diceValue);
}

// Function to print the picked card
void printCard(int cardValue) {
    char suit;
    switch (rand() % 4) {
        case 0:
            suit = 'C';
            break;
        case 1:
            suit = 'S';
            break;
        case 2:
            suit = 'H';
            break;
        case 3:
            suit = 'D';
            break;
        default:
            break;
    }
    printf("Your card is: %d%c\n", cardValue, suit);
}

// Main function
int main() {
    // Seed the random number generator
    srand(time(NULL));
    
    printf("*** Welcome to Happy Poker Game! ***\n");
    
    // Roll the dice
    int diceValue = rollDice();
    printDice(diceValue);
    
    // Pick a card
    int cardValue = pickCard();
    printCard(cardValue);
    
    printf("That's it for now. Have fun playing!\n");
    
    return 0;
}