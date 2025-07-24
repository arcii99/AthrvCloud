//FormAI DATASET v1.0 Category: Pong Game with AI Opponent ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <termios.h>
#include <unistd.h>

/* Function to randomly generate the direction of the ball */
int random_direction() {
    srand(time(NULL));
    int direction = rand() % 4;
    return direction;
}

/* Function to start the game */
void start_game() {
    int i, j;
    int player_score = 0, computer_score = 0;
    int paddle_length = 4;
    int ball_direction = random_direction();
    int ball_x = 20, ball_y = 10;
    int paddle_x = 2, paddle_y = 8;
    int computer_paddle_x = 75, computer_paddle_y = 8;
    int computer_paddle_length = 4;
    int game_over = 0;
    char input;
    struct termios original, modified;

    /* Set terminal to raw mode to capture arrow key inputs */
    tcgetattr(STDIN_FILENO, &original);
    modified = original;
    modified.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &modified);

    /* Clear the screen */
    printf("\033[2J");

    /* Draw the game board */
    for (i = 1; i <= 78; i++) {
        printf("-");
    }
    printf("\n");

    for (i = 1; i <= 22; i++) {
        for (j = 1; j <= 78; j++) {
            if ((j == 1 || j == 78) && i != 21) {
                printf("|");
            } else if (i == 21 && j != 1 && j != 78) {
                printf("-");
            } else if (i == paddle_y && j <= paddle_x + paddle_length && j >= paddle_x) {
                printf("=");
            } else if (i == computer_paddle_y && j <= computer_paddle_x + computer_paddle_length && j >= computer_paddle_x) {
                printf("=");
            } else if (i == ball_y && j == ball_x) {
                printf("O");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }

    /* Move the computer paddle randomly */
    srand(time(NULL));
    int computer_paddle_direction = rand() % 3 - 1;

    /* Game loop */
    while (!game_over) {
        /* Sleep for 100 milliseconds */
        usleep(100000);

        /* Get input */
        if (read(STDIN_FILENO, &input, 1) == 1) {
            /* Move the player paddle */
            if (input == 'A') {
                if (paddle_x > 2) {
                    paddle_x--;
                }
            } else if (input == 'D') {
                if (paddle_x + paddle_length < 77) {
                    paddle_x++;
                }
            }
        }

        /* Move the computer paddle */
        if (abs(computer_paddle_direction) == 1) {
            if (computer_paddle_x + computer_paddle_length < 77 && computer_paddle_direction == 1) {
                computer_paddle_x++;
            } else if (computer_paddle_x > 2 && computer_paddle_direction == -1) {
                computer_paddle_x--;
            }
        } else {
            if (rand() % 2 == 0) {
                if (computer_paddle_x + computer_paddle_length < 77) {
                    computer_paddle_x++;
                }
            } else {
                if (computer_paddle_x > 2) {
                    computer_paddle_x--;
                }
            }
        }

        /* Move the ball */
        switch(ball_direction) {
            case 0:
                ball_x--;
                ball_y--;
                break;
            case 1:
                ball_x++;
                ball_y--;
                break;
            case 2:
                ball_x--;
                ball_y++;
                break;
            case 3:
                ball_x++;
                ball_y++;
                break;
        }

        /* Check for wall collision */
        if (ball_x == 2 || ball_x == 77) {
            ball_direction = (ball_direction == 0 || ball_direction == 1) ? (3 - ball_direction) : (7 - ball_direction);
        } else if (ball_y == 2 || ball_y == 21) {
            ball_direction = (ball_direction == 0 || ball_direction == 3) ? (6 - ball_direction) : (4 - ball_direction);
        } else if (ball_y == paddle_y - 1 && ball_x >= paddle_x && ball_x <= paddle_x + paddle_length) {
            ball_direction = (ball_direction == 2) ? 3 : 0;
        } else if (ball_y == computer_paddle_y + 1 && ball_x >= computer_paddle_x && ball_x <= computer_paddle_x + computer_paddle_length) {
            ball_direction = (ball_direction == 3) ? 2 : 1;
        }

        /* Check for score */
        if (ball_y == 1) {
            player_score++;
            ball_x = 20;
            ball_y = 10;
            ball_direction = random_direction();
        } else if (ball_y == 22) {
            computer_score++;
            ball_x = 20;
            ball_y = 10;
            ball_direction = random_direction();
        }

        /* Check for game over */
        if (player_score == 5 || computer_score == 5) {
            game_over = 1;
        }

        /* Clear the screen */
        printf("\033[2J");

        /* Draw the game board */
        for (i = 1; i <= 78; i++) {
            printf("-");
        }
        printf("\n");

        for (i = 1; i <= 22; i++) {
            for (j = 1; j <= 78; j++) {
                if ((j == 1 || j == 78) && i != 21) {
                    printf("|");
                } else if (i == 21 && j != 1 && j != 78) {
                    printf("-");
                } else if (i == paddle_y && j <= paddle_x + paddle_length && j >= paddle_x) {
                    printf("=");
                } else if (i == computer_paddle_y && j <= computer_paddle_x + computer_paddle_length && j >= computer_paddle_x) {
                    printf("=");
                } else if (i == ball_y && j == ball_x) {
                    printf("O");
                } else {
                    printf(" ");
                }
            }
            printf("\n");
        }

        /* Print the player and computer scores */
        printf("\n\nPlayer: %d  Computer: %d", player_score, computer_score);
    }

    /* Reset terminal to original mode */
    tcsetattr(STDIN_FILENO, TCSANOW, &original);
}

/* Main function */
int main() {
    start_game();
    return 0;
}