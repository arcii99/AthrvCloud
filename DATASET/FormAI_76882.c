//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: invasive
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

char *chars = " .,-:;ox%#@";
int *grayscale;

int getWidth(FILE *f) {
    char buf[128];
    fgets(buf, 128, f);
    return strlen(buf) - 1;
}

void loadGrayscale(FILE *f, int width, int height) {
    grayscale = malloc(sizeof(int) * width * height);

    char buf[128];
    int i = 0;
    while (fgets(buf, 128, f) != NULL) {
        for (int j = 0; j < strlen(buf) - 1; j++) {
            grayscale[i + j] = (int)buf[j];
        }
        i += width;
    }
}

void convertToAscii(int width, int height) {
    int range = strlen(chars) - 1;

    for (int i = 0; i < width * height; i++) {
        int index = (int)((float)grayscale[i] / 256 * range);
        printf("%c", chars[index]);
        if ((i + 1) % width == 0) {
            printf("\n");
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("USAGE: %s <file>\n", argv[0]);
        return 1;
    }

    FILE *f = fopen(argv[1], "r");
    if (f == NULL) {
        printf("ERROR: could not open file %s\n", argv[1]);
        return 1;
    }

    int width = getWidth(f);
    rewind(f);
    int height = 0;
    char buf[128];
    while (fgets(buf, 128, f) != NULL) {
        height++;
    }

    rewind(f);
    loadGrayscale(f, width, height);
    fclose(f);

    convertToAscii(width, height);

    free(grayscale);
    return 0;
}