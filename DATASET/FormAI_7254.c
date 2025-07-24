//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: authentic
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define ROOM_MAX 8
#define ROWS 40
#define COLS 80

typedef struct  {
  int x;
  int y;
  int w;
  int h;
  int connected;
} ROOM;

typedef struct {
  int x;
  int y;
} TILE;

char tile[ROWS][COLS];
ROOM rooms[ROOM_MAX];
int ncx[100], ncy[100];
int room_count, corridor_count;
int filled_tiles[ROWS][COLS];

void init_map() {
  int i, j;
  for(i=0; i<ROWS; i++) {
    for(j=0; j<COLS; j++) {
      tile[i][j] = '#';
      filled_tiles[i][j] = 0;
    }
  }
}

void create_room(int r) {
  int x, y, w, h, i, j, cx, cy;
  x = rand()%(COLS-10);
  y = rand()%(ROWS-10);
  w = rand()%10 + 5;
  h = rand()%10 + 5;
  if (x+w > COLS)
    w = COLS-x;
  if (y+h > ROWS)
    h = ROWS-y;
  rooms[r].x = x;
  rooms[r].y = y;
  rooms[r].w = w;
  rooms[r].h = h;
  rooms[r].connected = 0;
  for(i=x; i<x+w; i++) {
    for(j=y; j<y+h; j++) {
      tile[j][i] = '.';
      filled_tiles[j][i] = 1;
    }
  }
}

int is_connected(int a, int b) {
  int i;
  for(i=0; i<room_count; i++) {
    if (rooms[a].connected == rooms[b].connected) {
      return 1;
    }
  }
  return 0;
}

void connect_rooms() {
  int i, a, b, cx, cy, len, x, y;
  for(i=0; i<10; i++) {
    ncx[i] = ncy[i] = -1;
  }
  for(i=0; i<room_count; i++) {
    rooms[i].connected = -1;
  }
  room_count = 0;
  for(a=0; a<ROOM_MAX; a++) {
    create_room(room_count);
    room_count++;
  }
  for(a=0; a<ROOM_MAX; a++) {
    b = rand()%ROOM_MAX;
    if (a==b) continue;
    if (is_connected(a, b)) continue;
    cx = (rooms[a].x + rooms[a].w/2 + rooms[b].x + rooms[b].w/2)/2;
    cy = (rooms[a].y + rooms[a].h/2 + rooms[b].y + rooms[b].h/2)/2;
    len = 0;
    x = rooms[a].x + rooms[a].w/2;
    y = rooms[a].y + rooms[a].h/2;
    while(x!=cx || y!=cy) {
      if (len > 100) 
        break;
      if (x > cx) {
        x--;
      }
      if (y > cy) {
        y--;
      }
      if (x < cx) {
        x++;
      }
      if (y < cy) {
        y++;
      }
      if (!filled_tiles[y][x]) {
        tile[y][x] = '.';
        filled_tiles[y][x] = 1;
      } 
      len++;
    }
    rooms[a].connected = rooms[b].connected = a;
    corridor_count++;
  }
  for(i=0; i<room_count; i++) {
    cx = rooms[i].x + rooms[i].w/2;
    cy = rooms[i].y + rooms[i].h/2;
    x = cx;
    y = rooms[i].y;
    while(y!=cy) {
      if (!filled_tiles[y][x]) {
        tile[y][x] = '.';
        filled_tiles[y][x] = 1;
      } 
      y += (y < cy) ? 1 : -1;
    }
    y = cy;
    x = rooms[i].x;
    while(x!=cx) {
     if (!filled_tiles[y][x]) {
        tile[y][x] = '.';
        filled_tiles[y][x] = 1;
      } 
      x += (x < cx) ? 1 : -1;
    }
  }
}

int main() {
  int i, j;
  srand(time(NULL));
  init_map();
  connect_rooms();
  for(i=0; i<ROWS; i++) {
    for(j=0; j<COLS; j++) {
      printf("%c", tile[i][j]);
    }
    printf("\n");
  }
  return 0;
}