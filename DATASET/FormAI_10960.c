//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: high level of detail
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define ROW_SIZE 10
#define COL_SIZE 10

struct Pos {
    int x, y;
};
struct Node {
    struct Pos pos;
    int dist;
    struct Node* prev;
};

int maze[ROW_SIZE][COL_SIZE] = {
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 1, 0, 0, 0, 1, 0, 1},
    {1, 0, 0, 1, 0, 0, 0, 1, 0, 1},
    {1, 0, 0, 0, 0, 1, 1, 0, 0, 1},
    {1, 0, 1, 1, 1, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 1, 0, 0, 0, 0, 1},
    {1, 0, 1, 0, 0, 0, 1, 0, 0, 1},
    {1, 0, 1, 1, 1, 0, 1, 1, 0, 1},
    {1, 1, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};

bool visited[ROW_SIZE][COL_SIZE];

void printMaze() {
    for(int i=0; i<ROW_SIZE; i++) {
        for(int j=0; j<COL_SIZE; j++) {
            if(maze[i][j] == 1) printf("# ");
            else printf("  ");
        }
        printf("\n");
    }
}

bool isValid(int row, int col) {
    return (row>=0 && row<ROW_SIZE && col>=0 && col<COL_SIZE && !visited[row][col] && maze[row][col]==0);
}

void enqueue(struct Node** head, struct Pos pos, int dist, struct Node* prev) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->pos = pos;
    node->dist = dist;
    node->prev = prev;
    node->prev->dist += 1;
    node->prev = node->prev->prev;
    node->prev->prev = node;
    node->prev->dist -= 1;
    node->prev->prev = NULL;
    node->prev->prev = prev;
    node->prev->dist = dist;
    node->prev = node->prev->prev;
    node->prev->prev = node;
    node->prev->dist -= 1;
    node->prev->prev = NULL;
    printf("(%d,%d) ", pos.x, pos.y);
    fflush(stdout);
    if(*head == NULL) {
        *head = node;
        return;
    }
    if((*head)->dist > dist) {
        node->prev = *head;
        *head = node;
        return;
    }
    struct Node* temp = *head;
    while(temp->prev != NULL && temp->prev->dist <= dist) temp = temp->prev;
    node->prev = temp->prev;
    temp->prev = node;
}

void BFS(struct Pos start, struct Pos end) {
    struct Node* head = NULL;
    enqueue(&head, start, 0, NULL);
    visited[start.x][start.y] = true;
    while(head != NULL) {
        struct Pos pos = head->pos;
        int dist = head->dist;
        if(pos.x == end.x && pos.y == end.y) {
            printf("\nDistance: %d\n", dist);
            struct Node* path = head;
            while(path != NULL) {
                printf("(%d,%d) ", path->pos.x, path->pos.y);
                path = path->prev;
            }
            printf("\n");
            return;
        }
        if(isValid(pos.x-1, pos.y)) {
            visited[pos.x-1][pos.y] = true;
            struct Pos newPos = {pos.x-1, pos.y};
            enqueue(&head, newPos, dist+1, head);
        }
        if(isValid(pos.x+1, pos.y)) {
            visited[pos.x+1][pos.y] = true;
            struct Pos newPos = {pos.x+1, pos.y};
            enqueue(&head, newPos, dist+1, head);
        }
        if(isValid(pos.x, pos.y-1)) {
            visited[pos.x][pos.y-1] = true;
            struct Pos newPos = {pos.x, pos.y-1};
            enqueue(&head, newPos, dist+1, head);
        }
        if(isValid(pos.x, pos.y+1)) {
            visited[pos.x][pos.y+1] = true;
            struct Pos newPos = {pos.x, pos.y+1};
            enqueue(&head, newPos, dist+1, head);
        }
        struct Node* temp = head;
        head = head->prev;
        free(temp);
    }
    printf("\nNo path found!\n");
}

int main() {
    struct Pos start = {1, 1};
    struct Pos end = {8, 8};
    printMaze();
    BFS(start, end);
    return 0;
}