//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // seed the random generator

    int size = 10; // the size of the pixel art
    char art[size][size]; // the 2D array to store the art

    // fill the array with random characters
    for(int i=0; i<size; i++) {
        for(int j=0; j<size; j++) {
            int r = rand()%26; // pick a random number between 0 and 25
            char c = 'A' + r; // convert the number to a character
            art[i][j] = c; // store the character in the array
        }
    }

    // display the art
    printf("\n");
    printf("     ");
    for(int i=0; i<size; i++) {
        printf("%d ", i);
    }
    printf("\n");
    printf("     ");
    for(int i=0; i<size; i++) {
        printf("- ");
    }
    printf("\n");
    for(int i=0; i<size; i++) {
        printf("%d | ", i);
        for(int j=0; j<size; j++) {
            printf("%c ", art[i][j]);
        }
        printf("\n");
    }

    // the romantic message
    printf("\n");
    printf("You are the colors in my life,\n");
    printf("the pixels that make my heart beat.\n");
    printf("Every time I look at this art,\n");
    printf("I see a reflection of you in each pixel.\n");
    printf("You make my world a beautiful place,\n");
    printf("just as this pixel art makes my day.\n");
    printf("\n");

    return 0;
}