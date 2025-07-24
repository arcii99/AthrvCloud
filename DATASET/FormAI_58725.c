//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LEVELS 10
#define MAX_ROOMS 20
#define HEIGHT 50
#define WIDTH 80

typedef struct {
  int x, y;
} Point;

typedef struct {
  int x, y;
  int width, height;
} Room;

enum TileType { WALL, FLOOR };

typedef struct {
  enum TileType type;
  int explored;
} Tile;

Tile dungeon[MAX_LEVELS][WIDTH][HEIGHT];

void initDungeon(int level)
{
  int i, j;
  for (i = 0; i < WIDTH; i++) {
    for (j = 0; j < HEIGHT; j++) {
      dungeon[level][i][j].type = WALL;
      dungeon[level][i][j].explored = 0;
    }
  }
}

void addRoomToDungeon(int level, Room r)
{
  int i, j;
  for (i = r.x; i < r.x + r.width; i++) {
    for (j = r.y; j < r.y + r.height; j++) {
      dungeon[level][i][j].type = FLOOR;
    }
  }
}

void addCorridorToDungeon(int level, Point p1, Point p2)
{
  if (p1.x == p2.x) {
    int i;
    for (i = p1.y; i <= p2.y; i++) {
      dungeon[level][p1.x][i].type = FLOOR;
    }
  } else {
    int i;
    for (i = p1.x; i <= p2.x; i++) {
      dungeon[level][i][p1.y].type = FLOOR;
    }
  }
}

void connectRooms(int level, Room r1, Room r2)
{
  Point p1, p2;
  p1.x = r1.x + (r1.width / 2);
  p1.y = r1.y + (r1.height / 2);
  p2.x = r2.x + (r2.width / 2);
  p2.y = r2.y + (r2.height / 2);
  addCorridorToDungeon(level, p1, p2);
}

void generateRoomsAndCorridors(int level)
{
  int i, j;
  Room rooms[MAX_ROOMS];
  int numRooms = 0;
  for (i = 0; i < MAX_ROOMS; i++) {
    Room r;
    r.x = rand() % (WIDTH - 10) + 5;
    r.y = rand() % (HEIGHT - 10) + 5;
    r.width = rand() % 8 + 4;
    r.height = rand() % 6 + 3;
    int overlaps = 0;
    for (j = 0; j < numRooms; j++) {
      Room r2 = rooms[j];
      if (r.x < r2.x + r2.width + 2 && r.x + r.width + 2 > r2.x &&
          r.y < r2.y + r2.height + 2 && r.y + r.height + 2 > r2.y) {
        overlaps = 1;
        break;
      }
    }
    if (!overlaps) {
      rooms[numRooms] = r;
      numRooms++;
    }
  }
  for (i = 0; i < numRooms; i++) {
    addRoomToDungeon(level, rooms[i]);
  }
  for (i = 0; i < numRooms - 1; i++) {
    connectRooms(level, rooms[i], rooms[i+1]);
  }
}

void printDungeon(int level)
{
  int i, j;
  for (j = 0; j < HEIGHT; j++) {
    for (i = 0; i < WIDTH; i++) {
      if (dungeon[level][i][j].type == WALL) {
        printf("#");
      } else {
        printf(".");
      }
    }
    printf("\n");
  }
}

int main()
{
  srand(time(NULL));
  int i;
  for (i = 0; i < MAX_LEVELS; i++) {
    initDungeon(i);
    generateRoomsAndCorridors(i);
    printDungeon(i);
    printf("\n");
  }
  return 0;
}