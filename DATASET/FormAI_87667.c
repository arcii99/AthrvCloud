//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#define ROW 10
#define COL 10
#define WALL 1
#define PATH 0
#define START_X 3
#define START_Y 3
#define END_X 8
#define END_Y 8

typedef struct node {
    int row, col;
    struct node* parent;
    int f, g, h;
} node;

int maze[ROW][COL] = { {0, 0, 1, 0, 0, 0, 1, 0, 0, 0},
                       {0, 0, 1, 0, 0, 0, 1, 0, 0, 0},
                       {0, 0, 0, 0, 1, 1, 0, 1, 0, 0},
                       {0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
                       {0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
                       {0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
                       {0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
                       {0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
                       {0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
                       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0} };

int is_valid(int row, int col) {
    if (row < 0 || row >= ROW || col < 0 || col >= COL)
        return 0;
    return 1;
}

int is_wall(int row, int col) {
    if (maze[row][col] == WALL)
        return 1;
    return 0;
}

int is_open(int row, int col) {
    if (maze[row][col] == PATH)
        return 1;
    return 0;
}

int calc_h(int row, int col) {
    return abs(row - END_X) + abs(col - END_Y);
}

node* create_node(int row, int col, node* parent, int g) {
    node* temp = malloc(sizeof(node));
    temp->row = row;
    temp->col = col;
    temp->parent = parent;
    temp->g = g;
    temp->h = calc_h(row, col);
    temp->f = temp->g + temp->h;
    return temp;
}

void print_path(node* current) {
    if (current->parent == NULL) {
        printf("(%d,%d)", current->row, current->col);
        return;
    }
    print_path(current->parent);
    printf(" -> (%d,%d)", current->row, current->col);
}

void a_star() {
    node* open_list[ROW*COL];
    int open_index = 0;
    int closed_list[ROW][COL] = { 0 };
    int i, j;
    for (i = 0; i < ROW; i++)
        for (j = 0; j < COL; j++)
            if (maze[i][j] == PATH)
                closed_list[i][j] = -1;
    node* start = create_node(START_X, START_Y, NULL, 0);
    open_list[open_index++] = start;
    while (open_index > 0) {
        int current_index = 0;
        for (i = 0; i < open_index; i++)
            if (open_list[i]->f < open_list[current_index]->f)
                current_index = i;
        node* current = open_list[current_index];
        if (current->row == END_X && current->col == END_Y) {
            print_path(current);
            return;
        }
        open_list[current_index] = open_list[--open_index];
        closed_list[current->row][current->col] = 1;
        int row, col;
        for (i = -1; i <= 1; i++)
            for (j = -1; j <= 1; j++) {
                row = current->row + i;
                col = current->col + j;
                if (!is_valid(row, col))
                    continue;
                if (is_wall(row, col))
                    continue;
                if (closed_list[row][col])
                    continue;
                int g = current->g + ((i && j) ? 14 : 10);
                node* temp = NULL;
                for (int k = 0; k < open_index; k++)
                    if (open_list[k]->row == row && open_list[k]->col == col)
                        temp = open_list[k];
                if (temp == NULL || g < temp->g) {
                    if (temp == NULL)
                        temp = create_node(row, col, current, g);
                    else {
                        temp->parent = current;
                        temp->g = g;
                        temp->f = temp->g + temp->h;
                    }
                    if (!temp) {
                        printf("Memory Allocation Error!\n");
                        return;
                    }
                    if (temp->h <= closed_list[row][col]) {
                        open_list[open_index++] = temp;
                        closed_list[row][col] = temp->h;
                    }
                }
            }
    }
    printf("No Path Found!\n");
}

int main() {
    a_star();
    return 0;
}