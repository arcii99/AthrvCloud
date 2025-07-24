//FormAI DATASET v1.0 Category: Breakout Game Clone ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <unistd.h>
#include <termios.h>

#define WIDTH 60 
#define HEIGHT 30 

enum Direction {LEFT, RIGHT, UP, DOWN};
enum BlockType {EMPTY, BRICK, BALL, BAR};
enum GameState {PLAYING, GAME_OVER, WIN};

struct Point {
    int x, y;
};

struct Block {
    struct Point pos;
    enum BlockType type;
};

struct Ball {
    struct Point pos, velocity;
};

struct Bar {
    struct Point pos;
    int length;
};

struct Game {
    struct Ball ball;
    struct Bar bar;
    struct Block blocks[HEIGHT][WIDTH];
    enum GameState state;
    int score, level;
};

// To capture user input without the need of pressing enter
int getch() {
    struct termios oldtc, newtc;
    int ch;
    tcgetattr(STDIN_FILENO, &oldtc);
    newtc = oldtc;
    newtc.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newtc);
    ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldtc);
    return ch;
}

// Initialize game
void init_game(struct Game *game) {
    // Initialize ball
    game->ball.pos = (struct Point) {WIDTH / 2, HEIGHT / 2};
    game->ball.velocity = (struct Point) {1, -1};
    // Initialize bar
    game->bar.pos = (struct Point) {WIDTH / 2 - 5, HEIGHT - 2};
    game->bar.length = 11;
    // Initialize blocks
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (i == 0 || j == 0 || i == HEIGHT - 1 || j == WIDTH - 1) {
                game->blocks[i][j].type = BRICK; // Set boundary bricks
            } else if (i < 5) {
                game->blocks[i][j].type = BRICK; // Set initial bricks
            } else {
                game->blocks[i][j].type = EMPTY;
            }
            game->blocks[i][j].pos = (struct Point) {j, i};
        }
    }
    // Initialize game state
    game->state = PLAYING;
    game->score = 0;
    game->level = 1;
}

// Draw game board
void draw_board(struct Game *game) {
    system("clear"); // Clear terminal screen
    // Draw blocks
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            printf(game->blocks[i][j].type == BRICK ? "#" :
                   game->blocks[i][j].type == BALL ? "O" :
                   game->blocks[i][j].type == BAR ? "=" : " ");
        }
        printf("\n");
    }
    // Draw score and level
    printf("Score: %d\tLevel: %d\n", game->score, game->level);
}

// Move ball and check for collision
void move_ball(struct Game *game) {
    int x = game->ball.pos.x;
    int y = game->ball.pos.y;
    int vel_x = game->ball.velocity.x;
    int vel_y = game->ball.velocity.y;
    // Move ball
    game->blocks[y][x].type = EMPTY;
    game->ball.pos.x += vel_x;
    game->ball.pos.y += vel_y;
    game->blocks[game->ball.pos.y][game->ball.pos.x].type = BALL;
    // Check for wall collision
    if (game->ball.pos.x == 0 || game->ball.pos.x == WIDTH - 1) {
        game->ball.velocity.x *= -1;
    }
    if (game->ball.pos.y == 0) {
        game->ball.velocity.y *= -1;
    }
    // Check for bar collision
    if (game->ball.pos.y == HEIGHT - 2 &&
        game->ball.pos.x >= game->bar.pos.x &&
        game->ball.pos.x < game->bar.pos.x + game->bar.length) {
        game->ball.velocity.y *= -1;
        game->score++;
    }
    // Check for brick collision
    if (game->blocks[game->ball.pos.y][game->ball.pos.x].type == BRICK) {
        game->ball.velocity.y *= -1;
        game->blocks[game->ball.pos.y][game->ball.pos.x].type = EMPTY;
        game->score++;
    }
    // Check for game over
    if (game->ball.pos.y == HEIGHT - 1) {
        game->state = GAME_OVER;
    }
}

// Move bar left or right
void move_bar(struct Game *game, enum Direction dir) {
    int new_pos = game->bar.pos.x + (dir == LEFT ? -1 : 1);
    if (new_pos >= 1 && new_pos <= WIDTH - game->bar.length - 1) {
        // Clear previous bar position
        for (int i = 0; i < game->bar.length; i++) {
            game->blocks[game->bar.pos.y][game->bar.pos.x + i].type = EMPTY;
        }
        // Update bar position
        game->bar.pos.x = new_pos;
        // Draw new bar position
        for (int i = 0; i < game->bar.length; i++) {
            game->blocks[game->bar.pos.y][game->bar.pos.x + i].type = BAR;
        }
    }
}

// Create new ball after losing a life
void respawn_ball(struct Game *game) {
    game->ball.pos = (struct Point) {WIDTH / 2, HEIGHT / 2};
    game->ball.velocity = (struct Point) {1, -1};
    usleep(800000);
}

// Main game loop
void play_game() {
    // Initialize game
    struct Game game;
    init_game(&game);

    while (game.state == PLAYING) {
        // Draw board
        draw_board(&game);
        // Move ball
        move_ball(&game);
        // Move bar if user input is given
        int input = getch();
        if (input == 'a' || input == 'A') {
            move_bar(&game, LEFT);
        } else if (input == 'd' || input == 'D') {
            move_bar(&game, RIGHT);
        }
        // Check for level completion and level up
        bool level_complete = true;
        for (int i = 0; i < HEIGHT; i++) {
            for (int j = 0; j < WIDTH; j++) {
                if (game.blocks[i][j].type == BRICK) {
                    level_complete = false;
                    break;
                }
            }
            if (!level_complete) {
                break;
            }
        }
        if (level_complete) {
            game.level++;
            for (int i = 0; i < HEIGHT; i++) {
                for (int j = 0; j < WIDTH; j++) {
                    if (i < 5) {
                        game.blocks[i][j].type = BRICK; // Set initial bricks for new level
                    } else {
                        game.blocks[i][j].type = EMPTY;
                    }
                }
            }
            game.ball.velocity.x += game.ball.velocity.x > 0 ? 1 : -1; // Increase ball speed
            game.ball.velocity.y += game.ball.velocity.y > 0 ? 1 : -1;
            game.bar.length += game.level % 2 == 0 ? 1 : 0; // Increase bar length every two levels
            respawn_ball(&game);
        }
        // Respawn ball if game over and ask for replay
        if (game.state == GAME_OVER) {
            printf("Game over!\n");
            char replay;
            do {
                printf("Do you want to replay? (y/n): ");
                scanf(" %c", &replay);
            } while (replay != 'y' && replay != 'n');
            if (replay == 'y') {
                init_game(&game);
                respawn_ball(&game);
            } else {
                return;
            }
        }
        // Sleep for 50ms before next frame
        usleep(50000);
    }
}

int main() {
    // Initialize random seed
    srand(time(NULL));
    // Start game loop
    play_game();
    return 0;
}