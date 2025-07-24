//FormAI DATASET v1.0 Category: Poker Game ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Function to get a random card from the deck
int getCard() {
    return rand()%13 + 1;
}

// Function to get a random suit from the deck
char getSuit() {
    char suits[] = "CDHS";
    return suits[rand()%4];
}

// Function to return the value of a card
int getValue(int card) {
    if(card > 10) {
        return 10;
    }
    return card;
}

// Function to check if a hand is a blackjack
int isBlackjack(int hand[]) {
    if(hand[0] == 1 && hand[1] == 10) {
        return 1;
    }
    if(hand[0] == 10 && hand[1] == 1) {
        return 1;
    }
    return 0;
}

// Function to print the cards in a hand
void printHand(int hand[]) {
    char suits[] = "CDHS";
    char faces[] = "A234567890JQK";
    int i;
    for(i = 0; i < 5; i++) {
        if(hand[i] == 0) {
            break;
        }
        printf("%c%c ", faces[hand[i]], suits[rand()%4]);
    }
    printf("\n");
}

// Function to calculate the score of a hand
int calculateScore(int hand[]) {
    int score = 0;
    int i;
    for(i = 0; i < 5; i++) {
        if(hand[i] == 0) {
            break;
        }
        score += getValue(hand[i]);
    }
    if(score <= 11 && hand[0] == 1) {
        score += 10;
    }
    return score;
}

// Function to play the game
void playGame() {
    int playerHand[5] = {0};
    int dealerHand[5] = {0};
    int playerScore = 0;
    int dealerScore = 0;
    srand(time(NULL));
    system("clear");
    printf("Welcome to C Blackjack!\n\n");
    printf("Dealing...\n\n");
    playerHand[0] = getCard();
    playerHand[1] = getCard();
    dealerHand[0] = getCard();
    dealerHand[1] = getCard();
    printf("Your hand: ");
    printHand(playerHand);
    printf("Dealer's hand: %c%c XX\n", getSuit(), getSuit());
    playerScore = calculateScore(playerHand);
    dealerScore = getValue(dealerHand[0]);
    if(isBlackjack(playerHand)) {
        printf("Blackjack! You win!\n");
        return;
    }
    while(playerScore < 21) {
        char input[5];
        printf("Hit or Stand (h or s): ");
        scanf("%s", input);
        if(strcmp(input, "h") == 0) {
            int i;
            for(i = 0; i < 5; i++) {
                if(playerHand[i] == 0) {
                    playerHand[i] = getCard();
                    break;
                }
            }
            printf("Your hand: ");
            printHand(playerHand);
            playerScore = calculateScore(playerHand);
            if(playerScore > 21) {
                printf("Busted! You lose!\n");
                return;
            }
        } else if(strcmp(input, "s") == 0) {
            printf("Your hand: ");
            printHand(playerHand);
            printf("Dealer's hand: ");
            printHand(dealerHand);
            dealerScore = calculateScore(dealerHand);
            while(dealerScore < 17) {
                int i;
                for(i = 0; i < 5; i++) {
                    if(dealerHand[i] == 0) {
                        dealerHand[i] = getCard();
                        break;
                    }
                }
                printf("Dealer hits...\n");
                dealerScore = calculateScore(dealerHand);
                printf("Dealer's hand: ");
                printHand(dealerHand);
                if(dealerScore > 21) {
                    printf("Dealer busts! You win!\n");
                    return;
                }
            }
            printf("Dealer stands.\n\n");
            if(playerScore > dealerScore) {
                printf("You win!\n");
            } else if(playerScore == dealerScore) {
                printf("Push!\n");
            } else {
                printf("You lose!\n");
            }
            return;
        } else {
            printf("Invalid input. Try again.\n");
        }
    }
    if(playerScore == 21) {
        printf("21! You stand.\n\n");
        printf("Dealer's hand: ");
        printHand(dealerHand);
        dealerScore = calculateScore(dealerHand);
        while(dealerScore < 17) {
            int i;
            for(i = 0; i < 5; i++) {
                if(dealerHand[i] == 0) {
                    dealerHand[i] = getCard();
                    break;
                }
            }
            printf("Dealer hits...\n");
            dealerScore = calculateScore(dealerHand);
            printf("Dealer's hand: ");
            printHand(dealerHand);
            if(dealerScore > 21) {
                printf("Dealer busts! You win!\n");
                return;
            }
        }
        printf("Dealer stands.\n\n");
        if(playerScore > dealerScore) {
            printf("You win!\n");
        } else if(playerScore == dealerScore) {
            printf("Push!\n");
        } else {
            printf("You lose!\n");
        }
        return;
    }
}

// The main function
int main() {
    char input[5];
    do {
        playGame();
        printf("Play again? (y or n): ");
        scanf("%s", input);
    } while(strcmp(input, "y") == 0);
    return 0;
}