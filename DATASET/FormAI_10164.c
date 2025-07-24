//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_X 100
#define MAX_Y 100

char space_map[MAX_X][MAX_Y];

// Function to randomly place space objects on the map
void place_objects() {
    srand(time(NULL));
    int obstacles = MAX_X * MAX_Y / 10;
    int x, y;
    for(int i=0; i<obstacles; i++) {
        x = rand() % MAX_X;
        y = rand() % MAX_Y;
        space_map[x][y] = '#';
    }
}

// Function to display the current state of the space map
void display_map() {
    for(int i=0; i<MAX_X; i++) {
        for(int j=0; j<MAX_Y; j++) {
            printf("%c", space_map[i][j]);
        }
        printf("\n");
    }
}

// Function to move the player's spaceship
void move_spaceship(int x, int y) {
    if(x<0 || y<0 || x>=MAX_X || y>=MAX_Y) {
        printf("Invalid move! You crashed into a planet!\n");
        exit(0);
    }
    if(space_map[x][y] == '#') {
        printf("Oops! You hit an obstacle. Game over!\n");
        exit(0);
    }
    space_map[x][y] = '-';
    printf("Spaceship moved to (%d,%d)\n", x, y);
}

// Function to check if the player has reached the destination
int check_win(int x, int y) {
    if(x == MAX_X-1 && y == MAX_Y-1) {
        printf("Congratulations! You have reached your destination.\n");
        return 1;
    }
    return 0;
}

int main() {
    // Initialize the space map
    for(int i=0; i<MAX_X; i++) {
        for(int j=0; j<MAX_Y; j++) {
            space_map[i][j] = ' ';
        }
    }
    place_objects();
    
    // Initialize the player's spaceship
    int curr_x = 0, curr_y = 0;
    space_map[curr_x][curr_y] = 'S';
    
    // Display the initial state of the space map
    display_map();
    
    // Prompt the user to make moves until they reach the destination
    int game_over = 0;
    char move;
    while(!game_over) {
        printf("Enter your next move (U/D/L/R): ");
        scanf(" %c", &move);
        if(move == 'U') {
            curr_x--;
            move_spaceship(curr_x, curr_y);
        }
        else if(move == 'D') {
            curr_x++;
            move_spaceship(curr_x, curr_y);
        }
        else if(move == 'L') {
            curr_y--;
            move_spaceship(curr_x, curr_y);
        }
        else if(move == 'R') {
            curr_y++;
            move_spaceship(curr_x, curr_y);
        }
        else {
            printf("Invalid move!\n");
        }
        game_over = check_win(curr_x, curr_y);
        display_map();
    }
    
    return 0;
}