//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 50 //define the width of the map
#define HEIGHT 30 //define the height of the map

void generate_map(char map[HEIGHT][WIDTH]){
    int i,j;
    srand(time(NULL)); //initialize the random seed
    for(i=0;i<HEIGHT;i++){
        for(j=0;j<WIDTH;j++){
            map[i][j] = (rand()%100 < 40) ? '#' : '.';
        }
    }
}

int main(){
    char map[HEIGHT][WIDTH];
    int i,j;
    generate_map(map); //generate the map
    for(i=0;i<HEIGHT;i++){
        for(j=0;j<WIDTH;j++){
            printf("%c", map[i][j]); //print the map
        }
        printf("\n");
    }
    return 0;
}