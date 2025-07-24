//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GRID_SIZE 10
#define NUM_PLAYERS 2
#define MAX_MOVES 20

typedef struct {
    int x, y;
} Coordinate;

typedef struct {
    int num_moves;
    Coordinate pos;
} Player;

void print_grid(char grid[][GRID_SIZE])
{
    printf("\n");
    for(int i = 0; i < GRID_SIZE; i++) {
        for(int j = 0; j < GRID_SIZE; j++) {
            printf("%c ", grid[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int is_valid_move(Coordinate dest, char grid[][GRID_SIZE])
{
    if(dest.x >= 0 && dest.x < GRID_SIZE && dest.y >= 0 && dest.y < GRID_SIZE) {
        if(grid[dest.x][dest.y] == '-') {
            return 1;
        }
    }
    return 0;
}

void make_move(Player *player, Coordinate dest, char grid[][GRID_SIZE])
{
    grid[player->pos.x][player->pos.y] = '-';
    player->pos = dest;
    grid[dest.x][dest.y] = 'P';
    player->num_moves++;
}

int main()
{
    char grid[GRID_SIZE][GRID_SIZE];
    Player players[NUM_PLAYERS];
    srand(time(NULL));
    Coordinate gps_destination;
    
    // Initialize grid and players
    for(int i = 0; i < GRID_SIZE; i++) {
        for(int j = 0; j < GRID_SIZE; j++) {
            grid[i][j] = '-';
        }
    }
    for(int i = 0; i < NUM_PLAYERS; i++) {
        players[i].pos.x = rand() % GRID_SIZE;
        players[i].pos.y = rand() % GRID_SIZE;
        players[i].num_moves = 0;
        grid[players[i].pos.x][players[i].pos.y] = 'P';
    }
    
    // Choose GPS destination and print initial grid
    gps_destination.x = rand() % GRID_SIZE;
    gps_destination.y = rand() % GRID_SIZE;
    grid[gps_destination.x][gps_destination.y] = 'D';
    printf("GPS destination: (%d, %d)\n", gps_destination.x, gps_destination.y);
    print_grid(grid);
    
    // Start game loop until max moves or someone reaches destination
    for(int i = 0; i < MAX_MOVES; i++) {
        for(int j = 0; j < NUM_PLAYERS; j++) {
            // Choose random move for each player
            Coordinate dest;
            dest.x = players[j].pos.x + (rand() % 3) - 1;  // Random number between -1 and 1
            dest.y = players[j].pos.y + (rand() % 3) - 1;
            while(!is_valid_move(dest, grid)) {
                dest.x = players[j].pos.x + (rand() % 3) - 1; 
                dest.y = players[j].pos.y + (rand() % 3) - 1;
            }
            make_move(&players[j], dest, grid);
            
            // Check if player reached destination
            if(players[j].pos.x == gps_destination.x && players[j].pos.y == gps_destination.y) {
                printf("Player %d wins!\n", j + 1);
                print_grid(grid);
                return 0;
            }
        }
        print_grid(grid);
    }
    printf("Maximum moves reached. No winner.\n");
    print_grid(grid);
    return 0;
}