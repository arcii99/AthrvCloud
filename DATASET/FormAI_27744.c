//FormAI DATASET v1.0 Category: Robot movement control ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the map dimensions
#define ROWS 10
#define COLUMNS 10

// Define the robot structure
typedef struct {
    int x;
    int y;
} Robot;

// Define the map structure
typedef struct {
    char grid[ROWS][COLUMNS];
    Robot robot;
} Map;

// Define the movement functions
void move_up(Map *map);
void move_down(Map *map);
void move_left(Map *map);
void move_right(Map *map);

int main() {
    // Initialize the map
    Map map = {
        .grid = {
            {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
            {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
            {'#', ' ', '#', '#', '#', '#', '#', '#', ' ', '#'},
            {'#', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', '#'},
            {'#', '#', '#', ' ', '#', '#', '#', ' ', ' ', '#'},
            {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', '#'},
            {'#', ' ', '#', '#', ' ', '#', '#', ' ', '#', '#'},
            {'#', ' ', ' ', '#', ' ', '#', '#', ' ', '#', '#'},
            {'#', ' ', '#', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
            {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
        },
        .robot = {
            .x = 3,
            .y = 3,
        },
    };
    
    // Print the initial map
    printf("Initial map:\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            printf("%c ", map.grid[i][j]);
        }
        printf("\n");
    }
    
    // Give some instructions to the user
    printf("\nUse WASD to move the robot in the desired direction.\nPress Q to quit.\nPress any key to continue...\n");
    
    // Wait for the user to press a key
    getchar();
    
    // Keep track of whether the game is over
    bool game_over = false;
    
    // Start the game loop
    while (!game_over) {
        // Clear the console
        system("clear");
        
        // Get the user input
        printf("Enter a direction (WASD): ");
        char input = getchar();
        
        // Move the robot
        switch (input) {
            case 'W':
            case 'w':
                move_up(&map);
                break;
            case 'A':
            case 'a':
                move_left(&map);
                break;
            case 'S':
            case 's':
                move_down(&map);
                break;
            case 'D':
            case 'd':
                move_right(&map);
                break;
            case 'Q':
            case 'q':
                game_over = true;
                break;
            default:
                break;
        }
        
        // Update the map
        map.grid[map.robot.x][map.robot.y] = 'R';
        
        // Print the map
        printf("\nCurrent map:\n");
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLUMNS; j++) {
                printf("%c ", map.grid[i][j]);
            }
            printf("\n");
        }
    }
    
    return 0;
}

void move_up(Map *map) {
    // Check if the robot can move up
    if (map->grid[map->robot.x-1][map->robot.y] != '#') {
        map->grid[map->robot.x][map->robot.y] = ' ';
        map->robot.x--;
    }
}

void move_down(Map *map) {
    // Check if the robot can move down
    if (map->grid[map->robot.x+1][map->robot.y] != '#') {
        map->grid[map->robot.x][map->robot.y] = ' ';
        map->robot.x++;
    }
}

void move_left(Map *map) {
    // Check if the robot can move left
    if (map->grid[map->robot.x][map->robot.y-1] != '#') {
        map->grid[map->robot.x][map->robot.y] = ' ';
        map->robot.y--;
    }
}

void move_right(Map *map) {
    // Check if the robot can move right
    if (map->grid[map->robot.x][map->robot.y+1] != '#') {
        map->grid[map->robot.x][map->robot.y] = ' ';
        map->robot.y++;
    }
}