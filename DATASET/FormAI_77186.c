//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 80
#define HEIGHT 24
#define MAX_ROOMS 6
#define MIN_ROOM_SIZE 4
#define MAX_ROOM_SIZE 10

typedef struct {
  int x, y, width, height;
} Room;

typedef struct {
  int x, y;
} Point;

typedef struct {
  char symbol;
  int x, y;
} Entity;

char map[WIDTH][HEIGHT];
Entity player;

int random_int(int min, int max) {
  return min + rand() % (max - min + 1);
}

int room_collides(Room a, Room b) {
  return (a.x <= b.x + b.width &&
          a.x + a.width >= b.x &&
          a.y <= b.y + b.height &&
          a.y + a.height >= b.y);
}

void fill_rect(int x1, int y1, int x2, int y2, char c) {
  int i, j;
  for (i = x1; i <= x2; i++) {
    for (j = y1; j <= y2; j++) {
      map[i][j] = c;
    }
  }
}

void draw_room(Room r) {
  fill_rect(r.x, r.y, r.x + r.width, r.y + r.height, '.');
}

void draw_corridor(Point a, Point b) {
  if (random_int(0, 1) == 0) {
    fill_rect(a.x, b.y, b.x, b.y, '.');
    fill_rect(b.x, a.y, b.x, b.y, '.');
  } else {
    fill_rect(a.x, a.y, b.x, a.y, '.');
    fill_rect(b.x, a.y, b.x, b.y, '.');
  }
}

void draw_map() {
  int i, j;
  for (i = 0; i < HEIGHT; i++) {
    for (j = 0; j < WIDTH; j++) {
      putchar(map[j][i]);
    }
    putchar('\n');
  }
}

void generate_dungeon() {
  int i, j, k, attempts;
  Room rooms[MAX_ROOMS];
  Point centers[MAX_ROOMS];
  
  // Initialize map with walls.
  for (i = 0; i < HEIGHT; i++) {
    for (j = 0; j < WIDTH; j++) {
      map[j][i] = '#';
    }
  }
  
  // Generate rooms.
  for (i = 0; i < MAX_ROOMS; i++) {
    attempts = 0;
    do {
      rooms[i].x = random_int(1, WIDTH - MAX_ROOM_SIZE - 2);
      rooms[i].y = random_int(1, HEIGHT - MAX_ROOM_SIZE - 2);
      rooms[i].width = random_int(MIN_ROOM_SIZE, MAX_ROOM_SIZE);
      rooms[i].height = random_int(MIN_ROOM_SIZE, MAX_ROOM_SIZE);
      attempts++;
    } while (attempts < 100 && 
            (rooms[i].x + rooms[i].width >= WIDTH - 1 ||
             rooms[i].y + rooms[i].height >= HEIGHT - 1 ||
             room_collides(rooms[i], rooms[k])));
    centers[i].x = rooms[i].x + rooms[i].width/2;
    centers[i].y = rooms[i].y + rooms[i].height/2;
    draw_room(rooms[i]);
  }
  
  // Generate corridors.
  for (i = 0; i < MAX_ROOMS; i++) {
    for (j = i+1; j < MAX_ROOMS; j++) {
      draw_corridor(centers[i], centers[j]);
    }
  }
  
  // Place player.
  do {
    player.x = random_int(1, WIDTH - 2);
    player.y = random_int(1, HEIGHT - 2);
  } while (map[player.x][player.y] != '.');
  map[player.x][player.y] = '@';
}

int main() {
  srand(time(NULL));
  generate_dungeon();
  draw_map();
  return 0;
}