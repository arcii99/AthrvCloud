//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <pthread.h>

#define MAX_PLAYERS 5
#define MAX_NUMBERS 75

int bingoNumbers[MAX_NUMBERS];
bool calledNumbers[MAX_NUMBERS];
bool winners[MAX_PLAYERS];

struct player {
    int id;
    int numbers[25];
};

struct player players[MAX_PLAYERS];

pthread_t threads[MAX_PLAYERS];

void printBoard(int *numbers, int size) {
    printf("\n");
    for (int i = 0; i < size; i++) {
        printf("%d\t", numbers[i]);
        if ((i + 1) % 5 == 0) {
            printf("\n");
        }
    }
    printf("\n");
}

void *playGame(void *playerArg) {
    struct player currentPlayer = *(struct player *) playerArg;
    printf("Player %d:\n", currentPlayer.id);
    printBoard(currentPlayer.numbers, 25);
    
    bool hasWon = false;
    while (!hasWon) {
        int chosenNumber = rand() % 75;
        if (!calledNumbers[chosenNumber]) {
            printf("Player %d: Calling number %d\n", currentPlayer.id, bingoNumbers[chosenNumber]);
            calledNumbers[chosenNumber] = true;
            
            for (int i = 0; i < 25; i++) {
                if (currentPlayer.numbers[i] == bingoNumbers[chosenNumber]) {
                    currentPlayer.numbers[i] = 0;
                }
            }
            
            printBoard(currentPlayer.numbers, 25);
            
            bool isBingo = true;
            for (int i = 0; i < 5; i++) {
                if (currentPlayer.numbers[i] != 0) {
                    isBingo = false;
                    break;
                }
            }
            
            if (isBingo) {
                printf("Player %d WINS!!!\n", currentPlayer.id);
                hasWon = true;
                winners[currentPlayer.id] = true;
            }
        }
    }
    
    pthread_exit(NULL);
}

int main() {
    srand(time(NULL));
    for (int i = 0; i < MAX_NUMBERS; i++) {
        bingoNumbers[i] = i + 1;
        calledNumbers[i] = false;
    }
    
    for (int i = 0; i < MAX_PLAYERS; i++) {
        players[i].id = i + 1;
        for (int j = 0; j < 25; j++) {
            if (j == 12) {
                players[i].numbers[j] = 0;
            } else {
                bool isUnique = false;
                while (!isUnique) {
                    int randomNumber = rand() % 75 + 1;
                    isUnique = true;
                    for (int k = 0; k < j; k++) {
                        if (players[i].numbers[k] == randomNumber) {
                            isUnique = false;
                            break;
                        }
                    }
                    players[i].numbers[j] = randomNumber;
                }
            }
        }
        printf("\nPlayer %d numbers:\n", i + 1);
        printBoard(players[i].numbers, 25);
    }
    
    for (int i = 0; i < MAX_PLAYERS; i++) {
        pthread_create(&threads[i], NULL, playGame, (void *) &players[i]);
    }
    
    for (int i = 0; i < MAX_PLAYERS; i++) {
        pthread_join(threads[i], NULL);
    }
    
    for (int i = 0; i < MAX_PLAYERS; i++) {
        if (winners[i]) {
            printf("Player %d won the game!\n", i + 1);
        } else {
            printf("Player %d did not win the game.\n", i + 1);
        }
    }
    
    return 0;
}