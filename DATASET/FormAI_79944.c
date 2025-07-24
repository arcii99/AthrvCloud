//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROW 5
#define COL 5

struct node {
    int row;
    int col;
    struct node *next;
};

typedef struct node Node;

Node *create_new_node(int row, int col) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->row = row;
    new_node->col = col;
    new_node->next = NULL;
    return new_node;
}

void print_path(Node *head) {
    while (head) {
        printf("(%d,%d) ", head->row, head->col);
        head = head->next;
    }
    printf("\n");
}

bool is_valid(int row, int col, bool visited[][COL]) {
    return (row >= 0 && row < ROW && col >= 0 && col < COL && !visited[row][col]);
}

void find_shortest_path(int maze[][COL], int row, int col, bool visited[][COL], Node *path, Node **shortest_path) {
    if (row == ROW - 1 && col == COL - 1) {
        if (!(*shortest_path) || path->row * ROW + path->col < (*shortest_path)->row * ROW + (*shortest_path)->col) {
            free(*shortest_path);
            *shortest_path = NULL;
            Node *current = path;
            Node *prev = NULL;
            while (current) {
                Node *new_node = create_new_node(current->row, current->col);
                new_node->next = prev;
                prev = new_node;
                current = current->next;
            }
            *shortest_path = prev;
        }
        return;
    }
    int neighbors[4][2] = {{-1,0}, {1,0}, {0,-1}, {0,1}};
    for (int i = 0; i < 4; i++) {
        int neighbor_row = row + neighbors[i][0];
        int neighbor_col = col + neighbors[i][1];
        if (is_valid(neighbor_row, neighbor_col, visited) && maze[neighbor_row][neighbor_col] == 1) {
            visited[neighbor_row][neighbor_col] = true;
            Node *new_node = create_new_node(neighbor_row, neighbor_col);
            path->next = new_node;
            find_shortest_path(maze, neighbor_row, neighbor_col, visited, new_node, shortest_path);
            path->next = NULL;
            visited[neighbor_row][neighbor_col] = false;
        }
    }
}

int main() {
    int maze[ROW][COL] = {{1, 0, 1, 1, 1},
                            {1, 0, 1, 0, 1},
                            {1, 1, 1, 0, 1},
                            {0, 0, 0, 0, 1},
                            {1, 1, 1, 0, 1}};
    bool visited[ROW][COL];
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            visited[i][j] = false;
        }
    }
    visited[0][0] = true;
    Node *start = create_new_node(0, 0);
    Node *shortest_path = NULL;
    find_shortest_path(maze, 0, 0, visited, start, &shortest_path);
    if (shortest_path) {
        printf("Shortest Path: ");
        print_path(shortest_path);
    } else {
        printf("No Path Found.\n");
    }
    return 0;
}