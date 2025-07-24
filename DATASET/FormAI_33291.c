//FormAI DATASET v1.0 Category: Pong Game with AI Opponent ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <time.h>

#define WIDTH 80
#define HEIGHT 25
#define PADDLE_SIZE 5
#define BALL_SYMBOL 'O'
#define PADDLE_SYMBOL 'X'
#define AI_SPEED 0.1 // time in seconds between AI paddle movements

void clear_screen() {
    system("clear");
}

void setup_gameboard(char gameboard[HEIGHT][WIDTH]) {
    int i, j;
    for(i=0; i<HEIGHT; i++) {
        for(j=0; j<WIDTH; j++) {
            if(i==0 || i==HEIGHT-1) {
                // top and bottom walls
                gameboard[i][j] = '-';
            } else if(j==0 || j==WIDTH-1) {
                // left and right walls
                gameboard[i][j] = '|';
            } else {
                // empty space
                gameboard[i][j] = ' ';
            }
        }
    }
}

int init_ball(int ball_pos[2]) {
    srand(time(NULL));
    if(rand()%2 == 0) {
        // ball starts at left wall
        ball_pos[0] = 1;
    } else {
        // ball starts at right wall
        ball_pos[0] = WIDTH-2;
    }
    ball_pos[1] = HEIGHT/2; // middle of screen
    return rand()%4; // random initial direction
}

void move_ball(int ball_pos[2], int ball_dir, int paddle_pos) {
    switch(ball_dir) {
        case 0:
            // ball moving up and to the right
            ball_pos[0]++;
            ball_pos[1]--;
            break;
        case 1:
            // ball moving down and to the right
            ball_pos[0]++;
            ball_pos[1]++;
            break;
        case 2:
            // ball moving down and to the left
            ball_pos[0]--;
            ball_pos[1]++;
            break;
        case 3:
            // ball moving up and to the left
            ball_pos[0]--;
            ball_pos[1]--;
            break;
    }

    // bounce off top and bottom walls
    if(ball_pos[1] == 1 || ball_pos[1] == HEIGHT-2) {
        if(ball_dir == 0) {
            ball_dir = 1;
        } else {
            ball_dir = 2;
        }
    }

    // check for paddle collision
    if(ball_pos[0] == WIDTH-2 && ball_pos[1] >= paddle_pos && ball_pos[1] <= paddle_pos+PADDLE_SIZE-1) {
        // ball hit player's paddle
        if(ball_dir == 1) {
            ball_dir = 0;
        } else {
            ball_dir = 3;
        }
    } else if(ball_pos[0] == 1 && ball_pos[1] == HEIGHT/2) {
        // ball hit left wall, reset
        ball_dir = init_ball(ball_pos);
    }
}

void move_paddle(int* paddle_pos, int direction) {
    switch(direction) {
        case -1:
            // move paddle up
            if(*paddle_pos > 1) {
                (*paddle_pos)--;
            }
            break;
        case 1:
            // move paddle down
            if(*paddle_pos < HEIGHT-PADDLE_SIZE-1) {
                (*paddle_pos)++;
            }
            break;
        default:
            // don't move paddle
            break;
    }
}

void move_ai_paddle(int* paddle_pos, int ball_pos[2]) {
    // move towards ball
    if(*paddle_pos+PADDLE_SIZE/2 > ball_pos[1]) {
        move_paddle(paddle_pos, -1);
    } else if(*paddle_pos+PADDLE_SIZE/2 < ball_pos[1]) {
        move_paddle(paddle_pos, 1);
    }
}

void display_game(char gameboard[HEIGHT][WIDTH], int ball_pos[2], int player_paddle_pos, int ai_paddle_pos) {
    int i, j;
    for(i=0; i<HEIGHT; i++) {
        for(j=0; j<WIDTH; j++) {
            if(ball_pos[0] == j && ball_pos[1] == i) {
                printf("%c", BALL_SYMBOL);
            } else if(j == 2 && i >= player_paddle_pos && i < player_paddle_pos+PADDLE_SIZE) {
                printf("%c", PADDLE_SYMBOL); // player's paddle
            } else if(j == WIDTH-3 && i >= ai_paddle_pos && i < ai_paddle_pos+PADDLE_SIZE) {
                printf("%c", PADDLE_SYMBOL); // AI's paddle
            } else {
                printf("%c", gameboard[i][j]);
            }
        }
        printf("\n");
    }
}

int main() {
    char gameboard[HEIGHT][WIDTH];
    int ball_pos[2], ball_dir, player_paddle_pos, ai_paddle_pos, player_score=0, ai_score=0, keypress;
    bool game_over = false;
    setup_gameboard(gameboard);
    ball_dir = init_ball(ball_pos);
    player_paddle_pos = HEIGHT/2;
    ai_paddle_pos = HEIGHT/2;
    display_game(gameboard, ball_pos, player_paddle_pos, ai_paddle_pos);

    while(!game_over) {
        if(ball_dir == 1 || ball_dir == 2) {
            // move AI paddle towards ball
            move_ai_paddle(&ai_paddle_pos, ball_pos);
        } else {
            // move AI paddle randomly
            if(rand()%2 == 0) {
                move_ai_paddle(&ai_paddle_pos, ball_pos);
            }
        }

        // move ball
        move_ball(ball_pos, ball_dir, player_paddle_pos);

        // check for game over
        if(ball_pos[0] == 0) {
            // player lost
            ai_score++;
            printf("AI wins! Score: Player %d, AI %d\n", player_score, ai_score);
            printf("Press any key to continue...");
            game_over = true;
            while((keypress = getchar()) != '\n' && keypress != EOF); // clear input buffer
        } else if(ball_pos[0] == WIDTH-1) {
            // player won
            player_score++;
            printf("Player wins! Score: Player %d, AI %d\n", player_score, ai_score);
            printf("Press any key to continue...");
            game_over = true;
            while((keypress = getchar()) != '\n' && keypress != EOF); // clear input buffer
        }

        if(!game_over) {
            // display game
            clear_screen();
            display_game(gameboard, ball_pos, player_paddle_pos, ai_paddle_pos);
            usleep(AI_SPEED * 1000000); // wait before moving AI paddle
        }
    }

    return 0;
}