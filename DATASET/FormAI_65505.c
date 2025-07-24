//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 50
#define HEIGHT 20
#define MAX_ROOMS 10
#define MAX_ROOM_SIZE 7
#define MIN_ROOM_SIZE 3

char map[HEIGHT][WIDTH];
int room_count;

typedef struct {
  int x, y, w, h;
} Room;

void init_map(){
  for(int i=0; i<HEIGHT; i++){
    for(int j=0; j<WIDTH; j++){
      map[i][j] = '#';
    }
  }
}

void place_rooms(){
  Room rooms[MAX_ROOMS];
  srand(time(NULL)); // seed random number generator

  // loop through each room slot and try to place one
  for(int i=0; i<MAX_ROOMS; i++){
    int w = rand() % (MAX_ROOM_SIZE - MIN_ROOM_SIZE + 1) + MIN_ROOM_SIZE;
    int h = rand() % (MAX_ROOM_SIZE - MIN_ROOM_SIZE + 1) + MIN_ROOM_SIZE;
    int x = rand() % (WIDTH - w - 1) + 1;
    int y = rand() % (HEIGHT - h - 1) + 1;

    Room new_room = {x, y, w, h};
    int collision = 0;

    // check for collision with existing rooms
    for(int j=0; j<i; j++){
      Room existing = rooms[j];
      if(new_room.x < existing.x + existing.w &&
         new_room.x + new_room.w > existing.x &&
         new_room.y < existing.y + existing.h &&
         new_room.y + new_room.h > existing.y){
        collision = 1;
        break;
      }
    }

    if(!collision){
      rooms[i] = new_room;
      room_count++;
      for(int Y=y; Y<y+h; Y++){
        for(int X=x; X<x+w; X++){
          map[Y][X] = '.';
        }
      }
    }
  }
}

int main(){
  init_map();
  place_rooms();

  // print the map
  for(int i=0; i<HEIGHT; i++){
    for(int j=0; j<WIDTH; j++){
      printf("%c", map[i][j]);
    }
    printf("\n");
  }

  printf("Generated %d rooms\n", room_count);

  return 0;
}