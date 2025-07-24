//FormAI DATASET v1.0 Category: Fractal Generation ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void drawFractal(int level, int x1, int y1, int x2, int y2){
    if(level == 0) return;
    
    // Calculate distance between two points
    int deltaX = x2 - x1;
    int deltaY = y2 - y1;
    
    // Calculate midpoint coordinates
    int midX = (x1 + x2) / 2;
    int midY = (y1 + y2) / 2;
    
    // Calculate new coordinate pairs for fractal lines
    int leftX = midX - deltaY / 2;
    int leftY = midY + deltaX / 2;
    int rightX = midX + deltaY / 2;
    int rightY = midY - deltaX / 2;
    
    // Draw line segments using calculated coordinates
    drawFractal(level - 1, x1, y1, leftX, leftY);
    drawFractal(level - 1, leftX, leftY, midX, midY);
    drawFractal(level - 1, midX, midY, rightX, rightY);
    drawFractal(level - 1, rightX, rightY, x2, y2);
}

int main(){
    // Define variables for drawing
    int screenWidth = 800;
    int screenHeight = 600;
    int level = 5;
    int startX = 50;
    int startY = 300;
    int endX = screenWidth - 50;
    int endY = startY;
    
    // Open new window and set background color
    printf("graphics window\n");
    printf("500 500\n");
    printf("bgcolor 255 255 255\n");
    
    // Draw fractal using above variables
    drawFractal(level, startX, startY, endX, endY);
    
    // Close window and exit program
    printf("endwin\n");
    return 0;
}