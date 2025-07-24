//FormAI DATASET v1.0 Category: File handling ; Style: medieval
#include <stdio.h>

int main()
{
  FILE *map;
  char dungeon[255];
  
  map = fopen("map.txt", "r");

  if (map == NULL) {
    printf("The map has been lost in time!\n");
    return 1;
  }

  while (fgets(dungeon, 255, map) != NULL) {
    printf("%s", dungeon);
  }

  fclose(map);
  return 0;
}