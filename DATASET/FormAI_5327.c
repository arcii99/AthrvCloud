//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: medieval
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>

// Defining the size of the board, number of treasures and the remote control range
#define BOARD_SIZE 10
#define NUM_TREASURES 5
#define REMOTE_RANGE 3

// Function to generate a random number within a certain range
int generateRandom(int lower, int upper){
    int num = (rand() % (upper - lower + 1)) + lower; 
    return num;
}

// Function to initialize the board with empty spaces and place the treasures on the board
void initializeBoard(char board[][BOARD_SIZE], int treasureX[], int treasureY[]){
    int i, j;

    // Initializing the board with empty spaces
    for(i=0; i<BOARD_SIZE; i++){
        for(j=0; j<BOARD_SIZE; j++){
            board[i][j] = '.';
        }
    }

    // Placing the treasures on the board
    for(i=0; i<NUM_TREASURES; i++){
        int x = generateRandom(0, BOARD_SIZE-1);
        int y = generateRandom(0, BOARD_SIZE-1);
        treasureX[i] = x;
        treasureY[i] = y;
        board[x][y] = '$';
    }
}

// Function to display the board
void displayBoard(char board[][BOARD_SIZE]){
    int i, j;

    for(i=0; i<BOARD_SIZE; i++){
        for(j=0; j<BOARD_SIZE; j++){
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int main(){
    char board[BOARD_SIZE][BOARD_SIZE];
    int treasureX[NUM_TREASURES];
    int treasureY[NUM_TREASURES];
    int i, j;
    int x = generateRandom(0, BOARD_SIZE-1);
    int y = generateRandom(0, BOARD_SIZE-1);
    int moves = 0;

    // Initializing the random number generator
    srand(time(0));

    // Initializing the board and placing the treasures
    initializeBoard(board, treasureX, treasureY);

    // Placing the remote control vehicle on the board
    board[x][y] = 'V';

    // Displaying the board with the vehicle and the treasures
    printf("Welcome to the Remote Control Vehicle Simulation Game!\n\n");
    displayBoard(board);

    // Looping until all the treasures are found
    while(true){
        int direction, distance;

        // Getting user input for direction and distance to move the vehicle
        printf("\nEnter direction (1-North, 2-South, 3-East, 4-West) and distance (0-%d): ", REMOTE_RANGE);
        scanf("%d %d", &direction, &distance);

        // Checking if the user input is valid
        if(direction<1 || direction>4 || distance<0 || distance>REMOTE_RANGE){
            printf("\nInvalid input! Try again.\n");
            continue;
        }

        // Moving the vehicle on the board based on user input
        switch(direction){
            case 1:
                for(i=x-1; i>=x-distance; i--){
                    if(i<0){
                        printf("\nOut of range! Try again.\n");
                        break;
                    }
                    else if(board[i][y] == '$'){
                        printf("\nTreasure found! :)\n");
                        board[i][y] = 'V';
                        board[x][y] = '.';
                        x = i;
                        moves++;
                        treasureX[i] = -1;
                        treasureY[i] = -1;
                        if(moves == NUM_TREASURES){
                            printf("\nCongratulations! You have found all the treasures in %d moves.\n", moves);
                            printf("Game Over.\n");
                            return 0;
                        }
                        displayBoard(board);
                        break;
                    }
                    else{
                        board[i][y] = 'V';
                        board[x][y] = '.';
                        x = i;
                        moves++;
                        displayBoard(board);
                    }
                }
                break;
            case 2:
                for(i=x+1; i<=x+distance; i++){
                    if(i>=BOARD_SIZE){
                        printf("\nOut of range! Try again.\n");
                        break;
                    }
                    else if(board[i][y] == '$'){
                        printf("\nTreasure found! :)\n");
                        board[i][y] = 'V';
                        board[x][y] = '.';
                        x = i;
                        moves++;
                        treasureX[i] = -1;
                        treasureY[i] = -1;
                        if(moves == NUM_TREASURES){
                            printf("\nCongratulations! You have found all the treasures in %d moves.\n", moves);
                            printf("Game Over.\n");
                            return 0;
                        }
                        displayBoard(board);
                        break;
                    }
                    else{
                        board[i][y] = 'V';
                        board[x][y] = '.';
                        x = i;
                        moves++;
                        displayBoard(board);
                    }
                }
                break;
            case 3:
                for(j=y+1; j<=y+distance; j++){
                    if(j>=BOARD_SIZE){
                        printf("\nOut of range! Try again.\n");
                        break;
                    }
                    else if(board[x][j] == '$'){
                        printf("\nTreasure found! :)\n");
                        board[x][j] = 'V';
                        board[x][y] = '.';
                        y = j;
                        moves++;
                        treasureX[j] = -1;
                        treasureY[j] = -1;
                        if(moves == NUM_TREASURES){
                            printf("\nCongratulations! You have found all the treasures in %d moves.\n", moves);
                            printf("Game Over.\n");
                            return 0;
                        }
                        displayBoard(board);
                        break;
                    }
                    else{
                        board[x][j] = 'V';
                        board[x][y] = '.';
                        y = j;
                        moves++;
                        displayBoard(board);
                    }
                }
                break;
            case 4:
                for(j=y-1; j>=y-distance; j--){
                    if(j<0){
                        printf("\nOut of range! Try again.\n");
                        break;
                    }
                    else if(board[x][j] == '$'){
                        printf("\nTreasure found! :)\n");
                        board[x][j] = 'V';
                        board[x][y] = '.';
                        y = j;
                        moves++;
                        treasureX[j] = -1;
                        treasureY[j] = -1;
                        if(moves == NUM_TREASURES){
                            printf("\nCongratulations! You have found all the treasures in %d moves.\n", moves);
                            printf("Game Over.\n");
                            return 0;
                        }
                        displayBoard(board);
                        break;
                    }
                    else{
                        board[x][j] = 'V';
                        board[x][y] = '.';
                        y = j;
                        moves++;
                        displayBoard(board);
                    }
                }
                break;
        }
    }

    return 0;
}