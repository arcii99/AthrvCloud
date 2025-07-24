//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: imaginative
#include <stdlib.h>
#include <time.h>

#define MAP_WIDTH 50
#define MAP_HEIGHT 20
#define MAX_ROOMS 10

typedef struct {
  int x, y, width, height, cx, cy;
} Room;

char map[MAP_HEIGHT][MAP_WIDTH];

void drawMap() {
  int i, j;
  
  for(i = 0; i < MAP_HEIGHT; i++) {
    for(j = 0; j < MAP_WIDTH; j++) {
      if(map[i][j] == '#')
        printf("#");
      else if(map[i][j] == '.')
        printf(".");
      else
        printf(" ");
    }
    printf("\n");
  }
}

void initMap() {
  int i, j;
  for(i = 0; i < MAP_HEIGHT; i++) {
    for(j = 0; j < MAP_WIDTH; j++) {
      map[i][j] = '#';
    }
  }
}

int intersects(Room r1, Room r2) {
  return (r1.x + r1.width >= r2.x && r1.x <= r2.x + r2.width &&
          r1.y + r1.height >= r2.y && r1.y <= r2.y + r2.height);
}

void createRoom(Room r) {
  int i, j;
  for(i = r.y; i < r.y + r.height; i++) {
    for(j = r.x; j < r.x + r.width; j++) {
      map[i][j] = '.';
    }
  }
}

void createHorizontalTunnel(int x1, int x2, int y) {
  int i;
  for(i = x1; i <= x2; i++) {
    map[y][i] = '.';
  }
}

void createVerticalTunnel(int y1, int y2, int x) {
  int i;
  for(i = y1; i <= y2; i++) {
    map[i][x] = '.';
  }
}

void connectRooms(Room r1, Room r2) {
  int cx = r1.cx;
  int cy = r1.cy;
  
  if(r1.cx <= r2.cx && r1.cy <= r2.cy) {
    createHorizontalTunnel(cx, r2.cx, cy);
    createVerticalTunnel(cy, r2.cy, r2.cx);
  } else if(r1.cx <= r2.cx && r1.cy >= r2.cy) {
    createHorizontalTunnel(cx, r2.cx, cy);
    createVerticalTunnel(cy, r2.cy, r2.cx);
  } else if(r1.cx >= r2.cx && r1.cy <= r2.cy) {
    createHorizontalTunnel(r2.cx, cx, cy);
    createVerticalTunnel(cy, r2.cy, r2.cx);
  } else if(r1.cx >= r2.cx && r1.cy >= r2.cy) {
    createHorizontalTunnel(r2.cx, cx, cy);
    createVerticalTunnel(cy, r2.cy, r2.cx);
  }
}

void generateMap() {
  initMap();
  srand(time(NULL));

  Room rooms[MAX_ROOMS];
  int numRooms = 0;
  
  while(numRooms < MAX_ROOMS) {
    int w = 4 + rand() % 6;
    int h = 3 + rand() % 4;
    int x = rand() % (MAP_WIDTH - w - 2) + 1;
    int y = rand() % (MAP_HEIGHT - h - 2) + 1;
    
    Room r = { x, y, w, h, x + w/2, y + h/2 };
    
    int i;
    for(i = 0; i < numRooms; i++) {
      if(intersects(r, rooms[i])) {
        break;
      }
    }
    
    if(i == numRooms) {
      createRoom(r);
      rooms[numRooms] = r;
      numRooms++;
    }
  }
  
  int i;
  for(i = 0; i < numRooms - 1; i++) {
    connectRooms(rooms[i], rooms[i+1]);
  }
}

int main() {
  generateMap();
  drawMap();
  return 0;
}