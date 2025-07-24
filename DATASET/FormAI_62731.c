//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define WIDTH 50
#define HEIGHT 20

/* Define the room structure */
typedef struct Room {
    int top, left;
    int width, height;
} Room;

/* Global variables */
char map[HEIGHT][WIDTH];
Room rooms[10];
bool visited[HEIGHT][WIDTH];
int num_rooms = 0;

/* Function prototypes */
void generate_rooms();
void generate_corridors();
void generate_walls();
void print_map();

int main() {
    /* Seed the random number generator */
    srand(time(NULL));

    /* Generate the rooms and corridors */
    generate_rooms();
    generate_corridors();

    /* Generate the walls */
    generate_walls();

    /* Print the map */
    print_map();

    /* Exit the program */
    return 0;
}

/* Function to generate the rooms */
void generate_rooms() {
    /* Randomly generate rooms */
    for (int i = 0; i < 10; i++) {
        /* Get random values for the top, left, width, and height */
        int top = rand() % (HEIGHT - 6) + 3;
        int left = rand() % (WIDTH - 16) + 3;
        int width = rand() % 4 + 4;
        int height = rand() % 4 + 4;

        /* Check if the room overlaps with any other room */
        bool overlap = false;
        for (int j = 0; j < num_rooms; j++) {
            Room r = rooms[j];
            if (top < r.top + r.height && top + height > r.top && left < r.left + r.width && left + width > r.left) {
                overlap = true;
                break;
            }
        }

        /* Create the room if there is no overlap */
        if (!overlap) {
            Room room = { top, left, width, height };
            rooms[num_rooms++] = room;

            /* Mark the room as visited */
            for (int x = left; x < left + width; x++) {
                for (int y = top; y < top + height; y++) {
                    visited[y][x] = true;
                    map[y][x] = '.';
                }
            }
        }
    }
}

/* Function to generate the corridors */
void generate_corridors() {
    /* Generate a corridor between each adjacent room */
    for (int i = 0; i < num_rooms - 1; i++) {
        Room r1 = rooms[i];
        Room r2 = rooms[i + 1];

        int x = r1.left + r1.width / 2;
        int y = r1.top + r1.height / 2;

        /* Move to the second room horizontally */
        while (x != r2.left + r2.width / 2) {
            if (!visited[y][x]) {
                visited[y][x] = true;
                map[y][x] = '.';
            }
            if (x < r2.left + r2.width / 2) {
                x++;
            } else {
                x--;
            }
        }

        /* Move to the second room vertically */
        while (y != r2.top + r2.height / 2) {
            if (!visited[y][x]) {
                visited[y][x] = true;
                map[y][x] = '.';
            }
            if (y < r2.top + r2.height / 2) {
                y++;
            } else {
                y--;
            }
        }
    }
}

/* Function to generate the walls */
void generate_walls() {
    /* Generate walls around the edge of the map */
    for (int x = 0; x < WIDTH; x++) {
        visited[0][x] = true;
        visited[HEIGHT - 1][x] = true;
        map[0][x] = '#';
        map[HEIGHT - 1][x] = '#';
    }
    for (int y = 0; y < HEIGHT; y++) {
        visited[y][0] = true;
        visited[y][WIDTH - 1] = true;
        map[y][0] = '#';
        map[y][WIDTH - 1] = '#';
    }

    /* Generate walls around each room */
    for (int i = 0; i < num_rooms; i++) {
        Room r = rooms[i];

        for (int x = r.left - 1; x <= r.left + r.width; x++) {
            if (!visited[r.top - 1][x]) {
                visited[r.top - 1][x] = true;
                map[r.top - 1][x] = '#';
            }
            if (!visited[r.top + r.height][x]) {
                visited[r.top + r.height][x] = true;
                map[r.top + r.height][x] = '#';
            }
        }
        for (int y = r.top - 1; y <= r.top + r.height; y++) {
            if (!visited[y][r.left - 1]) {
                visited[y][r.left - 1] = true;
                map[y][r.left - 1] = '#';
            }
            if (!visited[y][r.left + r.width]) {
                visited[y][r.left + r.width] = true;
                map[y][r.left + r.width] = '#';
            }
        }
    }
}

/* Function to print the map */
void print_map() {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            printf("%c", map[y][x]);
        }
        printf("\n");
    }
}