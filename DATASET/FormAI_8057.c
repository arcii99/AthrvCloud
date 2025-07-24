//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 80
#define HEIGHT 25

void init_map(char map[HEIGHT][WIDTH]){
    //Initiate the map using "#" for walls and "." for floors
    for(int i=0;i<HEIGHT;i++){
        for(int j=0;j<WIDTH;j++){
            if(i==0 || i == HEIGHT-1 || j==0 || j == WIDTH-1){
                map[i][j] = '#';
            }
            else{
                map[i][j] = '.';
            }
        }
    }
}

void create_rooms(char map[HEIGHT][WIDTH], int rooms_num){
    srand(time(NULL));
    for(int i=0;i<rooms_num;i++){
        int x = rand()%(WIDTH-2)+1;
        int y = rand()%(HEIGHT-2)+1;
        int w = rand()%10+3;
        int h = rand()%6+3;

        for(int j=y;j<y+h;j++){
            for(int k=x;k<x+w;k++){
                map[j][k] = '.';
            }
        }
    }
}

void print_map(char map[HEIGHT][WIDTH]){
    printf("\n");
    for(int i=0;i<HEIGHT;i++){
        for(int j=0;j<WIDTH;j++){
            printf("%c", map[i][j]);
        }
        printf("\n");
    }
}

int main(){
    char map[HEIGHT][WIDTH];
    int rooms_num = 8;
    init_map(map);
    create_rooms(map, rooms_num);
    print_map(map);

    return 0;
}