//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 50
#define HEIGHT 30
#define MAX_ROOMS 10
#define ROOM_MIN_SIZE 5
#define ROOM_MAX_SIZE 15

typedef struct Room {
  int x, y, width, height;
} Room;

void generateDungeon(int dungeon[HEIGHT][WIDTH]) {
  // Initialize dungeon to all walls
  for (int i = 0; i < HEIGHT; i++) {
    for (int j = 0; j < WIDTH; j++) {
      dungeon[i][j] = '#';
    }
  }
  
  srand(time(NULL));
  
  Room rooms[MAX_ROOMS];
  int numRooms = 0;
  
  // Generate rooms
  for (int i = 0; i < MAX_ROOMS; i++) {
    int roomWidth = rand() % (ROOM_MAX_SIZE - ROOM_MIN_SIZE) + ROOM_MIN_SIZE;
    int roomHeight = rand() % (ROOM_MAX_SIZE - ROOM_MIN_SIZE) + ROOM_MIN_SIZE;
    int x = rand() % (WIDTH - roomWidth - 1) + 1;
    int y = rand() % (HEIGHT - roomHeight - 1) + 1;
    
    Room newRoom = {x, y, roomWidth, roomHeight};
    
    // Check for overlap with existing rooms
    int overlaps = 0;
    for (int j = 0; j < numRooms; j++) {
      if (newRoom.x < rooms[j].x + rooms[j].width &&
          newRoom.x + newRoom.width > rooms[j].x &&
          newRoom.y < rooms[j].y + rooms[j].height &&
          newRoom.y + newRoom.height > rooms[j].y) {
            overlaps = 1;
            break;
          }
    }
    
    if (!overlaps) {
      // Create new room
      for (int j = newRoom.y; j < newRoom.y + newRoom.height; j++) {
        for (int k = newRoom.x; k < newRoom.x + newRoom.width; k++) {
          dungeon[j][k] = '.';
        }
      }
      
      // Connect new room to previous room (if any)
      if (numRooms > 0) {
        int prevX = rooms[numRooms-1].x + rooms[numRooms-1].width/2;
        int prevY = rooms[numRooms-1].y + rooms[numRooms-1].height/2;
        int currX = newRoom.x + newRoom.width/2;
        int currY = newRoom.y + newRoom.height/2;
        
        if (rand() % 2 == 0) {
          // Horizontal tunnel first, then vertical
          for (int j = prevX; j <= currX; j++) {
            dungeon[prevY][j] = '.';
          }
          for (int j = prevY; j <= currY; j++) {
            dungeon[j][currX] = '.';
          }
        } else {
          // Vertical tunnel first, then horizontal
          for (int j = prevY; j <= currY; j++) {
            dungeon[j][prevX] = '.';
          }
          for (int j = prevX; j <= currX; j++) {
            dungeon[currY][j] = '.';
          }
        }
      }
      
      rooms[numRooms++] = newRoom;
    }
  }
}

int main() {
  int dungeon[HEIGHT][WIDTH];
  
  generateDungeon(dungeon);
  
  // Print dungeon
  for (int i = 0; i < HEIGHT; i++) {
    for (int j = 0; j < WIDTH; j++) {
      printf("%c", dungeon[i][j]);
    }
    printf("\n");
  }
  
  return 0;
}