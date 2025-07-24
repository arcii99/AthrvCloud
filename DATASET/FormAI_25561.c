//FormAI DATASET v1.0 Category: Pong Game with AI Opponent ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

//Initialize game variables
const int MAX_SCORE = 10;
int player_score = 0;
int ai_score = 0;
int ball_x = 40, ball_y = 12;
int player_x = 4, player_y = 10;
int ai_x = 76, ai_y = 10;
int ball_dir = 1, ball_vel = 1;
bool in_play = true;

//Function to print game board
void print_board() {
    system("clear");
    printf("Player 1 Score: %d\n", player_score);
    printf("Player 2 Score: %d\n", ai_score);
    printf("   ___________\n");
    for (int i = 0; i < 20; i++) {
        printf("  |");
        for (int j = 0; j < 80; j++) {
            if (i == ball_y && j == ball_x) {
                printf("o");
            } else if (i == player_y && j >= player_x && j < player_x + 5) {
                printf("-");
            } else if (i == ai_y && j >= ai_x && j < ai_x + 5) {
                printf("-");
            } else if (j == 0 || j == 79) {
                printf("|");
            } else if (i == 0 || i == 19) {
                printf("_");
            } else {
                printf(" ");
            }
        }
        printf("|\n");
    }
    printf("   -----------\n");
}

//Function to update ball position
void update_ball() {
    ball_x += ball_vel * ball_dir;
    if (ball_x <= 2) {
        ball_dir = 1;
        ball_x = 4;
        ai_score++;
    } else if (ball_x >= 77) {
        ball_dir = -1;
        ball_x = 75;
        player_score++;
    }
    ball_y += rand() % 3 - 1;
    if (ball_y <= 1 || ball_y >= 18) {
        ball_y -= rand() % 3 - 1;
    }
}

//Function to update player position
void update_player() {
    int input = getchar();
    if (input == 'w' && player_y > 1) {
        player_y--;
    } else if (input == 's' && player_y < 18) {
        player_y++;
    }
}

//Function to update ai position
void update_ai() {
    if (ai_y < ball_y && ai_y < 18) {
        ai_y++;
    } else if (ai_y > ball_y && ai_y > 1) {
        ai_y--;
    }
}

//Function to check for end of game
bool end_game() {
    if (player_score >= MAX_SCORE || ai_score >= MAX_SCORE) {
        in_play = false;
        return true;
    }
    return false;
}

int main() {
    //Seed random number generator
    srand(time(NULL));

    //Run game loop
    while (in_play) {
        print_board();
        update_ball();
        update_player();
        update_ai();
        if (end_game()) {
            break;
        }
    }

    //Print end of game message
    printf("Game Over\n");
    if (player_score > ai_score) {
        printf("Romeo wins!\n");
    } else {
        printf("Juliet wins!\n");
    }
    return 0;
}