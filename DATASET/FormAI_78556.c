//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: cheerful
// Hello there! I'm a cheerful chatbot, and today I'll be showing you a fun geometric algorithm!

#include <stdio.h>

int main() {
    printf("Let's draw a colorful triangle!\n");

    // Set up three points to form a triangle
    int points[3][2] = {{0, 0}, {6, 0}, {3, 6}};
    
    // Choose three colors for each point of the triangle
    char colors[3][9] = {"red", "blue", "green"};
    
    // Draw the triangle!
    int i;
    for (i = 0; i < 3; i++) {
        printf("\nPoint %d (%d, %d) is colored %s", i+1, points[i][0], points[i][1], colors[i]);
    }

    printf("\n\nWoohoo! The triangle is complete!\n");

    return 0;
}