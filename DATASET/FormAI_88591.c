//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: romantic
#include <stdio.h>
#include <stdlib.h>

#define ROW 5
#define COL 5

struct Node {
    int row;
    int col;
    int f_score;
    int g_score;
    int h_score;
    struct Node* parent;
};

struct Node* open_set[ROW * COL];
struct Node* closed_set[ROW * COL];
int open_count = 0;
int closed_count = 0;

int map[ROW][COL] = {
    {0,0,1,0,0},
    {0,1,0,1,0},
    {0,0,0,1,0},
    {1,1,0,1,0},
    {0,0,0,0,0}
};

void initialize() {
    int i, j;
    for(i=0; i<ROW; i++) {
        for(j=0; j<COL; j++) {
            open_set[i*COL+j] = NULL;
            closed_set[i*COL+j] = NULL;
        }
    }
    open_count = 0;
    closed_count = 0;
}

int is_valid(int row, int col) {
    if(row >= 0 && row < ROW && col >= 0 && col < COL && map[row][col] == 0) {
        return 1;
    }
    return 0;
}

int is_present_in_set(struct Node** set, int set_count, struct Node* node) {
    int i;
    for(i=0; i<set_count; i++) {
        if(set[i]->row == node->row && set[i]->col == node->col) {
            return 1;
        }
    }
    return 0;
}

void retrace_path(struct Node* node) {
    printf("Path found:\n");
    while(node != NULL) {
        printf("(%d,%d)\n", node->row, node->col);
        node = node->parent;
    }
}

void a_star(int start_row, int start_col, int end_row, int end_col) {
    initialize();
    struct Node* start = (struct Node*) malloc(sizeof(struct Node));
    start->row = start_row;
    start->col = start_col;
    start->g_score = 0;
    start->h_score = abs(end_row - start_row) + abs(end_col - start_col);
    start->f_score = start->g_score + start->h_score;
    start->parent = NULL;
    open_set[open_count++] = start;
    while(open_count > 0) {
        int min_f_score_index = 0, i;
        for(i=0; i<open_count; i++) {
            if(open_set[i]->f_score < open_set[min_f_score_index]->f_score) {
                min_f_score_index = i;
            }
        }
        struct Node* current = open_set[min_f_score_index];
        if(current->row == end_row && current->col == end_col) {
            retrace_path(current);
            return;
        }
        open_set[min_f_score_index] = NULL;
        open_count--;
        closed_set[closed_count++] = current;
        int row, col;
        // Check top neighbor
        row = current->row - 1;
        col = current->col;
        if(is_valid(row, col)) {
            struct Node* neighbor = (struct Node*) malloc(sizeof(struct Node));
            neighbor->row = row;
            neighbor->col = col;
            neighbor->g_score = current->g_score + 1;
            neighbor->h_score = abs(end_row - row) + abs(end_col - col);
            neighbor->f_score = neighbor->g_score + neighbor->h_score;
            neighbor->parent = current;
            if(!is_present_in_set(open_set, open_count, neighbor) &&
               !is_present_in_set(closed_set, closed_count, neighbor)) {
                open_set[open_count++] = neighbor;
            }
        }
        // Check bottom neighbor
        row = current->row + 1;
        col = current->col;
        if(is_valid(row, col)) {
            struct Node* neighbor = (struct Node*) malloc(sizeof(struct Node));
            neighbor->row = row;
            neighbor->col = col;
            neighbor->g_score = current->g_score + 1;
            neighbor->h_score = abs(end_row - row) + abs(end_col - col);
            neighbor->f_score = neighbor->g_score + neighbor->h_score;
            neighbor->parent = current;
            if(!is_present_in_set(open_set, open_count, neighbor) &&
               !is_present_in_set(closed_set, closed_count, neighbor)) {
                open_set[open_count++] = neighbor;
            }
        }
        // Check left neighbor
        row = current->row;
        col = current->col - 1;
        if(is_valid(row, col)) {
            struct Node* neighbor = (struct Node*) malloc(sizeof(struct Node));
            neighbor->row = row;
            neighbor->col = col;
            neighbor->g_score = current->g_score + 1;
            neighbor->h_score = abs(end_row - row) + abs(end_col - col);
            neighbor->f_score = neighbor->g_score + neighbor->h_score;
            neighbor->parent = current;
            if(!is_present_in_set(open_set, open_count, neighbor) &&
               !is_present_in_set(closed_set, closed_count, neighbor)) {
                open_set[open_count++] = neighbor;
            }
        }
        // Check right neighbor
        row = current->row;
        col = current->col + 1;
        if(is_valid(row, col)) {
            struct Node* neighbor = (struct Node*) malloc(sizeof(struct Node));
            neighbor->row = row;
            neighbor->col = col;
            neighbor->g_score = current->g_score + 1;
            neighbor->h_score = abs(end_row - row) + abs(end_col - col);
            neighbor->f_score = neighbor->g_score + neighbor->h_score;
            neighbor->parent = current;
            if(!is_present_in_set(open_set, open_count, neighbor) &&
               !is_present_in_set(closed_set, closed_count, neighbor)) {
                open_set[open_count++] = neighbor;
            }
        }
    }
}

int main() {
    a_star(0, 0, 4, 4);
    return 0;
}