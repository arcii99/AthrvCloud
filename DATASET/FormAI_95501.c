//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define room dimensions
#define ROWS 10
#define COLS 10

// Define player coordinates
int playerRow = 1;
int playerCol = 1;

// Define room matrix
char room[ROWS][COLS] = {
    {'#','#','#','#','#','#','#','#','#','#'},
    {'#','.','.','.','.','.','.','.','.','#'},
    {'#','.','#','#','.','#','.','#','.','#'},
    {'#','.','.','.','.','.','.','#','.','#'},
    {'#','#','#','.','#','#','.','#','.','#'},
    {'#','.','.','.','#','.','.','.','.','#'},
    {'#','.','#','.','.','.','#','.','#','#'},
    {'#','.','.','.','#','.','.','.','.','#'},
    {'#','.','#','.','.','.','#','#','.','#'},
    {'#','#','#','#','#','#','#','#','#','#'}
};

// Define room description
char* roomDescription = "You step foot into a haunted house, your choice is to move your way through the rooms and out to safety. Beware of traps and hidden dangers or face being haunted for eternity.";

// Define function prototypes
void printRoom();
void initializeGame();
void checkMove(int moveRow, int moveCol);

int main() {
    // Seed random number generator with current time
    srand(time(NULL));
    
    // Initialize game
    initializeGame();

    // Display initial room description and layout
    printf("%s\n", roomDescription);
    printRoom();

    // Prompt player for input and continue until they reach the end
    while(room[playerRow][playerCol] != '.') {
        printf("Where would you like to move? [WASD or Q to quit]: ");
        char choice;
        scanf(" %c", &choice);

        switch(choice) {
            case 'w':
                checkMove(playerRow - 1, playerCol);
                break;

            case 'a':
                checkMove(playerRow, playerCol - 1);
                break;

            case 's':
                checkMove(playerRow + 1, playerCol);
                break;

            case 'd':
                checkMove(playerRow, playerCol + 1);
                break;

            case 'q':
                printf("Quitting game...\n");
                return 0;

            default:
                printf("Invalid choice. Please choose [WASD or Q to quit].\n");
        }

        // Display updated room
        printRoom();
    }

    // End of game message
    printf("Congratulations you make it out alive!\n");

    return 0;
}

void printRoom() {
    for(int row = 0; row < ROWS; row++) {
        for(int col = 0; col < COLS; col++) {
            if(playerRow == row && playerCol == col) {
                printf("*");
            } else {
                printf("%c", room[row][col]);
            }
        }
        printf("\n");
    }
}

void initializeGame() {
    // Place player in first room
    playerRow = 1;
    playerCol = 1;

    // Randomly place keys and traps in each room
    for(int row = 1; row < ROWS - 1; row++) {
        for(int col = 1; col < COLS - 1; col++) {
            int randNum = rand() % 10 + 1;
            if(randNum <= 2) {
                room[row][col] = 'X'; // Trap
            } else if(randNum <= 4) {
                room[row][col] = 'K'; // Key
            }
        }
    }

    // Place exit in last room
    room[ROWS - 2][COLS - 2] = '.';
}

void checkMove(int moveRow, int moveCol) {
    // Check if move is within bounds of room 
    if(moveRow >= ROWS || moveCol >= COLS || moveRow < 0 || moveCol < 0) {
        printf("You can't move outside the room.\n");
        return;
    }

    // Check what is in the room that the player wants to move to
    if(room[moveRow][moveCol] == '#') {
        printf("There's a wall blocking your path.\n");
    } else if(room[moveRow][moveCol] == 'X') {
        printf("You fell for a trap! Game over.\n");
        exit(0);
    } else if(room[moveRow][moveCol] == 'K') {
        printf("You found a key! Keep going.\n");
        room[moveRow][moveCol] = '.'; // Remove key from room
    } else {
        playerRow = moveRow;
        playerCol = moveCol;
    }
}