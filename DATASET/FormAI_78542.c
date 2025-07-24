//FormAI DATASET v1.0 Category: Poker Game ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Function to generate a random number between a minimum and maximum value */
int generateRandomNumber(int min, int max) {
    srand(time(NULL));
    return (rand() % (max - min + 1)) + min;
}

/* Function to initialize the deck with 52 cards */
void initializeDeck(int deck[]) {
    int cardIndex = 0;
    for (int suit = 0; suit < 4; suit++) {
        for (int rank = 2; rank <= 14; rank++) {
            deck[cardIndex++] = rank;
        }
    }
}

/* Function to shuffle the deck of cards */
void shuffleDeck(int deck[]) {
    for (int i = 0; i < 52; i++) {
        int randomIndex = generateRandomNumber(0, 51);
        int temp = deck[i];
        deck[i] = deck[randomIndex];
        deck[randomIndex] = temp;
    }
}

/* Function to print the card rank */
void printRank(int rank) {
    if (rank >= 2 && rank <= 10) {
        printf("%d", rank);
    } else if (rank == 11) {
        printf("Jack");
    } else if (rank == 12) {
        printf("Queen");
    } else if (rank == 13) {
        printf("King");
    } else if (rank == 14) {
        printf("Ace");
    }
}

/* Function to print the card suit */
void printSuit(int suit) {
    if (suit == 0) {
        printf("Spades");
    } else if (suit == 1) {
        printf("Hearts");
    } else if (suit == 2) {
        printf("Diamonds");
    } else if (suit == 3) {
        printf("Clubs");
    }
}

/* Function to print the player's hand */
void printHand(int hand[], int size) {
    for (int i = 0; i < size; i++) {
        printRank(hand[i] % 13 + 2);
        printf(" of ");
        printSuit(hand[i] / 13);
        printf("\n");
    }
}

/* Function to get the player's bet */
int getBet(int chips) {
    int bet;
    printf("You currently have %d chips. Enter your bet (minimum 1 chip): ", chips);
    scanf("%d", &bet);
    while (bet < 1 || bet > chips) {
        printf("Invalid bet. Enter your bet (minimum 1 chip): ");
        scanf("%d", &bet);
    }
    return bet;
}

/* Function that returns the highest rank of the hand */
int getHighestRank(int hand[], int size) {
    int maxRank = 0;
    for (int i = 0; i < size; i++) {
        int rank = hand[i] % 13 + 2;
        if (rank > maxRank) {
            maxRank = rank;
        }
    }
    return maxRank;
}

/* Function that returns the rank with the highest frequency in the hand */
int getHighestFrequencyRank(int hand[], int size) {
    int frequency[13] = {0};
    for (int i = 0; i < size; i++) {
        int rank = hand[i] % 13;
        frequency[rank]++;
    }
    int maxFrequency = 0;
    int maxRank = 0;
    for (int i = 0; i < 13; i++) {
        if (frequency[i] > maxFrequency) {
            maxFrequency = frequency[i];
            maxRank = i + 2;
        }
    }
    return maxRank;
}

/* Main function */
int main() {
    // Initialize the player's chips and initial deck of cards
    int chips = 100;
    int deck[52];
    initializeDeck(deck);

    // Play the game until the player runs out of chips or chooses to quit
    char playAgain;
    do {
        // Shuffle the deck and deal the player's hand
        shuffleDeck(deck);
        int hand[5];
        for (int i = 0; i < 5; i++) {
            hand[i] = deck[i];
        }

        // Print the player's hand
        printf("\nYour hand:\n");
        printHand(hand, 5);

        // Ask the player to place a bet
        int bet = getBet(chips);
        chips -= bet;

        // Determine the outcome of the game based on the hand
        int highestRank = getHighestRank(hand, 5);
        int highestFrequencyRank = getHighestFrequencyRank(hand, 5);
        if (highestRank >= 10) {
            printf("\nYou have a high card of ");
            printRank(highestRank);
            printf(". You win %d chips!\n", bet * 2);
            chips += bet * 2;
        } else if (highestFrequencyRank == 14) {
            printf("\nYou have a pair of Aces! You win %d chips!\n", bet * 4);
            chips += bet * 4;
        } else if (highestFrequencyRank >= 11) {
            printf("\nYou have a pair of ");
            printRank(highestFrequencyRank);
            printf("s! You win %d chips!\n", bet * 3);
            chips += bet * 3;
        } else {
            printf("\nYou have a losing hand. Better luck next time!\n");
        }

        // Check if the player wants to continue playing
        if (chips > 0) {
            printf("\nDo you want to play again? (Y/N) ");
            scanf(" %c", &playAgain);
            while (playAgain != 'Y' && playAgain != 'N') {
                printf("Invalid option. Do you want to play again? (Y/N) ");
                scanf(" %c", &playAgain);
            }
        }
    } while (chips > 0 && playAgain == 'Y');

    // Game over, print the player's final score
    printf("\nGame over! You finished with %d chips.\n", chips);

    return 0;
}