//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define ROW 10
#define COL 10

typedef struct Node {
    int x, y;
    int f, g, h;
    struct Node* parent;
}node;

int grid[ROW][COL] = {
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
};

void aStar(node start, node end) {
    node* openList[ROW*COL], *closedList[ROW*COL];
    int oCounter = 0, cCounter = 0;
    node* current = NULL;
    node* successors[4];
    int sCounter = 0;
    int ftemp, gtemp, htemp;
    int flag = 0;
    int i = 0, j = 0, k = 0;

    //Add starting node to open list
    openList[oCounter++] = &start;

    //Loop until target node is found
    while(oCounter > 0) {
        //Find node with lowest f in open list
        current = openList[0];
        k = 0;
        for(i = 0; i < oCounter; i++) {
            if(openList[i]->f < current->f) {
                current = openList[i];
                k = i;
            }
        }

        //Check if target node is found
        if(current->x == end.x && current->y == end.y) {
            flag = 1;
            break;
        }

        //Remove current node from open list and add to closed list
        openList[k] = openList[--oCounter];
        closedList[cCounter++] = current;

        //Find all successors of the current node
        sCounter = 0;
        for(i = -1; i <= 1; i++) {
            for(j = -1; j <= 1; j++) {
                if(i == 0 && j == 0) continue;
                if(current->x + i < 0 || current->x + i >= ROW || current->y + j < 0 || current->y + j >= COL) continue;
                if(grid[current->x + i][current->y + j] == 1) continue;

                successors[sCounter] = (node*)malloc(sizeof(node));
                successors[sCounter]->x = current->x + i;
                successors[sCounter]->y = current->y + j;
                successors[sCounter]->parent = current;
                sCounter++;
            }
        }

        //Loop through successors
        for(i = 0; i < sCounter; i++) {
            //Check if successor is already in the closed list
            flag = 0;
            for(j = 0; j < cCounter; j++) {
                if(successors[i]->x == closedList[j]->x && successors[i]->y == closedList[j]->y) {
                    flag = 1;
                    break;
                }
            }
            if(flag == 1) continue;

            //Calculate f, g, and h values for successor
            gtemp = current->g + 1;
            htemp = sqrt(pow(successors[i]->x - end.x, 2) + pow(successors[i]->y - end.y, 2));
            ftemp = gtemp + htemp;

            //Check if successor is already in open list
            flag = 0;
            for(j = 0; j < oCounter; j++) {
                if(successors[i]->x == openList[j]->x && successors[i]->y == openList[j]->y) {
                    flag = 1;
                    break;
                }
            }

            //Add successor to open list if it is not already present or if it has a lower f value
            if(flag == 0 || ftemp < openList[j]->f) {
                openList[oCounter] = successors[i];
                openList[oCounter]->f = ftemp;
                openList[oCounter]->g = gtemp;
                openList[oCounter]->h = htemp;
                openList[oCounter]->parent = current;
                oCounter++;
            }
        }
    }

    //Check if path is found
    if(flag == 0) {
        printf("Path not found!\n");
        return;
    }

    //Print path
    node* temp = current;
    while(temp != NULL) {
        printf("(%d, %d)\n", temp->x, temp->y);
        temp = temp->parent;
    }
}

int main() {
    node start = {0, 0, 0, 0, 0, NULL};
    node end = {9, 9, 0, 0, 0, NULL};

    aStar(start, end);

    return 0;
}