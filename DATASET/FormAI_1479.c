//FormAI DATASET v1.0 Category: Robot movement control ; Style: rigorous
#include<stdio.h>
#include<stdlib.h>

#define MAX_X 20
#define MAX_Y 20

//function to initialize movement map
void init_map(int map[MAX_X][MAX_Y]){
    for(int i=0;i<MAX_X;i++){
        for(int j=0;j<MAX_Y;j++){
            map[i][j]=0;
        }
    }
}

//function to print the movement map
void print_map(int map[MAX_X][MAX_Y]){
    for(int i=0;i<MAX_X;i++){
        for(int j=0;j<MAX_Y;j++){
            printf("%d ",map[i][j]);
        }
        printf("\n");
    }
}

//function to move the robot in the given direction
void move_robot(int *x,int *y,char direction,int map[MAX_X][MAX_Y]){
    //moving north
    if(direction=='N'){
        if((*y)<MAX_Y-1 && map[*x][(*y)+1]!=1){
            (*y)=(*y)+1;
            map[*x][(*y)]=1;
        }
        else printf("Cannot move in this direction\n");
    }
    //moving south
    else if(direction=='S'){
        if((*y)>0 && map[*x][(*y)-1]!=1){
            (*y)=(*y)-1;
            map[*x][(*y)]=1;
        }
        else printf("Cannot move in this direction\n");
    }
    //moving east
    else if(direction=='E'){
        if((*x)<MAX_X-1 && map[(*x)+1][*y]!=1){
            (*x)=(*x)+1;
            map[*x][*y]=1;
        }
        else printf("Cannot move in this direction\n");
    }
    //moving west
    else if(direction=='W'){
        if((*x)>0 && map[(*x)-1][*y]!=1){
            (*x)=(*x)-1;
            map[*x][*y]=1;
        }
        else printf("Cannot move in this direction\n");
    }
}

int main(){
    int robot_x=0,robot_y=0;
    int movement_map[MAX_X][MAX_Y];
    char direction;
    //initializing map
    init_map(movement_map);
    movement_map[0][0]=1;
    //moving robot in different directions
    move_robot(&robot_x,&robot_y,'N',movement_map);
    move_robot(&robot_x,&robot_y,'E',movement_map);
    move_robot(&robot_x,&robot_y,'S',movement_map);
    move_robot(&robot_x,&robot_y,'W',movement_map);
    //printing final map
    print_map(movement_map);
    return 0;
}