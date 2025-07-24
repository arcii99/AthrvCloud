//FormAI DATASET v1.0 Category: Poker Game ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random number between min and max
int generateRandomNumber(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Function to shuffle the deck of cards
void shuffle(int deck[]) {
    for (int i = 0; i < 52; i++) {
        int j = generateRandomNumber(0, 51);
        int temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

// Function to get the value of a card
int getCardValue(int card) {
    int value = card % 13;
    if (value == 0 || value == 10 || value == 11 || value == 12) {
        return 10;
    } else if (value == 1) {
        return 11;
    } else {
        return value;
    }
}

// Function to print the deck of cards
void printDeck(int deck[]) {
    for (int i = 0; i < 52; i++) {
        switch (deck[i] / 13) {
            case 0:
                printf("Spades ");
                break;
            case 1:
                printf("Hearts ");
                break;
            case 2:
                printf("Diamonds ");
                break;
            case 3:
                printf("Clubs ");
                break;
            default:
                break;
        }
        switch (deck[i] % 13) {
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
                printf("%d\n", deck[i] % 13 + 1);
                break;
        }
    }
}

int main() {
    srand(time(NULL)); // Initialize random seed
    
    int deck[52]; // Create a deck of cards
    for (int i = 0; i < 52; i++) {
        deck[i] = i;
    }
    
    shuffle(deck); // Shuffle the deck
    
    int playerHand[11]; // Create the player's hand
    playerHand[0] = deck[0];
    playerHand[1] = deck[2];
    int playerScore = getCardValue(deck[0]) + getCardValue(deck[2]);
    int playerCardCount = 2;
    printf("Your hand:\n");
    printf("----------------\n");
    printf("| ");
    switch (playerHand[0] % 13) {
        case 0:
            printf("A ");
            break;
        case 10:
            printf("J ");
            break;
        case 11:
            printf("Q ");
            break;
        case 12:
            printf("K ");
            break;
        default:
            printf("%d ", playerHand[0] % 13 + 1);
            break;
    }
    switch (playerHand[1] % 13) {
        case 0:
            printf("A");
            break;
        case 10:
            printf("J");
            break;
        case 11:
            printf("Q");
            break;
        case 12:
            printf("K");
            break;
        default:
            printf("%d", playerHand[1] % 13 + 1);
            break;
    }
    printf(" |\n");
    printf("----------------\n");
    
    int dealerHand[11]; // Create the dealer's hand
    dealerHand[0] = deck[1];
    dealerHand[1] = deck[3];
    int dealerScore = getCardValue(deck[1]) + getCardValue(deck[3]);
    int dealerCardCount = 2;
    printf("Dealer's hand:\n");
    printf("----------------\n");
    printf("| ");
    switch (dealerHand[0] % 13) {
        case 0:
            printf("A ");
            break;
        case 10:
            printf("J ");
            break;
        case 11:
            printf("Q ");
            break;
        case 12:
            printf("K ");
            break;
        default:
            printf("%d ", dealerHand[0] % 13 + 1);
            break;
    }
    printf("| X |\n");
    printf("----------------\n");
    
    char choice;
    do {
        printf("Would you like to hit (h) or stand (s)? ");
        scanf(" %c", &choice);
        if (choice == 'h') {
            playerHand[playerCardCount] = deck[playerCardCount + 3];
            playerScore += getCardValue(deck[playerCardCount + 3]);
            playerCardCount++;
            printf("Your hand:\n");
            printf("----------------\n");
            printf("| ");
            for (int i = 0; i < playerCardCount; i++) {
                switch (playerHand[i] % 13) {
                    case 0:
                        printf("A ");
                        break;
                    case 10:
                        printf("J ");
                        break;
                    case 11:
                        printf("Q ");
                        break;
                    case 12:
                        printf("K ");
                        break;
                    default:
                        printf("%d ", playerHand[i] % 13 + 1);
                        break;
                }
            }
            printf("|\n");
            printf("----------------\n");
            if (playerScore > 21) {
                printf("Bust! You lose.\n");
                return 0;
            }
        }
    } while (choice == 'h');
    
    printf("Dealer's hand:\n");
    printf("----------------\n");
    printf("| ");
    for (int i = 0; i < dealerCardCount; i++) {
        switch (dealerHand[i] % 13) {
            case 0:
                printf("A ");
                break;
            case 10:
                printf("J ");
                break;
            case 11:
                printf("Q ");
                break;
            case 12:
                printf("K ");
                break;
            default:
                printf("%d ", dealerHand[i] % 13 + 1);
                break;
        }
    }
    printf("|\n");
    printf("----------------\n");
    while (dealerScore < 17) {
        dealerHand[dealerCardCount] = deck[dealerCardCount + 4];
        dealerScore += getCardValue(deck[dealerCardCount + 4]);
        dealerCardCount++;
        printf("Dealer draws another card.\n");
        printf("Dealer's hand:\n");
        printf("----------------\n");
        printf("| ");
        for (int i = 0; i < dealerCardCount; i++) {
            switch (dealerHand[i] % 13) {
                case 0:
                    printf("A ");
                    break;
                case 10:
                    printf("J ");
                    break;
                case 11:
                    printf("Q ");
                    break;
                case 12:
                    printf("K ");
                    break;
                default:
                    printf("%d ", dealerHand[i] % 13 + 1);
                    break;
            }
        }
        printf("|\n");
        printf("----------------\n");
    }
    if (dealerScore > 21) {
        printf("Dealer busts! You win!\n");
    } else if (dealerScore > playerScore) {
        printf("Dealer wins!\n");
    } else if (playerScore > dealerScore) {
        printf("You win!\n");
    } else {
        printf("It's a tie!\n");
    }
    return 0;
}