//FormAI DATASET v1.0 Category: Pac-Man Game Clone ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAXSIZE 20
#define MAXCHAR 100

typedef struct {
    int x;
    int y;
} point;

typedef struct {
    char board[MAXSIZE][MAXSIZE];
    point position;
} game;

void initialize(game *g);
void draw(game *g);
void move(game *g, char *input);
int in_bounds(point p);
int can_move(game *g, point p);

int main() {

    game g;
    char input[MAXCHAR];

    printf("Welcome to Pac-Man game clone in Romeo and Juliet style!\n");

    initialize(&g);
    draw(&g);

    while (1) {
        printf("Enter your move (N/S/E/W): ");
        fgets(input, MAXCHAR, stdin);

        if (strlen(input) > 1 && input[strlen(input)-1] == '\n') {
            input[strlen(input)-1] = '\0';
        }

        if (!strcmp(input, "quit")) {
            break;
        } else {
            move(&g, input);
            draw(&g);
        }
    }

    printf("Thanks for playing Pac-Man game clone in Romeo and Juliet style!");
    return 0;
}

void initialize(game *g) {
    memset(g->board, '.', sizeof(g->board));
    g->position.x = 5;
    g->position.y = 5;
    g->board[g->position.x][g->position.y] = 'P';
}

void draw(game *g) {
    printf("\n");
    int i, j;
    for (i = 0; i < MAXSIZE; i++) {
        for (j = 0; j < MAXSIZE; j++) {
            printf("%c ", g->board[i][j]);
        }
        printf("\n");
    }
}

void move(game *g, char *input) {
    int i;
    for (i = 0; i < strlen(input); i++) {
        point new_pos;
        new_pos = g->position;

        switch(toupper(input[i])) {
            case 'N':
                new_pos.x--;
                break;

            case 'S':
                new_pos.x++;
                break;

            case 'W':
                new_pos.y--;
                break;

            case 'E':
                new_pos.y++;
                break;
        }

        if (in_bounds(new_pos) && can_move(g, new_pos)) {
            g->board[g->position.x][g->position.y] = ' ';
            g->position = new_pos;
            g->board[g->position.x][g->position.y] = 'P';
        }
    }
}

int in_bounds(point p) {
    return (p.x >= 0 && p.x < MAXSIZE && p.y >=0 && p.y < MAXSIZE);
}

int can_move(game *g, point p) {
    return (g->board[p.x][p.y] == '.' || g->board[p.x][p.y] == ' ');
}