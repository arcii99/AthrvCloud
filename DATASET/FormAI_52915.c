//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define ROW 20
#define COL 20

char haunted_house[ROW][COL];

// Function to initialize the haunted house
void init_haunted_house() {
    int i, j;
    for (i = 0; i < ROW; i++) {
        for (j = 0; j < COL; j++) {
            haunted_house[i][j] = '#';
        }
    }
}

// Function to print the haunted house
void print_haunted_house() {
    int i, j;
    for (i = 0; i < ROW; i++) {
        for (j = 0; j < COL; j++) {
            printf("%c ", haunted_house[i][j]);
        }
        printf("\n");
    }
}

// Function to randomly place ghosts in the haunted house
void place_ghosts() {
    int i, j, num_ghosts;
    srand(time(NULL));
    num_ghosts = rand() % 10 + 1; // random number of ghosts between 1 and 10
    for (i = 0; i < num_ghosts; i++) {
        do {
            // random position for the ghosts
            j = rand() % COL;
            i = rand() % ROW;
        } while (haunted_house[i][j] != '#');
        haunted_house[i][j] = 'G'; // place the ghost
    }
}

// Function to play the game
void play_game() {
    int i, j, x, y, moves = 0;
    bool game_over = false;
    srand(time(NULL));
    // random starting position for the player
    x = rand() % COL;
    y = rand() % ROW;
    haunted_house[y][x] = 'P'; // place the player
    while (!game_over) {
        print_haunted_house();
        printf("Moves: %d\n", moves);
        printf("Enter direction (N/S/E/W): ");
        char dir;
        scanf(" %c", &dir);
        switch(dir) {
            case 'N':
                if (y > 0) {
                    if (haunted_house[y-1][x] == 'G') {
                        printf("Game Over!\n");
                        game_over = true;
                    } else {
                        haunted_house[y][x] = '#';
                        y--;
                        haunted_house[y][x] = 'P';
                        moves++;
                    }
                }
                break;
            case 'S':
                if (y < ROW-1) {
                    if (haunted_house[y+1][x] == 'G') {
                        printf("Game Over!\n");
                        game_over = true;
                    } else {
                        haunted_house[y][x] = '#';
                        y++;
                        haunted_house[y][x] = 'P';
                        moves++;
                    }
                }
                break;
            case 'E':
                if (x < COL-1) {
                    if (haunted_house[y][x+1] == 'G') {
                        printf("Game Over!\n");
                        game_over = true;
                    } else {
                        haunted_house[y][x] = '#';
                        x++;
                        haunted_house[y][x] = 'P';
                        moves++;
                    }
                }
                break;
            case 'W':
                if (x > 0) {
                    if (haunted_house[y][x-1] == 'G') {
                        printf("Game Over!\n");
                        game_over = true;
                    } else {
                        haunted_house[y][x] = '#';
                        x--;
                        haunted_house[y][x] = 'P';
                        moves++;
                    }
                }
                break;
            default:
                printf("Invalid direction\n");
                break;
        }
        // check if all ghosts have been caught
        int num_ghosts = 0;
        for (i = 0; i < ROW; i++) {
            for (j = 0; j < COL; j++) {
                if (haunted_house[i][j] == 'G') {
                    num_ghosts++;
                }
            }
        }
        if (num_ghosts == 0) {
            printf("You caught all the ghosts!\n");
            game_over = true;
        }        
    }
}

int main() {
    printf("Welcome to the Haunted House Simulator\n");
    printf("You must navigate the haunted house and catch all the ghosts\n");
    init_haunted_house();
    place_ghosts();
    play_game();
    return 0;
}