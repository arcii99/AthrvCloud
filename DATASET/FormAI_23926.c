//FormAI DATASET v1.0 Category: Pac-Man Game Clone ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 22
#define COL 19

char map[ROW][COL] = {
    "+------------------+", 
    "|     ******       |",
    "|  **      **  *** |",
    "|  **    ****      |",
    "|          **  *   |",
    "|   ****   **      |",
    "|      **  ********|",
    "|                  |",
    "|   ****           |",
    "|                  |",
    "|  *****           |",
    "|                  |",
    "|                  |",
    "| ****             |",
    "|                  |",
    "| ***    ******    |",
    "|   *********      |",
    "|                  |",
    "|        **        |",
    "|        ||        |", 
    "+------------------+"};

int start_row = 1;
int start_col = 1;
int points = 0;

void display_map(){
    printf("%c[2J", 27); // clear terminal screen
    printf("%c[%d;%dH", 27, 0, 0); // move cursor to top left corner
    for(int i=0; i<ROW; i++){
        for(int j=0; j<COL; j++){
            printf("%c", map[i][j]);
        }
        printf("\n");
    }
    printf("\nPoints: %d\n", points);
}

int main(){
    srand(time(0)); // seed random number generator
    map[start_row][start_col] = 'C'; // place pacman on starting position
    display_map();
    
    // game loop
    while(1){
        char input = getchar();
        if(input == 'w'){
            if(map[start_row-1][start_col] != '*' && start_row-1 >= 0){
                map[start_row][start_col] = ' ';
                start_row--;
                if(map[start_row][start_col] == '.'){
                    points++;
                }
                map[start_row][start_col] = 'C';
            }
        }
        if(input == 'a'){
            if(map[start_row][start_col-1] != '*' && start_col-1 >= 0){
                map[start_row][start_col] = ' ';
                start_col--;
                if(map[start_row][start_col] == '.'){
                    points++;
                }
                map[start_row][start_col] = 'C';
            }
        }
        if(input == 's'){
            if(map[start_row+1][start_col] != '*' && start_row+1 < ROW){
                map[start_row][start_col] = ' ';
                start_row++;
                if(map[start_row][start_col] == '.'){
                    points++;
                }
                map[start_row][start_col] = 'C';
            }
        }
        if(input == 'd'){
            if(map[start_row][start_col+1] != '*' && start_col+1 < COL){
                map[start_row][start_col] = ' ';
                start_col++;
                if(map[start_row][start_col] == '.'){
                    points++;
                }
                map[start_row][start_col] = 'C';
            }
        }
        if(points == 2){
            printf("\nCongratulations! You won!");
            break;
        }
        display_map();
    }
    return 0;
}