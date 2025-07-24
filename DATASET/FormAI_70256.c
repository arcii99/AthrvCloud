//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: grateful
#include <stdlib.h> 
#include <stdio.h> 
#include <time.h> 

void generate_map(int width, int height) { 
  // Seed RNG 
  srand(time(NULL)); 

  // Generate map 
  char map[width][height]; 
  for(int x = 0; x < width; x++) { 
    for(int y = 0; y < height; y++) { 
      // Generate random terrain type 
      int terrain = rand() % 3; 
      if(terrain == 0) { 
        map[x][y] = '.'; // Plain 
      } else if(terrain == 1) { 
        map[x][y] = '#'; // Wall 
      } else { 
        map[x][y] = '~'; // Water 
      } 
    } 
  } 

  // Print map 
  for(int y = 0; y < height; y++) { 
    for(int x = 0; x < width; x++) { 
      printf("%c", map[x][y]); 
    } 
    printf("\n"); 
  } 
} 

int main() { 
  generate_map(20, 20); 
  return 0; 
}