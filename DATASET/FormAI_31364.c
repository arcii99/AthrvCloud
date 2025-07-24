//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MapWidth 30
#define MapHeight 20

int DungeonMap[MapHeight][MapWidth];

int RoomMinWidth = 4;
int RoomMinHeight = 3;
int RoomMaxWidth = 12;
int RoomMaxHeight = 8;
int MaxRooms = 10;

void SetupDungeon() {
    for(int y = 0; y < MapHeight; y++) {
        for(int x = 0; x < MapWidth; x++) {
            DungeonMap[y][x] = 1;
        }
    }
}

void PrintDungeon() {
    for(int y = 0; y < MapHeight; y++) {
        for(int x = 0; x < MapWidth; x++) {
            if(DungeonMap[y][x] == 0)
                printf("#");
            else if(DungeonMap[y][x] == 1)
                printf(".");
            else
                printf("%d", DungeonMap[y][x]);
        }
        printf("\n");
    }
}

void PlaceRoom(int roomX, int roomY, int roomW, int roomH, int roomID) {
    for(int y = roomY; y < roomY + roomH; y++) {
        for(int x = roomX; x < roomX + roomW; x++) {
            DungeonMap[y][x] = roomID;
        }
    }
}

int RoomOverlap(int roomX, int roomY, int roomW, int roomH) {
    for(int y = roomY - 1; y < roomY + roomH + 1; y++) {
        for(int x = roomX - 1; x < roomX + roomW + 1; x++) {
            if(DungeonMap[y][x] != 1)
                return 1;
        }
    }
    return 0;
}

void GenerateDungeon() {
    int roomCount = 0;
    while(roomCount < MaxRooms) {
        int roomW = (rand() % (RoomMaxWidth - RoomMinWidth + 1)) + RoomMinWidth;
        int roomH = (rand() % (RoomMaxHeight - RoomMinHeight + 1)) + RoomMinHeight;
        int roomX = rand() % (MapWidth - roomW - 1) + 1;
        int roomY = rand() % (MapHeight - roomH - 1) + 1;

        if(!RoomOverlap(roomX, roomY, roomW, roomH)) {
            roomCount++;
            PlaceRoom(roomX, roomY, roomW, roomH, roomCount);
        }
    }
}

int main() {
    srand(time(NULL));
    SetupDungeon();
    GenerateDungeon();
    PrintDungeon();
    return 0;
}