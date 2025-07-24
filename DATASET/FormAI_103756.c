//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: ultraprecise
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define ROW 10
#define COL 10

typedef struct node{
    int x, y;   //coordinates of the node
    int g_cost; //cost to move from start to currentNode
    int h_cost; //estimated cost to move from currentNode to goal node
    int f_cost; //total cost (g_cost + h_cost)
    struct node* parent;    //pointer to parent node
}node;

node* openList[ROW * COL];  //list of nodes to be evaluated
node* closedList[ROW * COL];    //list of nodes which have already been evaluated
int openCount = 0, closedCount = 0;     //count of nodes in openList and closedList

//function to find the Manhattan distance between two nodes
int manhattanDistance(node* current, node* goal){
    int dx = abs(current->x - goal->x);
    int dy = abs(current->y - goal->y);
    return dx + dy;
}

//function to check if the given coordinates are within the boundaries of the grid
int isValid(int x, int y){
    if(x < 0 || x >= ROW || y < 0 || y >= COL){
        return 0;
    }
    return 1;
}

//function to check if the given node is in the closedList
int isClosed(node* n){
    int i;
    for(i = 0; i < closedCount; i++){
        if(n == closedList[i]){
            return 1;
        }
    }
    return 0;
}

//function to check if the given node is in the openList
int isOpen(node* n){
    int i;
    for(i = 0; i < openCount; i++){
        if(n == openList[i]){
            return 1;
        }
    }
    return 0;
}

//function to update the cost of the given node
void updateCost(node* current, node* neighbor){
    int gCost = current->g_cost + 1;    //cost of moving from current node to neighbor node is 1
    if(gCost < neighbor->g_cost){
        neighbor->g_cost = gCost;
        neighbor->f_cost = gCost + neighbor->h_cost;
        neighbor->parent = current;
    }
}

//function to add the given node to the openList
void addToOpenList(node* n){
    openList[openCount++] = n;
}

//function to sort the openList in ascending order of f_cost
void sortOpenList(){
    int i, j;
    for(i = 0; i < openCount-1; i++){
        for(j = 0; j < openCount-i-1; j++){
            if(openList[j]->f_cost > openList[j+1]->f_cost){
                node* temp = openList[j];
                openList[j] = openList[j+1];
                openList[j+1] = temp;
            }
        }
    }
}

//function to print the path from start node to goal node
void printPath(node* goal){
    if(goal->parent != NULL){
        printPath(goal->parent);
    }
    printf("(%d, %d) -> ", goal->x, goal->y);
}

//function to perform A* pathfinding algorithm
void AStarAlgorithm(int grid[ROW][COL], node* start, node* goal){
    addToOpenList(start);
    start->g_cost = 0;
    start->h_cost = manhattanDistance(start, goal);
    start->f_cost = start->h_cost;
    int foundGoal = 0;
    while(openCount > 0){
        sortOpenList();
        node* current = openList[0];
        if(current == goal){
            foundGoal = 1;
            break;
        }
        openList[0] = openList[--openCount];
        closedList[closedCount++] = current;
        int i, j;
        for(i = -1; i <= 1; i++){
            for(j = -1; j <= 1; j++){
                if(i == 0 && j == 0){
                    continue;
                }
                if(isValid(current->x+i, current->y+j) && grid[current->x+i][current->y+j] == 0){
                    node* neighbor = (node*)malloc(sizeof(node));
                    neighbor->x = current->x + i;
                    neighbor->y = current->y + j;
                    neighbor->parent = current;
                    neighbor->g_cost = 99999;    //a high cost which will be updated later
                    neighbor->h_cost = manhattanDistance(neighbor, goal);
                    neighbor->f_cost = neighbor->g_cost + neighbor->h_cost;
                    if(!isClosed(neighbor)){
                        if(!isOpen(neighbor)){
                            addToOpenList(neighbor);
                        }
                        updateCost(current, neighbor);
                    }
                    else{
                        free(neighbor);
                    }
                }
            }
        }
    }
    if(foundGoal){
        printf("Path found: ");
        printPath(goal);
        printf("\n");
    }
    else{
        printf("Path not found.\n");
    }
}

int main(){
    int grid[ROW][COL] = { { 0, 0, 1, 0, 0, 0, 0, 0, 0, 0 },
                           { 1, 0, 1, 0, 1, 1, 0, 1, 1, 1 },
                           { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                           { 0, 1, 1, 1, 0, 1, 1, 0, 0, 0 },
                           { 0, 1, 0, 0, 0, 0, 0, 0, 1, 0 },
                           { 0, 1, 0, 1, 1, 1, 1, 1, 1, 0 },
                           { 0, 1, 0, 0, 0, 0, 0, 0, 0, 0 },
                           { 0, 0, 0, 1, 1, 0, 0, 1, 1, 1 },
                           { 0, 1, 0, 1, 0, 0, 0, 0, 0, 0 },
                           { 0, 0, 0, 0, 0, 0, 1, 1, 0, 0 } };
    printf("Grid: \n");
    int i, j;
    for(i = 0; i < ROW; i++){
        for(j = 0; j < COL; j++){
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
    node* start = (node*)malloc(sizeof(node));
    start->x = 0;
    start->y = 0;
    node* goal = (node*)malloc(sizeof(node));
    goal->x = 9;
    goal->y = 9;
    printf("\nStart node: (%d, %d)\n", start->x, start->y);
    printf("Goal node: (%d, %d)\n\n", goal->x, goal->y);
    AStarAlgorithm(grid, start, goal);
    return 0;
}