//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10 // Change this to adjust the size of the canvas

// Color codes
#define BLACK 0
#define WHITE 1
#define RED 2
#define BLUE 3
#define YELLOW 4


// Function to generate random color code from 0 to max_color
int random_color(int max_color){
    return rand() % (max_color+1);
}

// Function to draw the canvas
void draw_canvas(int canvas[SIZE][SIZE]){
    for(int i=0; i<SIZE; i++){
        for(int j=0; j<SIZE; j++){
            switch(canvas[i][j]){
                case BLACK:
                    printf("\u25A0 ");
                    break;
                case WHITE:
                    printf("\u25A1 ");
                    break;
                case RED:
                    printf("\u25CF ");
                    break;
                case BLUE:
                    printf("\u25CB ");
                    break;
                case YELLOW:
                    printf("\u25C9 ");
                    break;
            }
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL)); // Initialize random seed

    int canvas[SIZE][SIZE] = {BLACK}; // Initialize canvas with all black pixels

    // Draw a heart in the canvas
    for(int i=3; i<=6; i++){
        for(int j=3; j<=7; j++){
            if((i==3 && (j==3 || j==7)) ||
                (i==4 && (j==2 || j==8)) ||
                (i>=5 && i<=6 && j>=2 && j<=8)){
                canvas[i][j] = RED;
            }
        }
    }

    // Randomly fill the rest of the canvas with colors
    for(int i=0; i<SIZE; i++){
        for(int j=0; j<SIZE; j++){
            if(canvas[i][j] == BLACK){
                canvas[i][j] = random_color(YELLOW);
            }
        }
    }

    // Draw the canvas
    draw_canvas(canvas);
    
    return 0;
}