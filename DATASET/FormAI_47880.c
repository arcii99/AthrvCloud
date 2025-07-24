//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: happy
#include <stdio.h>
#include <stdlib.h>

#define MAX_ROW 20
#define MAX_COL 30

typedef struct {
    int row, col;
} Point;

Point stack[1000];
int top = 0;

void push(Point p) {
    stack[top++] = p;
}

Point pop() {
    return stack[--top];
}

int is_empty() {
    return !top;
}

char maze[MAX_ROW][MAX_COL+1] = {
    "##############################",
    "#    #       #       #       #",
    "# ####### ####### # #########",
    "#          #      ## #       #",
    "##### ###### #####   ########",
    "#    # #    # #          #   #",
    "# ## # # ## # ############## #",
    "#                       #    #",
    "##### ############## #####   ",
    "#       #          #    # # # ",
    "####### # ####### ###### # # #",
    "#       #   #               #",
    "######### ### ##############",
    "#       #   # # #          # #",
    "# ########## # # ########## #",
    "#    #          #        #   #",
    "##############################",
};

void visit(Point p) {
    printf("(%d,%d)\n", p.row, p.col);
    maze[p.row][p.col] = '!';
}

int main() {
    Point p = { 1, 0 };
    int found = 0;

    while (1) {
        if (p.row == MAX_ROW-2 && p.col == MAX_COL-1) {
            found = 1;
            break;
        }
        if (maze[p.row][p.col+1] == ' ') { /* Right */
            push(p);
            visit(p);
            p.col++;
        } else if (maze[p.row+1][p.col] == ' ') { /* Down */
            push(p);
            visit(p);
            p.row++;
        } else if (maze[p.row][p.col-1] == ' ') { /* Left */
            push(p);
            visit(p);
            p.col--;
        } else if (maze[p.row-1][p.col] == ' ') { /* Up */
            push(p);
            visit(p);
            p.row--;
        } else { /* backtrack */
            if (is_empty()) {
                break;
            } else {
                p = pop();
            }
        }
    }

    if (found) {
        printf("(%d,%d)\n", MAX_ROW-2, MAX_COL-1);
    } else {
        printf("No route found.\n");
    }

    return 0;
}