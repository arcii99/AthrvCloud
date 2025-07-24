//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 80
#define HEIGHT 24

int level = 1;
int player_x = 0, player_y = 0;

char map[HEIGHT][WIDTH];

void create_map();
void print_map();
void move_player(int dx, int dy);

int main() {
    srand(time(NULL)); // seed the random number generator

    for (;;) { // infinite game loop
        create_map();
        print_map();

        for (;;) { // infinite player input loop
            char c = getchar();

            switch (c) {
                case 'w': move_player(0, -1); break; // move up
                case 'a': move_player(-1, 0); break; // move left
                case 's': move_player(0, 1); break; // move down
                case 'd': move_player(1, 0); break; // move right
                default: continue; // ignore other input
            }

            print_map();

            if (player_x == WIDTH - 1 && player_y == HEIGHT - 1) { // the player has reached the end
                printf("You have completed level %d!\n", level++);
                getchar(); // wait for user input
                break; // exit player input loop and generate a new map
            }
        }
    }

    return 0;
}

void create_map() {
    int i, j;

    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            if (i == 0 || j == 0 || i == HEIGHT - 1 || j == WIDTH - 1) { // set boundaries
                map[i][j] = '#';
            } else {
                if (rand() % 10 == 0) { // set random walls
                    map[i][j] = '#';
                } else {
                    map[i][j] = '.';
                }
            }
        }
    }

    player_x = rand() % (WIDTH - 2) + 1; // set random player position
    player_y = rand() % (HEIGHT - 2) + 1;
    map[player_y][player_x] = '@'; // place player symbol

    map[HEIGHT - 2][WIDTH - 2] = 'X'; // place exit symbol
}

void print_map() {
    system("clear"); // clear the console

    int i, j;

    printf("Level: %d\n", level);

    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            printf("%c", map[i][j]);
        }

        printf("\n");
    }
}

void move_player(int dx, int dy) {
    if (map[player_y + dy][player_x + dx] == '.') { // check if the destination is empty
        map[player_y][player_x] = '.'; // clear the current position
        player_x += dx; // move the player
        player_y += dy;
        map[player_y][player_x] = '@'; // update the new position
    }
}