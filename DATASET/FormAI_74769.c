//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 20
#define HEIGHT 10

int map[WIDTH*HEIGHT];

void generate_map(){
    int rand_num = rand() % 10;
    for(int i=0;i<WIDTH*HEIGHT;i++){
        if(rand() % 10 < rand_num){
            map[i] = 1;
        }else{
            map[i] = 0;
        }
    }
}

void render_map(){
    for(int y=0;y<HEIGHT;y++){
        for(int x=0;x<WIDTH;x++){
            switch(map[x+y*WIDTH]){
                case 0:
                    printf(".");
                    break;
                case 1:
                    printf("#");
                    break;
            }
        }
        printf("\n");
    }
}

int main(){
    srand(time(0));
    generate_map();
    render_map();
    return 0;
}