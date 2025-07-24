//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROWS 5
#define COLS 10

typedef struct node_t {
    int row;
    int col;
    int f_score;
    int g_score;
    struct node_t* parent;
} node;

void print_path(node* end) {
    if(end == NULL) {
        return;
    }
    print_path(end->parent);
    printf("(%d, %d) -> ", end->row, end->col);
}

int heuristic(int current_row, int current_col, int goal_row, int goal_col) {
    return abs(current_row - goal_row) + abs(current_col - goal_col);
}

bool is_valid(int row, int col) {
    return (row >= 0 && row < ROWS && col >= 0 && col < COLS);
}

bool is_obstacle(int grid[ROWS][COLS], int row, int col) {
    return grid[row][col] == 1;
}

void A_star(int grid[ROWS][COLS], int start_row, int start_col, int goal_row, int goal_col) {
    node* open_list[ROWS*COLS];
    node* closed_list[ROWS*COLS];
    for(int i=0; i<ROWS*COLS; i++) {
        open_list[i] = NULL;
        closed_list[i] = NULL;
    }
    int counter = 0;
    node* current = (node*) malloc(sizeof(node));
    current->row = start_row;
    current->col = start_col;
    current->f_score = heuristic(start_row, start_col, goal_row, goal_col);
    current->g_score = 0;
    current->parent = NULL;
    open_list[counter++] = current;
    while(counter != 0) {
        current = open_list[0];
        int index = 0;
        for(int i=1; i<counter; i++) {
            if(open_list[i]->f_score < current->f_score || (open_list[i]->f_score == current->f_score && open_list[i]->g_score < current->g_score)) {
                current = open_list[i];
                index = i;
            }
        }
        if(current->row == goal_row && current->col == goal_col) {
            printf("Path found: ");
            print_path(current);
            printf("GOAL\n");
            return;
        }
        open_list[index] = NULL;
        for(int r=-1; r<=1; r++) {
            for(int c=-1; c<=1; c++) {
                if((r==0 && c==0) || !is_valid(current->row + r, current->col + c) || is_obstacle(grid, current->row + r, current->col + c)) {
                    continue;
                }
                node* neighbor = (node*) malloc(sizeof(node));
                neighbor->row = current->row + r;
                neighbor->col = current->col + c;
                neighbor->g_score = current->g_score + 1;
                neighbor->f_score = neighbor->g_score + heuristic(neighbor->row, neighbor->col, goal_row, goal_col);
                neighbor->parent = current;
                bool in_open_list = false;
                bool in_closed_list = false;
                for(int i=0; i<ROWS*COLS; i++) {
                    if(open_list[i] != NULL && open_list[i]->row == neighbor->row && open_list[i]->col == neighbor->col) {
                        in_open_list = true;
                        break;
                    }
                    if(closed_list[i] != NULL && closed_list[i]->row == neighbor->row && closed_list[i]->col == neighbor->col) {
                        in_closed_list = true;
                        break;
                    }
                }
                if(in_open_list || in_closed_list) {
                    free(neighbor);
                    continue;
                }
                open_list[counter++] = neighbor;
            }
        }
        closed_list[index] = current;
    }
    printf("No path found\n");
}

int main() {
    int grid[ROWS][COLS] = {
        {0,0,0,0,0,0,0,0,0,0},
        {0,1,0,0,0,0,1,0,0,0},
        {0,1,0,1,0,1,1,0,1,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,1,0,0,0,0,1,0}
    };
    A_star(grid, 0, 0, 4, 9);
    return 0;
}