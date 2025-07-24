//FormAI DATASET v1.0 Category: Memory Game ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 16

int board[BOARD_SIZE] = {0}; // initialize the board with all 0's

void clearScreen() {
    system("clear||cls");
}

void shuffle() {
    srand(time(NULL));
    for(int i = BOARD_SIZE - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int temp = board[i];
        board[i] = board[j];
        board[j] = temp;
    }
}

void fillBoard() {
    for(int i = 0; i < BOARD_SIZE/2; i++) {
        board[i] = i+1;
        board[i+BOARD_SIZE/2] = i+1;
    }
    shuffle();
}

void displayBoard() {
    printf("\n-------------");
    for(int i = 0; i < BOARD_SIZE; i++) {
        if(i%4 == 0) printf("\n| ");
        if(board[i] == 0) printf(". | ");
        else printf("%d | ", board[i]);
    }
    printf("\n-------------\n");
}

int isValidInput(int val) {
    if(val < 1 || val > BOARD_SIZE/2) return 0;
    for(int i = 0; i < BOARD_SIZE; i++) {
        if(board[i] == val) return 1;
    }
    return 0;
}

int getValidInput() {
    int val = -1;
    while(1) {
        printf("Enter a valid number from 1-%d: ", BOARD_SIZE/2);
        scanf("%d", &val);
        if(isValidInput(val)) break;
        printf("Invalid input!\n");
    }
    return val;
}

int isGameOver() {
    for(int i = 0; i < BOARD_SIZE; i++) {
        if(board[i] != 0) return 0;
    }
    return 1;
}

void playGame() {
    int score = 0;
    while(!isGameOver()) {
        displayBoard();
        int first = getValidInput();
        clearScreen();
        displayBoard();
        int second = getValidInput();
        if(board[first-1] == board[second-1]) {
            board[first-1] = 0;
            board[second-1] = 0;
            score += 2;
            printf("Match found!\n");
        } else {
            printf("No match.\n");
        }
    }
    printf("Game over! Your score is: %d\n", score);
}

int main() {
    fillBoard();
    playGame();
    return 0;
}