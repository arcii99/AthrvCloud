//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

#define ROWS 10
#define COLS 20

char maze[ROWS][COLS] = {  
    "# ##########",
    "# #        ##",
    "# # ###### ##",
    "#   #     ###",
    "### # #### ##",
    "##  # #    ##",
    "## ## ### ###",
    "##    #   ###",
    "######### ###",
    "#           #"
};

struct node {
    int x, y;             // current position
    int prev_x, prev_y;   // previous position
};

struct stack {
    int top;
    struct node data[ROWS * COLS];
};

void push(struct stack *st, struct node n) {
    st->top += 1;
    st->data[st->top] = n;
}

struct node pop(struct stack *st) {
    struct node n = st->data[st->top];
    st->top -= 1;
    return n;
}

int is_empty(struct stack *st) {
    return (st->top == -1);
}

int is_valid(int x, int y) {
    if (x < 0 || x >= ROWS || y < 0 || y >= COLS) {
        return 0;
    }
    if (maze[x][y] == '#' || maze[x][y] == '.') {
        return 0;
    }
    return 1;
}

int is_destination(int x, int y, int dx, int dy) {
    return (x == dx && y == dy);
}

void print_maze() {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("%c", maze[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int i, j, dx, dy;
    dx = ROWS - 1;
    dy = COLS - 1;

    struct stack st;
    st.top = -1;

    struct node start;
    start.x = 0;
    start.y = 0;
    start.prev_x = -1;
    start.prev_y = -1;

    push(&st, start);

    while (!is_empty(&st)) {
        struct node curr = pop(&st);

        if (is_destination(curr.x, curr.y, dx, dy)) {
            printf("Found destination!\n");
            printf("Path: ");
            while (curr.prev_x != -1 && curr.prev_y != -1) {
                maze[curr.x][curr.y] = '.';
                printf("(%d,%d) ", curr.x, curr.y);
                curr = st.data[curr.prev_x * COLS + curr.prev_y];
            }
            printf("(0,0)\n");
            print_maze();
            return 0;
        }

        if (is_valid(curr.x - 1, curr.y)) {  // up
            struct node n;
            n.x = curr.x - 1;
            n.y = curr.y;
            n.prev_x = curr.x;
            n.prev_y = curr.y;
            push(&st, n);
        }

        if (is_valid(curr.x, curr.y + 1)) {  // right
            struct node n;
            n.x = curr.x;
            n.y = curr.y + 1;
            n.prev_x = curr.x;
            n.prev_y = curr.y;
            push(&st, n);
        }

        if (is_valid(curr.x + 1, curr.y)) {  // down
            struct node n;
            n.x = curr.x + 1;
            n.y = curr.y;
            n.prev_x = curr.x;
            n.prev_y = curr.y;
            push(&st, n);
        }

        if (is_valid(curr.x, curr.y - 1)) {  // left
            struct node n;
            n.x = curr.x;
            n.y = curr.y - 1;
            n.prev_x = curr.x;
            n.prev_y = curr.y;
            push(&st, n);
        }
    }

    printf("Destination not found!\n");
    return 0;
}