//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 30
#define HEIGHT 20

char map[HEIGHT][WIDTH];

void generateMap(){
  srand(time(0));
  for(int i=0; i<HEIGHT; i++){
    for(int j=0; j<WIDTH; j++){
      if(i == 0 || j == 0 || i == HEIGHT-1 || j == WIDTH-1){
        map[i][j] = '#';
      }
      else{
        if(rand() % 100 < 50){
          map[i][j] = '.';
        }
        else{
          map[i][j] = '#';
        }
      }
    }
  }
  map[1][1] = '@';
}

void printMap(){
  for(int i=0; i<HEIGHT; i++){
    for(int j=0; j<WIDTH; j++){
      printf("%c", map[i][j]);
    }
    printf("\n");
  }
}

int main(){
  generateMap();
  printMap();

  return 0;
}