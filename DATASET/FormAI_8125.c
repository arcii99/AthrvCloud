//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: puzzling
// Procedural Rogue-like Game with Puzzling Elements
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define constants
#define MAX_MAP_SIZE 30
#define EMPTY_TILE ' '
#define WALL_TILE '#'
#define PLAYER_TILE '@'
#define GOAL_TILE 'X'
#define MIN_ROOM_SIZE 5
#define MAX_ROOM_SIZE 10

// Define structures
typedef struct Coord {
    int x;
    int y;
} Coord;

typedef struct Room {
    Coord position;
    int width;
    int height;
} Room;

// Define global variables
char map[MAX_MAP_SIZE][MAX_MAP_SIZE];
Coord player_position;
Coord goal_position;

// Function prototypes
void initialize_map();
void generate_rooms(int num_rooms);
void generate_corridors();
void add_player_and_goal();
void print_map();
int move_player(int dx, int dy);

// Function to initialize the map with walls
void initialize_map() {
    for(int i = 0; i < MAX_MAP_SIZE; i++) {
        for(int j = 0; j < MAX_MAP_SIZE; j++) {
            if(i == 0 || i == MAX_MAP_SIZE-1 || j == 0 || j == MAX_MAP_SIZE-1) {
                map[i][j] = WALL_TILE;
            } else {
                map[i][j] = EMPTY_TILE;
            }
        }
    }
}

// Function to generate random rooms
void generate_rooms(int num_rooms) {
    srand(time(NULL));
    int num_generated = 0;
    
    while(num_generated < num_rooms) {
        int room_width = rand() % (MAX_ROOM_SIZE - MIN_ROOM_SIZE) + MIN_ROOM_SIZE;
        int room_height = rand() % (MAX_ROOM_SIZE - MIN_ROOM_SIZE) + MIN_ROOM_SIZE;
        
        int x = rand() % (MAX_MAP_SIZE - room_width - 2) + 1;
        int y = rand() % (MAX_MAP_SIZE - room_height - 2) + 1;
        
        // Check if the room overlaps with any existing rooms
        int overlap = 0;
        for(int i = x - 1; i < x + room_width + 1; i++) {
            for(int j = y - 1; j < y + room_height + 1; j++) {
                if(map[i][j] != EMPTY_TILE) {
                    overlap = 1;
                    break;
                }
            }
            if(overlap) {
                break;
            }
        }
        
        if(!overlap) {
            Room new_room;
            new_room.position.x = x;
            new_room.position.y = y;
            new_room.width = room_width;
            new_room.height = room_height;
            
            for(int i = x; i < x + room_width; i++) {
                for(int j = y; j < y + room_height; j++) {
                    map[i][j] = EMPTY_TILE;
                }
            }
            
            num_generated++;
        }
    }
}

// Function to generate corridors between the rooms
void generate_corridors() {
    srand(time(NULL));
    for(int i = 0; i < MAX_MAP_SIZE; i++) {
        for(int j = 0; j < MAX_MAP_SIZE; j++) {
            if(map[i][j] == EMPTY_TILE && map[i][j+1] == WALL_TILE && map[i][j-1] == WALL_TILE) {
                int distance_up = 0;
                int distance_down = 0;
                // Measure the distance to the nearest room above
                for(int k = i-1; k >= 0; k--) {
                    if(map[k][j] == EMPTY_TILE) {
                        distance_up++;
                    } else {
                        break;
                    }
                }
                // Measure the distance to the nearest room below
                for(int k = i+1; k < MAX_MAP_SIZE; k++) {
                    if(map[k][j] == EMPTY_TILE) {
                        distance_down++;
                    } else {
                        break;
                    }
                }
                if(distance_up > 0 && distance_down > 0) {
                    int maxLength = (distance_up < distance_down ? distance_up : distance_down);
                    int corridor_length = rand() % maxLength + 1;
                    
                    for(int k = i-corridor_length; k <= i+corridor_length; k++) {
                        map[k][j] = EMPTY_TILE;
                    }
                }       
            }
            if(map[i][j] == EMPTY_TILE && map[i+1][j] == WALL_TILE && map[i-1][j] == WALL_TILE) {
                int distance_left = 0;
                int distance_right = 0;
                // Measure the distance to the nearest room to the left
                for(int k = j-1; k >= 0; k--) {
                    if(map[i][k] == EMPTY_TILE) {
                        distance_left++;
                    } else {
                        break;
                    }
                }
                // Measure the distance to the nearest room to the right
                for(int k = j+1; k < MAX_MAP_SIZE; k++) {
                    if(map[i][k] == EMPTY_TILE) {
                        distance_right++;
                    } else {
                        break;
                    }
                }
                if(distance_left > 0 && distance_right > 0) {
                    int maxLength = (distance_left < distance_right ? distance_left : distance_right);
                    int corridor_length = rand() % maxLength + 1;
                    
                    for(int k = j-corridor_length; k <= j+corridor_length; k++) {
                        map[i][k] = EMPTY_TILE;
                    }
                }       
            }
        }
    }
}

// Function to add the player and the goal to the map
void add_player_and_goal() {
    srand(time(NULL));
    // Add the player
    while(1) {
        int x = rand() % (MAX_MAP_SIZE - 2) + 1;
        int y = rand() % (MAX_MAP_SIZE - 2) + 1;
        
        if(map[x][y] == EMPTY_TILE) {
            map[x][y] = PLAYER_TILE;
            player_position.x = x;
            player_position.y = y;
            break;
        }
    }
    // Add the goal
    while(1) {
        int x = rand() % (MAX_MAP_SIZE - 2) + 1;
        int y = rand() % (MAX_MAP_SIZE - 2) + 1;
        
        if(map[x][y] == EMPTY_TILE) {
            map[x][y] = GOAL_TILE;
            goal_position.x = x;
            goal_position.y = y;
            break;
        }
    }
}

// Function to print the map
void print_map() {
    for(int i = 0; i < MAX_MAP_SIZE; i++) {
        for(int j = 0; j < MAX_MAP_SIZE; j++) {
            printf("%c ", map[i][j]);
        }
        printf("\n");
    }
}

// Function to move the player
int move_player(int dx, int dy) {
    int new_x = player_position.x + dx;
    int new_y = player_position.y + dy;
    
    if(map[new_x][new_y] == EMPTY_TILE) {
        map[player_position.x][player_position.y] = EMPTY_TILE;
        map[new_x][new_y] = PLAYER_TILE;
        player_position.x = new_x;
        player_position.y = new_y;
        
        if(player_position.x == goal_position.x && player_position.y == goal_position.y) {
            return 1;
        } else {
            return 0;
        }
    } else {
        return 0;
    }
}

// Main function
int main() {
    initialize_map();
    generate_rooms(5);
    generate_corridors();
    add_player_and_goal();
    printf("Welcome to the Rogue-like Puzzler! Find your way to the X on the map to win!\n");
    print_map();
    while(1) {
        char input;
        printf("Enter movement direction (W/A/S/D): ");
        scanf(" %c", &input);
        int win_flag = 0;
        switch(input) {
            case 'w':
                win_flag = move_player(-1, 0);
                break;
            case 'a':
                win_flag = move_player(0, -1);
                break;
            case 's':
                win_flag = move_player(1, 0);
                break;
            case 'd':
                win_flag = move_player(0, 1);
                break;
            default:
                printf("Invalid input!\n");
                break;
        }
        print_map();
        if(win_flag) {
            printf("You win!\n");
            break;
        }
    }
    return 0;
}