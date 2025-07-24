//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: protected
#include <stdio.h>
#include <stdbool.h>

#define MAX_ROWS 10
#define MAX_COLS 10

// Maze Grid Representation
char maze[MAX_ROWS][MAX_COLS] = {
    {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
    {'#', 'S', ' ', ' ', ' ', '#', ' ', '#', ' ', '#'},
    {'#', '#', ' ', '#', ' ', '#', ' ', '#', ' ', '#'},
    {'#', ' ', ' ', '#', ' ', ' ', ' ', '#', ' ', '#'},
    {'#', ' ', '#', '#', '#', '#', '#', '#', ' ', '#'},
    {'#', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', '#'},
    {'#', '#', '#', ' ', '#', ' ', '#', '#', '#', '#'},
    {'#', ' ', ' ', ' ', '#', ' ', ' ', ' ', 'F', '#'},
    {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'}
};

// Position structure
struct position {
    int row;
    int col;
};

// Stack structure for maintaining the path
struct stack {
    struct position path[MAX_ROWS * MAX_COLS];
    int top;
};

// Function to check if the given position is valid
bool is_valid_position(struct position pos) {
    if (pos.row < 0 || pos.row >= MAX_ROWS || pos.col < 0 || pos.col >= MAX_COLS) {
        return false;
    }
    if (maze[pos.row][pos.col] == '#') {
        return false;
    }
    return true;
}

// Function to check if the given position is the final position
bool is_final_position(struct position pos) {
    if (maze[pos.row][pos.col] == 'F') {
        return true;
    }
    return false;
}

// Function to initialize the stack
void init_stack(struct stack* s) {
    s->top = -1;
}

// Function to push a position into the stack
void push(struct stack* s, struct position pos) {
    s->top++;
    s->path[s->top] = pos;
}

// Function to pop a position from the stack
struct position pop(struct stack* s) {
    struct position pos = s->path[s->top];
    s->top--;
    return pos;
}

// Function to print the path
void print_path(struct stack* s) {
    printf("The path is: ");
    for (int i = 0; i <= s->top; i++) {
        printf("(%d,%d) ", s->path[i].row, s->path[i].col);
    }
    printf("\n");
}

// Recursive function to find the path
void find_path(struct position start_pos, struct position current_pos, struct stack* s) {
    if (is_final_position(current_pos)) {
        push(s, current_pos);
        print_path(s);
        return;
    }
    struct position next_pos;
    next_pos.row = current_pos.row + 1;
    next_pos.col = current_pos.col;
    if (is_valid_position(next_pos)) {
        push(s, current_pos);
        find_path(start_pos, next_pos, s);
        pop(s);
    }
    next_pos.row = current_pos.row - 1;
    next_pos.col = current_pos.col;
    if (is_valid_position(next_pos)) {
        push(s, current_pos);
        find_path(start_pos, next_pos, s);
        pop(s);
    }
    next_pos.row = current_pos.row;
    next_pos.col = current_pos.col + 1;
    if (is_valid_position(next_pos)) {
        push(s, current_pos);
        find_path(start_pos, next_pos, s);
        pop(s);
    }
    next_pos.row = current_pos.row;
    next_pos.col = current_pos.col - 1;
    if (is_valid_position(next_pos)) {
        push(s, current_pos);
        find_path(start_pos, next_pos, s);
        pop(s);
    }
}

int main() {
    struct stack s;
    struct position start_pos = {1, 1};
    init_stack(&s);
    find_path(start_pos, start_pos, &s);
    return 0;
}