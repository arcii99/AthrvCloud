//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: optimized
#include<stdio.h>
#include<stdlib.h>

#define ROW 5
#define COL 5

typedef struct {
    int row, col;
} Coord;

typedef struct {
    Coord coord;
    int visited;
} Node;

Node maze[ROW][COL];

Coord getStartNode() {
    return (Coord){0, 0};
}

Coord getEndNode() {
    return (Coord){ROW-1, COL-1};
}

void initMaze() {
    //initialize maze
    for(int i=0; i<ROW; i++) {
        for(int j=0; j<COL; j++) {
            maze[i][j].visited = 0;
            maze[i][j].coord = (Coord){i, j};
        }
    }
    //mark the blocked cells
    maze[1][2].visited = 1;
    maze[2][2].visited = 1;
    maze[3][2].visited = 1;
}

int isBlock(Coord node) {
    if(node.row < 0 || node.row >= ROW || node.col < 0 || node.col >= COL) {
        //out of bounds
        return 1;
    }
    return maze[node.row][node.col].visited;
}

int isEndNode(Coord node) {
    Coord end = getEndNode();
    return node.row == end.row && node.col == end.col;
}

int dfs(Coord node) {
    if(isEndNode(node)) {
        printf("Reached the end\n");
        return 1;
    }
    if(isBlock(node)) {
        //cannot move further
        return 0;
    }
    //mark visited
    maze[node.row][node.col].visited = 1;
    //explore neighbors
    if(dfs((Coord){node.row+1, node.col})) { //down
        printf("(%d, %d) -> ", node.row, node.col);
        return 1;
    }
    if(dfs((Coord){node.row, node.col+1})) { //right
        printf("(%d, %d) -> ", node.row, node.col);
        return 1;
    }
    if(dfs((Coord){node.row-1, node.col})) { //up
        printf("(%d, %d) -> ", node.row, node.col);
        return 1;
    }
    if(dfs((Coord){node.row, node.col-1})) { //left
        printf("(%d, %d) -> ", node.row, node.col);
        return 1;
    }
    //unmark visited
    maze[node.row][node.col].visited = 0;
    return 0;
}

int main() {
    initMaze();
    Coord start = getStartNode();
    printf("DFS maze path: ");
    dfs(start);
    printf("\n");
    return 0;
}