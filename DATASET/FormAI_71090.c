//FormAI DATASET v1.0 Category: Poker Game ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <ctype.h>
#include <pthread.h>

struct Player {
    char name[20];
    int chips;
    int hand[2];
    bool fold;
};

// Global variables
int pot = 0;
int bet = 0;
int numPlayers = 2;
bool gameOver = false;
int currentPlayer = -1; // player who is currently making a move
struct Player players[10]; // max 10 players

void initializePlayers() {
    for(int i = 0; i < numPlayers; i++) {
        memset(players[i].name, 0, sizeof(players[i].name));
        players[i].chips = 500;
        players[i].hand[0] = -1;
        players[i].hand[1] = -1;
        players[i].fold = false;
    }
}

void printPlayer(struct Player player) {
    printf("%s has %d chips.\n", player.name, player.chips);
    printf("%s's hand: %d %d\n", player.name, player.hand[0], player.hand[1]);
}

void printAllPlayers() {
    for(int i = 0; i < numPlayers; i++) {
        if(!players[i].fold) {
            printPlayer(players[i]);
        }
    }
}

void dealHands() {
    for(int i = 0; i < numPlayers; i++) {
        players[i].hand[0] = rand() % 52;
        do {
            players[i].hand[1] = rand() % 52;
        } while(players[i].hand[1] == players[i].hand[0]);
    }
}

int getWinner() {
    // implement this later
    return -1;
}

void takeBet(int amount) {
    players[currentPlayer].chips -= amount;
    pot += amount;
}

void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

void *playerTurn(void *arg) {
    int playerIndex = *(int *)arg;
    bet = 0;
    printf("%s's turn.\n", players[playerIndex].name);
    sleep(2);
    
    // check if player has options to make a move
    if(players[playerIndex].fold || players[playerIndex].chips < bet) {
        printf("%s cannot make a move.\n", players[playerIndex].name);
        pthread_exit(NULL);
    }
    
    // get player's move choice
    printf("%s, would you like to:\n1. Check\n2. Bet\n3. Fold\n", players[playerIndex].name);
    int input;
    do {
        printf("Please enter your choice: ");
        scanf("%d", &input);
        clearInputBuffer();
        if(input < 1 || input > 3) {
            printf("Invalid choice. Please enter 1, 2, or 3.\n");
            sleep(1);
        }
    } while(input < 1 || input > 3);
    
    // handle player's move
    switch(input) {
        case 1:
            printf("%s checks.\n", players[playerIndex].name);
            break;
        case 2:
            int betAmount;
            do {
                printf("Enter bet amount: ");
                scanf("%d", &betAmount);
                clearInputBuffer();
                if(betAmount > players[playerIndex].chips) {
                    printf("You do not have enough chips to bet that amount.\n");
                    sleep(1);
                }
                else if(betAmount < bet) {
                    printf("You must bet at least %d chips.\n", bet);
                    sleep(1);
                }
            } while(betAmount < bet || betAmount > players[playerIndex].chips);
            bet = betAmount;
            takeBet(betAmount);
            printf("%s bets %d chips.\n", players[playerIndex].name, betAmount);
            break;
        case 3:
            printf("%s folds.\n", players[playerIndex].name);
            players[playerIndex].fold = true;
            pthread_exit(NULL);
            break;
    }
    
    sleep(1);
    pthread_exit(NULL);
}

void playGame() {
    // initialize game
    srand(time(NULL));
    initializePlayers();
    dealHands();
    printAllPlayers();
    
    // loop through rounds
    for(int round = 1; round <= 4; round++) {
        printf("Round %d\n", round);
        sleep(2);
        
        // loop through player turns
        for(int i = 0; i < numPlayers; i++) {
            currentPlayer = i;
            pthread_t thread;
            pthread_create(&thread, NULL, playerTurn, (void *)&i);
            pthread_join(thread, NULL);
        }
        
        // check if game is over
        int numActivePlayers = 0;
        for(int i = 0; i < numPlayers; i++) {
            if(!players[i].fold) {
                numActivePlayers++;
            }
        }
        if(numActivePlayers == 1) {
            gameOver = true;
            int winner = getWinner();
            printf("%s wins the game!\n", players[winner].name);
            break; // end game
        }
        
        bet = 0;
    }
}

int main() {
    printf("Welcome to Poker!\n");
    
    while(!gameOver) {
        playGame();
        printf("Would you like to play again? (Y/N)\n");
        char input;
        do {
            printf("Please enter your choice: ");
            input = toupper(getchar());
            clearInputBuffer();
            if(input != 'Y' && input != 'N') {
                printf("Invalid choice. Please enter Y or N.\n");
                sleep(1);
            }
        } while(input != 'Y' && input != 'N');
        
        if(input == 'N') {
            gameOver = true;
        }
    }
    
    return 0;
}