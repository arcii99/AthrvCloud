//FormAI DATASET v1.0 Category: Memory Game ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    char colors[6][10] = {"red", "blue", "green", "yellow", "orange", "purple"};
    int grid[4][4];
    int selected[16] = {0};
    int count = 0, attempts = 0, playerScore = 0;

    srand(time(NULL));
    // Initializing the grid with random colors
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            int colorIndex = rand() % 6;
            while(selected[colorIndex] >= 2)
                colorIndex = rand() % 6;
            selected[colorIndex]++;
            grid[i][j] = colorIndex;
        }
    }

    printf("WELCOME TO THE FUNNY MEMORY GAME!\n\n");
    printf("You will be presented with a 4x4 grid of colors.\nYou need to match the colors in pairs by selecting their row and column numbers.\nYou need to match all the pairs in the shortest amount of attempts to win the game.\n\nLet's begin!\n\n");

    // Displaying the grid initially with all colors hidden
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            printf("|****|");
        }
        printf("\n");
    }

    while(playerScore < 8) {
        int rowOne, colOne, rowTwo, colTwo;
        printf("Enter the row number (0-3) and column number (0-3) of the first color: ");
        scanf("%d %d", &rowOne, &colOne);
        while(rowOne < 0 || rowOne > 3 || colOne < 0 || colOne > 3) {
            printf("Invalid input! Please enter again: ");
            scanf("%d %d", &rowOne, &colOne);
        }

        printf("Enter the row number (0-3) and column number (0-3) of the second color: ");
        scanf("%d %d", &rowTwo, &colTwo);
        while(rowTwo < 0 || rowTwo > 3 || colTwo < 0 || colTwo > 3) {
            printf("Invalid input! Please enter again: ");
            scanf("%d %d", &rowTwo, &colTwo);
        }

        printf("\n");

        if(grid[rowOne][colOne] == grid[rowTwo][colTwo]) {
            if(rowOne == rowTwo && colOne == colTwo) {
                printf("You chose the same cell twice. That is not how it works! ;)\n\n");
            }
            else {
                playerScore++;
                count++;
                printf("You have matched a pair! Woohoo! Your score: %d\n\n", playerScore);
                grid[rowOne][colOne] = -1;
                grid[rowTwo][colTwo] = -1;
            }
        }
        else {
            count++;
            printf("Sorry, those colors do not match. Try again!\n\n");
        }
        
        // Displaying the grid after each player move
        for(int i = 0; i < 4; i++) {
            for(int j = 0; j < 4; j++) {
                if(grid[i][j] == -1)
                    printf("| %s |", colors[grid[i][j]]);
                else
                    printf("|****|");
            }
            printf("\n");
        }
    }

    printf("Congratulations! You have matched all the pairs in %d attempts!\n", count);
    printf("You are a memory genius. You should go work for NASA, but they might not be as fun as this game!\n\n");

    return 0;    
}