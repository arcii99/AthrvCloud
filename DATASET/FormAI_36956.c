//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROW 5
#define COL 10

typedef struct node {
    int x;
    int y;
    struct node* next;
} Node;

int maze[ROW][COL] = {
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 1, 0, 0, 0, 0, 1},
    {1, 0, 1, 0, 1, 1, 1, 1, 0, 1},
    {1, 0, 1, 0, 0, 0, 0, 0, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};

Node* create_node(int x, int y) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Unable to allocate memory!\n");
        exit(1);
    }
    newNode->x = x;
    newNode->y = y;
    newNode->next = NULL;
    return newNode;
}

bool is_valid(int row, int col) {
    if (row < 0 || col < 0 || row >= ROW || col >= COL) {
        return false;
    }
    return maze[row][col] == 0;
}

Node* find_path(int startRow, int startCol, int endRow, int endCol) {
    Node* head = NULL;
    Node* tail = NULL;
    bool visited[ROW][COL] = {false};
    int movesRow[] = {-1, 0, 1, 0};
    int movesCol[] = {0, 1, 0, -1};
    
    Node* start = create_node(startRow, startCol);
    visited[startRow][startCol] = true;
    head = tail = start;
    
    while (head != NULL) {
        int row = head->x;
        int col = head->y;
        if (row == endRow && col == endCol) {
            return start;
        }
        for (int i = 0; i < 4; i++) {
            int newRow = row + movesRow[i];
            int newCol = col + movesCol[i];
            if (is_valid(newRow, newCol) && !visited[newRow][newCol]) {
                Node* newNode = create_node(newRow, newCol);
                visited[newRow][newCol] = true;
                tail->next = newNode;
                tail = newNode;
            }
        }
        Node* temp = head;
        head = head->next;
        free(temp);
    }
    return NULL;
}

void print_maze() {
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            printf("%d ", maze[i][j]);
        }
        printf("\n");
    }
}

void print_path(Node* path) {
    if (path == NULL) {
        printf("No path found!\n");
        return;
    }
    while (path != NULL) {
        printf("(%d, %d) ", path->x, path->y);
        path = path->next;
    }
    printf("\n");
}

int main() {
    print_maze();
    Node* path = find_path(1, 1, 3, 8);
    print_path(path);
    return 0;
}