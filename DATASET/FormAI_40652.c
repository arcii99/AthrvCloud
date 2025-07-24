//FormAI DATASET v1.0 Category: Poker Game ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Function declarations
void dealCards(int deck[][13], int playerCards[][2]);
void displayHands(int playerCards[][2], char * suits[], char * ranks[]);
int determineWinner(int playerCards[][2]);

int main() {

    int deck[4][13] = {0};
    int playerCards[4][2] = {0};

    //Initializing the deck of cards
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 13; j++) {
            deck[i][j] = 1;
        }
    }

    //Initializing the suits and ranks arrays
    char *suits[] = {"Hearts", "Diamonds", "Clubs", "Spades"};
    char *ranks[] = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King"};

    //Dealing cards to the players
    dealCards(deck, playerCards);

    //Displaying the hands of each player
    displayHands(playerCards, suits, ranks);

    //Determining the winner of the game
    int winner = determineWinner(playerCards);

    printf("The winner of the game is Player %d\n", winner);

    return 0;
}

void dealCards(int deck[][13], int playerCards[][2]) {

    srand(time(NULL));

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 2; j++) {
            int suit = rand() % 4;
            int rank = rand() % 13;

            //Checking if the card has already been dealt
            while (deck[suit][rank] == 0) {
                suit = rand() % 4;
                rank = rand() % 13;
            }

            playerCards[i][j] = rank;
            playerCards[i][j+1] = suit;
            deck[suit][rank] = 0;
        }
    }
}

void displayHands(int playerCards[][2], char * suits[], char * ranks[]) {

    for (int i = 0; i < 4; i++) {
        printf("Player %d: ", i+1);
        for (int j = 0; j < 2; j++) {
            printf("%s of %s, ", ranks[playerCards[i][j]], suits[playerCards[i][j+1]]);
        }
        printf("\n");
    }
}

int determineWinner(int playerCards[][2]) {

    int maxSum = 0;
    int winner = 0;

    for (int i = 0; i < 4; i++) {
        int sum = 0;
        for (int j = 0; j < 2; j++) {
            sum += playerCards[i][j];
        }
        if (sum > maxSum) {
            maxSum = sum;
            winner = i+1;
        }
    }

    return winner;
}