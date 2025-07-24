//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAP_WIDTH 80
#define MAP_HEIGHT 24

char map[MAP_HEIGHT][MAP_WIDTH];

void init_map(){
    //initialize map with walls
    for(int i=0;i<MAP_HEIGHT;i++){
        for(int j=0;j<MAP_WIDTH;j++){
            map[i][j] = '#';
        }
    }
}

void print_map(){
    //print current state of map
    for(int i=0;i<MAP_HEIGHT;i++){
        for(int j=0;j<MAP_WIDTH;j++){
            printf("%c", map[i][j]);
        }
        printf("\n");
    }
}

void add_room(int left, int top, int right, int bottom){
    //add a room to the map
    for(int i=top+1;i<bottom;i++){
        for(int j=left+1;j<right;j++){
            map[i][j] = '.';
        }
    }
}

void connect_rooms(int left1, int top1, int right1, int bottom1, int left2, int top2, int right2, int bottom2){
    //connect two rooms with a corridor
    int x1 = rand()%(right1-left1-1)+left1+1;
    int y1 = rand()%(bottom1-top1-1)+top1+1;
    int x2 = rand()%(right2-left2-1)+left2+1;
    int y2 = rand()%(bottom2-top2-1)+top2+1;
    while(x1!=x2){
        if(x1<x2){
            x1++;
        }else{
            x1--;
        }
        map[y1][x1] = '.';
    }
    while(y1!=y2){
        if(y1<y2){
            y1++;
        }else{
            y1--;
        }
        map[y1][x1] = '.';
    }
}

void generate_map(int num_rooms){
    //generate a new map with given number of rooms
    init_map();
    srand(time(NULL));
    for(int i=0;i<num_rooms;i++){
        int left = rand()%(MAP_WIDTH-10)+1;
        int top = rand()%(MAP_HEIGHT-5)+1;
        int right = rand()%(10-4)+4+left;
        int bottom = rand()%(5-3)+3+top;
        add_room(left, top, right, bottom);
        if(i!=0){
            connect_rooms(left, top, right, bottom, 
                rand()%(right-1-left)+left+1, rand()%(bottom-1-top)+top+1, 
                rand()%(right-1-left)+left+1, rand()%(bottom-1-top)+top+1);
        }
    }
}

int main(){
    generate_map(10);
    print_map();
    return 0;
}