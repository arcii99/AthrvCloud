//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

#define ROWS 10
#define COLS 10

int maze[ROWS][COLS] = {
    {1,1,1,1,1,1,1,1,1,1},
    {1,0,1,0,0,0,0,0,0,1},
    {1,0,1,0,1,1,1,1,0,1},
    {1,0,1,0,1,0,0,0,0,1},
    {1,0,1,0,1,0,1,1,1,1},
    {1,0,1,0,1,0,0,0,0,1},
    {1,0,1,0,1,0,1,1,0,1},
    {1,0,0,0,1,0,0,0,0,1},
    {1,1,1,1,1,1,1,1,1,1},
};

typedef struct {
    int i;
    int j;
} Position;

typedef struct {
    int top;
    Position positions[ROWS * COLS];
} Stack;

void stack_push(Stack *stack, Position position) {
    stack->positions[stack->top++] = position;
}

Position stack_pop(Stack *stack) {
    return stack->positions[--stack->top];
}

int stack_is_empty(Stack *stack) {
    return stack->top == 0;
}

int is_valid_move(Position position) {
    return position.i >= 0 && position.i < ROWS && position.j >= 0 && position.j < COLS && maze[position.i][position.j] == 0;
}

Position get_next_position(Position position, int direction) {
    switch (direction) {
        case 0: // up
            return (Position){position.i - 1, position.j};
        case 1: // right
            return (Position){position.i, position.j + 1};
        case 2: // down
            return (Position){position.i + 1, position.j};
        case 3: // left
            return (Position){position.i, position.j - 1};
        default:
            return position;
    }
}

void print_stack(Stack *stack) {
    printf("[");
    for (int i = 0; i < stack->top; i++) {
        printf("(%d,%d)", stack->positions[i].i, stack->positions[i].j);
        if (i != stack->top - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}

void print_maze(Position current_position) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (i == current_position.i && j == current_position.j) {
                printf("X ");
            } else {
                printf("%d ", maze[i][j]);
            }
        }
        printf("\n");
    }
}

int main() {
    Position start = {1, 1};
    Position end = {8, 8};

    Stack stack = {0};
    stack_push(&stack, start);

    int found_end = 0;

    while (!stack_is_empty(&stack) && !found_end) {
        Position current_position = stack_pop(&stack);
        for (int direction = 0; direction < 4; direction++) {
            Position next_position = get_next_position(current_position, direction);
            if (is_valid_move(next_position)) {
                if (next_position.i == end.i && next_position.j == end.j) {
                    found_end = 1;
                    stack_push(&stack, next_position);
                    break;
                } else {
                    stack_push(&stack, next_position);
                    maze[next_position.i][next_position.j] = 1;
                }
            }
        }
    }

    if (found_end) {
        printf("Route found:\n");
        print_maze(end);
        print_stack(&stack);
    } else {
        printf("Route not found.\n");
    }

    return 0;
}