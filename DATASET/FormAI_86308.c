//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define GRID_SIZE 10 // Define Grid Size
#define NUM_OBSTACLES 5 // Define number of obstacles
#define MOVEMENT_LIMIT 20 // Define Movement limit

char grid[GRID_SIZE][GRID_SIZE]; // Initialize Grid

typedef struct {
    int x, y; // Vehicle's current location
    int moves_left; // Number of moves left
    bool has_reached_goal; // Check if goal is reached
} vehicle;

typedef struct {
    int x, y; // Obstacle's location
} obstacle;

vehicle v; // Initialize Vehicle

obstacle obstacles[NUM_OBSTACLES]; // Initialize Obstacles

int get_random(int min, int max) 
{
    return min + rand() % (max - min + 1);
}

void initialize_obstacles()
{
    for(int i = 0; i < NUM_OBSTACLES; i++) {
        int x = get_random(0, GRID_SIZE-1);
        int y = get_random(0, GRID_SIZE-1);

        obstacles[i].x = x;
        obstacles[i].y = y;

        grid[x][y] = 'O';
    }
}

void print_grid()
{
    for(int i = 0; i < GRID_SIZE; i++) {
        for(int j = 0; j < GRID_SIZE; j++) {
            printf("%c ", grid[i][j]);
        }
        printf("\n");
    }
}

bool is_obstacle(int x, int y)
{
    for(int i = 0; i < NUM_OBSTACLES; i++) {
        if(obstacles[i].x == x && obstacles[i].y == y)
            return true;
    }

    return false;
}

void move_vehicle_up()
{
    if(v.x <= 0) {
        v.moves_left--; // Reduce move if boundary is reached
        return;
    }
    
    v.x--;
    v.moves_left--;

    if(is_obstacle(v.x, v.y)) {
        v.x++; // Revert move
        v.moves_left--; // Reduce move if obstacle is in the way
    }

    grid[v.x][v.y] = 'V';
}

void move_vehicle_down()
{
    if(v.x >= GRID_SIZE-1) {
        v.moves_left--; // Reduce move if boundary is reached
        return;
    }
    
    v.x++;
    v.moves_left--;

    if(is_obstacle(v.x, v.y)) {
        v.x--; // Revert move
        v.moves_left--; // Reduce move if obstacle is in the way
    }

    grid[v.x][v.y] = 'V';
}

void move_vehicle_left()
{
    if(v.y <= 0) {
        v.moves_left--; // Reduce move if boundary is reached
        return;
    }
    
    v.y--;
    v.moves_left--;

    if(is_obstacle(v.x, v.y)) { 
        v.y++; // Revert move
        v.moves_left--; // Reduce move if obstacle is in the way
    }

    grid[v.x][v.y] = 'V';
}

void move_vehicle_right()
{
    if(v.y >= GRID_SIZE-1) {
        v.moves_left--; // Reduce move if boundary is reached
        return;
    }
    
    v.y++;
    v.moves_left--;

    if(is_obstacle(v.x, v.y)) {
        v.y--; // Revert move
        v.moves_left--; // Reduce move if obstacle is in the way
    }

    grid[v.x][v.y] = 'V';
}

bool has_reached_goal()
{
    return v.has_reached_goal;
}

void set_goal()
{
    int x = get_random(0, GRID_SIZE-1);
    int y = get_random(0, GRID_SIZE-1);

    grid[x][y] = 'G';
}

void initialize_vehicle()
{
    v.x = get_random(0, GRID_SIZE-1);
    v.y = get_random(0, GRID_SIZE-1);
    v.moves_left = MOVEMENT_LIMIT;
    v.has_reached_goal = false;

    grid[v.x][v.y] = 'V';
}

void run_game()
{
    set_goal();
    initialize_vehicle();
    initialize_obstacles();
    
    while(v.moves_left > 0 && !has_reached_goal()) {
        print_grid();

        printf("Moves left: %d\n1. Move Up\n2. Move Down\n3. Move Left\n4. Move Right\nEnter your choice: ", v.moves_left);
        int choice;
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                move_vehicle_up();
                break;
            case 2:
                move_vehicle_down();
                break;
            case 3:
                move_vehicle_left();
                break;
            case 4:
                move_vehicle_right();
                break;
            default:
                printf("Invalid choice!\n");
                break;
        }

        if(grid[v.x][v.y] == 'G') {
            v.has_reached_goal = true;
            printf("You reached the goal!\n");
            print_grid();
            return;
        }

        system("clear"); // Clear console
    }

    printf("You're out of moves!\n");
}

int main()
{
    srand(time(NULL)); // Initialize random seed

    run_game();

    return 0;
}