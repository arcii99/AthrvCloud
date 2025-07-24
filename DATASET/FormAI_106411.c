//FormAI DATASET v1.0 Category: Memory Game ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 4

void printGrid(char grid[ROWS][COLS]){
    printf("    1   2   3   4\n");
    printf("  +---+---+---+---+\n");
    for(int row=0; row<ROWS; row++){
        printf("%c |", row+65);
        for(int col=0; col<COLS; col++){
            printf(" %c |", grid[row][col]);
        }
        printf("\n");
        printf("  +---+---+---+---+\n");
    }
}

void genGrid(char grid[ROWS][COLS]){
    srand(time(NULL));
    char letters[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
    int countLetters[8] = {0, 0, 0, 0, 0, 0, 0, 0};
    int row, col, index;
    for(int letter=0; letter<8; letter++){
        for(int i=0; i<2; i++){
            do{
                row = rand() % ROWS;
                col = rand() % COLS;
            }while(grid[row][col] != ' ');
            index = rand() % (8 - letter);
            grid[row][col] = letters[index];
            countLetters[index]++;
            if(countLetters[index] == 2){
                letters[index] = letters[7-letter];
            }
        }
    }
}

int main(){
    char grid[ROWS][COLS];
    for(int row=0; row<ROWS; row++){
        for(int col=0; col<COLS; col++){
            grid[row][col] = ' ';
        }
    }

    genGrid(grid);
    printGrid(grid);
    return 0;
}