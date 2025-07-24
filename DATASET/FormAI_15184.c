//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//defining constants
#define MAP_SIZE 10
#define MAX_ROOMS 6
#define MIN_ROOM_SIZE 3
#define MAX_ROOM_SIZE 6

//function declarations
void generate_map(char map[MAP_SIZE][MAP_SIZE]);
void print_map(char map[MAP_SIZE][MAP_SIZE]);

int main() {
    char map[MAP_SIZE][MAP_SIZE]; //initializing map array
    srand(time(NULL)); //setting seed for random number generator
    
    generate_map(map); //calling map generation function
    print_map(map); //printing generated map
    
    return 0;
}

void generate_map(char map[MAP_SIZE][MAP_SIZE]) {
    //initializing map with empty spaces and borders
    for(int i = 0; i < MAP_SIZE; i++) {
        for(int j = 0; j < MAP_SIZE; j++) {
            if(i == 0 || j == 0 || i == MAP_SIZE-1 || j == MAP_SIZE-1) {
                map[i][j] = '#'; //adding border walls
            } else {
                map[i][j] = ' '; //adding empty spaces
            }
        }
    }
    
    int num_rooms = 0; //counter for number of rooms generated
    
    //generating rooms
    while(num_rooms < MAX_ROOMS) {
        int x_position = rand() % (MAP_SIZE - MAX_ROOM_SIZE - 1) + 1; //random x position within map bounds
        int y_position = rand() % (MAP_SIZE - MAX_ROOM_SIZE - 1) + 1; //random y position within map bounds
        int room_width = rand() % (MAX_ROOM_SIZE - MIN_ROOM_SIZE + 1) + MIN_ROOM_SIZE; //random width within range
        int room_height = rand() % (MAX_ROOM_SIZE - MIN_ROOM_SIZE + 1) + MIN_ROOM_SIZE; //random height within range
        
        //checking if room intersects with any existing rooms
        int intersects = 0;
        for(int i = y_position - 1; i < y_position + room_height + 1; i++) {
            for(int j = x_position - 1; j < x_position + room_width + 1; j++) {
                if(map[i][j] == '.') {
                    intersects = 1;
                }
            }
        }
        
        //if room does not intersect, add it to the map
        if(!intersects) {
            for(int i = y_position; i < y_position + room_height; i++) {
                for(int j = x_position; j < x_position + room_width; j++) {
                    map[i][j] = '.'; //adding room floor
                }
            }
            num_rooms++; //incrementing room counter
        }
    }
}

void print_map(char map[MAP_SIZE][MAP_SIZE]) {
    for(int i = 0; i < MAP_SIZE; i++) {
        for(int j = 0; j < MAP_SIZE; j++) {
            printf("%c ", map[i][j]); //printing each character in the map array with a space in between
        }
        printf("\n"); //creating new line after each row is printed
    }
}