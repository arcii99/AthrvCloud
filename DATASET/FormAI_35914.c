//FormAI DATASET v1.0 Category: Space Invaders Game Clone ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <termios.h>
#include <fcntl.h>

#define WIDTH 60
#define HEIGHT 20
#define PLAYER 'V'
#define ENEMY 'X'
#define BULLET '|'
#define ENEMY_BULLET 'o'

int kbhit() {
    struct termios oldt, newt;
    int ch, oldf;

    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);

    ch = getchar();

    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    fcntl(STDIN_FILENO, F_SETFL, oldf);

    if(ch != EOF) {
        ungetc(ch, stdin);
        return 1;
    }

    return 0;
}

void show_game(char game[HEIGHT][WIDTH]) {
    system("clear");
    for(int i = 0; i < HEIGHT; i++) {
        printf("%s\n", game[i]);
    }
}

void update_player(char game[HEIGHT][WIDTH], int player_x) {
    game[HEIGHT - 1][player_x] = PLAYER;
}

void update_enemies(char game[HEIGHT][WIDTH], int enemies[][2], int num_enemies) {
    char enemy_icon = ENEMY;

    for(int i = 0; i < num_enemies; i++) {
        if(enemies[i][0] == -1 && enemies[i][1] == -1) {
            continue;
        }

        char prev_icon = game[enemies[i][0]][enemies[i][1]];
        game[enemies[i][0]][enemies[i][1]] = enemy_icon;

        if(prev_icon != enemy_icon) {
            game[enemies[i][0]][enemies[i][1]] = enemy_icon;
            if(i == num_enemies - 1) {
                game[enemies[i][0] + 1][0] = enemy_icon;
            }
        }
    }
}

void update_bullets(char game[HEIGHT][WIDTH], int bullets[][2], int num_bullets, char bullet_icon) {
    for(int i = 0; i < num_bullets; i++) {
        if(bullets[i][0] == -1 && bullets[i][1] == -1) {
            continue;
        }

        char prev_icon = game[bullets[i][0]][bullets[i][1]];

        if(prev_icon == ENEMY) {
            for(int j = 0; j < HEIGHT; j++) {
                for(int k = 0; k < WIDTH; k++) {
                    if(game[j][k] == ENEMY) {
                        game[j][k] = ' ';
                    }
                }
            }
            printf("YOU WON!\n");
            exit(EXIT_SUCCESS);
        }

        game[bullets[i][0]][bullets[i][1]] = bullet_icon;

        if(prev_icon != bullet_icon) {
            game[bullets[i][0]][bullets[i][1]] = bullet_icon;
        }
    }
}

void move_bullets(int bullets[][2], int num_bullets, int y_delta) {
    for(int i = 0; i < num_bullets; i++) {
        if(bullets[i][0] == -1 && bullets[i][1] == -1) {
            continue;
        }

        bullets[i][0] -= y_delta;

        if(bullets[i][0] < 0) {
            bullets[i][0] = -1;
            bullets[i][1] = -1;
        }
    }
}

bool all_enemies_killed(int enemies[][2], int num_enemies) {
    for(int i = 0; i < num_enemies; i++) {
        if(enemies[i][0] != -1 && enemies[i][1] != -1) {
            return false;
        }
    }
    return true;
}

int main(void) {
    char game[HEIGHT][WIDTH];

    int player_x = (WIDTH - 1) / 2;

    int enemy_spacing = 4;
    int num_enemies = WIDTH / enemy_spacing;
    int enemies[num_enemies][2];

    for(int i = 0; i < num_enemies; i++) {
        enemies[i][0] = 1;
        enemies[i][1] = i * enemy_spacing;
    }

    int num_player_bullets = 3;
    int player_bullets[num_player_bullets][2];
    for(int i = 0; i < num_player_bullets; i++) {
        player_bullets[i][0] = -1;
        player_bullets[i][1] = -1;
    }

    int num_enemies_bullets = num_enemies;
    int enemy_bullets[num_enemies_bullets][2];
    for(int i = 0; i < num_enemies_bullets; i++) {
        enemy_bullets[i][0] = -1;
        enemy_bullets[i][1] = -1;
    }

    for(int i = 0; i < HEIGHT; i++) {
        for(int j = 0; j < WIDTH; j++) {
            if(i == HEIGHT - 1 && j == player_x) {
                game[i][j] = PLAYER;
            } else if(i == 0) {
                game[i][j] = '-';
            } else {
                game[i][j] = ' ';
            }
        }
    }

    int score = 0;

    while(true) {
        show_game(game);

        char input;

        if(kbhit()) {
            input = getchar();
        } else {
            input = '\0';
        }

        if(input == 'a') {
            if(player_x > 0) {
                player_x--;
                update_player(game, player_x);
            }
        } else if(input == 'd') {
            if(player_x < WIDTH - 1) {
                player_x++;
                update_player(game, player_x);
            }
        } else if(input == ' ') {
            for(int i = 0; i < num_player_bullets; i++) {
                if(player_bullets[i][0] == -1 && player_bullets[i][1] == -1) {
                    player_bullets[i][0] = HEIGHT - 2;
                    player_bullets[i][1] = player_x;
                    break;
                }
            }
        }

        if(all_enemies_killed(enemies, num_enemies)) {
            printf("YOU WON!\n");
            break;
        }

        int alive_enemies = 0;

        for(int i = 0; i < num_enemies; i++) {
            if(enemies[i][0] == -1 && enemies[i][1] == -1) {
                continue;
            }

            alive_enemies++;

            if(rand() % 50 == 0) {
                for(int j = 0; j < num_enemies_bullets; j++) {
                    if(enemy_bullets[j][0] == -1 && enemy_bullets[j][1] == -1) {
                        enemy_bullets[j][0] = enemies[i][0] + 1;
                        enemy_bullets[j][1] = enemies[i][1];
                        break;
                    }
                }
            }
        }

        if(alive_enemies == 0) {
            printf("YOU WON!\n");
            break;
        }

        update_enemies(game, enemies, num_enemies);
        update_bullets(game, player_bullets, num_player_bullets, BULLET);
        update_bullets(game, enemy_bullets, num_enemies_bullets, ENEMY_BULLET);

        move_bullets(player_bullets, num_player_bullets, 1);
        move_bullets(enemy_bullets, num_enemies_bullets, -1);

        for(int i = 0; i < num_player_bullets; i++) {
            if(player_bullets[i][0] == -1 && player_bullets[i][1] == -1) {
                continue;
            }

            for(int j = 0; j < num_enemies; j++) {
                if(enemies[j][0] == -1 && enemies[j][1] == -1) {
                    continue;
                }

                if(player_bullets[i][0] == enemies[j][0] && 
                   player_bullets[i][1] == enemies[j][1]) {
                    enemies[j][0] = -1;
                    enemies[j][1] = -1;
                    player_bullets[i][0] = -1;
                    player_bullets[i][1] = -1;
                    score++;
                }
            }
        }

        for(int i = 0; i < num_enemies_bullets; i++) {
            if(enemy_bullets[i][0] == -1 && enemy_bullets[i][1] == -1) {
                continue;
            }

            if(enemy_bullets[i][0] == HEIGHT - 1 && enemy_bullets[i][1] == player_x) {
                printf("YOU LOST! Final score: %d\n", score);
                exit(EXIT_SUCCESS);
            }
        }

        usleep(25000);
    }

    return 0;
}