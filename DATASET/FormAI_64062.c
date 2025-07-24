//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){

    // Setting random seed
    srand(time(0));

    // Defining character set to be used
    char charset[] = {'0', '1'};

    // Defining pixel array
    char pixels[8][8];

    // Generating random pixel colors with ASCII art
    printf("\nGenerated Pixel Art:\n\n");
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            pixels[i][j] = charset[rand() % 2];
            printf(" %c ", pixels[i][j]);
        }
        printf("\n");
    }

    // Saving pixel art to file
    FILE *file;
    file = fopen("pixel_art.txt", "w");
    fprintf(file, "Generated Pixel Art:\n\n");
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            fprintf(file, " %c ", pixels[i][j]);
        }
        fprintf(file, "\n");
    }
    fclose(file);

    // Informing user of saved file location
    printf("\n\nPixel art saved to \"pixel_art.txt\" file!\n");

    return 0;
}