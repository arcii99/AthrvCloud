//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define size of remote control
#define ROWS 5
#define COLS 5

// Define custom data types
typedef struct {
    int x;
    int y;
} Coord;

typedef struct {
    char id;
    Coord pos;
} Button;

// Define global variables
Button buttons[ROWS][COLS];
Coord currentPos = {0, 0};

// Function declarations
void initButtons();
void printButtons();
void handleInput(char input[10]);
void move(char direction);
void pressButton(Button button);

int main() {
    char input[10];

    // Initialize the buttons
    initButtons();

    // Print the buttons
    printButtons();

    // Wait for input
    while (1) {
        printf("Enter command: ");
        fgets(input, 10, stdin);
        handleInput(input);
    }

    return 0;
}

void initButtons() {
    // Initialize the buttons
    char id = 'A';
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            buttons[i][j].id = id++;
            buttons[i][j].pos.x = i;
            buttons[i][j].pos.y = j;
        }
    }

    // Set the initial position of the remote to the center button
    currentPos.x = ROWS / 2;
    currentPos.y = COLS / 2;
}

void printButtons() {
    printf("Remote control layout:\n");
    printf("+---+---+---+---+---+\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("| %c ", buttons[i][j].id);
        }
        printf("|\n");
        printf("+---+---+---+---+---+\n");
    }
}

void handleInput(char input[10]) {
    char command = input[0];

    if (command == 'Q') {
        exit(0);
    } else if (command == 'U' || command == 'D' || command == 'L' || command == 'R') {
        move(command);
    } else if (command >= 'A' && command <= 'Z') {
        Button button = buttons[currentPos.x][currentPos.y];
        if (button.id == command) {
            printf("Button %c is already pressed\n", command);
        } else {
            pressButton(buttons[button.pos.x][button.pos.y]);
        }
    } else {
        printf("Invalid command. Use U, D, L, R or a button ID (A-Z)\n");
    }
}

void move(char direction) {
    switch (direction) {
        case 'U':
            if (currentPos.x > 0) {
                currentPos.x--;
            }
            break;
        case 'D':
            if (currentPos.x < ROWS - 1) {
                currentPos.x++;
            }
            break;
        case 'L':
            if (currentPos.y > 0) {
                currentPos.y--;
            }
            break;
        case 'R':
            if (currentPos.y < COLS - 1) {
                currentPos.y++;
            }
            break;
    }

    printf("Moved %c. Current position: %c\n", direction, buttons[currentPos.x][currentPos.y].id);
}

void pressButton(Button button) {
    printf("Pressed button %c\n", button.id);
}