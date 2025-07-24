//FormAI DATASET v1.0 Category: Pac-Man Game Clone ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>    

#define ROW_SIZE 25
#define COLUMN_SIZE 25

void drawMap(char map[ROW_SIZE][COLUMN_SIZE], int row, int column);
void spawnPacMan(char map[ROW_SIZE][COLUMN_SIZE], int row, int column, int *pacMan_row, int *pacMan_column);
void spawnGhosts(char map[ROW_SIZE][COLUMN_SIZE], int row, int column);
void movePacMan(char map[ROW_SIZE][COLUMN_SIZE], int *pacMan_row, int *pacMan_column, char direction);
int gameOver(char map[ROW_SIZE][COLUMN_SIZE], int pacMan_row, int pacMan_column, int score);

int main()
{
    char map[ROW_SIZE][COLUMN_SIZE] = {
        "++++++++++++++--------",
        "+............+---------",
        "+.+-++++++++-+.---------",
        "+.+........+.+.---------",
        "+.+.+-++++-+.+.---------",
        "+.+.+.++++.+.+.---------",
        "+.+.+.++++.+.+.---------",
        "+.+.+.++++.+.+.---------",
        "+.+.+-++++-+.+.---------",
        "+.+........+.+.---------",
        "+.+-++++++++-+.---------",
        "+............+---------",
        "++++++++++++++---------",
        "--------++++++++++------",
        "-------+++++++++++------",
        "-------+++++++++++------",
        "--------++++++++++------",
        "-------+++++++++++------",
        "-------+++++++++++------",
        "--------++++++++++------",
        "++++++++++--------+-----",
        "++++++++++---------+----",
        "++++++++++----------+---",
        "++++++++++-----------+--",
        "++++++++++------------+-"
    };
    
    int score = 0;
    int pacMan_row, pacMan_column;

    srand(time(NULL));

    drawMap(map, ROW_SIZE, COLUMN_SIZE);
    spawnPacMan(map, ROW_SIZE, COLUMN_SIZE, &pacMan_row, &pacMan_column);
    spawnGhosts(map, ROW_SIZE, COLUMN_SIZE);

    char direction;
    while (gameOver(map, pacMan_row, pacMan_column, score) == 0) {
        printf("Enter direction: ");
        scanf(" %c", &direction);

        movePacMan(map, &pacMan_row, &pacMan_column, direction);
        drawMap(map, ROW_SIZE, COLUMN_SIZE);
    }
    
    return 0;
}

void drawMap(char map[ROW_SIZE][COLUMN_SIZE], int row, int column)
{
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            printf("%c", map[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void spawnPacMan(char map[ROW_SIZE][COLUMN_SIZE], int row, int column, int *pacMan_row, int *pacMan_column)
{
    int row_pos = rand() % (row - 2) + 1;
    int col_pos = rand() % (column - 2) + 1;

    while (1) {
        if (map[row_pos][col_pos] == '.') {
            map[row_pos][col_pos] = 'O';
            *pacMan_row = row_pos;
            *pacMan_column = col_pos;
            break;
        }
        row_pos = rand() % (row - 2) + 1;
        col_pos = rand() % (column - 2) + 1;
    }   
}

void spawnGhosts(char map[ROW_SIZE][COLUMN_SIZE], int row, int column)
{
    int ghost_count = (row + column) / 10;

    for (int i = 0; i < ghost_count; i++) {
        int row_pos = rand() % (row - 2) + 1;
        int col_pos = rand() % (column - 2) + 1;

        while (1) {
            if (map[row_pos][col_pos] == '.') {
                map[row_pos][col_pos] = 'X';
                break;
            }
            row_pos = rand() % (row - 2) + 1;
            col_pos = rand() % (column - 2) + 1;
        }
    }
}

void movePacMan(char map[ROW_SIZE][COLUMN_SIZE], int *pacMan_row, int *pacMan_column, char direction)
{
    int new_row = *pacMan_row;
    int new_column = *pacMan_column;

    switch (direction) {
        case 'w': {
            new_row = *pacMan_row - 1;
            break;
        }
        case 'a': {
            new_column = *pacMan_column - 1;
            break;
        }
        case 's': {
            new_row = *pacMan_row + 1;
            break;
        }
        case 'd': {
            new_column = *pacMan_column + 1;
            break;
        }
        default: {
            printf("Invalid direction\n");
            return;
        }
    }

    if (map[new_row][new_column] == '.') {
        map[new_row][new_column] = 'O';
        map[*pacMan_row][*pacMan_column] = '.';
        *pacMan_row = new_row;
        *pacMan_column = new_column;
    } else if (map[new_row][new_column] == 'X') {
        printf("Game Over!\n");
        exit(0);
    } else {
        printf("Invalid move\n");
    }
}

int gameOver(char map[ROW_SIZE][COLUMN_SIZE], int pacMan_row, int pacMan_column, int score)
{
    int dot_count = 0;
    for (int i = 0; i < ROW_SIZE; i++) {
        for (int j = 0; j < COLUMN_SIZE; j++) {
            if (map[i][j] == '.') {
                dot_count++;
            }
        }
    }

    if (score == dot_count) {
        printf("You Win!\n");
        exit(0);
    }

    return 0;
}