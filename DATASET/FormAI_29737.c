//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 10
#define COLUMN 10
#define MAX_ITERATIONS ROW*COLUMN*2

int map[ROW][COLUMN];
int visited[ROW][COLUMN];

void generateMap(){
    int i,j;
    srand(time(0));
    for(i=0;i<ROW;i++){
        for(j=0;j<COLUMN;j++){
            map[i][j] = rand()%2; 
            visited[i][j] = 0;
        }
    }
}

void printMap(){
    int i,j;
    printf("MAP:\n");
    for(i=0;i<ROW;i++){
        for(j=0;j<COLUMN;j++){
            printf("%d ",map[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int isValid(int x, int y){
    if(x>=0 && x<ROW && y>=0 && y<COLUMN && map[x][y]==1 && visited[x][y]==0){
        return 1;
    }
    return 0;
}

int findPath(int x1, int y1, int x2, int y2){
    int i,j,k,found,dir;
    int x,y;
    int destX = x2,destY = y2;
    int sourceX = x1,sourceY = y1;
    int pathX[ROW*COLUMN],pathY[ROW*COLUMN];
    int pathLength = 0;
    int pathExists = 0;
    int directions[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
    for(i=0;i<ROW;i++){
        for(j=0;j<COLUMN;j++){
            visited[i][j] = 0;
        }
    }
    visited[x1][y1] = 1;
    for(k=0;k<MAX_ITERATIONS;k++){
        found = 0;
        for(dir=0;dir<4;dir++){
            x = sourceX + directions[dir][0];
            y = sourceY + directions[dir][1];
            if(isValid(x,y)){
                found = 1;
                visited[x][y] = 1;
                pathX[pathLength] = x;
                pathY[pathLength] = y;
                pathLength++;
                sourceX = x;
                sourceY = y;
                if(sourceX==destX && sourceY==destY){
                    pathExists = 1;
                    break;
                }
            }
        }
        if(found==0){
            pathLength--;
            if(pathLength<=0){
                break;
            }
            sourceX = pathX[pathLength-1];
            sourceY = pathY[pathLength-1];
        }
        if(pathExists){
            break;
        }
    }
    if(pathExists){
        printf("PATH FOUND:\n");
        for(i=0;i<pathLength;i++){
            printf("(%d,%d)->",pathX[i],pathY[i]);
        }
        printf("(%d,%d)\n",destX,destY);
    }else{
        printf("NO PATH FOUND\n");
    }
    return pathExists;
}

int main(){
    int startX,startY,endX,endY;
    generateMap();
    printMap();
    printf("Enter starting position (x,y):\n");
    scanf("%d %d",&startX,&startY);
    printf("Enter end position (x,y):\n");
    scanf("%d %d",&endX,&endY);
    findPath(startX,startY,endX,endY);
    return 0;
}