//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLUMNS 5

void fillCard(int bingo[ROWS][COLUMNS]);
void printCard(int bingo[ROWS][COLUMNS]);
void drawNumber(int *numbers, int count);
int checkBingo(int bingo[ROWS][COLUMNS]);

int main() {
    int bingo[ROWS][COLUMNS];
    int numbers[75];
    int count = 0;
    int drawn = 0;
    int call = 0;
    int winner = 0;
    int playAgain = 1;
    
    printf("Welcome to Bingo!\n");
    printf("You will be playing with a %d x %d bingo card.\n", ROWS, COLUMNS);
    
    // Initialize random seed
    srand(time(NULL));
    
    // Fill bingo card with random numbers
    fillCard(bingo);
    // Print bingo card
    printf("\nHere is your bingo card:\n");
    printCard(bingo);
    
    // Fill array with numbers 1-75
    for (int i = 1; i <= 75; i++) {
        numbers[i-1] = i;
    }
    
    while (playAgain) {
        
        count = 0;
        drawn = 0;
        winner = 0;
        
        // Shuffle numbers
        for (int i = 0; i < 75; i++) {
            int temp = numbers[i];
            int randomIndex = rand() % 75;
            numbers[i] = numbers[randomIndex];
            numbers[randomIndex] = temp;
        }
        
        printf("\nLet's begin!\n");
        
        // Loop until someone wins
        while (!winner) {
            
            // Draw number
            drawNumber(&numbers[drawn], count);
            count++;
            drawn++;
            call = numbers[drawn-1];
            printf("\n%d!\n", call);
            
            // Check if number is on card
            for (int i = 0; i < ROWS; i++) {
                for (int j = 0; j < COLUMNS; j++) {
                    if (bingo[i][j] == call) {
                        bingo[i][j] = 0;
                        printCard(bingo);
                        // Check for bingo
                        if (checkBingo(bingo)) {
                            winner = 1;
                            break;
                        }
                    }
                }
                if (winner) {
                    break;
                }
            }
            
        }
        
        printf("\nCongratulations! You have won!\n");
        
        char input;
        printf("\nWould you like to play again? (y/n): ");
        scanf(" %c", &input);
        
        if (input == 'y' || input == 'Y') {
            playAgain = 1;
        } else {
            printf("\nThanks for playing!\n");
            playAgain = 0;
        }
        
    }
    
    return 0;
}

void fillCard(int bingo[ROWS][COLUMNS]) {
    int numbers[15];
    int count = 0;
    int drawn = 0;
    
    // Initialize random seed
    srand(time(NULL));
    
    for (int i = 0; i < ROWS; i++) {
        drawn = 0;
        while (drawn < 5) {
            int number = rand() % 15 + (15 * i) + 1;
            // Check if number has already been drawn
            int found = 0;
            for (int j = 0; j < count; j++) {
                if (numbers[j] == number) {
                    found = 1;
                    break;
                }
            }
            if (!found) {
                numbers[count] = number;
                count++;
                bingo[i][drawn] = number;
                drawn++;
            }
        }
    }
    
    count = 0;
    for (int i = 0; i < ROWS; i++) {
        drawn = 0;
        while (drawn < 5) {
            if (bingo[i][drawn] == 0) {
                drawn++;
                continue;
            }
            int number = rand() % 15 + (15 * i) + 1;
            // Check if number has already been drawn
            int found = 0;
            for (int j = 0; j < count; j++) {
                if (numbers[j] == number) {
                    found = 1;
                    break;
                }
            }
            if (!found) {
                numbers[count] = number;
                count++;
                bingo[i][drawn] = number;
                drawn++;
            }
        }
    }
}

void printCard(int bingo[ROWS][COLUMNS]) {
    printf("---------------------\n");
    for (int i = 0; i < ROWS; i++) {
        printf("|");
        for (int j = 0; j < COLUMNS; j++) {
            if (bingo[i][j] == 0) {
                printf("  ");
            } else {
                printf("%2d", bingo[i][j]);
            }
            printf("|");
        }
        printf("\n---------------------\n");
    }
}

void drawNumber(int *numbers, int count) {
    printf("\nPress Enter to draw a number.\n");
    getchar();
    printf("\nDrawing number %d...\n", count+1);
}

int checkBingo(int bingo[ROWS][COLUMNS]) {
    int bingoCount = 0;
    // Check if all numbers in a row are marked
    for (int i = 0; i < ROWS; i++) {
        int count = 0;
        for (int j = 0; j < COLUMNS; j++) {
            if (bingo[i][j] == 0) {
                count++;
            }
        }
        if (count == 5) {
            bingoCount++;
        }
    }
    // Check if all numbers in a column are marked
    for (int i = 0; i < COLUMNS; i++) {
        int count = 0;
        for (int j = 0; j < ROWS; j++) {
            if (bingo[j][i] == 0) {
                count++;
            }
        }
        if (count == 5) {
            bingoCount++;
        }
    }
    // Check if all numbers in a diagonal are marked
    int count = 0;
    for (int i = 0; i < ROWS; i++) {
        if (bingo[i][i] == 0) {
            count++;
        }
    }
    if (count == 5) {
        bingoCount++;
    }
    count = 0;
    for (int i = 0; i < ROWS; i++) {
        if (bingo[i][COLUMNS-i-1] == 0) {
            count++;
        }
    }
    if (count == 5) {
        bingoCount++;
    }
    return bingoCount;
}