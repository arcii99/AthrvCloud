//FormAI DATASET v1.0 Category: Memory Game ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 4

int board[BOARD_SIZE][BOARD_SIZE];
int revealed[BOARD_SIZE][BOARD_SIZE] = {0};
int score = 0;

void printBoard() {
    printf("\tScore: %d\n", score);
    printf("\t  1 2 3 4\n");
    printf("\t +-+-+-+-+\n");
    for(int i=0; i<BOARD_SIZE; i++) {
        printf("\t%d|", i+1);
        for(int j=0; j<BOARD_SIZE; j++) {
            if(revealed[i][j] == 0) {
                printf(" |");
            } else {
                printf("%d|", board[i][j]);
            }
        }
        printf("\n\t +-+-+-+-+\n");
    }
}

int checkWin() {
    for(int i=0; i<BOARD_SIZE; i++) {
        for(int j=0; j<BOARD_SIZE; j++) {
            if(revealed[i][j] == 0) {
                return 0;
            }
        }
    }
    return 1;
}

void revealCard(int x1, int y1, int x2, int y2) {
    if(board[x1][y1] == board[x2][y2]) {
        printf("\nMatch found!\n");
        revealed[x1][y1] = revealed[x2][y2] = 1;
        score += 2;
    } else {
        printf("\nNo match found.\n");
        revealed[x1][y1] = revealed[x2][y2] = 0;
        score--;
    }
    printf("\n");
}

void playGame() {
    printf("\nStarting game...\n");
    int x1, y1, x2, y2;
    while(!checkWin()) {
        printBoard();
        printf("\nEnter the coordinates of the first card: ");
        scanf("%d %d", &x1, &y1);
        while(revealed[x1-1][y1-1] != 0) {
            printf("\nThat card has already been revealed. Please enter different coordinates: ");
            scanf("%d %d", &x1, &y1);
        }
        printf("\nEnter the coordinates of the second card: ");
        scanf("%d %d", &x2, &y2);
        while(revealed[x2-1][y2-1] != 0 || (x1 == x2 && y1 == y2)) {
            printf("\nThat card has either already been revealed or is the same as the first card. Please enter different coordinates: ");
            scanf("%d %d", &x2, &y2);
        }
        revealCard(x1-1, y1-1, x2-1, y2-1);
    }
    printf("\nCongratulations, you won!\n\nFinal Score: %d\n", score);
}

void initializeBoard() {
    int nums[BOARD_SIZE*BOARD_SIZE/2];
    for(int i=0; i<BOARD_SIZE*BOARD_SIZE/2; i++) {
        nums[i] = i+1;
    }
    srand(time(NULL));
    for(int i=0; i<BOARD_SIZE; i++) {
        for(int j=0; j<BOARD_SIZE; j++) {
            if(board[i][j] != 0) {
                continue;
            }
            int randIndex = rand() % (BOARD_SIZE*BOARD_SIZE/2 - i*j/2);
            board[i][j] = nums[randIndex];
            board[BOARD_SIZE-1-i][BOARD_SIZE-1-j] = board[i][j];
            for(int k=randIndex; k<BOARD_SIZE*BOARD_SIZE/2-i*j/2; k++) {
                nums[k] = nums[k+1];
            }
        }
    }
}

int main() {
    initializeBoard();
    playGame();
    return 0;
}