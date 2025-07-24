//FormAI DATASET v1.0 Category: Fractal Generation ; Style: funny
#include <stdio.h>
#include <stdlib.h>

// A funny C Fractal Generation program
// Execution requires endless cups of coffee and patience
// be prepared, young apprentice.

void drawFractal(int n, int indent) {
    if (n <= 0) {
        return;
    }
    
    // first draw the spaces
    for (int i = 0; i < indent; i++) {
        printf(" ");
    }
    
    // then draw the asterisk
    printf("*\n");
    
    // draw the left branch
    drawFractal(n - 1, indent + 2);
    
    // draw the right branch
    drawFractal(n - 1, indent + 2);
}

int main() {
    printf("Welcome to the C Fractal Generation program!\n");
    printf("Please enter the depth of the fractal (must be a positive integer): ");
    
    int depth;
    scanf("%d", &depth);
    
    // validate input
    if (depth < 1) {
        printf("Invalid input. The depth must be a positive integer.\n");
        exit(1);
    }
    
    printf("Generating Fractal...\n");
    
    // start drawing the fractal
    drawFractal(depth, 0);
    
    printf("Fractal generated successfully. Your mind is now expanded.\n");
    
    return 0;
}