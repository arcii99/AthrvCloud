//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

#define ROW 7
#define COL 10

typedef struct Node {
    int row, col, g_cost, h_cost;
    struct Node *parent;
} Node;

Node *node_alloc(int row, int col, int g_cost, int h_cost, Node *parent) {
    Node *node = malloc(sizeof(Node));
    node->row = row;
    node->col = col;
    node->g_cost = g_cost;
    node->h_cost = h_cost;
    node->parent = parent;
    return node;
}

void node_free(Node *node) {
    if (node)
        free(node);
}

int distance(int row1, int col1, int row2, int col2) {
    return abs(row1 - row2) + abs(col1 - col2);
}

int h_cost(int row, int col, int end_row, int end_col) {
    return distance(row, col, end_row, end_col);
}

Node *lowest_f_cost(Node **frontier, int size) {
    Node *lowest_node = frontier[0];
    for (int i = 1; i < size; i++)
        if (frontier[i]->g_cost + frontier[i]->h_cost < lowest_node->g_cost + lowest_node->h_cost)
            lowest_node = frontier[i];
    return lowest_node;
}

void print_path(Node *node) {
    if (node->parent)
        print_path(node->parent);
    printf("(%d,%d) ", node->row, node->col);
}

void print_grid(int grid[][COL]) {
    for (int row = 0; row < ROW; row++) {
        for (int col = 0; col < COL; col++)
            printf("%2d ", grid[row][col]);
        putchar('\n');
    }
}

void a_star(int start_row, int start_col, int end_row, int end_col, int grid[][COL]) {
    Node *frontier[ROW * COL];
    int frontier_size = 0;
    int visited[ROW][COL];
    for (int row = 0; row < ROW; row++)
        for (int col = 0; col < COL; col++)
            visited[row][col] = 0;

    Node *start_node = node_alloc(start_row, start_col, 0, h_cost(start_row, start_col, end_row, end_col), NULL);
    frontier[frontier_size++] = start_node;

    Node *current_node = NULL;

    while (frontier_size) {
        current_node = lowest_f_cost(frontier, frontier_size);
        if (current_node->row == end_row && current_node->col == end_col)
            break;

        for (int dr = -1; dr <= 1; dr++) {
            for (int dc = -1; dc <= 1; dc++) {
                if ((dr == 0 || dc == 0) && dr != dc) {
                    int next_row = current_node->row + dr;
                    int next_col = current_node->col + dc;
                    if (next_row >= 0 && next_row < ROW &&
                            next_col >= 0 && next_col < COL &&
                            grid[next_row][next_col] == 0 &&
                            !visited[next_row][next_col]) {
                        Node *next_node = node_alloc(next_row, next_col, current_node->g_cost + 1,
                                                     h_cost(next_row, next_col, end_row, end_col), current_node);
                        frontier[frontier_size++] = next_node;
                        visited[next_row][next_col] = 1;
                    }
                }
            }
        }

        for (int i = 0; i < frontier_size; i++) {
            if (frontier[i] == current_node) {
                frontier_size--;
                frontier[i] = frontier[frontier_size];
                break;
            }
        }
    }

    if (current_node->row != end_row && current_node->col != end_col)
        printf("Unable to find path from (%d,%d) to (%d,%d)\n", start_row, start_col, end_row, end_col);
    else {
        printf("Shortest path from (%d,%d) to (%d,%d): ", start_row, start_col, end_row, end_col);
        print_path(current_node);
    }

    node_free(start_node);
    for (int i = 0; i < frontier_size; i++)
        node_free(frontier[i]);
}

int main() {
    int grid[ROW][COL] = {
        {0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
    };

    printf("Grid:\n");
    print_grid(grid);
    putchar('\n');

    printf("Finding shortest path from (0,0) to (6,9):\n");
    a_star(0, 0, 6, 9, grid);

    return 0;
}