//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 20

char maze[ROWS][COLS] = {
    {'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'},
    {'#',' ',' ',' ','#',' ',' ',' ',' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' ','#'},
    {'#',' ','#',' ','#',' ','#','#','#',' ','#',' ','#','#','#',' ','#','#',' ','#'},
    {'#',' ','#',' ','#',' ',' ',' ','#',' ','#',' ',' ',' ','#',' ',' ',' ',' ','#'},
    {'#',' ','#',' ',' ','#','#',' ','#',' ','#',' ','#','#','#',' ','#','#','#','#'},
    {'#',' ','#','#',' ',' ',' ',' ','#',' ','#',' ',' ',' ','#',' ','#',' ',' ','#'},
    {'#',' ','#',' ','#','#','#',' ','#',' ','#','#','#','#','#',' ','#','#',' ','#'},
    {'#',' ','#',' ',' ',' ','#',' ','#',' ','#',' ',' ',' ',' ',' ',' ','#',' ','#'},
    {'#',' ','#','#',' ','#','#',' ','#',' ','#',' ','#','#','#','#','#','#',' ','#'},
    {'#',' ',' ',' ','#',' ','#',' ',' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' ','#'},
    {'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'}
};

typedef struct Position {
    int row;
    int col;
} Position;

typedef enum Direction {
    NORTH,
    SOUTH,
    EAST,
    WEST
} Direction;

// Function prototypes
void printMaze();
int canMove(Position position, Direction direction);
Direction getNextDirection(Direction direction);
int solveMaze(Position position, Direction direction);
void paranoidPrint(char* message);
void paranoidScanf(char* message, int* input);
void paranoidSleep(char* message);

int main() {
    srand(time(NULL));
    Position startPosition;
    startPosition.row = 1;
    startPosition.col = 1;
    Direction startDirection = SOUTH;
    
    paranoidPrint("Welcome to the paranoid maze solver!\n");
    paranoidPrint("You never know what lies ahead...\n");
    paranoidPrint("Loading maze...\n");
    paranoidSleep("...\n");
    printMaze();
    paranoidSleep("Starting solving algorithm...\n");
    paranoidSleep("...\n");
    int success = solveMaze(startPosition, startDirection);
    if (success) {
        paranoidPrint("Maze solved!\n");
        paranoidPrint("I told you there was nothing to worry about...\n");
    } else {
        paranoidPrint("Maze could not be solved!\n");
        paranoidPrint("What did I tell you? Always have a plan B...\n");
    }
    return 0;
}

void printMaze() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c", maze[i][j]);
        }
        printf("\n");
    }
}

int canMove(Position position, Direction direction) {
    int row = position.row;
    int col = position.col;
    switch (direction) {
        case NORTH:
            row--;
            break;
        case SOUTH:
            row++;
            break;
        case EAST:
            col++;
            break;
        case WEST:
            col--;
            break;
    }
    char next = maze[row][col];
    return (next == ' ');
}

Direction getNextDirection(Direction direction) {
    Direction next;
    do {
        int random = rand() % 4;
        switch (random) {
            case 0:
                next = NORTH;
                break;
            case 1:
                next = SOUTH;
                break;
            case 2:
                next = EAST;
                break;
            case 3:
                next = WEST;
                break;
        }
    } while (next == direction);
    return next;
}

int solveMaze(Position position, Direction direction) {
    maze[position.row][position.col] = 'o';
    int row = position.row;
    int col = position.col;
    if (row == ROWS - 2 && col == COLS - 2) {
        return 1;
    }
    paranoidSleep("...\n");
    Direction nextDirection = getNextDirection(direction);
    for (int i = 0; i < 4; i++) {
        if (canMove(position, nextDirection)) {
            switch (nextDirection) {
                case NORTH:
                    position.row--;
                    break;
                case SOUTH:
                    position.row++;
                    break;
                case EAST:
                    position.col++;
                    break;
                case WEST:
                    position.col--;
                    break;
            }
            int success = solveMaze(position, nextDirection);
            if (success) {
                return 1;
            } else {
                switch (nextDirection) {
                    case NORTH:
                        position.row++;
                        break;
                    case SOUTH:
                        position.row--;
                        break;
                    case EAST:
                        position.col--;
                        break;
                    case WEST:
                        position.col++;
                        break;
                }
            }
        }
        nextDirection = getNextDirection(direction);
    }
    maze[position.row][position.col] = ' ';
    return 0;
}

void paranoidPrint(char* message) {
    int length = 0;
    for (int i = 0; message[i] != '\0'; i++) {
        length++;
    }
    int binary[length];
    for (int i = 0; i < length; i++) {
        binary[i] = message[i];
    }
    int errorCount = rand() % (length / 5);
    if (errorCount == 0) {
        printf("%s", message);
    } else {
        for (int i = 0; i < length; i++) {
            if (rand() % (errorCount * 5) == 0) {
                printf("%d", rand() % 2);
            } else {
                printf("%c", binary[i]);
            }
        }
        printf("\n");
    }
}

void paranoidScanf(char* message, int* input) {
    printf("%s", message);
    char buffer[10];
    scanf("%s", buffer);
    int length = 0;
    for (int i = 0; buffer[i] != '\0'; i++) {
        length++;
    }
    int binary[length];
    for (int i = 0; i < length; i++) {
        binary[i] = buffer[i];
    }
    int errorCount = rand() % (length / 5);
    if (errorCount == 0) {
        *input = atoi(buffer);
    } else {
        for (int i = 0; i < length; i++) {
            if (rand() % (errorCount * 5) == 0) {
                printf("%d", rand() % 2);
            } else {
                printf("%c", binary[i]);
            }
        }
        printf("\n");
        *input = rand() % 100;
    }
    paranoidSleep("...\n");
}

void paranoidSleep(char* message) {
    int delay = rand() % 3000;
    time_t start = time(NULL);
    time_t current = start;
    while (current - start < delay) {
        printf("%c", rand() % 2 ? '.' : ',');
        fflush(stdout);
        current = time(NULL);
    }
    if (message != NULL) {
        printf("%s", message);
    }
}