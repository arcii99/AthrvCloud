//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 1000
#define MAX_HEIGHT 1000

char ascii_chars[] = {' ','.',',',':','-','=','+','*','#','%','@'};

int main(int argc, char* argv[]) {
    char* filename = argv[1];
    FILE* fp = fopen(filename, "r");

    int width, height;
    char buffer[MAX_WIDTH];
    char grid[MAX_HEIGHT][MAX_WIDTH];

    fgets(buffer, MAX_WIDTH, fp);
    sscanf(buffer, "%d %d", &width, &height);

    for (int i=0; i<height; i++) {
        fgets(buffer, MAX_WIDTH, fp);
        strncpy(grid[i], buffer, width);
    }

    for (int i=0; i<height; i++) {
        for (int j=0; j<width; j++) {
            int brightness = grid[i][j];
            int ascii_index = brightness * (sizeof(ascii_chars)/sizeof(char)) / 256;
            printf("%c ", ascii_chars[ascii_index]);
        }
        printf("\n");
    }

    return 0;
}