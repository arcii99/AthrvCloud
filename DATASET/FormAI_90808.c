//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROW 10
#define COL 10

int grid[ROW][COL];

typedef struct node {
    int row;
    int col;
    int dist;
    struct node* parent;
} Node;

bool is_valid(int row, int col) {
    return (row >= 0) && (row < ROW) && (col >= 0) && (col < COL);
}

bool is_unblocked(int row, int col) {
    return (grid[row][col] == 1);
}

bool is_destination(int row, int col, Node* dest) {
    return (row == dest->row) && (col == dest->col);
}

void print_path(Node* curr) {
    if (curr->parent == NULL) {
        return;
    }
    print_path(curr->parent);
    printf("(%d,%d)\n", curr->row, curr->col);
}

void a_star_search(int start_row, int start_col, int dest_row, int dest_col) {
    if (!is_valid(start_row, start_col) || !is_valid(dest_row, dest_col)) {
        printf("Invalid Input\n");
        return;
    }

    if (!is_unblocked(start_row, start_col) || !is_unblocked(dest_row, dest_col)) {
        printf("Blocked Entry or Exit\n");
        return;
    }

    if (is_destination(start_row, start_col, &(Node){dest_row, dest_col})) {
        printf("You have already arrived at the destination\n");
        return;
    }

    bool closed_list[ROW][COL] = {0};

    Node* start = (Node*)malloc(sizeof(Node));
    start->row = start_row;
    start->col = start_col;
    start->dist = 0;
    start->parent = NULL;

    Node* dest = (Node*)malloc(sizeof(Node));
    dest->row = dest_row;
    dest->col = dest_col;
    dest->parent = NULL;

    int num_of_moves = 4;
    int d_row[] = {-1, 0, 1, 0};
    int d_col[] = {0, 1, 0, -1};

    Node* open_list[ROW * COL];
    int size = 1;
    open_list[0] = start;

    while (size > 0) {
        Node* curr = open_list[0];

        if (is_destination(curr->row, curr->col, dest)) {
            printf("Path found!\n");
            print_path(curr);
            return;
        }

        open_list[0] = open_list[size - 1];
        size--;

        int curr_row = curr->row;
        int curr_col = curr->col;

        closed_list[curr_row][curr_col] = true;

        for (int i = 0; i < num_of_moves; i++) {
            int row = curr_row + d_row[i];
            int col = curr_col + d_col[i];

            if (is_valid(row, col) && is_unblocked(row, col) && !closed_list[row][col]) {
                Node* child = (Node*)malloc(sizeof(Node));

                child->row = row;
                child->col = col;
                child->dist = curr->dist + 1;
                child->parent = curr;

                open_list[size] = child;
                size++;

                for (int j = 0; j < size - 1; j++) {
                    if (open_list[j]->dist + h(open_list[j], dest) > child->dist + h(child, dest)) {
                        for (int k = size - 1; k > j; k--) {
                            open_list[k] = open_list[k - 1];
                        }
                        open_list[j] = child;
                        break;
                    }
                }
            }
        }
    }

    printf("Path not found\n");
}

int h(Node* curr, Node* dest) {
    return abs(curr->row - dest->row) + abs(curr->col - dest->col);
}

int main() {
    // initialize the grid
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            grid[i][j] = 1;
        }
    }

    // add some obstacles
    grid[3][2] = 0;
    grid[3][3] = 0;
    grid[3][4] = 0;
    grid[3][5] = 0;
    grid[5][7] = 0;
    grid[5][8] = 0;
    grid[5][9] = 0;
    grid[5][0] = 0;
    grid[6][0] = 0;

    a_star_search(0, 0, 9, 9);

    return 0;
}