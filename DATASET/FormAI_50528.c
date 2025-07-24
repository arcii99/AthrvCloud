//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Constants
#define WIDTH 20
#define HEIGHT 10
#define MAX_ROOMS 5
#define MAX_ROOM_WIDTH 5
#define MAX_ROOM_HEIGHT 5
#define PLAYER_CHAR '@'
#define WALL_CHAR '#'
#define FLOOR_CHAR '.'
#define DOOR_CHAR '+'

// Structures
typedef struct {
    int x, y, w, h;
} Room;

typedef struct {
    int x, y;
} Point;

// Function declarations
void initialize_board(char board[HEIGHT][WIDTH]);
void print_board(char board[HEIGHT][WIDTH]);
void generate_rooms(Room rooms[MAX_ROOMS]);
int is_collision(Room r1, Room r2);
void add_room_to_board(Room r, char board[HEIGHT][WIDTH]);
void add_corridors_between_rooms(Room rooms[MAX_ROOMS], char board[HEIGHT][WIDTH]);
void place_player(char board[HEIGHT][WIDTH], Point *player);
Point get_random_valid_move(char board[HEIGHT][WIDTH], Point p);
void move_player(char board[HEIGHT][WIDTH], Point *player, Point target_point);

// Game variables
char board[HEIGHT][WIDTH];
Point player;

int main() {
    // Initialize the random number generator
    srand(time(NULL));

    // Initialize the game board
    initialize_board(board);

    // Generate the rooms
    Room rooms[MAX_ROOMS];
    generate_rooms(rooms);

    // Add the rooms and corridors to the board
    for (int i = 0; i < MAX_ROOMS; i++) {
        add_room_to_board(rooms[i], board);
    }
    add_corridors_between_rooms(rooms, board);

    // Place the player
    place_player(board, &player);

    // Main game loop
    char input;
    Point target_point;
    while (1) {
        // Print the board
        print_board(board);

        // Get user input
        printf("Enter a direction (w/a/s/d): ");
        scanf(" %c", &input);

        // Calculate the target point
        switch (input) {
            case 'w':
                target_point = (Point) {player.x, player.y - 1};
                break;
            case 'a':
                target_point = (Point) {player.x - 1, player.y};
                break;
            case 's':
                target_point = (Point) {player.x, player.y + 1};
                break;
            case 'd':
                target_point = (Point) {player.x + 1, player.y};
                break;
            default:
                printf("Invalid input\n");
                continue;
        }

        // Check if the move is valid
        if (target_point.x < 0 || target_point.x >= WIDTH || target_point.y < 0 || target_point.y >= HEIGHT) {
            printf("Invalid move\n");
            continue;
        }

        if (board[target_point.y][target_point.x] == WALL_CHAR) {
            printf("You hit a wall\n");
            continue;
        }

        // Move the player
        move_player(board, &player, target_point);

        // Check for win
        if (board[player.y][player.x] == DOOR_CHAR) {
            printf("Congratulations, you found the exit!\n");
            break;
        }
    }

    return 0;
}

void initialize_board(char board[HEIGHT][WIDTH]) {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            board[y][x] = WALL_CHAR;
        }
    }
}

void print_board(char board[HEIGHT][WIDTH]) {
    printf("\n");
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            if (x == player.x && y == player.y) {
                printf("%c ", PLAYER_CHAR);
            } else {
                printf("%c ", board[y][x]);
            }
        }
        printf("\n");
    }
}

void generate_rooms(Room rooms[MAX_ROOMS]) {
    for (int i = 0; i < MAX_ROOMS; i++) {
        // Pick a random position and size for the room
        Room r = {
            .x = rand() % (WIDTH - MAX_ROOM_WIDTH - 1) + 1,
            .y = rand() % (HEIGHT - MAX_ROOM_HEIGHT - 1) + 1,
            .w = rand() % MAX_ROOM_WIDTH + 2,
            .h = rand() % MAX_ROOM_HEIGHT + 2
        };

        // Check if the room collides with any existing rooms
        int collided = 0;
        for (int j = 0; j < i; j++) {
            if (is_collision(r, rooms[j])) {
                collided = 1;
                break;
            }
        }

        if (!collided) {
            rooms[i] = r;
        }
    }
}

int is_collision(Room r1, Room r2) {
    // Check if the rectangles overlap
    if (r1.x + r1.w < r2.x || r1.x > r2.x + r2.w || r1.y + r1.h < r2.y || r1.y > r2.y + r2.h) {
        return 0;
    }

    return 1;
}

void add_room_to_board(Room r, char board[HEIGHT][WIDTH]) {
    // Add the floor tiles
    for (int y = r.y; y < r.y + r.h; y++) {
        for (int x = r.x; x < r.x + r.w; x++) {
            board[y][x] = FLOOR_CHAR;
        }
    }

    // Add the walls
    for (int y = r.y - 1; y <= r.y + r.h; y++) {
        board[y][r.x - 1] = WALL_CHAR;
        board[y][r.x + r.w] = WALL_CHAR;
    }

    for (int x = r.x - 1; x <= r.x + r.w; x++) {
        board[r.y - 1][x] = WALL_CHAR;
        board[r.y + r.h][x] = WALL_CHAR;
    }

    // Add the door
    int dir = rand() % 4;
    int door_x, door_y;
    switch (dir) {
        case 0: // North
            door_x = rand() % r.w + r.x;
            door_y = r.y - 1;
            break;
        case 1: // South
            door_x = rand() % r.w + r.x;
            door_y = r.y + r.h;
            break;
        case 2: // West
            door_x = r.x - 1;
            door_y = rand() % r.h + r.y;
            break;
        case 3: // East
            door_x = r.x + r.w;
            door_y = rand() % r.h + r.y;
            break;
    }

    board[door_y][door_x] = DOOR_CHAR;
}

void add_corridors_between_rooms(Room rooms[MAX_ROOMS], char board[HEIGHT][WIDTH]) {
    // Sort the rooms from left to right
    for (int i = 0; i < MAX_ROOMS - 1; i++) {
        for (int j = i + 1; j < MAX_ROOMS; j++) {
            if (rooms[i].x > rooms[j].x) {
                Room tmp = rooms[i];
                rooms[i] = rooms[j];
                rooms[j] = tmp;
            }
        }
    }

    // Add the corridors
    for (int i = 0; i < MAX_ROOMS - 1; i++) {
        int x1 = rooms[i].x + rand() % rooms[i].w;
        int y1 = rooms[i].y + rand() % rooms[i].h;
        int x2 = rooms[i+1].x + rand() % rooms[i+1].w;
        int y2 = rooms[i+1].y + rand() % rooms[i+1].h;

        // Add the horizontal corridor
        for (int x = x1; x <= x2; x++) {
            if (board[y1][x] == WALL_CHAR) {
                board[y1][x] = FLOOR_CHAR;
            }
        }

        // Add the vertical corridor
        for (int y = y1; y <= y2; y++) {
            if (board[y][x2] == WALL_CHAR) {
                board[y][x2] = FLOOR_CHAR;
            }
        }
    }
}

void place_player(char board[HEIGHT][WIDTH], Point *player) {
    while (1) {
        int x = rand() % WIDTH;
        int y = rand() % HEIGHT;
        if (board[y][x] == FLOOR_CHAR) {
            player->x = x;
            player->y = y;
            return;
        }
    }
}

Point get_random_valid_move(char board[HEIGHT][WIDTH], Point p) {
    while (1) {
        int dir = rand() % 4;
        Point np;
        switch(dir) {
            case 0: // North
                np.x = p.x;
                np.y = p.y - 1;
                break;
            case 1: // South
                np.x = p.x;
                np.y = p.y + 1;
                break;
            case 2: // West
                np.x = p.x - 1;
                np.y = p.y;
                break;
            case 3: // East
                np.x = p.x + 1;
                np.y = p.y;
                break;
        }

        if (np.x < 0 || np.x >= WIDTH || np.y < 0 || np.y >= HEIGHT) {
            continue;
        }

        if (board[np.y][np.x] != WALL_CHAR) {
            return np;
        }
    }
}

void move_player(char board[HEIGHT][WIDTH], Point *player, Point target_point) {
    // Move the player to the target point
    player->x = target_point.x;
    player->y = target_point.y;

    // Move any monsters in the vicinity
    for (int i = 0; i < 5; i++) {
        Point m = get_random_valid_move(board, *player);
        if (m.x == player->x && m.y == player->y) {
            printf("You were attacked by a monster!\n");
        }
    }
}