//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

// Define maze size and start and end position
#define ROWS 5
#define COLS 5
#define START_ROW 0
#define START_COL 0
#define END_ROW 4
#define END_COL 4

// Define maze structure with cells
typedef struct {
    int row, col;
} Cell;

// Define stack structure for keeping track of visited cells
typedef struct {
    Cell data[ROWS * COLS];
    int len;
} Stack;

// Add cell to stack
void push(Stack *stack, Cell cell) {
    stack->data[stack->len++] = cell;
}

// Remove cell from stack
Cell pop(Stack *stack) {
    return stack->data[--stack->len];
}

// Check if cell is valid
int is_valid(Cell cell) {
    return cell.row >= 0 && cell.row < ROWS && cell.col >= 0 && cell.col < COLS;
}

// Check if cell is equal to another cell
int is_equal(Cell cell1, Cell cell2) {
    return cell1.row == cell2.row && cell1.col == cell2.col;
}

// Find route through maze
void find_route(int maze[ROWS][COLS], Cell start, Cell end) {
    Stack stack = {0};

    // Add start position to stack
    push(&stack, start);

    // Mark start position as visited
    maze[start.row][start.col] = 2;

    // Keep searching until stack is empty
    while (stack.len > 0) {
        // Get current cell and check if it is the end
        Cell curr = stack.data[stack.len - 1];
        if (is_equal(curr, end)) {
            // Print route
            printf("Route found:\n");
            for (int i = 0; i < stack.len; i++) {
                printf("(%d,%d)\n", stack.data[i].row, stack.data[i].col);
            }
            return;
        }

        // Check neighbors for unvisited cells
        int found = 0;
        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                if ((i == 0 || j == 0) && !(i == 0 && j == 0)) {
                    Cell next = {curr.row + i, curr.col + j};
                    if (is_valid(next) && maze[next.row][next.col] == 0) {
                        found = 1;
                        push(&stack, next);
                        maze[next.row][next.col] = 2;
                        break;
                    }
                }
            }
            if (found) break;
        }

        // If no unvisited neighbors, remove current cell from stack
        if (!found) {
            pop(&stack);
        }
    }

    printf("No route found\n");
}

// Main function
int main() {
    // Define maze
    int maze[ROWS][COLS] = {{0, 0, 1, 0, 0},
                            {0, 1, 0, 1, 0},
                            {0, 1, 0, 0, 0},
                            {0, 1, 1, 1, 0},
                            {0, 0, 0, 0, 0}};

    // Find route through maze
    Cell start = {START_ROW, START_COL};
    Cell end = {END_ROW, END_COL};
    find_route(maze, start, end);

    return 0;
}