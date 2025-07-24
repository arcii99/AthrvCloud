//FormAI DATASET v1.0 Category: Fractal Generation ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>

#define WIDTH 80 // width of the screen
#define HEIGHT 24 // height of the screen
#define MAX_DEPTH 100 // maximum depth of the fractal
#define MAX_PLAYERS 10 // maximum number of players in the game

int main()
{
    int i, j, k; // loop variables
    int x, y, z; // fractal coordinate variables
    int input; // variable for player input
    int depth = 0; // current depth of the fractal
    int player[MAX_PLAYERS] = {0}; // array of players
    char screen[HEIGHT][WIDTH]; // screen buffer
    char playerscreen[MAX_PLAYERS][HEIGHT][WIDTH]; // buffer for each player's screen
    
    // initialize screen buffer
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            screen[i][j] = ' ';
        }
    }
    
    // initialize player screen buffers
    for (i = 0; i < MAX_PLAYERS; i++) {
        for (j = 0; j < HEIGHT; j++) {
            for (k = 0; k < WIDTH; k++) {
                playerscreen[i][j][k] = ' ';
            }
        }
    }
    
    // main game loop
    while (1) {
        // check for player input
        for (i = 0; i < MAX_PLAYERS; i++) {
            printf("Player %d: ", i+1);
            scanf("%d", &input);
            if (input == 1) {
                player[i] = (player[i] + 1) % 2; // toggle player's current screen buffer
            } else if (input == 2) {
                depth++; // increase fractal depth
                if (depth > MAX_DEPTH) {
                    depth = MAX_DEPTH; // cap depth at maximum
                }
            } else if (input == 3) {
                depth--; // decrease fractal depth
                if (depth < 0) {
                    depth = 0; // cap depth at minimum
                }
            }
        }
        
        // generate fractal
        for (z = 0; z < depth; z++) {
            for (y = 0; y < HEIGHT; y++) {
                for (x = 0; x < WIDTH; x++) {
                    screen[y][x] = ' '; // initialize screen buffer with space characters
                    double a = (double)x / WIDTH * 4.0 - 2.0; // map x coordinate to between -2 and 2
                    double b = (double)y / HEIGHT * 4.0 - 2.0; // map y coordinate to between -2 and 2
                    double ca = a;
                    double cb = b;
                    int n;
                    for (n = 0; n < 100; n++) { // maximum number of iterations
                        double aa = a * a - b * b; // real part of z^2
                        double bb = 2 * a * b; // imaginary part of z^2
                        a = aa + ca; // real part of new z
                        b = bb + cb; // imaginary part of new z
                        if (a * a + b * b > 4.0) { // check if point is outside the mandelbrot set
                            screen[y][x] = '*'; // set screen buffer to asterisk character
                            break;
                        }
                    }
                }
            }
        }
        
        // display screens for each player
        for (i = 0; i < MAX_PLAYERS; i++) {
            for (j = 0; j < HEIGHT; j++) {
                for (k = 0; k < WIDTH; k++) {
                    if (player[i] == 0) {
                        printf("%c", screen[j][k]); // if player i is viewing the main screen, display fractal
                    } else if (player[i] == 1) {
                        printf("%c", playerscreen[i][j][k]); // if player i is viewing their own screen, display their buffer
                    }
                }
                printf("\n"); // new line for each row of characters
            }
            printf("\n"); // empty line between each player's screen
        }
    }
    
    return 0; // program finished successfully
}