//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <termios.h>

#define BOARD_SIZE 10
#define NUM_ENEMIES 5

// Struct for player
typedef struct {
    int x;
    int y;
} Player;

// Struct for enemies
typedef struct {
    int x;
    int y;
    int active;
    pthread_t thread;
} Enemy;

// Global variables
Player player;
Enemy enemies[NUM_ENEMIES];
int score;

// Function to get user input
int getch()
{
    struct termios old, new;
    int ch;
    tcgetattr(0, &old);
    new = old;
    new.c_lflag &= ~(ICANON|ECHO);
    tcsetattr(0, TCSANOW, &new);
    ch = getchar();
    tcsetattr(0, TCSANOW, &old);
    return ch;
}

// Function to draw game board
void draw_board()
{
    system("clear");
    printf("Score: %d\n", score);
    for (int i = 0; i < BOARD_SIZE+2; i++) printf("-");
    printf("\n");
    for (int y = 0; y < BOARD_SIZE; y++) {
        printf("|");
        for (int x = 0; x < BOARD_SIZE; x++) {
            if (x == player.x && y == player.y) printf("P");
            else {
                int enemy_found = 0;
                for (int i = 0; i < NUM_ENEMIES; i++) {
                    if (enemies[i].x == x && enemies[i].y == y && enemies[i].active) {
                        printf("E");
                        enemy_found = 1;
                        break;
                    }
                }
                if (!enemy_found) printf(" ");
            }
        }
        printf("|\n");
    }
    for (int i = 0; i < BOARD_SIZE+2; i++) printf("-");
    printf("\n");
}

// Thread function for enemies
void* enemy_thread(void* arg)
{
    Enemy* enemy_ptr = (Enemy*) arg;
    while (enemy_ptr->active) {
        int rand_x = rand() % BOARD_SIZE;
        int rand_y = rand() % BOARD_SIZE;
        if (rand_x != player.x && rand_y != player.y) {
            enemy_ptr->x = rand_x;
            enemy_ptr->y = rand_y;
            usleep(500000);
        }
    }
    return NULL;
}

// Function to start enemy threads
void start_enemies()
{
    for (int i = 0; i < NUM_ENEMIES; i++) {
        enemies[i].active = 1;
        enemies[i].x = -1;
        enemies[i].y = -1;
        pthread_create(&enemies[i].thread, NULL, enemy_thread, &enemies[i]);
    }
}

// Function to stop enemy threads
void stop_enemies()
{
    for (int i = 0; i < NUM_ENEMIES; i++) {
        enemies[i].active = 0;
        pthread_join(enemies[i].thread, NULL);
    }
}

// Function to handle user input
void handle_input(char input)
{
    switch (input) {
        case 'w':
            if (player.y > 0) player.y--;
            break;
        case 'a':
            if (player.x > 0) player.x--;
            break;
        case 's':
            if (player.y < BOARD_SIZE-1) player.y++;
            break;
        case 'd':
            if (player.x < BOARD_SIZE-1) player.x++;
            break;
        default:
            break;
    }
}

// Function to check for collisions between player and enemies
void check_collisions()
{
    for (int i = 0; i < NUM_ENEMIES; i++) {
        if (enemies[i].x == player.x && enemies[i].y == player.y && enemies[i].active) {
            printf("Game over! Final score: %d\n", score);
            stop_enemies();
            exit(0);
        }
    }
}

// Main function
int main()
{
    player.x = 0;
    player.y = 0;
    score = 0;
    srand(time(NULL));
    start_enemies();
    while (1) {
        draw_board();
        char input = getch();
        handle_input(input);
        check_collisions();
        for (int i = 0; i < NUM_ENEMIES; i++) {
            if (enemies[i].x == player.x && enemies[i].y == player.y && enemies[i].active) {
                enemies[i].active = 0;
                pthread_join(enemies[i].thread, NULL);
                score++;
                pthread_create(&enemies[i].thread, NULL, enemy_thread, &enemies[i]);
            }
        }
    }
}