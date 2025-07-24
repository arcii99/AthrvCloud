//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <stdbool.h>

#define MAX_WIDTH 80
#define MAX_HEIGHT 80

char ASCII_CHARS[10] = {'#', '@', '%', '+', '=', '-', ':', '.', ' '};
int ASCII_CHARS_LEN = 9;

void generateImage(char *text, int textLength, bool saveToFile) {
    srand(time(NULL));
    char image[MAX_HEIGHT][MAX_WIDTH];
    memset(image, ' ', sizeof(image[0][0]) * MAX_HEIGHT * MAX_WIDTH);

    int index = rand() % ASCII_CHARS_LEN;

    for(int i = 0; i < textLength; i++) {
        int randomWidth = rand() % MAX_WIDTH;
        int randomHeight = rand() % MAX_HEIGHT;
        image[randomHeight][randomWidth] = ASCII_CHARS[index];
        index = rand() % ASCII_CHARS_LEN;
    }

    if(saveToFile) {
        char fileName[50];
        time_t t = time(NULL);
        struct tm tm = *localtime(&t);
        sprintf(fileName, "textArt_%d-%d-%d_%d:%d:%d.txt", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
        FILE *fp = fopen(fileName, "w");
        fprintf(fp, "ASCII Art Generated from the text: %s\n", text);
        for(int i = 0; i < MAX_HEIGHT; i++) {
            for(int j = 0; j < MAX_WIDTH; j++) {
                fprintf(fp, "%c", image[i][j]);
            }
            fprintf(fp, "\n");
        }
        fclose(fp);
    } else {
        printf("ASCII Art Generated from the text: %s\n", text);
        for(int i = 0; i < MAX_HEIGHT; i++) {
            for(int j = 0; j < MAX_WIDTH; j++) {
                printf("%c", image[i][j]);
            }
            printf("\n");
        }
    }
}

void generateTextArt(char *text, bool saveToFile) {
    int textLength = strlen(text);
    generateImage(text, textLength, saveToFile);
}

int main() {
    generateTextArt("Hello World", false);
    return 0;
}