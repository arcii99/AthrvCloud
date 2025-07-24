//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: immersive
#include <stdio.h>
#include <stdlib.h>

#define ROW 10
#define COL 10

typedef struct {
    int row, col, fval, gval, hval;
} Node;

Node open_list[ROW*COL], closed_list[ROW*COL];
int grid[ROW][COL], dir_row[8]={-1,-1,-1,0,0,1,1,1}, dir_col[8]={-1,0,1,-1,1,-1,0,1};
int open_ptr=0, closed_ptr=0, start_row, start_col, end_row, end_col;

int is_valid(int row, int col) {
    return (row>=0 && row<ROW && col>=0 && col<COL);
}

int is_unblocked(int row, int col) {
    return (grid[row][col]!=0);
}

int heuristic(int row, int col) {
    return abs(row - end_row) + abs(col - end_col);
}

void insert_open_list(int row, int col, int f, int g, int h) {
    Node temp;
    temp.row = row; temp.col = col; temp.fval = f; temp.gval = g; temp.hval = h;
    open_list[open_ptr] = temp; open_ptr++;
}

void print_path(Node path[], int ptr) {
    printf("(row,col)\n");
    for (int i=ptr; i>=0; i--) {
        printf("(%d,%d)\n", path[i].row, path[i].col);
    }
}

void print_grid_path(Node path[], int ptr) {
    for (int i=0; i<=ptr; i++) {
        grid[path[i].row][path[i].col] = 3;
    }
    grid[start_row][start_col] = 1;
    grid[end_row][end_col] = 2;
    printf("\n");
    for (int i=0; i<ROW; i++) {
        for (int j=0; j<COL; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}

void a_star_pathfinding() {
    int curr_row, curr_col, curr_f, curr_g, curr_h, next_row, next_col, next_f, next_g, next_h;
    Node curr_node, next_node;
    curr_node.row = start_row; curr_node.col = start_col; curr_node.fval = 0; curr_node.gval = 0; curr_node.hval = 0;
    insert_open_list(curr_node.row, curr_node.col, curr_node.fval, curr_node.gval, curr_node.hval);

    while(open_ptr > 0) {
        curr_node = open_list[0];
        curr_row = curr_node.row; curr_col = curr_node.col; curr_f = curr_node.fval; curr_g = curr_node.gval; curr_h = curr_node.hval;

        if (curr_row == end_row && curr_col == end_col) {
            print_path(closed_list, closed_ptr);
            print_grid_path(closed_list, closed_ptr);
            return;
        }

        for (int i=0; i<8; i++) {
            next_row = curr_row + dir_row[i];
            next_col = curr_col + dir_col[i];
            if (is_valid(next_row, next_col) && is_unblocked(next_row, next_col)) {

                next_g = curr_g + 1;
                next_h = heuristic(next_row, next_col);
                next_f = next_g + next_h;

                next_node.row = next_row; next_node.col = next_col; next_node.fval = next_f; next_node.gval = next_g; next_node.hval = next_h;

                int flag = 1, j;
                for (j=0; j<open_ptr; j++) {
                    if (open_list[j].row == next_row && open_list[j].col == next_col) {
                        flag = 0;
                        break;
                    }
                }
                if (flag) {
                    insert_open_list(next_row, next_col, next_f, next_g, next_h);
                }
            }
        }
        open_list[0] = open_list[--open_ptr];
        curr_node.fval = open_list[0].fval; curr_node.gval = open_list[0].gval; curr_node.hval = open_list[0].hval;
        curr_node.row = open_list[0].row; curr_node.col = open_list[0].col;

        closed_list[closed_ptr] = curr_node;
        closed_ptr++;
    }
}

int main() {
    printf("A STAR PATHFINDING ALGORITHM WITH IMMERSIVE STYLE\n");

    for (int i=0; i<ROW; i++) {
        for (int j=0; j<COL; j++) {
            grid[i][j] = 1; // populate with blocked cells
        }
    }

    start_row = 1; start_col = 1; end_row = 8; end_col = 8;
    grid[start_row][start_col] = 0; // unblock start cell
    grid[end_row][end_col] = 0; // unblock end cell

    a_star_pathfinding();

    return 0;
}