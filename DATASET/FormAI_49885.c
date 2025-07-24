//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: ultraprecise
#include <stdio.h>
#include <stdbool.h>

// Constants
#define WIDTH 100
#define HEIGHT 50
#define MAX_PLANETS 10
#define MAX_DISTANCE 100
#define MIN_DISTANCE 10

// Struct definitions
typedef struct {
    int x;
    int y;
    int radius;
} Planet;

typedef struct {
    int x;
    int y;
} Ship;

// Function declarations
void drawGalaxy(Planet[], int, Ship);
bool checkCollision(Ship, Planet[], int);
bool checkWin(Ship, Planet);

int main() {
    // Seed random number generator
    srand(time(0));

    // Initialize ship and planets
    Ship ship = {WIDTH/2, HEIGHT/2};
    Planet planets[MAX_PLANETS];
    for (int i = 0; i < MAX_PLANETS; i++) {
        planets[i].x = rand() % WIDTH;
        planets[i].y = rand() % HEIGHT;
        planets[i].radius = rand() % 5 + 5;
    }

    // Game loop
    bool gameover = false;
    int planetsVisited = 0;
    while (!gameover) {
        // Draw galaxy
        drawGalaxy(planets, MAX_PLANETS, ship);

        // Check for collision with planets
        if (checkCollision(ship, planets, MAX_PLANETS)) {
            printf("You crashed into a planet!\n");
            gameover = true;
            continue;
        }

        // Check for win condition
        if (checkWin(ship, planets[planetsVisited])) {
            printf("You have visited planet %d!\n", planetsVisited+1);
            planetsVisited++;
            if (planetsVisited == MAX_PLANETS) {
                printf("Congratulations, you have visited all planets!\n");
                gameover = true;
                continue;
            }
        }

        // Get user input and update ship position
        printf("Use arrow keys to move the ship.\n");
        char input;
        scanf(" %c", &input);
        switch (input) {
            case 'u':
                if (ship.y > 0) {
                    ship.y--;
                }
                break;
            case 'd':
                if (ship.y < HEIGHT - 1) {
                    ship.y++;
                }
                break;
            case 'l':
                if (ship.x > 0) {
                    ship.x--;
                }
                break;
            case 'r':
                if (ship.x < WIDTH - 1) {
                    ship.x++;
                }
                break;
            default:
                printf("Invalid input, try again.\n");
        }
    }

    return 0;
}

// Function definitions
void drawGalaxy(Planet planets[], int numPlanets, Ship ship) {
    char galaxy[HEIGHT][WIDTH];
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            galaxy[i][j] = ' ';
        }
    }

    // Draw planets
    for (int i = 0; i < numPlanets; i++) {
        for (int j = planets[i].y - planets[i].radius; j <= planets[i].y + planets[i].radius; j++) {
            for (int k = planets[i].x - planets[i].radius; k <= planets[i].x + planets[i].radius; k++) {
                if (j >= 0 && j < HEIGHT && k >= 0 && k < WIDTH) {
                    if ((j-planets[i].y)*(j-planets[i].y) + (k-planets[i].x)*(k-planets[i].x) <= planets[i].radius*planets[i].radius) {
                        galaxy[j][k] = '*';
                    }
                }
            }
        }
    }

    // Draw ship
    galaxy[ship.y][ship.x] = 'O';

    // Print galaxy
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            printf("%c", galaxy[i][j]);
        }
        printf("\n");
    }
}

bool checkCollision(Ship ship, Planet planets[], int numPlanets) {
    for (int i = 0; i < numPlanets; i++) {
        if ((ship.x - planets[i].x)*(ship.x - planets[i].x) + (ship.y - planets[i].y)*(ship.y - planets[i].y) <= planets[i].radius*planets[i].radius) {
            return true;
        }
    }
    return false;
}

bool checkWin(Ship ship, Planet planet) {
    return (ship.x - planet.x)*(ship.x - planet.x) + (ship.y - planet.y)*(ship.y - planet.y) <= (rand() % (MAX_DISTANCE - MIN_DISTANCE + 1)) + MIN_DISTANCE;
}