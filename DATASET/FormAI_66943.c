//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 10
#define HEIGHT 10
#define PIXEL_SIZE 2
#define MAX_PLAYERS 5

// Struct to represent a pixel on the screen
typedef struct Pixel {
    char colors[3];
} Pixel;

// Struct to represent a player's position and color
typedef struct Player {
    int x;
    int y;
    char color[3];
} Player;

// Function to generate a random color for a player
void generate_random_color(char color[3]) {
    for (int i = 0; i < 3; i++) {
        color[i] = rand() % 256;
    }
}

// Function to initialize the screen with 10x10 black pixels
void initialize_screen(Pixel screen[HEIGHT][WIDTH]) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            screen[i][j].colors[0] = screen[i][j].colors[1] = screen[i][j].colors[2] = 0;
        }
    }
}

// Function to draw a pixel on the screen
void draw_pixel(Pixel screen[HEIGHT][WIDTH], int x, int y, char color[3]) {
    if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT) {
        screen[y][x].colors[0] = color[0];
        screen[y][x].colors[1] = color[1];
        screen[y][x].colors[2] = color[2];
    }
}

// Function to print the screen to the console
void print_screen(Pixel screen[HEIGHT][WIDTH]) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            for (int k = 0; k < PIXEL_SIZE; k++) {
                for (int l = 0; l < PIXEL_SIZE; l++) {
                    printf("\033[48;2;%d;%d;%dm  ", screen[i][j].colors[0], screen[i][j].colors[1], screen[i][j].colors[2]);
                }
            }
        }
        printf("\033[0m\n");
    }
}

int main() {
    srand(time(NULL));
    Pixel screen[HEIGHT][WIDTH];
    Player players[MAX_PLAYERS];
    int num_players = 0;

    // Initialize the screen
    initialize_screen(screen);

    // Prompt the user to enter the number of players
    printf("Enter the number of players (up to %d): ", MAX_PLAYERS);
    scanf("%d", &num_players);

    // Generate random colors for each player and draw their starting positions on the screen
    for (int i = 0; i < num_players; i++) {
        generate_random_color(players[i].color);
        players[i].x = rand() % WIDTH;
        players[i].y = rand() % HEIGHT;
        draw_pixel(screen, players[i].x, players[i].y, players[i].color);
    }

    // Print the initial screen
    print_screen(screen);

    // Main game loop
    char input;
    do {
        // Ask each player to move
        for (int i = 0; i < num_players; i++) {
            printf("Player %d: Use WASD to move\n", i + 1);
            scanf("\n%c", &input);
            switch (input) {
                case 'w':
                    draw_pixel(screen, players[i].x, players[i].y, (char[3]) {0, 0, 0});
                    players[i].y--;
                    draw_pixel(screen, players[i].x, players[i].y, players[i].color);
                    break;
                case 'a':
                    draw_pixel(screen, players[i].x, players[i].y, (char[3]) {0, 0, 0});
                    players[i].x--;
                    draw_pixel(screen, players[i].x, players[i].y, players[i].color);
                    break;
                case 's':
                    draw_pixel(screen, players[i].x, players[i].y, (char[3]) {0, 0, 0});
                    players[i].y++;
                    draw_pixel(screen, players[i].x, players[i].y, players[i].color);
                    break;
                case 'd':
                    draw_pixel(screen, players[i].x, players[i].y, (char[3]) {0, 0, 0});
                    players[i].x++;
                    draw_pixel(screen, players[i].x, players[i].y, players[i].color);
                    break;
                default:
                    printf("Invalid input\n");
                    break;
            }
        }

        // Print the updated screen
        printf("\033[H\033[J");
        print_screen(screen);

    } while (1);

    return 0;
}