//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>

// surreal A* Pathfinding Algorithm program
int main()
{
    // initialize map with surreal landscape
    char map[10][10] = {
        {'#','#','#','#','#','#','#','#','#','#'},
        {'#',' ',' ','#','#','#','#','#',' ','#'},
        {'#',' ','#',' ',' ',' ',' ',' ',' ','#'},
        {'#',' ','#',' ','#',' ','#',' ',' ','#'},
        {'#',' ','#',' ','#',' ','#',' ',' ','#'},
        {'#',' ','#',' ','#',' ','#',' ',' ','#'},
        {'#',' ','#',' ','#',' ','#',' ',' ','#'},
        {'#',' ','#',' ',' ',' ',' ',' ',' ','#'},
        {'#',' ',' ','#','#','#','#','#',' ','#'},
        {'#','#','#','#','#','#','#','#','#','#'}
    };

    // define start and end points
    int start[2] = {1,1};
    int end[2] = {8,8};

    // create open and closed lists
    int openList[100][2];
    int closedList[100][2];

    // initialize lists
    int openListLength = 1;
    openList[0][0] = start[0];
    openList[0][1] = start[1];
    int closedListLength = 0;

    // initialize cost arrays
    int gScore[10][10];
    int fScore[10][10];
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            gScore[i][j] = 999;
            fScore[i][j] = 999;
        }
    }
    gScore[start[0]][start[1]] = 0;
    fScore[start[0]][start[1]] = 0;

    // search for path using A* algorithm
    while (openListLength > 0) {
        // find lowest f score on open list
        int lowestF = 999;
        int currentIndex = -1;
        for (int i = 0; i < openListLength; i++) {
            int row = openList[i][0];
            int col = openList[i][1];
            int f = fScore[row][col];
            if (f < lowestF) {
                lowestF = f;
                currentIndex = i;
            }
        }

        // set current node to node with lowest f score
        int currentNode[2] = {openList[currentIndex][0], openList[currentIndex][1]};

        // if current node is the end node, return the path
        if (currentNode[0] == end[0] && currentNode[1] == end[1]) {
            printf("Path found!\n");
            return 0;
        }

        // remove current node from open list and add to closed list
        openList[currentIndex][0] = openList[openListLength-1][0];
        openList[currentIndex][1] = openList[openListLength-1][1];
        openListLength--;
        closedList[closedListLength][0] = currentNode[0];
        closedList[closedListLength][1] = currentNode[1];
        closedListLength++;

        // get adjacent nodes
        int adjacentNodes[4][2] = {
            {currentNode[0]-1, currentNode[1]}, // up
            {currentNode[0]+1, currentNode[1]}, // down
            {currentNode[0], currentNode[1]-1}, // left
            {currentNode[0], currentNode[1]+1}  // right
        };

        // iterate through each adjacent node
        for (int i = 0; i < 4; i++) {
            int row = adjacentNodes[i][0];
            int col = adjacentNodes[i][1];

            // check if adjacent node is valid and not on closed list
            if (row >= 0 && row < 10 && col >= 0 && col < 10 && map[row][col] != '#' && !isOnList(closedList, closedListLength, row, col)) {
                int tentativeGScore = gScore[currentNode[0]][currentNode[1]] + 1;
                if (!isOnList(openList, openListLength, row, col)) {
                    // add adjacent node to open list
                    openList[openListLength][0] = row;
                    openList[openListLength][1] = col;
                    openListLength++;
                } else if (tentativeGScore >= gScore[row][col]) {
                    // skip node if better path already exists
                    continue;
                }
                // update scores and path
                gScore[row][col] = tentativeGScore;
                fScore[row][col] = gScore[row][col] + heuristic(row, col, end[0], end[1]);
            }
        }
    }

    // path not found
    printf("Path not found.\n");
    return 0;
}

// calculate heuristic score for A* algorithm
int heuristic(int x1, int y1, int x2, int y2) {
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    return dx + dy;
}

// check if node is on a list
int isOnList(int list[100][2], int listLength, int row, int col) {
    for (int i = 0; i < listLength; i++) {
        if (list[i][0] == row && list[i][1] == col) {
            return 1;
        }
    }
    return 0;
}