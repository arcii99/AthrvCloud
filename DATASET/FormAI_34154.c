//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define WIDTH 20
#define HEIGHT 20

// Structure for storing player information
typedef struct {
    int x;
    int y;
    char name[20];
    char symbol;
} Player;

// Function for generating random colors
int generateColor() {
    return rand() % 8;
}

// Function for drawing pixel art
void drawPixel(int color) {
    printf("\x1b[4%dm  ", color);
}

// Function for drawing the game board
void drawBoard(Player *players, int numPlayers) {
    system("clear");
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            int isPlayer = 0;
            Player *p = NULL;
            for (int i = 0; i < numPlayers; i++) {
                if (players[i].x == x && players[i].y == y) {
                    isPlayer = 1;
                    p = &players[i];
                    break;
                }
            }
            if (isPlayer) {
                drawPixel(p->symbol - 'A' + 1);
            } else {
                drawPixel(generateColor());
            }
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));
    
    Player players[4];
    strcpy(players[0].name, "Alice");
    players[0].symbol = 'A';
    players[0].x = 0;
    players[0].y = 0;
    strcpy(players[1].name, "Bob");
    players[1].symbol = 'B';
    players[1].x = WIDTH - 1;
    players[1].y = HEIGHT - 1;
    strcpy(players[2].name, "Charlie");
    players[2].symbol = 'C';
    players[2].x = WIDTH - 1;
    players[2].y = 0;
    strcpy(players[3].name, "Dave");
    players[3].symbol = 'D';
    players[3].x = 0;
    players[3].y = HEIGHT - 1;
    
    int numPlayers = 4;
    
    drawBoard(players, numPlayers);
    
    while (1) {
        for (int i = 0; i < numPlayers; i++) {
            printf("%s's turn. Enter direction (u/d/l/r): ", players[i].name);
            char dir;
            scanf("%c", &dir);
            getchar(); // remove newline
            switch (dir) {
                case 'u':
                    players[i].y--;
                    break;
                case 'd':
                    players[i].y++;
                    break;
                case 'l':
                    players[i].x--;
                    break;
                case 'r':
                    players[i].x++;
                    break;
                default:
                    printf("Invalid direction. Try again.\n");
                    i--;
            }
            drawBoard(players, numPlayers);
        }
    }
    
    return 0;
}