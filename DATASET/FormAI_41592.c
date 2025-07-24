//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAP_WIDTH 50
#define MAP_HEIGHT 20

#define MAX_ROOM_WIDTH 10
#define MAX_ROOM_HEIGHT 8
#define MIN_ROOM_WIDTH 4
#define MIN_ROOM_HEIGHT 4

#define MAX_ROOMS 10

int map[MAP_WIDTH][MAP_HEIGHT];

typedef struct room {
    int x, y;
    int width, height;
} Room;

void print_map() {
    for(int y=0; y<MAP_HEIGHT; y++) {
        for(int x=0; x<MAP_WIDTH; x++) {
            if(map[x][y] == 1) {
                printf(".");
            } else {
                printf("#");
            }
        }
        printf("\n");
    }
}

void create_room(Room r) {
    for(int y=r.y; y<r.y+r.height; y++) {
        for(int x=r.x; x<r.x+r.width; x++) {
            map[x][y] = 1;
        }
    }
}

int intersect(Room r1, Room r2) {
    if(r1.x+r1.width < r2.x || r1.x > r2.x+r2.width) {
        return 0;
    }
    if(r1.y+r1.height < r2.y || r1.y > r2.y+r2.height) {
        return 0;
    }
    return 1;
}

int create_room_and_check_intersections(Room r, int num_rooms, Room *rooms) {
    // Create the room
    create_room(r);
    
    // Check for intersections with other rooms
    for(int i=0; i<num_rooms; i++) {
        if(intersect(r, rooms[i])) {
            return 1;
        }
    }
    return 0;
}

void create_hallway(int x1, int y1, int x2, int y2) {
    // Horizontal hallway
    if(y1 == y2) {
        for(int x=x1; x<=x2; x++) {
            map[x][y1] = 1;
        }
    }
    // Vertical hallway
    else if(x1 == x2) {
        for(int y=y1; y<=y2; y++) {
            map[x1][y] = 1;
        }
    }
}

void connect_rooms(Room *r1, Room *r2) {
    int x1 = r1->x + r1->width/2;
    int y1 = r1->y + r1->height/2;
    int x2 = r2->x + r2->width/2;
    int y2 = r2->y + r2->height/2;
    
    // Create a straight hallway between the rooms
    create_hallway(x1, y1, x2, y2);
}

void generate_map() {
    // Initialize the map with walls
    for(int y=0; y<MAP_HEIGHT; y++) {
        for(int x=0; x<MAP_WIDTH; x++) {
            map[x][y] = 0;
        }
    }
    
    // Seed the random number generator
    srand(time(NULL));
    
    // Generate some rooms
    int num_rooms = 0;
    Room rooms[MAX_ROOMS];
    while(num_rooms < MAX_ROOMS) {
        // Generate a random room
        Room r;
        r.width = rand() % (MAX_ROOM_WIDTH-MIN_ROOM_WIDTH+1) + MIN_ROOM_WIDTH;
        r.height = rand() % (MAX_ROOM_HEIGHT-MIN_ROOM_HEIGHT+1) + MIN_ROOM_HEIGHT;
        r.x = rand() % (MAP_WIDTH-r.width);
        r.y = rand() % (MAP_HEIGHT-r.height);
        
        if(!create_room_and_check_intersections(r, num_rooms, rooms)) {
            rooms[num_rooms++] = r;
        }
    }
    
    // Connect the rooms with hallways
    for(int i=0; i<num_rooms-1; i++) {
        connect_rooms(&rooms[i], &rooms[i+1]);
    }
}

int main() {
    generate_map();
    print_map();
    return 0;
}