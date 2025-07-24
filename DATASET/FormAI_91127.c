//FormAI DATASET v1.0 Category: Memory Game ; Style: brave
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define BOARD_SIZE 16

void printBoard(char board[]) {
    printf("\n");
    for(int i = 0; i < BOARD_SIZE; i++) {
        printf("%c\t", board[i]);
        if((i+1) % 4 == 0) printf("\n\n");
    }
}

int main() {
    char board[BOARD_SIZE];
    int flipped[2];
    int remainingPairs = 8;

    srand(time(NULL));
    char alphabets[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
    for(int i = 0; i < BOARD_SIZE; i++) board[i] = '-';

    // Randomly placing pairs of alphabets on the board
    for(int i = 0; i < 8; i++) {
        int count = 0;
        while(count < 2) {
            int index = rand() % BOARD_SIZE;
            if(board[index] == '-') {
                board[index] = alphabets[i];
                count++;
            }
        }
    }

    printf("\nMEMORY GAME\n");
    printf("Try to match all pairs in minimum number of turns\n\n");
    printBoard(board);

    while(remainingPairs > 0) {
        printf("\nEnter the indices of the two cards you want to flip (0 to 15): ");
        scanf("%d %d", &flipped[0], &flipped[1]);

        if(flipped[0] > BOARD_SIZE-1 || flipped[0] < 0 || flipped[1] > BOARD_SIZE-1 || flipped[1] < 0) {
            printf("\nEnter valid indices between 0 and 15\n");
            continue;
        }

        if(flipped[0] == flipped[1]) {
            printf("\nEnter two different indices\n");
            continue;
        }

        if(board[flipped[0]] == '-' || board[flipped[1]] == '-') {
            printf("\nCard already matched or not flipped yet\n");
            continue;
        }

        // If the two flipped cards match
        if(board[flipped[0]] == board[flipped[1]]) {
            printf("\nMatch!\n");
            board[flipped[0]] = '-';
            board[flipped[1]] = '-';
            remainingPairs--;
        } else {    // If the two flipped cards don't match
            printf("\nTry again\n");
        }

        printBoard(board);
    }

    printf("\nCongratulations! You won in %d turns\n", BOARD_SIZE/2 - remainingPairs);

    return 0;
}