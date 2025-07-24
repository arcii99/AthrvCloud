//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define WIDTH 30
#define HEIGHT 10
#define MAX_ROOMS 6

char map[HEIGHT][WIDTH];

typedef struct {
    int x;
    int y;
    int w;
    int h;
} Room;

void initMap(){
    for(int y=0;y<HEIGHT;y++){
        for(int x=0;x<WIDTH;x++){
            map[y][x] = '#';
        }
    }
}

void printMap(){
    for(int y=0;y<HEIGHT;y++){
        for(int x=0;x<WIDTH;x++){
            printf("%c",map[y][x]);
        }
        printf("\n");
    }
}

bool hasCollision(Room rooms[], int numRooms, Room newRoom){
    for(int i=0;i<numRooms;i++){
        Room room = rooms[i];
        if(newRoom.x <= room.x + room.w && newRoom.x + newRoom.w >= room.x && newRoom.y <= room.y + room.h && newRoom.y + newRoom.h >= room.y){
            return true;
        }
    }
    return false;
}

void generateRoom(Room *room){
    room->x = rand() % (WIDTH - 7) + 1;
    room->y = rand() % (HEIGHT - 5) + 1;
    room->w = rand() % 6 + 4;
    room->h = rand() % 4 + 3;
}

void generateRooms(Room rooms[], int numRooms){
    int i = 0;
    while(i < numRooms){
        Room room;
        generateRoom(&room);
        if(!hasCollision(rooms, i, room)){
            rooms[i] = room;
            i++;
        }
    }

}

void connectRooms(Room room1, Room room2){
    int x1 = rand() % (room1.w - 2) + room1.x + 1;
    int x2 = rand() % (room2.w - 2) + room2.x + 1;
    int y1 = rand() % (room1.h - 2) + room1.y + 1;
    int y2 = rand() % (room2.h - 2) + room2.y + 1;
    
    while(x1 != x2){
        if(x1 < x2){
            x1++;
        }else{
            x1--;
        }
        map[y1][x1] = '.';
    }
    
    while(y1 != y2){
        if(y1 < y2){
            y1++;
        }else{
            y1--;
        }
        map[y1][x1] = '.';
    }
}

void generateMap(){
    Room rooms[MAX_ROOMS];
    for(int i=0;i<MAX_ROOMS;i++){
        Room room;
        rooms[i] = room;
    }
    generateRooms(rooms, MAX_ROOMS);
    for(int i=0;i<MAX_ROOMS-1;i++){
        connectRooms(rooms[i], rooms[i+1]);
    }
}


int main(){
    srand(time(NULL));
    initMap();
    generateMap();
    printMap();
    return 0;
}