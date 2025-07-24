//FormAI DATASET v1.0 Category: Memory Game ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 4

typedef struct{
    int row;
    int col;
} Position;

typedef enum{
    HIDDEN,
    REVEALED,
    MATCHED
} CardStatus;

typedef struct{
    int value;
    CardStatus status;
} Card;

void initializeBoard(Card board[BOARD_SIZE][BOARD_SIZE]);
void printBoard(Card board[BOARD_SIZE][BOARD_SIZE]);
void shuffleDeck(Card deck[]);
void swap(Card *a, Card *b);
int isGameOver(Card board[BOARD_SIZE][BOARD_SIZE]);
void revealCard(Card board[BOARD_SIZE][BOARD_SIZE], Position pos);
void hideCard(Card board[BOARD_SIZE][BOARD_SIZE], Position pos);

int main(){
    srand(time(NULL));
    Card deck[BOARD_SIZE * BOARD_SIZE / 2];
    initializeDeck(deck);
    shuffleDeck(deck);
    Card board[BOARD_SIZE][BOARD_SIZE];
    for(int row = 0; row < BOARD_SIZE; row++){
        for(int col = 0; col < BOARD_SIZE; col++){
            int index = row * BOARD_SIZE + col;
            board[row][col].value = deck[index/2].value;
            board[row][col].status = HIDDEN;
        }
    }
    int numGuesses = 0;
    while(!isGameOver(board)){
        printf("Number of guesses: %d\n", numGuesses);
        printBoard(board);
        Position pos1, pos2;
        printf("Enter row and column of first card: ");
        scanf("%d %d", &pos1.row, &pos1.col);
        printf("Enter row and column of second card: ");
        scanf("%d %d", &pos2.row, &pos2.col);
        if(board[pos1.row][pos1.col].value == board[pos2.row][pos2.col].value){
            board[pos1.row][pos1.col].status = MATCHED;
            board[pos2.row][pos2.col].status = MATCHED;
            printf("Match!\n");
        } else {
            revealCard(board, pos1);
            revealCard(board, pos2);
            printf("No match.\n");
            printf("Press enter to continue.\n");
            getchar();
            hideCard(board, pos1);
            hideCard(board, pos2);
        }
        numGuesses++;
    }
    printf("Congratulations, you won in %d guesses!\n", numGuesses);
    return 0;
}

void initializeDeck(Card deck[]){
    for(int i = 0; i < BOARD_SIZE * BOARD_SIZE / 2; i++){
        deck[i].value = i + 1;
    }
}

void shuffleDeck(Card deck[]){
    for(int i = 0; i < BOARD_SIZE * BOARD_SIZE / 2; i++){
        int j = rand() % (BOARD_SIZE * BOARD_SIZE / 2);
        swap(&deck[i], &deck[j]);
    }
}

void swap(Card *a, Card *b){
    Card temp = *a;
    *a = *b;
    *b = temp;
}

void initializeBoard(Card board[BOARD_SIZE][BOARD_SIZE]){
    for(int row = 0; row < BOARD_SIZE; row++){
        for(int col = 0; col < BOARD_SIZE; col++){
            board[row][col].value = 0;
            board[row][col].status = HIDDEN;
        }
    }
}

void printBoard(Card board[BOARD_SIZE][BOARD_SIZE]){
    printf("\n");
    printf("    ");
    for(int col = 0; col < BOARD_SIZE; col++){
        printf("%d   ", col);
    }
    printf("\n");
    printf("   ");
    for(int col = 0; col < BOARD_SIZE; col++){
        printf("----");
    }
    printf("\n");
    for(int row = 0; row < BOARD_SIZE; row++){
        printf("%d | ", row);
        for(int col = 0; col < BOARD_SIZE; col++){
            if(board[row][col].status == HIDDEN){
                printf("X | ");
            } else {
                printf("%d | ", board[row][col].value);
            }
        }
        printf("\n");
        printf("   ");
        for(int col = 0; col < BOARD_SIZE; col++){
            printf("----");
        }
        printf("\n");
    }
}

int isGameOver(Card board[BOARD_SIZE][BOARD_SIZE]){
    for(int row = 0; row < BOARD_SIZE; row++){
        for(int col = 0; col < BOARD_SIZE; col++){
            if(board[row][col].status != MATCHED){
                return 0;
            }
        }
    }
    return 1;
}

void revealCard(Card board[BOARD_SIZE][BOARD_SIZE], Position pos){
    board[pos.row][pos.col].status = REVEALED;
}

void hideCard(Card board[BOARD_SIZE][BOARD_SIZE], Position pos){
    board[pos.row][pos.col].status = HIDDEN;
}