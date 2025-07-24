//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

// Function prototypes
void displayMenu();
int getVehicleSize();
void generateRandomMap(char map[][50], int rows, int cols);
void displayMap(char map[][50], int rows, int cols);
void updatePosition(char input, char map[][50], int *row, int *col);
bool checkWinningPosition(char map[][50], int row, int col);

int main() {
    // Initialize the map and vehicle position
    char map[10][50];
    int vehicleRow, vehicleCol;
    generateRandomMap(map, 10, 50);
    vehicleRow = 5;
    vehicleCol = 5;

    // Start the game loop
    bool gameOver = false;
    while (!gameOver) {
        // Display the menu and get user input
        displayMenu();
        char input;
        scanf(" %c", &input);

        // Update the vehicle position based on user input
        updatePosition(input, map, &vehicleRow, &vehicleCol);

        // Check if the vehicle is on a winning position
        gameOver = checkWinningPosition(map, vehicleRow, vehicleCol);

        // Display the updated map
        system("clear"); // Clear the console screen
        displayMap(map, 10, 50);
    }

    printf("Congratulations, you have reached the winning position!\n");

    return 0;
}

void displayMenu() {
    printf("Use the arrow keys to move the vehicle:\n");
    printf("Up    - w\n");
    printf("Left  - a\n");
    printf("Down  - s\n");
    printf("Right - d\n");
}

int getVehicleSize() {
    int size;
    printf("Enter the size of the vehicle (1-5): ");
    scanf("%d", &size);
    if (size < 1 || size > 5) {
        printf("Invalid vehicle size. Please try again.\n");
        return getVehicleSize();
    }
    return size;
}

void generateRandomMap(char map[][50], int rows, int cols) {
    // Set all positions to empty
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            map[i][j] = ' ';
        }
    }

    // Generate random obstacles
    srand(time(NULL));
    int numObstacles = rand() % 10 + 5;
    for (int i = 0; i < numObstacles; i++) {
        int row = rand() % 10;
        int col = rand() % 50;
        map[row][col] = '#';
    }

    // Generate random goal position
    int goalRow = rand() % 10;
    int goalCol = rand() % 50;
    map[goalRow][goalCol] = 'G';

    // Generate random vehicle position
    int vehicleSize = getVehicleSize();
    int vehicleOrientation = rand() % 2;
    if (vehicleOrientation == 0) { // Horizontal
        while (true) {
            int row = rand() % 10;
            int col = rand() % (50 - vehicleSize + 1);
            bool isValid = true;
            for (int i = 0; i < vehicleSize; i++) {
                if (map[row][col+i] == '#' || map[row][col+i] == 'G') {
                    isValid = false;
                    break;
                }
            }
            if (isValid) {
                for (int i = 0; i < vehicleSize; i++) {
                    map[row][col+i] = 'V';
                }
                break;
            }
        }
    } else { // Vertical
        while (true) {
            int row = rand() % (10 - vehicleSize + 1);
            int col = rand() % 50;
            bool isValid = true;
            for (int i = 0; i < vehicleSize; i++) {
                if (map[row+i][col] == '#' || map[row+i][col] == 'G') {
                    isValid = false;
                    break;
                }
            }
            if (isValid) {
                for (int i = 0; i < vehicleSize; i++) {
                    map[row+i][col] = 'V';
                }
                break;
            }
        }
    }
}

void displayMap(char map[][50], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%c", map[i][j]);
        }
        printf("\n");
    }
}

void updatePosition(char input, char map[][50], int *row, int *col) {
    switch (input) {
        case 'w':
            if (*row > 0 && map[*row-1][*col] != '#') {
                map[*row][*col] = ' ';
                (*row)--;
                map[*row][*col] = 'V';
            }
            break;
        case 'a':
            if (*col > 0 && map[*row][*col-1] != '#') {
                map[*row][*col] = ' ';
                (*col)--;
                map[*row][*col] = 'V';
            }
            break;
        case 's':
            if (*row < 9 && map[*row+1][*col] != '#') {
                map[*row][*col] = ' ';
                (*row)++;
                map[*row][*col] = 'V';
            }
            break;
        case 'd':
            if (*col < 49 && map[*row][*col+1] != '#') {
                map[*row][*col] = ' ';
                (*col)++;
                map[*row][*col] = 'V';
            }
            break;
        default:
            printf("Invalid input. Please try again.\n");
    }
}

bool checkWinningPosition(char map[][50], int row, int col) {
    if (map[row][col] == 'G') {
        return true;
    }
    return false;
}