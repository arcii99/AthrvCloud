//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAP_WIDTH 50
#define MAP_HEIGHT 20

char map[MAP_HEIGHT][MAP_WIDTH];

void generate_map() {
  // Initialize random seed
  srand(time(NULL));
  
  // Fill entire map with walls
  for(int i=0; i<MAP_HEIGHT; i++) {
    for(int j=0; j<MAP_WIDTH; j++) {
      map[i][j] = '#';
    }
  }
  
  // Place some random floors
  for(int i=0; i<MAP_HEIGHT; i++) {
    for(int j=0; j<MAP_WIDTH; j++) {
      if(rand() % 100 < 40) {
        map[i][j] = '.';
      }
    }
  }
  
  // Place player at center of map
  map[MAP_HEIGHT/2][MAP_WIDTH/2] = '@';
}

int main() {
  generate_map();
  
  // Print out map
  for(int i=0; i<MAP_HEIGHT; i++) {
    for(int j=0; j<MAP_WIDTH; j++) {
      printf("%c", map[i][j]);
    }
    
    printf("\n");
  }
  
  return 0;
}