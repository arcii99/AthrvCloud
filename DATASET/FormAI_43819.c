//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 10

int main(){
    int i, j, player_column, player_row, count = 0, game_over = 0;
    char maze[ROWS][COLS];
    srand(time(NULL));
    player_row = rand() % ROWS;
    player_column = rand() % COLS;

    for (i = 0; i < ROWS; i++){
        for (j = 0; j < COLS; j++){
            if (i == 0 || i == ROWS - 1){
                maze[i][j] = '|';
            } else if (j == 0 || j == COLS - 1){
                maze[i][j] = '-';
            } else {
                maze[i][j] = ' ';
            }
            maze[player_row][player_column] = 'P';
            printf("%c", maze[i][j]);
        }
        printf("\n");
    }

    printf("Welcome to the haunted house! You are the player, P, and you must find the exit, E.\n");
    printf("Use 'WASD' to move up, left, down, or right. Good Luck!!!\n\n");

    while (!game_over){
        char input;
        printf("Enter your move: ");
        scanf(" %c", &input);

        if (input == 'w'){
            if (maze[player_row - 1][player_column] != '|'){
                maze[player_row][player_column] = ' ';
                player_row--;
                maze[player_row][player_column] = 'P';
            }
        } else if (input == 'a'){
            if (maze[player_row][player_column - 1] != '-'){
                maze[player_row][player_column] = ' ';
                player_column--;
                maze[player_row][player_column] = 'P';
            }
        } else if (input == 's'){
            if (maze[player_row + 1][player_column] != '|'){
                maze[player_row][player_column] = ' ';
                player_row++;
                maze[player_row][player_column] = 'P';
            }
        } else if (input == 'd'){
            if (maze[player_row][player_column + 1] != '-'){
                maze[player_row][player_column] = ' ';
                player_column++;
                maze[player_row][player_column] = 'P';
            }
        }

        system("clear");

        for (i = 0; i < ROWS; i++){
            for (j = 0; j < COLS; j++){
                printf("%c", maze[i][j]);
            }
            printf("\n");
        }

        if (maze[player_row][player_column] == '|'){
            printf("You hit a wall! Try again.\n");
        } else if (maze[player_row][player_column] == '-'){
            printf("You hit a wall! Try again.\n");
        } else if (maze[player_row][player_column] == 'E'){
            printf("Congratulations! You found the exit in %d moves.\n", count);
            game_over = 1;
        } else {
        count++;
        }
    }
    return 0;
}