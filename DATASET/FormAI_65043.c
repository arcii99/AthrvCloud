//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

const int MAX_LETTER_SIZE = 10;
const int MAX_HEIGHT_SIZE = 5;
const int MAX_WIDTH_SIZE = 5;

// Returns the height of a letter given width and ratio
int getHeight(int width, double ratio) {
    return (int)(width * ratio);
}

// Converts a character to its ASCII art representation
char** charToArt(char letter, int width, int height) {
    char** art = (char**) malloc(sizeof(char*) * height);
    for (int i = 0; i < height; i++) {
        art[i] = (char*) malloc(sizeof(char) * width);
        for (int j = 0; j < width; j++) {
            art[i][j] = ' ';
        }
    }

    if (isalpha(letter)) {
        letter = toupper(letter);
        FILE* file = fopen("letters.txt", "r");
        if (file == NULL) {
            printf("Could not open letters.txt\n");
            exit(1);
        }

        int asciiValue = letter - 'A' + 1;
        int rowOffset = MAX_LETTER_SIZE * (asciiValue - 1);
        char buffer[MAX_LETTER_SIZE];
        for (int i = 0; i < height; i++) {
            fgets(buffer, sizeof(buffer), file);
            for (int j = 0; j < width; j++) {
                art[i][j] = buffer[rowOffset + j];
            }
        }

        fclose(file);
    }

    return art;
}

// Prints an ASCII art letter
void printCharArt(char letter, int width, double ratio) {
    int height = getHeight(width, ratio);
    char** art = charToArt(letter, width, height);

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%c", art[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < height; i++) {
        free(art[i]);
    }
    free(art);
}

// Prints a word in ASCII art
void printWordArt(char* word, int width, double ratio) {
    int length = strlen(word);
    int height = getHeight(width, ratio);
    char*** arts = (char***) malloc(sizeof(char**) * height);
    for (int i = 0; i < height; i++) {
        arts[i] = (char**) malloc(sizeof(char*) * length);
    }

    for (int i = 0; i < length; i++) {
        arts[0][i] = charToArt(word[i], width, height)[0];
    }
    for (int i = 1; i < height; i++) {
        for (int j = 0; j < length; j++) {
            arts[i][j] = charToArt(word[j], width, height)[i];
        }
    }

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < length; j++) {
            printf("%s ", arts[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < length; j++) {
            free(arts[i][j]);
        }
        free(arts[i]);
    }
    free(arts);
}

int main() {
    char* word = "ASCII";
    int width = 5;
    double ratio = 0.5;
    printWordArt(word, width, ratio);

    return 0;
}