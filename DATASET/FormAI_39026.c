//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: retro
#include <stdio.h>

// Define the width and height of the remote control screen
#define SCREEN_WIDTH 40
#define SCREEN_HEIGHT 20

// Define the position of the drone
int drone_x = SCREEN_WIDTH/2;
int drone_y = SCREEN_HEIGHT/2;

// Define the position of the cursor
int cursor_x = 0;
int cursor_y = 0;

// Define the screen buffer
char screen[SCREEN_HEIGHT][SCREEN_WIDTH+1];

// Function to clear the screen
void clear_screen() {
    for (int y=0; y<SCREEN_HEIGHT; y++) {
        for (int x=0; x<SCREEN_WIDTH+1; x++) {
            screen[y][x] = ' ';
        }
    }
}

// Function to draw the screen
void draw_screen() {
    for (int y=0; y<SCREEN_HEIGHT; y++) {
        printf("%s\n", screen[y]);
    }
}

// Function to draw the drone
void draw_drone() {
    screen[drone_y][drone_x] = 'D';
}

// Function to draw the cursor
void draw_cursor() {
    screen[cursor_y][cursor_x] = '-';
}

// Function to handle the input
void handle_input(char input) {
    switch (input) {
        case 'w':
            drone_y--;
            break;
        case 'a':
            drone_x--;
            break;
        case 's':
            drone_y++;
            break;
        case 'd':
            drone_x++;
            break;
        case 'i':
            cursor_y--;
            break;
        case 'j':
            cursor_x--;
            break;
        case 'k':
            cursor_y++;
            break;
        case 'l':
            cursor_x++;
            break;
        default:
            break;
    }
}

// Main function
int main() {

    // Clear the screen
    clear_screen();

    // Draw the drone and cursor
    draw_drone();
    draw_cursor();

    // Draw the screen
    draw_screen();

    // Get input from the user
    char input;
    while (1) {
        scanf("%c", &input);

        // Handle the input
        handle_input(input);

        // Clear the screen
        clear_screen();

        // Draw the drone and cursor
        draw_drone();
        draw_cursor();

        // Draw the screen
        draw_screen();
    }

    return 0;
}