//FormAI DATASET v1.0 Category: Breakout Game Clone ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <termios.h>
#include <fcntl.h>

#define ROWS 20
#define COLS 70
#define BRICK_WIDTH 5
#define BRICK_HEIGHT 2
#define PADDLE_WIDTH 6
#define PADDLE_HEIGHT 1
#define BALL_START_X (ROWS-2)
#define BALL_START_Y (COLS/2)
#define PADDLE_START_X (ROWS-1)
#define PADDLE_START_Y ((COLS-PADDLE_WIDTH)/2)
#define BALL_CHAR 'o'
#define PADDLE_CHAR '_'
#define BRICK_CHAR '#'
#define WALL_CHAR '|'
#define EMPTY_SPACE ' '

typedef struct brick {
    int broken;
    int x;
    int y;
} brick_t;

typedef struct ball {
    int x;
    int y;
    int dx;
    int dy;
} ball_t;

typedef struct paddle {
    int x;
    int y;
} paddle_t;

typedef struct player {
    int score;
    char name[20];
} player_t;

typedef struct client {
    int fd;
    char name[20];
} client_t;

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
    if (ch != EOF) {
        ungetc(ch, stdin);
        return 1;
    }
    return 0;
}

int getch() {
    char c;
    struct termios org_opts, new_opts;
    int res = 0;
    tcgetattr(STDIN_FILENO, &org_opts);
    memcpy(&new_opts, &org_opts, sizeof(org_opts));
    new_opts.c_lflag &= ~(ICANON | ECHO | ECHOE | ECHOK | ECHONL | ECHOPRT | ECHOKE | ICRNL);
    tcsetattr(STDIN_FILENO, TCSANOW, &new_opts);
    setbuf(stdin, NULL);
    do {
        c = getchar();
        res = c;
    } while (c != EOF && c != '\n' && c != '\r');
    tcsetattr(STDIN_FILENO, TCSANOW, &org_opts);
    return res;
}

void draw_char(char c, int row, int col) {
    printf("\033[%d;%dH%c", row, col, c);
    fflush(stdout);
}

void draw_wall() {
    int i;
    for (i = 0; i <= ROWS; i++) {
        draw_char(WALL_CHAR, i, 0);
        draw_char(WALL_CHAR, i, COLS+1);
    }
    for (i = 0; i <= COLS+1; i++) {
        draw_char(WALL_CHAR, ROWS+1, i);
    }
}

void draw_paddle(paddle_t *paddle) {
    int i;
    for (i = 0; i < PADDLE_WIDTH; i++) {
        draw_char(PADDLE_CHAR, paddle->x, paddle->y+i);
    }
}

void draw_ball(ball_t *ball) {
    draw_char(BALL_CHAR, ball->x, ball->y);
}

void draw_brick(brick_t *brick) {
    int i, j;
    if (!brick->broken) {
        for (i = 0; i < BRICK_HEIGHT; i++) {
            for (j = 0; j < BRICK_WIDTH; j++) {
                draw_char(BRICK_CHAR, brick->x+i, brick->y+j);
            }
        }
    }
}

void draw_bricks(brick_t *bricks) {
    int i;
    for (i = 0; i < ROWS-BRICK_HEIGHT-2; i += BRICK_HEIGHT+1) {
        int j;
        for (j = 0; j < COLS-BRICK_WIDTH*2; j += BRICK_WIDTH+1) {
            draw_brick(&bricks[i*(COLS/BRICK_WIDTH)+j/BRICK_WIDTH]);
        }
    }
}

int check_for_collision(ball_t *ball, paddle_t *paddle, brick_t *bricks, int *score) {
    int x = ball->x;
    int y = ball->y;
    int dx = ball->dx;
    int dy = ball->dy;
    int broke_brick = 0;

    if (dy == 0) {
        dy = 1;
    }

    if (x+dx <= 0 || x+dx > ROWS) {
        dx = -dx;
    }

    if (y+dy < 0 || y+dy > COLS-PADDLE_WIDTH) {
        dy = -dy;
    } else if (x+dx == paddle->x) {
        if (y+dy >= paddle->y && y+dy < paddle->y+PADDLE_WIDTH) {
            dx = -1;
            dy = -1;
        }
    }

    int i, j;
    for (i = 0; i < ROWS-BRICK_HEIGHT-2; i += BRICK_HEIGHT+1) {
        for (j = 0; j < COLS-BRICK_WIDTH*2; j += BRICK_WIDTH+1) {
            brick_t *brick = &bricks[i*(COLS/BRICK_WIDTH)+j/BRICK_WIDTH];
            if (!brick->broken && x+dx >= brick->x && x+dx < brick->x+BRICK_HEIGHT &&
                y+dy >= brick->y && y+dy < brick->y+BRICK_WIDTH) {
                brick->broken = 1;
                *score += 10;
                dx = -dx;
                broke_brick = 1;
            }
        }
    }

    ball->x += dx;
    ball->y += dy;
    ball->dx = dx;
    ball->dy = dy;
    return broke_brick;
}

void add_player(client_t **clients, int *num_clients, int fd) {
    client_t *client = malloc(sizeof(client_t));
    client->fd = fd;
    sprintf(client->name, "player%d", *num_clients+1);
    (*num_clients)++;
    *clients = realloc(*clients, sizeof(client_t)*(*num_clients));
    (*clients)[*num_clients-1] = *client;
}

void read_from_clients(client_t *clients, int num_clients, char buffer[]) {
    int i, n;
    for (i = 0; i < num_clients; i++) {
        n = read(clients[i].fd, buffer, sizeof(buffer));
        if (n > 0) {
            buffer[n] = '\0';
            printf("Message from %s: %s", clients[i].name, buffer);
        }
    }
}

void send_to_clients(client_t *clients, int num_clients, char *message) {
    int i;
    for (i = 0; i < num_clients; i++) {
        write(clients[i].fd, message, strlen(message));
    }
}

int main(int argc, char *argv[]) {
    srand(time(NULL));

    int i, j;
    int score = 0;
    int num_clients = 0;
    char buffer[256];
    client_t *clients = NULL;

    brick_t bricks[(ROWS-BRICK_HEIGHT-2)*(COLS/BRICK_WIDTH)];
    for (i = 0; i < ROWS-BRICK_HEIGHT-2; i += BRICK_HEIGHT+1) {
        for (j = 0; j < COLS-BRICK_WIDTH*2; j += BRICK_WIDTH+1) {
            brick_t brick = {0};
            brick.x = i+1;
            brick.y = j+1;
            bricks[i*(COLS/BRICK_WIDTH)+j/BRICK_WIDTH] = brick;
        }
    }

    paddle_t paddle = {0};
    paddle.x = PADDLE_START_X;
    paddle.y = PADDLE_START_Y;

    ball_t ball = {0};
    ball.x = BALL_START_X;
    ball.y = BALL_START_Y;
    ball.dx = 1;
    ball.dy = 1;

    draw_wall();
    draw_bricks(bricks);
    draw_paddle(&paddle);
    draw_ball(&ball);

    add_player(&clients, &num_clients, STDIN_FILENO);
    fd_set readfds;
    struct timeval tv;
    tv.tv_sec = 0;
    tv.tv_usec = 0;

    while (1) {
        FD_ZERO(&readfds);
        FD_SET(STDIN_FILENO, &readfds);
        for (i = 0; i < num_clients; i++) {
            FD_SET(clients[i].fd, &readfds);
        }

        int maxfd = clients[num_clients-1].fd;
        if (select(maxfd+1, &readfds, NULL, NULL, &tv) == -1) {
            perror("select");
            exit(4);
        }

        if (kbhit()) {
            int c = getch();
            if (c == 'a' && paddle.y > 1) {
                paddle.y--;
            } else if (c == 'd' && paddle.y+PADDLE_WIDTH < COLS) {
                paddle.y++;
            }
            draw_paddle(&paddle);
        }

        int broke_brick = check_for_collision(&ball, &paddle, bricks, &score);

        if (broke_brick) {
            draw_bricks(bricks);
        }

        if (ball.x == ROWS) {
            break;
        }

        draw_ball(&ball);

        sprintf(buffer, "Score: %d    ", score);
        draw_char(' ', ROWS+2, 1);
        printf("\033[%d;%dH%s", ROWS+2, 1, buffer);
        fflush(stdout);

        read_from_clients(clients, num_clients, buffer);
        if (strlen(buffer) > 0) {
            send_to_clients(clients, num_clients, buffer);
        }
    }

    for (i = 0; i < num_clients; i++) {
        close(clients[i].fd);
    }
    free(clients);

    return 0;
}