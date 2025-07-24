//FormAI DATASET v1.0 Category: Game ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <termios.h>
#include <fcntl.h>

#define FIELD_WIDTH 60
#define FIELD_HEIGHT 20

struct ball {
    int x;
    int y;
    int dx;
    int dy;
};

struct paddle {
    int x;
    int y;
    int length;
};

struct game_state {
    struct ball ball;
    struct paddle player_paddle;
    struct paddle ai_paddle;
};

// Initializes the game state
void init_game_state(struct game_state* state) {
    // Set the initial ball position and velocity
    state->ball.x = FIELD_WIDTH / 2;
    state->ball.y = FIELD_HEIGHT / 2;
    state->ball.dx = 1;
    state->ball.dy = 1;

    // Set the initial player paddle position and length
    state->player_paddle.x = 2;
    state->player_paddle.y = FIELD_HEIGHT / 2 - 2;
    state->player_paddle.length = 5;

    // Set the initial AI paddle position and length
    state->ai_paddle.x = FIELD_WIDTH - 4;
    state->ai_paddle.y = FIELD_HEIGHT / 2 - 2;
    state->ai_paddle.length = 5;
}

// Draws the game state on the screen
void draw_game_state(struct game_state* state) {
    // Clear the screen
    system("clear");

    // Draw the top field boundary
    for (int i = 0; i < FIELD_WIDTH + 2; i++) {
        printf("-");
    }
    printf("\n");

    // Draw the field and paddles
    for (int i = 0; i < FIELD_HEIGHT; i++) {
        printf("|");
        for (int j = 0; j < FIELD_WIDTH; j++) {
            if (i == state->ball.y && j == state->ball.x) {
                printf("O");
            } else if (i >= state->player_paddle.y && i < state->player_paddle.y + state->player_paddle.length && j == state->player_paddle.x) {
                printf("|");
            } else if (i >= state->ai_paddle.y && i < state->ai_paddle.y + state->ai_paddle.length && j == state->ai_paddle.x) {
                printf("|");
            } else {
                printf(" ");
            }
        }
        printf("|\n");
    }

    // Draw the bottom field boundary
    for (int i = 0; i < FIELD_WIDTH + 2; i++) {
        printf("-");
    }
    printf("\n");
}

// Moves the ball according to its velocity
void* move_ball(void* gs) {
    struct game_state* state = (struct game_state*)gs;

    while (1) {
        // Move the ball
        state->ball.x += state->ball.dx;
        state->ball.y += state->ball.dy;

        // Check for collision with top wall
        if (state->ball.y == 0) {
            state->ball.dy = 1;
        }

        // Check for collision with bottom wall
        if (state->ball.y == FIELD_HEIGHT - 1) {
            state->ball.dy = -1;
        }

        // Check for collision with left paddle
        if (state->ball.x == state->player_paddle.x + 1 && state->ball.y >= state->player_paddle.y && state->ball.y < state->player_paddle.y + state->player_paddle.length) {
            state->ball.dx = 1;
        }

        // Check for collision with right paddle
        if (state->ball.x == state->ai_paddle.x - 1 && state->ball.y >= state->ai_paddle.y && state->ball.y < state->ai_paddle.y + state->ai_paddle.length) {
            state->ball.dx = -1;
        }

        // Check for scoring on left side
        if (state->ball.x == 0) {
            init_game_state(state);
        }

        // Check for scoring on right side
        if (state->ball.x == FIELD_WIDTH - 1) {
            init_game_state(state);
        }

        // Sleep for 50 milliseconds to slow down the ball movement
        usleep(50000);
    }

    return NULL;
}

// Gets the keyboard input from the user
void* get_input(void* player_paddle_y) {
    int* y = (int*)player_paddle_y;
    struct termios oldt, newt;
    int ch;

    // Set the terminal to raw mode to get keystrokes immediately
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);

    while (1) {
        ch = getchar();

        // Move the player paddle up when the W key is pressed
        if (ch == 'w' && *y > 0) {
            (*y)--;
        }

        // Move the player paddle down when the S key is pressed
        if (ch == 's' && *y < FIELD_HEIGHT - 5) {
            (*y)++;
        }
    }

    // Reset the terminal to its original mode
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);

    return NULL;
}

// Moves the AI paddle towards the ball
void* move_ai_paddle(void* gs) {
    struct game_state* state = (struct game_state*)gs;

    while (1) {
        // Move the AI paddle towards the ball
        if (state->ball.y < state->ai_paddle.y && state->ai_paddle.y > 0) {
            state->ai_paddle.y--;
        } else if (state->ball.y > state->ai_paddle.y && state->ai_paddle.y + state->ai_paddle.length < FIELD_HEIGHT) {
            state->ai_paddle.y++;
        }

        // Sleep for 100 milliseconds to slow down the AI movement
        usleep(100000);
    }

    return NULL;
}

// Initializes the threads and game state, then runs the game loop
int main(int argc, char** argv) {
    // Initialize the game state
    struct game_state state;
    init_game_state(&state);

    // Initialize the player paddle position
    int player_paddle_y = FIELD_HEIGHT / 2 - 2;

    // Create the threads for moving the ball, getting input, and moving the AI paddle
    pthread_t ball_thread, input_thread, ai_thread;
    pthread_create(&ball_thread, NULL, move_ball, &state);
    pthread_create(&input_thread, NULL, get_input, &player_paddle_y);
    pthread_create(&ai_thread, NULL, move_ai_paddle, &state);

    // Run the game loop
    while (1) {
        // Update the player paddle position
        state.player_paddle.y = player_paddle_y;

        // Draw the game state
        draw_game_state(&state);

        // Sleep for 100 milliseconds to slow down the loop
        usleep(100000);
    }

    // Wait for the threads to finish before exiting
    pthread_join(ball_thread, NULL);
    pthread_join(input_thread, NULL);
    pthread_join(ai_thread, NULL);

    return 0;
}