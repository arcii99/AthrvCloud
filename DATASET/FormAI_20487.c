//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* chars[] = {"#", "@", "%", "&", "*", "+", "=", "-", ".", " "};

void generateArt(char* message) {
    int length = strlen(message);
    int height = 10;
    int width = length * 10;

    char art[height][width];
    memset(art, ' ', sizeof(art));

    int i, j, k;
    for(i = 0; i < length; i ++) {
        int idx = message[i] - 65;
        for(j = 0; j < height; j ++) {
            for(k = i * 10; k < (i + 1) * 10; k ++) {
                int random = rand() % 10;
                if(random > j) {
                    art[j][k] = chars[idx][random];
                }
            }
        }
    }

    for(i = 0; i < height; i++) {
        for(j = 0; j < width; j++) {
            printf("%c", art[i][j]);
        }
        printf("\n");
    }
}

int main() {
    char message[] = "ASCII ART";
    generateArt(message);
    return 0;
}