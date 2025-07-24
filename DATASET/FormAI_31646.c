//FormAI DATASET v1.0 Category: Table Game ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//function to call the menu and select game
void menu();

//function to play game 1: Guess the Number
void guessNumber();

//function to play game 2: Odd One Out
void oddOneOut();

//function to play game 3: Sudoku
void sudoku();

//main function
int main() {
    menu();
    return 0;
}

void menu() {
    int choice;
    printf("Welcome to the C Table Game Collection!\n");
    printf("Please select a game to play:\n");
    printf("1. Guess the Number\n");
    printf("2. Odd One Out\n");
    printf("3. Sudoku\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch(choice) {
        case 1:
            guessNumber();
            break;
        case 2:
            oddOneOut();
            break;
        case 3:
            sudoku();
            break;
        default:
            printf("Invalid choice! Please try again.\n");
            menu();
    }
}

void guessNumber() {
    int secretNumber, guess, attempts = 0;
    srand(time(NULL));
    secretNumber = rand() % 101;
    printf("I'm thinking of a number between 0 and 100. Can you guess what it is?\n");
    do {
        printf("Enter your guess: ");
        scanf("%d", &guess);
        attempts++;
        if(guess > secretNumber) {
            printf("Too high! Try again.\n");
        } else if(guess < secretNumber) {
            printf("Too low! Try again.\n");
        }
    } while(guess != secretNumber);
    printf("Congratulations! You guessed the number in %d attempts.\n", attempts);
}

void oddOneOut() {
    int numbers[5];
    srand(time(NULL));
    for(int i=0; i<5; i++) {
        numbers[i] = rand() % 10 + 1;
    }
    int oddIndex = rand() % 5;
    int oddNumber = numbers[oddIndex];
    for(int i=0; i<5; i++) {
        if(i == oddIndex) {
            printf("*  ");
        } else {
            printf("%d  ", numbers[i]);
        }
    }
    printf("\n");
    printf("Which number is the odd one out? Enter your answer: ");
    int guess;
    scanf("%d", &guess);
    if(guess == oddNumber) {
        printf("Correct! %d is the odd one out.\n", oddNumber);
    } else {
        printf("Incorrect! The odd one out was %d.\n", oddNumber);
    }
}

void sudoku() {
    int grid[9][9] = {{7, 0, 0, 0, 4, 0, 5, 3, 0},
                      {0, 0, 5, 0, 0, 8, 0, 1, 0},
                      {0, 0, 8, 5, 0, 9, 0, 4, 0},
                      {5, 3, 9, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 9, 0, 0, 0, 0, 0, 0, 0},
                      {0, 1, 0, 7, 0, 0, 3, 0, 0},
                      {0, 0, 0, 0, 2, 6, 0, 0, 7}};
    printf("Welcome to Sudoku!\n");
    printf("Enter rows and columns of cells separated by a space (eg. 1 2) to make a guess, or enter 0 0 to quit.\n");
    while(1) {
        int row, col, guess;
        printf("Enter your guess: ");
        scanf("%d %d", &row, &col);
        if(row == 0 && col == 0) {
            printf("Thanks for playing Sudoku!\n");
            break;
        }
        printf("Enter your guess: ");
        scanf("%d", &guess);
        if(grid[row-1][col-1] != 0) {
            printf("Invalid guess! That cell is already filled.\n");
        } else if(guess < 1 || guess > 9) {
            printf("Invalid guess! Guesses must be numbers between 1 and 9.\n");
        } else if(validGuess(grid, row-1, col-1, guess)) {
            grid[row-1][col-1] = guess;
            if(isGameComplete(grid)) {
                printf("Congratulations! You completed the Sudoku.\n");
                break;
            }
            printGrid(grid);
        } else {
            printf("Invalid guess! That guess violates Sudoku rules.\n");
        }
    }
}

//function to check if a row, column, or 3x3 square contains a certain number
int isValid(int grid[][9], int row, int col, int num) {
    for(int i=0; i<9; i++) {
        if(grid[row][i] == num || grid[i][col] == num) {
            return 0;
        }
    }
    int startRow = (row/3)*3;
    int startCol = (col/3)*3;
    for(int i=startRow; i<startRow+3; i++) {
        for(int j=startCol; j<startCol+3; j++) {
            if(grid[i][j] == num) {
                return 0;
            }
        }
    }
    return 1;
}

//function to check if a guess is valid
int validGuess(int grid[][9], int row, int col, int guess) {
    for(int i=0; i<9; i++) {
        if(grid[row][i] == guess || grid[i][col] == guess) {
            return 0;
        }
    }
    int startRow = (row/3)*3;
    int startCol = (col/3)*3;
    for(int i=startRow; i<startRow+3; i++) {
        for(int j=startCol; j<startCol+3; j++) {
            if(grid[i][j] == guess) {
                return 0;
            }
        }
    }
    return 1;
}

//function to check if the Sudoku is complete
int isGameComplete(int grid[][9]) {
    for(int i=0; i<9; i++) {
        for(int j=0; j<9; j++) {
            if(grid[i][j] == 0) {
                return 0;
            }
        }
    }
    return 1;
}

//function to print the Sudoku grid
void printGrid(int grid[][9]) {
    printf("\n");
    printf(" -----------------------\n");
    for(int i=0; i<9; i++) {
        printf("| ");
        for(int j=0; j<9; j++) {
            if(grid[i][j] == 0) {
                printf("  ");
            } else {
                printf("%d ", grid[i][j]);
            }
            if(j == 2 || j == 5) {
                printf("| ");
            }
        }
        printf("|\n");
        if(i == 2 || i == 5) {
            printf(" -----------------------\n");
        }
    }
    printf(" -----------------------\n");
}