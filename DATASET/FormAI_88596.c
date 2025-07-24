//FormAI DATASET v1.0 Category: Pac-Man Game Clone ; Style: Claude Shannon
#include <stdio.h>

#define ROWS 20
#define COLS 30

void display_maze(char[][COLS]); // Function to display maze

int main() {

char maze[ROWS][COLS] = { // Maze array
    "+XXXXXXXXXXXXXXXXXXXXXXXXXXXXXX+",
    "|                              |",
    "|+XXX+ +XXX+ +XXXXX+ +XXX+ +XXX+|",
    "|+XXX+ +XXX+ +XXXXX+ +XXX+ +XXX+|",
    "|+XXX+ +XXX+ +XXXXX+ +XXX+ +XXX+|",
    "|                              |",
    "|+XXX+ +XXXXX+ +XXX+ +XXXXX+ +XXX|",
    "|+XXX+ +XXXXX+ +XXX+ +XXXXX+ +XXX|",
    "|                              |",
    "+XXX+ +XXX+ +XXXXX+ +XXX+ +XXX+ +",
    "XXXX+ +XXX+ +XXXXX+ +XXX+ +XXXX+",
    "+XXX+ +XXX+ +XXXXX+ +XXX+ +XXX+ +",
    "|                              |",
    "|+XXX+ +XXXXX+ +XXX+ +XXXXX+ +XXX|",
    "|+XXX+ +XXXXX+ +XXX+ +XXXXX+ +XXX|",
    "|+XXX+ +XXXXX+ +XXX+ +XXXXX+ +XXX|",
    "|                              |",
    "|+XXX+ +XXX+ +XXXXX+ +XXX+ +XXX+|",
    "|+XXX+ +XXX+ +XXXXX+ +XXX+ +XXX+|",
    "+XXXXXXXXXXXXXXXXXXXXXXXXXXXXXX+",
};

display_maze(maze); // Display the maze

return 0;
}

void display_maze(char maze[][COLS]) {
int r, c;
for (r = 0; r < ROWS; r++) {
    for (c = 0; c < COLS; c++) {
        printf("%c", maze[r][c]);
    }
    printf("\n");
}
}