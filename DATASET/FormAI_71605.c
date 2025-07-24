//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 5

void generateCard(int card[ROWS][COLS]) {
    int used[76] = {0}; // array to store used numbers
    srand(time(NULL)); // seed the random number generator with current time
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            int num;
            do {
                num = rand() % 75 + 1; // generate a random number between 1 to 75
            } while(used[num]); // loop until an unused number is obtained
            used[num] = 1; // mark the number as used
            card[i][j] = num; // assign the number to the card
        }
    }
}

void printCard(int card[ROWS][COLS], int calledNumbers[]) {
    printf("+---+---+---+---+---+\n");
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            printf("| ");
            if(card[i][j] == calledNumbers[card[i][j]]) // check if the number is already called
                printf("X");
            else
                printf("%2d", card[i][j]);
            printf(" ");
        }
        printf("|\n");
        printf("+---+---+---+---+---+\n");
    }
}

int checkBingo(int card[ROWS][COLS], int calledNumbers[]) {
    int bingo = 0;
    for(int i=0; i<ROWS; i++) {
        int count = 0;
        for(int j=0; j<COLS; j++) {
            if(card[i][j] == calledNumbers[card[i][j]]) // check if the number is already called
                count++;
        }
        if(count == ROWS) {
            printf("Bingo on row %d!\n", i+1);
            bingo = 1;
        }
    }
    for(int j=0; j<COLS; j++) {
        int count = 0;
        for(int i=0; i<ROWS; i++) {
            if(card[i][j] == calledNumbers[card[i][j]]) // check if the number is already called
                count++;
        }
        if(count == COLS) {
            printf("Bingo on column %d!\n", j+1);
            bingo = 1;
        }
    }
    int count = 0;
    for(int i=0; i<ROWS; i++) {
        if(card[i][i] == calledNumbers[card[i][i]]) // check if the number is already called
            count++;
    }
    if(count == ROWS) {
        printf("Bingo on diagonal from top-left to bottom-right!\n");
        bingo = 1;
    }
    count = 0;
    for(int i=0; i<ROWS; i++) {
        if(card[i][ROWS-i-1] == calledNumbers[card[i][ROWS-i-1]]) // check if the number is already called
            count++;
    }
    if(count == ROWS) {
        printf("Bingo on diagonal from top-right to bottom-left!\n");
        bingo = 1;
    }
    return bingo;
}

int main() {
    int card[ROWS][COLS];
    int calledNumbers[76] = {0}; // array to store called numbers
    generateCard(card);
    printf("Your Bingo Card is:\n");
    printCard(card, calledNumbers);
    printf("Press enter key to start calling numbers...\n");
    getchar();
    system("clear"); // clear the screen
    int numCalled = 0;
    while(1) {
        printf("Number called: ");
        int num;
        do {
            num = rand() % 75 + 1; // generate a random number between 1 to 75
        } while(calledNumbers[num]); // loop until an uncalled number is obtained
        calledNumbers[num] = num; // mark the number as called
        printf("%d\n", num);
        numCalled++;
        if(checkBingo(card, calledNumbers)) { // check if bingo is achieved
            printf("Congratulations! You have won Bingo in %d calls!\n", numCalled);
            break;
        }
        printf("Press enter key to call next number...\n");
        getchar();
        system("clear"); // clear the screen
        printf("Your Bingo Card is:\n");
        printCard(card, calledNumbers);
    }
    return 0;
}