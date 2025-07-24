//FormAI DATASET v1.0 Category: Memory Game ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 4

void initBoard(int board[ROWS][COLS]);
void printBoard(int board[ROWS][COLS], int revealed[ROWS][COLS]);
void revealCard(int row, int col, int board[ROWS][COLS], int revealed[ROWS][COLS]);
void hideCards(int board[ROWS][COLS], int revealed[ROWS][COLS]);
int checkGameOver(int board[ROWS][COLS], int revealed[ROWS][COLS]);

int main(){
    int board[ROWS][COLS]; //the game board
    int revealed[ROWS][COLS]; //whether or not a card has been revealed
    int currRow, currCol; //current row and column selected by the player
    char playAgain = 'y'; //whether or not to play again

    srand(time(NULL)); //setting the seed for the random number generator

    printf("Welcome to Memory Game!\n");

    while(playAgain == 'y'){
        printf("Starting a new game...\n");

        //initialize the game board and revealed array
        initBoard(board);
        initBoard(revealed);

        //set up game loop
        while(!checkGameOver(board, revealed)){
            //print the game board
            printBoard(board, revealed);

            //player selects a card to reveal
            printf("Enter row and column of card to reveal (e.g. 3 2): ");
            scanf("%d %d", &currRow, &currCol);

            //reveal the selected card
            revealCard(currRow, currCol, board, revealed);

            //wait a moment to simulate thinking
            printf("Thinking...\n");
            sleep(1);

            //hide all cards if two have been revealed
            if(checkGameOver(board, revealed)){
                printf("Game over! You win!\n");
            }
            else{
                hideCards(board, revealed);
            }
        }

        //prompt user to play again
        printf("Play again? (y/n): ");
        scanf(" %c", &playAgain);
    }

    printf("Thanks for playing Memory Game! Goodbye.\n");

    return 0;
}

void initBoard(int board[ROWS][COLS]){
    int numPairs = (ROWS * COLS) / 2; //number of pairs of cards
    int pairs[numPairs]; //array to hold the values of each pair
    int i, j, r;

    //set the values of each pair of cards
    for(i = 0; i < numPairs; i++){
        pairs[i] = i + 1;
    }

    //shuffle the pairs
    for(i = numPairs - 1; i > 0; i--){
        r = rand() % (i + 1);
        int temp = pairs[i];
        pairs[i] = pairs[r];
        pairs[r] = temp;
    }

    //place the pairs on the game board
    int cardCount = 0;
    for(i = 0; i < ROWS; i++){
        for(j = 0; j < COLS; j++){
            board[i][j] = pairs[cardCount % numPairs];
            cardCount++;
        }
    }
}

void printBoard(int board[ROWS][COLS], int revealed[ROWS][COLS]){
    int i, j;

    printf("\n    ");
    for(i = 0; i < COLS; i++){
        printf("%d   ", i);
    }
    printf("\n");

    for(i = 0; i < ROWS; i++){
        printf("%d  ", i);
        for(j = 0; j < COLS; j++){
            if(revealed[i][j]){
                printf("%d   ", board[i][j]);
            }
            else{
                printf("X   ");
            }
        }
        printf("\n");
    }
}

void revealCard(int row, int col, int board[ROWS][COLS], int revealed[ROWS][COLS]){
    revealed[row][col] = 1;
}

void hideCards(int board[ROWS][COLS], int revealed[ROWS][COLS]){
    int i, j, numRevealed = 0;

    //count number of cards currently revealed
    for(i = 0; i < ROWS; i++){
        for(j = 0; j < COLS; j++){
            if(revealed[i][j]){
                numRevealed++;
            }
        }
    }

    //if two cards are revealed, hide them
    if(numRevealed == 2){
        for(i = 0; i < ROWS; i++){
            for(j = 0; j < COLS; j++){
                if(revealed[i][j]){
                    revealed[i][j] = 0;
                }
            }
        }
    }
}

int checkGameOver(int board[ROWS][COLS], int revealed[ROWS][COLS]){
    int i, j, numRevealed = 0;

    //count number of cards currently revealed
    for(i = 0; i < ROWS; i++){
        for(j = 0; j < COLS; j++){
            if(revealed[i][j]){
                numRevealed++;
            }
        }
    }

    //if all cards are revealed, game is over
    if(numRevealed == ROWS * COLS){
        return 1;
    }
    else{
        return 0;
    }
}