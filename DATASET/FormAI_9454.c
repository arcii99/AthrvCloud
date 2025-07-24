//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 15
#define COLS 15

typedef struct {
    int x;
    int y;
} Coordinate;

typedef enum {
    PATH,
    WALL,
    START,
    END
} CellType;

void add_wall(CellType cells[ROWS][COLS], Coordinate start, Coordinate end) {
    int min_x = start.x < end.x ? start.x : end.x;
    int max_x = start.x > end.x ? start.x : end.x;
    int min_y = start.y < end.y ? start.y : end.y;
    int max_y = start.y > end.y ? start.y : end.y;

    for (int i = min_x; i <= max_x; i++) {
        for (int j = min_y; j <= max_y; j++) {
            cells[i][j] = WALL;
        }
    }
}

CellType get_adjacent_cell_type(CellType cells[ROWS][COLS], Coordinate current, Coordinate next) {
    if (next.x < 0 || next.x >= ROWS || next.y < 0 || next.y >= COLS) {
        return WALL;
    }

    if (cells[next.x][next.y] == WALL) {
        return WALL;
    }

    if (next.x == current.x + 1 && next.y == current.y) {
        return PATH;
    }

    if (next.x == current.x - 1 && next.y == current.y) {
        return PATH;
    }

    if (next.y == current.y + 1 && next.x == current.x) {
        return PATH;
    }

    if (next.y == current.y - 1 && next.x == current.x) {
        return PATH;
    }

    return WALL;
}

void generate_maze(CellType cells[ROWS][COLS], Coordinate start, Coordinate end) {
    srand(time(NULL));

    // Initialize cells to walls
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            cells[i][j] = WALL;
        }
    }

    // Create entrance and exit
    cells[start.x][start.y] = START;
    cells[end.x][end.y] = END;

    // Generate maze
    Coordinate current = start;
    Coordinate next;
    int stack_size = 0;
    Coordinate stack[ROWS * COLS];

    do {
        if (stack_size == 0) {
            // Starting cell
            next.x = current.x + 1;
            next.y = current.y;
        } else {
            // Randomly select a direction
            int directions[4] = { 0, 1, 2, 3 };
            for (int i = 0; i < 4; i++) {
                int direction = rand() % 4;
                int temp = directions[direction];
                directions[direction] = directions[i];
                directions[i] = temp;
            }

            int direction_chosen = 0;
            for (int i = 0; i < 4; i++) {
                if (directions[i] == 0 && current.x > 0) {
                    next.x = current.x - 1;
                    next.y = current.y;
                    direction_chosen = 1;
                    break;
                } else if (directions[i] == 1 && current.x < ROWS - 1) {
                    next.x = current.x + 1;
                    next.y = current.y;
                    direction_chosen = 1;
                    break;
                } else if (directions[i] == 2 && current.y > 0) {
                    next.x = current.x;
                    next.y = current.y - 1;
                    direction_chosen = 1;
                    break;
                } else if (directions[i] == 3 && current.y < COLS - 1) {
                    next.x = current.x;
                    next.y = current.y + 1;
                    direction_chosen = 1;
                    break;
                }
            }

            if (!direction_chosen) {
                // If we can't go any further, backtrack
                stack_size--;
                current = stack[stack_size];
                continue;
            }
        }

        // Mark next cell as part of the path
        cells[next.x][next.y] = PATH;

        // Add the wall between the current and next cell to the maze
        add_wall(cells, current, next);

        // Move to the next cell
        stack[stack_size] = current;
        stack_size++;
        current = next;
    } while (stack_size > 0);
}

void print_maze(CellType cells[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            switch (cells[i][j]) {
                case PATH:
                    printf(" ");
                    break;
                case WALL:
                    printf("#");
                    break;
                case START:
                    printf("S");
                    break;
                case END:
                    printf("E");
                    break;
            }
        }
        printf("\n");
    }
}

int main() {
    // Create maze
    CellType cells[ROWS][COLS];
    Coordinate start = { 0, 0 };
    Coordinate end = { ROWS - 1, COLS - 1 };
    generate_maze(cells, start, end);

    // Print maze
    print_maze(cells);

    return 0;
}