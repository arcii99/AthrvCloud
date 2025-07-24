//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>

/* Defining the maze */
#define ROW 8
#define COL 11

/* Printing Maze for better understanding */
char maze[ROW][COL] = {
    "+-+-+-+-+-+-+-+-+-+",
    "| |       |     | |",
    "+ +-+-+ +-+ +-+ + +",
    "| |   | |   | | | |",
    "+-+-+-+ +-+-+ + + +",
    "| | |     |     | |",
    "+ +-+-----+-----+ +",
    "|                 |",
    "+-+-+-+-+-+-+-+-+-+"
};

/* our pathfinding algorithm function*/
void pathfinding(char maze[][COL], int start_x, int start_y, int end_x, int end_y);

/* driver code */
int main(void)
{
    /* Set the start and end points */
    int start_x = 6;
    int start_y = 1;
    int end_x = 3;
    int end_y = 9;

    /* Print the maze and it's starting & ending positions */
    printf("THE MAZE\n");
    for (int i = 0; i < ROW; ++i) {
        printf("%s\n", maze[i]);
    }
    printf("\nStarting Position: (%d, %d)\n", start_x, start_y);
    printf("Ending Position: (%d, %d)\n", end_x, end_y);
    printf("\n");

    /* Find the path from start to end*/
    pathfinding(maze, start_x, start_y, end_x, end_y);

    /* Print the maze with the path in highlighted manner*/
    printf("\nMAZE WITH PATH\n");
    for (int i = 0; i < ROW; ++i) {
        for (int j = 0; j < COL; ++j) {
            if (maze[i][j] == '.') {
                printf("#");
            } else {
                printf("%c", maze[i][j]);
            }
        }
        printf("\n");
    }

    return 0;
}

/* function to find the path */
void pathfinding(char maze[][COL], int start_x, int start_y, int end_x, int end_y)
{
    int current_x = start_x;
    int current_y = start_y;
    int found_end = 0;
    int backtracking = 0;
    int i;
    char back_char;

    /* Traverse through the maze until we find the end point */
    while (!found_end) {

        /* check if we have reached the end point */
        if (current_x == end_x && current_y == end_y) {
            found_end = 1;
            break;
        }

        /* Check in all four directions */
        if (maze[current_x - 1][current_y] == ' ' && !backtracking) {
            back_char = '+';
            current_x--;
        } else if (maze[current_x + 1][current_y] == ' ' && !backtracking) {
            back_char = '-';
            current_x++;
        } else if (maze[current_x][current_y - 1] == ' ' && !backtracking) {
            back_char = '|';
            current_y--;
        } else if (maze[current_x][current_y + 1] == ' ' && !backtracking) {
            back_char = '|';
            current_y++;
        } else {
            /* backtrack if no path found */
            if (backtracking) {
                backtracking--;
            } else {
                backtracking = 3;
            }

            if (back_char == '+') {
                current_x++;
            } else if (back_char == '-') {
                current_x--;
            } else if (back_char == '|') {
                current_y++;
            } else {
                current_y--;
            }
            continue;
        }

        /* Marking '.' to show the path */
        if (maze[current_x][current_y] != 'A' && maze[current_x][current_y] != 'B') {
            maze[current_x][current_y] = '.';
        }

        /* Printing the process */
        for (i = 0; i < ROW; ++i) {
            printf("%s\n", maze[i]);
        }
        printf("\n");

        /* Delay to fill up the path properly */
        for (i = 0; i <= 50000000; ++i) {
            /* Do nothing */
        }
    }

}