//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: cheerful
/* Bingo Simulator - Enjoy The Game! */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 5
#define MAX_NUM 75
#define MAX_TURN 75

void printCard(int card[][COLS]);
int generateRandom(int num[]);
int checkWin(int card[][COLS]);

int main()
{
    srand(time(NULL));
    int card[ROWS][COLS] = {};
    int num[MAX_NUM] = {};
    int turn = 0;
    int win = 0;
    int i, j, n;

    // Generate unique random numbers
    for(i = 0; i < MAX_NUM; i++){
        n = generateRandom(num);
        num[i] = n;
    }

    // Generate bingo card
    for(i = 0; i < ROWS; i++){
        for(j = 0; j < COLS; j++){
            if(i == 2 && j == 2){
                card[i][j] = -1; // Free space
            }
            else{
                card[i][j] = generateRandom(num);
            }
        }
    }

    // Welcome message
    printf("\n==========================================\n");
    printf("               BINGO SIMULATOR\n");
    printf("==========================================\n\n");

    // Print card
    printf("Here's your bingo card:\n\n");
    printCard(card);

    // Start game
    while(turn < MAX_TURN && !win){
        printf("\nPress ENTER to draw a number...");
        getchar();

        // Draw a number
        n = generateRandom(num);

        printf("\nThe number is: %d\n", n);

        // Check card
        for(i = 0; i < ROWS; i++){
            for(j = 0; j < COLS; j++){
                if(card[i][j] == n){
                    card[i][j] = -1;
                }
            }
        }

        // Print card
        printf("\nHere's your updated bingo card:\n\n");
        printCard(card);

        // Check for win
        win = checkWin(card);

        turn++;
    }

    // Game over message
    if(win){
        printf("\n==========================================\n");
        printf("               BINGO!!!\n");
        printf("==========================================\n\n");
        printf("Congratulations! You won in %d turns.\n", turn);
    }
    else{
        printf("\n==========================================\n");
        printf("               GAME OVER\n");
        printf("==========================================\n\n");
        printf("Sorry, you didn't win. Better luck next time!\n");
    }

    return 0;
}

void printCard(int card[][COLS])
{
    int i, j;

    printf("-----------------\n");
    for(i = 0; i < ROWS; i++){
        printf("| ");
        for(j = 0; j < COLS; j++){
            if(card[i][j] == -1){
                printf("F ");
            }
            else{
                printf("%d ", card[i][j]);
            }
            if(j == 4){
                printf("|");
            }
        }
        printf("\n");
    }
    printf("-----------------\n");
}

int generateRandom(int num[])
{
    int n, i;
    do{
        n = rand() % MAX_NUM + 1;
        for(i = 0; i < MAX_NUM; i++){
            if(num[i] == n){
                break;
            }
        }
    }while(i < MAX_NUM);
    return n;
}

int checkWin(int card[][COLS])
{
    int i, j, x, y, count;

    // Check rows
    for(i = 0; i < ROWS; i++){
        count = 0;
        for(j = 0; j < COLS; j++){
            if(card[i][j] == -1){
                count++;
            }
        }
        if(count == 5){
            return 1;
        }
    }

    // Check columns
    for(j = 0; j < COLS; j++){
        count = 0;
        for(i = 0; i < ROWS; i++){
            if(card[i][j] == -1){
                count++;
            }
        }
        if(count == 5){
            return 1;
        }
    }

    // Check diagonals
    count = 0;
    for(x = 0, y = 0; x < ROWS && y < COLS; x++, y++){
        if(card[x][y] == -1){
            count++;
        }
    }
    if(count == 5){
        return 1;
    }

    count = 0;
    for(x = 0, y = 4; x < ROWS && y >= 0; x++, y--){
        if(card[x][y] == -1){
            count++;
        }
    }
    if(count == 5){
        return 1;
    }

    return 0;
}