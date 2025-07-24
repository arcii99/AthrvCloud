//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: Cryptic
#include<stdio.h>
#define ROW 5
#define COL 5
#define MAX 65535

int gScore[ROW][COL];       //cost of getting from starting node to reaching a node
int hScore[ROW][COL];       //estimated cost of getting from starting node to desired destination
int fScore[ROW][COL];       //estimated total cost of a path through current node

typedef struct node{
    int i;
    int j;
}node;

//Initialize gScore & fScore with Max value
void initialize(int start_x, int start_y, int end_x, int end_y){

    for(int i=0; i<ROW; i++){
        for(int j=0; j<COL; j++){
            gScore[i][j] = MAX;
            fScore[i][j] = MAX;
        }
    }
    gScore[start_x][start_y] = 0;
    hScore[start_x][start_y] = abs(start_x-end_x) + abs(start_y-end_y);  //manhattan distance
    fScore[start_x][start_y] = hScore[start_x][start_y];
} 

//Get node with minimum fScore value 
node getMin(node arr[], int len){

    node min = arr[0];
    for(int i=1; i<len; i++){

        if(fScore[arr[i].i][arr[i].j] < fScore[min.i][min.j])
            min = arr[i];
    }
    return min;
}

//Check whether node is valid or not i.e. node does not cross the boundary and it is an open space
int isValid(int x, int y, int maze[][COL]){
    if(x<0 || x>=ROW || y<0 || y>=COL || maze[x][y]==1) 
        return 0;
    return 1;
}

//Calculate path through the maze from start node to end node
void calculatePath(int maze[][COL], int start_x, int start_y, int end_x, int end_y){

    node closedList[ROW*COL];    //To store nodes that are being checked
    node openList[ROW*COL];      //To store nodes that are to be checked
    int openLen = 1, closedLen = 0;
    node neighbors[4];

    node current = {start_x, start_y};
    openList[0] = current;

    while(openLen>0){

        current = getMin(openList, openLen);
        openLen--;

        if(current.i == end_x && current.j == end_y){    //Destination reached
            printf("Path Found!\n");
            return;
        }

        //Adding current node to closedList and checking its neighbor nodes
        closedList[closedLen++] = current;
        int x = current.i, y = current.j;

        //Finding the neighbors of current node
        neighbors[0] = (node){x+1, y};
        neighbors[1] = (node){x-1, y};
        neighbors[2] = (node){x, y+1};
        neighbors[3] = (node){x, y-1};

        for(int i=0; i<4; i++){

            //If neighbor is not valid, skip it
            if(!isValid(neighbors[i].i, neighbors[i].j, maze)) 
                continue;

            //Cost of getting to neighbor node
            int tentative_gScore = gScore[x][y] + 1;

            //If node is already in closed list
            int flag = 0;
            for(int j=0; j<closedLen; j++){
                if(closedList[j].i == neighbors[i].i && closedList[j].j == neighbors[i].j){
                    flag = 1;
                    break;
                }
            }
            if(flag == 1)  continue;

            //If node is already in open list
            flag = 0;
            for(int j=0; j<openLen; j++){
                if(openList[j].i == neighbors[i].i && openList[j].j == neighbors[i].j){
                    flag = 1;
                    break;
                }
            }
            if(flag != 1)  openList[openLen++] = neighbors[i];

            //Set scores for neighbor nodes
            if(tentative_gScore < gScore[neighbors[i].i][neighbors[i].j]){
                gScore[neighbors[i].i][neighbors[i].j] = tentative_gScore;
                hScore[neighbors[i].i][neighbors[i].j] = abs(neighbors[i].i-end_x) + abs(neighbors[i].j-end_y);
                fScore[neighbors[i].i][neighbors[i].j] = gScore[neighbors[i].i][neighbors[i].j] + hScore[neighbors[i].i][neighbors[i].j];
            }
        }
    }
}

int main(){

    int maze[ROW][COL] = { { 0, 0, 0, 0, 0 },
                           { 0, 0, 0, 1, 0 },
                           { 0, 1, 0, 1, 0 },
                           { 0, 1, 0, 1, 1 },
                           { 0, 0, 0, 0, 0 } };
    int start_x = 0, start_y = 0, end_x = 4, end_y = 4;
    initialize(start_x, start_y, end_x, end_y);
    calculatePath(maze, start_x, start_y, end_x, end_y);
    return 0;
}