//FormAI DATASET v1.0 Category: Memory Game ; Style: complete
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define SIZE 4 //defined the size of the board

int board[SIZE][SIZE], guessboard[SIZE][SIZE]; //declared two 2D arrays for game board and guess board
int gameover=0,score=0; //initialized with 0

/**
 * Function to print the game board
 **/
void print_board() {
    printf("\t========Memory Game========\n");
    printf("\tScore = %d\n\n",score);
    printf("\t| 1 | 2 | 3 | 4 |\n");
    printf("\t----------------\n");
    for(int i=0;i<SIZE;i++) {
        printf("\t");
        for(int j=0;j<SIZE;j++) {
            if(guessboard[i][j] == -1) 
                printf("| %c ",219); // ASCII code to print a block
            else
                printf("| %d ",guessboard[i][j]);
        }
        printf("|\n");
        printf("\t----------------\n");
    }
    printf("\n");
}

/**
 * Function to initialize the game board
 **/
void init_board() {
    for(int i=0;i<SIZE;i++) {
        for(int j=0;j<SIZE;j++) {
            board[i][j] = -1;
            guessboard[i][j] = -1;
        }
    }
}

/**
 * Function to randomly place 8 numbers on the board
 **/
void place_numbers() {
    srand(time(NULL)); //random seed
    int temp[SIZE*SIZE];
    for(int i=0;i<SIZE*SIZE/2;i++) {
        temp[i] = rand()%(SIZE*SIZE/2)+1; //generating random numbers
        int count = 0;
        int flag = 0;
        while(count<2) {
            int x = rand()%SIZE;
            int y = rand()%SIZE;
            if(board[x][y] == -1) {
                board[x][y] = temp[i];
                count++;
            }
        }
    }
}

/**
 * Function to check if the guess is correct 
 **/
int check_guess(int x1,int y1,int x2,int y2) {
    if(board[x1][y1] == board[x2][y2]) return 1;
    else return 0;
}

/**
 * Function to play the game
 **/
void play() {
    init_board();
    place_numbers();
    while(!gameover) {
        print_board();
        int x1,x2,y1,y2;
        printf("Enter first guess (row col): ");
        scanf("%d%d",&x1,&y1);
        guessboard[x1-1][y1-1] = board[x1-1][y1-1];
        print_board();
        printf("Enter second guess (row col): ");
        scanf("%d%d",&x2,&y2);
        guessboard[x2-1][y2-1] = board[x2-1][y2-1];
        if(check_guess(x1-1,y1-1,x2-1,y2-1)) { //if guesses match
            score++;
            printf("\nGood Job! You found a match!\n");
            getchar();
        }
        else {
            guessboard[x1-1][y1-1] = -1;
            guessboard[x2-1][y2-1] = -1;
            printf("\nOops! Try again!\n");
            getchar();
        }
        gameover = 1;
        for(int i=0;i<SIZE;i++) {
            for(int j=0;j<SIZE;j++) {
                if(guessboard[i][j] == -1) gameover = 0;
            }
        }
    }
}

//main function to run the game
int main() {
    printf("\tWelcome to Memory Game\n");
    printf("\tInstructions:\n\n");
    printf("\t1. Enter the row and column of the guess separated by a space\n");
    printf("\t2. You get one point for each correct guess\n");
    printf("\t3. You have to keep guessing till you match all the numbers on the board\n\n");
    printf("\tPress enter to start the game");
    getchar();
    play();
    printf("\tYou Won!\n");
    return 0;
}