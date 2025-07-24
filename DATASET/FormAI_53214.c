//FormAI DATASET v1.0 Category: Robot movement control ; Style: retro
#include <stdio.h>
#include <stdbool.h>

#define LEFT 0
#define RIGHT 1
#define UP 2
#define DOWN 3

void move(char* map, int size, int direction, int* player_pos);
void print_map(char* map, int size);

int main()
{
  int size = 15;
  char map[15*15]=
  "##########..##"
  "#.............."
  "#.............."
  "#...###....#..."
  "#.............."
  "##............."
  "..............."
  "..............."
  "..............."
  "..............."
  "#.............."
  "#.............."
  "#.............."
  "#.....#####...."
  "...............";
  
  int player_pos[2] = {1,1};   // Starting position of the robot on the map
  bool game_over = false;
  
  printf("Welcome to the Retro Robot Game!\n\n");
  printf("Move the robot around the map using the arrow keys.\n");
  printf("Collect all the dots (.) to win the game!\n\n");
  print_map(map, size);

  while(!game_over)   // Main game loop
  {
    int direction = getchar();
    
    if(direction == 27 && getchar() == 91)
    {
      switch(getchar())
      {
        case 68:   // Left arrow key
          move(map, size, LEFT, player_pos);
          break;
        case 67:   // Right arrow key
          move(map, size, RIGHT, player_pos);
          break;
        case 65:   // Up arrow key
          move(map, size, UP, player_pos);
          break;
        case 66:   // Down arrow key
          move(map, size, DOWN, player_pos);
          break;
      }
    }
    
    print_map(map, size);
    
    // Check if all the dots have been collected
    if(strchr(map, '.') == NULL)
    {
      printf("\nCongratulations! You won!\n");
      game_over = true;
    }
  }
  
  return 0;
}

void move(char* map, int size, int direction, int* player_pos)
{
  int x = player_pos[0];
  int y = player_pos[1];
  
  switch(direction)
  {
    case LEFT:
      if(map[y*size + (x - 1)] != '#')
      {
        if(map[y*size + (x - 1)] == '.')
        {
          printf("\nYou collected a dot!\n");
        }
        
        map[y*size + x] = ' ';
        x--;
        player_pos[0] = x;
        map[y*size + x] = 'P';
      }
      break;
  
    case RIGHT:
      if(map[y*size + (x + 1)] != '#')
      {
        if(map[y*size + (x + 1)] == '.')
        {
          printf("\nYou collected a dot!\n");
        }
        
        map[y*size + x] = ' ';
        x++;
        player_pos[0] = x;
        map[y*size + x] = 'P';
      }
      break;
  
    case UP:
      if(map[(y - 1)*size + x] != '#')
      {
        if(map[(y - 1)*size + x] == '.')
        {
          printf("\nYou collected a dot!\n");
        }
        
        map[y*size + x] = ' ';
        y--;
        player_pos[1] = y;
        map[y*size + x] = 'P';
      }
      break;
  
    case DOWN:
      if(map[(y + 1)*size + x] != '#')
      {
        if(map[(y + 1)*size + x] == '.')
        {
          printf("\nYou collected a dot!\n");
        }
        
        map[y*size + x] = ' ';
        y++;
        player_pos[1] = y;
        map[y*size + x] = 'P';
      }
      break;
  }
}

void print_map(char* map, int size)
{
  printf("\n");
  
  for(int i = 0; i < size; i++)
  {
    for(int j = 0; j < size; j++)
    {
      printf("%c", map[i*size + j]);
    }
    printf("\n");
  }
}