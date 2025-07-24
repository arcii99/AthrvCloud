//FormAI DATASET v1.0 Category: Space Invaders Game Clone ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <pthread.h>

#define BOARD_WIDTH 20
#define BOARD_HEIGHT 20
#define ALIEN_ROWS 5
#define ALIEN_COLS 10
#define UFO_SCORE 100
#define INVADER_SCORE 10

// Global variables
int board[BOARD_HEIGHT][BOARD_WIDTH]; // board representation
int player_pos = BOARD_WIDTH/2-1; // player initial position
int player_score = 0; // player score
int alien_speed = 1000000; // speed of alien movement
int game_over = 0; // flag indicating game over
pthread_mutex_t board_mutex; // mutex protecting board access

// Generate a random number between a and b
int random_between(int a, int b) {
    return rand() % (b-a+1) + a;
}

// Initialize the board with aliens
void init_board() {
    // Fill board with empty spaces
    for (int i=0; i<BOARD_HEIGHT; i++)
        for (int j=0; j<BOARD_WIDTH; j++)
            board[i][j] = ' ';

    // Place aliens
    for (int i=0; i<ALIEN_ROWS; i++)
        for (int j=0; j<ALIEN_COLS; j++)
            board[i][j*2] = 'A';
}

// Print the board
void print_board() {
    // Clear screen
    system("clear");

    // Print board
    for (int i=0; i<BOARD_HEIGHT; i++) {
        for (int j=0; j<BOARD_WIDTH; j++)
            printf("%c", board[i][j]);
        printf("\n");
    }

    // Print score
    printf("Score: %d\n", player_score);
}

// Move aliens
void* move_aliens() {
    while (!game_over) {
        // Move aliens down
        for (int i=BOARD_HEIGHT-1; i>=0; i--)
            for (int j=0; j<BOARD_WIDTH; j++)
                if (board[i][j] == 'A') {
                    // Check if aliens reach the bottom
                    if (i == BOARD_HEIGHT-1) {
                        game_over = 1;
                        return NULL;
                    }

                    // Move alien down
                    board[i][j] = ' ';
                    board[i+1][j] = 'A';
                }
        
        // Move aliens left or right
        if (random_between(0, 1) == 0) {
            // Move aliens left
            for (int j=0; j<BOARD_WIDTH-2; j+=2) {
                int empty_column = 1;
                for (int i=0; i<BOARD_HEIGHT; i++)
                    if (board[i][j] == 'A') {
                        empty_column = 0;
                        break;
                    }
                if (!empty_column) // cannot move aliens left
                    break;
                for (int i=0; i<BOARD_HEIGHT; i++) {
                    board[i][j] = ' ';
                    board[i][j+2] = 'A';
                }
                usleep(alien_speed);
            }
        }
        else {
            // Move aliens right
            for (int j=BOARD_WIDTH-2; j>=0; j-=2) {
                int empty_column = 1;
                for (int i=0; i<BOARD_HEIGHT; i++)
                    if (board[i][j] == 'A') {
                        empty_column = 0;
                        break;
                    }
                if (!empty_column) // cannot move aliens right
                    break;
                for (int i=0; i<BOARD_HEIGHT; i++) {
                    board[i][j] = ' ';
                    board[i][j+2] = 'A';
                }
                usleep(alien_speed);
            }
        }
    }
    return NULL;
}

// Move player left or right
void* move_player(void* arg) {
    int player_num = *(int*)arg;
    while (!game_over) {
        int c = getchar();
        if (c == 'a' && player_pos > 0) {
            pthread_mutex_lock(&board_mutex);
            board[BOARD_HEIGHT-1][player_pos*2] = ' ';
            player_pos--;
            board[BOARD_HEIGHT-1][player_pos*2] = (char)player_num + '0';
            pthread_mutex_unlock(&board_mutex);
        }
        else if (c == 'd' && player_pos < BOARD_WIDTH/2-1) {
            pthread_mutex_lock(&board_mutex);
            board[BOARD_HEIGHT-1][player_pos*2] = ' ';
            player_pos++;
            board[BOARD_HEIGHT-1][player_pos*2] = (char)player_num + '0';
            pthread_mutex_unlock(&board_mutex);
        }
        // Consume new line character
        getchar();
    }
    return NULL;
}

// Detect collision between bullets and aliens
void* detect_collision() {
    while (!game_over) {
        // Detect bullet collisions
        for (int i=0; i<BOARD_HEIGHT; i++)
            for (int j=0; j<BOARD_WIDTH; j+=2)
                if (board[i][j] == '|' && board[i][j+1] >= '0' && board[i][j+1] <= '9') {
                    int player_num = board[i][j+1] - '0';
                    board[i][j] = ' ';

                    // Check if hit UFO
                    if (i == 1 && random_between(0, 9) == 0) {
                        pthread_mutex_lock(&board_mutex);
                        player_score += UFO_SCORE;
                        pthread_mutex_unlock(&board_mutex);
                    }

                    // Check if hit alien
                    for (int k=0; k<ALIEN_ROWS; k++)
                        for (int l=0; l<ALIEN_COLS; l++)
                            if (board[k][l*2] == 'A' && i == k+2 && j == l*2) {
                                pthread_mutex_lock(&board_mutex);
                                player_score += INVADER_SCORE;
                                board[k][l*2] = ' ';
                                pthread_mutex_unlock(&board_mutex);
                            }
                }

        usleep(10000); // Wait 10 ms
    }
    return NULL;
}

// Shoot bullet
void* shoot(void* arg) {
    int player_num = *(int*)arg;
    while (!game_over) {
        int c = getchar();
        if (c == ' ') {
            pthread_mutex_lock(&board_mutex);
            for (int i=BOARD_HEIGHT-1; i>=0; i--)
                if (board[i][player_pos*2] == ' ') {
                    board[i][player_pos*2] = '|';
                    board[i][player_pos*2+1] = (char)player_num + '0';
                    break;
                }
            pthread_mutex_unlock(&board_mutex);
        }
    }
    return NULL;
}

int main() {
    srand(time(NULL)); // Seed random number generator
    init_board(); // Initialize board

    // Place player on board
    board[BOARD_HEIGHT-1][player_pos*2] = 'P';

    // Print instructions
    printf("**** C SPACE INVADERS MULTIPLAYER ****\n");
    printf("Controls:\n");
    printf("   Move left: a\n");
    printf("   Move right: d\n");
    printf("   Fire: space\n");

    // Create threads
    pthread_t alien_thread, player1_thread, player2_thread, collision_thread, player1_shoot_thread, player2_shoot_thread;

    // Initialize mutex
    if (pthread_mutex_init(&board_mutex, NULL) != 0) {
        printf("Mutex initialization failed!\n");
        return 1;
    }

    // Start game loop
    pthread_create(&alien_thread, NULL, move_aliens, NULL);
    int player1_num = 1;
    pthread_create(&player1_thread, NULL, move_player, &player1_num);
    int player2_num = 2;
    pthread_create(&player2_thread, NULL, move_player, &player2_num);
    pthread_create(&collision_thread, NULL, detect_collision, NULL);
    pthread_create(&player1_shoot_thread, NULL, shoot, &player1_num);
    pthread_create(&player2_shoot_thread, NULL, shoot, &player2_num);

    while (!game_over) {
        pthread_mutex_lock(&board_mutex);
        print_board();
        pthread_mutex_unlock(&board_mutex);
        usleep(100000); // Wait 100 ms
    }

    // Join threads
    pthread_join(alien_thread, NULL);
    pthread_join(player1_thread, NULL);
    pthread_join(player2_thread, NULL);
    pthread_join(collision_thread, NULL);
    pthread_join(player1_shoot_thread, NULL);
    pthread_join(player2_shoot_thread, NULL);

    // Clean up mutex
    pthread_mutex_destroy(&board_mutex);

    return 0;
}