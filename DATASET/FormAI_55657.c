//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 80
#define MAX_HEIGHT 60

void drawImage(char *filename, char art[MAX_HEIGHT][MAX_WIDTH+1]) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("File not found.\n");
        exit(1);
    }
    char line[MAX_WIDTH+1];
    int row = 0;
    while (fgets(line, MAX_WIDTH+1, fp) != NULL && row < MAX_HEIGHT) {
        strncpy(art[row], line, MAX_WIDTH);
        art[row][strlen(art[row])-1] = '\0'; // replace '\n' with '\0'
        row++;
    }
    fclose(fp);
}

void convertToASCII(char art[MAX_HEIGHT][MAX_WIDTH+1], char asciiArt[MAX_HEIGHT][MAX_WIDTH*6+1]) {
    char chars[] = {'@', '#', 'S', '%', '?', '*', '+', ';', ':', ',', '.'};
    int numChars = strlen(chars);
    int vals[] = {0, 25, 50, 75, 100, 125, 150, 175, 200, 225, 250};
    int numVals = sizeof(vals)/sizeof(int);
    for (int i = 0; i < MAX_HEIGHT; i++) {
        for (int j = 0; j < MAX_WIDTH; j++) {
            int val = (int) (255.0 * (art[i][j] - '0') / 9.0);
            int charIndex = 0;
            while (charIndex < numChars-1 && vals[charIndex] < val) {
                charIndex++;
            }
            asciiArt[i][j*6+0] = chars[charIndex];
            asciiArt[i][j*6+1] = chars[charIndex];
            asciiArt[i][j*6+2] = chars[charIndex];
            asciiArt[i][j*6+3] = chars[charIndex];
            asciiArt[i][j*6+4] = chars[charIndex];
            asciiArt[i][j*6+5] = chars[charIndex];
        }
    }
}

void printASCII(char asciiArt[MAX_HEIGHT][MAX_WIDTH*6+1]) {
    for (int i = 0; i < MAX_HEIGHT; i++) {
        printf("%s\n", asciiArt[i]);
    }
}

int main(int argc, char *argv[]) {
    char art[MAX_HEIGHT][MAX_WIDTH+1];
    char asciiArt[MAX_HEIGHT][MAX_WIDTH*6+1];
    drawImage(argv[1], art);
    convertToASCII(art, asciiArt);
    printASCII(asciiArt);
    return 0;
}