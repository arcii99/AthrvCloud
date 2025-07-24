//FormAI DATASET v1.0 Category: Image Editor ; Style: funny
#include <stdio.h>

// Function definition
void imageEditor();
 
// Definition of a joke structure
struct Joke {
    char* setup;
    char* punchline;
};
 
// Array of jokes
struct Joke jokes[] = {
    {"Why was the programmer cold?", "Because he left his Windows open!"},
    {"Why did the tomato turn red?", "It saw the salad dressing!"},
    {"Why do we tell programmers to use their headlights?", "Because they can't C#!"},
    {"Why do emojis make bad programmers?", "Because they always return NULL!"},
    {"Why don't scientists trust atoms?", "Because they make up everything!"},
};
 
void imageEditor() {
    printf("Welcome to the C Image Editor!\n");

    // Let's tell a joke
    int i = rand() % 5;
    printf("\nHere's a joke for you: %s\n%s\n\n", jokes[i].setup, jokes[i].punchline);
 
    // Let's edit some pixels
    int w = 10;
    int h = 10;

    // Create an array for the pixels of our image
    int pixels[h][w];
 
    // Fill the image with random shades of gray
    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            pixels[i][j] = rand() % 256;
        }
    }

    // Print the original image
    printf("Original image:\n");
    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            printf("%3d ", pixels[i][j]);
        }
        printf("\n");
    }
 
    // Let's brighten the image
    printf("\nBrightening the image...\n");
    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            pixels[i][j] += 50;
        }
    }

    // Print the brightened image
    printf("Brightened image:\n");
    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            printf("%3d ", pixels[i][j]);
        }
        printf("\n");
    }

    // Let's invert the image
    printf("\nInverting the image...\n");
    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            pixels[i][j] = 255 - pixels[i][j];
        }
    }

    // Print the inverted image
    printf("Inverted image:\n");
    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            printf("%3d ", pixels[i][j]);
        }
        printf("\n");
    }

    printf("\nThanks for using the C Image Editor. Have a pixel-perfect day!\n");
}

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Call the imageEditor function
    imageEditor();

    return 0;
}