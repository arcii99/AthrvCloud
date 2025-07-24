//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 20
#define COLS 40

char grid[ROWS][COLS];

void generate_dungeon() {
    srand(time(NULL));
    int row, col;
    
    //initialize grid with walls
    for(row = 0; row < ROWS; row++) {
        for(col = 0; col < COLS; col++) {
            grid[row][col] = '#';
        }
    }
    
    //carve out rooms
    int num_rooms = rand()%10 + 5; //generate between 5-14 rooms
    int room_width, room_height, x, y;
    for(int i = 0; i < num_rooms; i++) {
        room_width = rand()%10 + 5; //generate between 5-14 width
        room_height = rand()%10 + 5; //generate between 5-14 height
        x = rand()%(COLS-room_width-1) + 1; //generate random x position for room
        y = rand()%(ROWS-room_height-1) + 1; //generate random y position for room
        
        //create room
        for(row = y; row < y+room_height; row++) {
            for(col = x; col < x+room_width; col++) {
                grid[row][col] = '.';
            }
        }
    }
    
    //carve out corridors
    int max_corridor_length = 15;
    int num_corridors = rand()%10 + 5; //generate between 5-14 corridors
    int direction, corridor_length, dx, dy;
    for(int i = 0; i < num_corridors; i++) {
        x = rand()%COLS;
        y = rand()%ROWS;
        dx = dy = corridor_length = 0;
        do {
            direction = rand()%4;
            if(direction == 0) { //north
                dy = -1;
            } else if(direction == 1) { //east
                dx = 1;
            } else if(direction == 2) { //south
                dy = 1;
            } else { //west
                dx = -1;
            }
            if(corridor_length == 0) { //start corridor from a room
                if(grid[y][x] == '.') {
                    corridor_length++;
                } else {
                    dx = dy = 0;
                }
            } else { //continue corridor
                if(grid[y+dy][x+dx] == '#') {
                    grid[y+dy][x+dx] = '.';
                    corridor_length++;
                } else {
                    dx = dy = 0;
                }
            }
        } while(dx != 0 || dy != 0 || corridor_length > max_corridor_length);
    }
}

void print_dungeon() {
    for(int row = 0; row < ROWS; row++) {
        for(int col = 0; col < COLS; col++) {
            printf("%c", grid[row][col]);
        }
        printf("\n");
    }
}

int main() {
    generate_dungeon();
    print_dungeon();
    return 0;
}