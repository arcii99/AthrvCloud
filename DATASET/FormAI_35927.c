//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void generateWatermark(char *text, char *watermark, int length) {
    int i, j, k;
    int ascii = 0;
    char binary[1000];

    // Convert text to binary
    for (i = 0; i < length; i++) {
        ascii = (int)text[i];
        for (j = 0; j < 8; j++) {
            if (ascii % 2 == 0) {
                binary[(i * 8) + (7 - j)] = '0';
            } else {
                binary[(i * 8) + (7 - j)] = '1';
            }
            ascii /= 2;
        }
    }

    // Convert binary to watermark
    k = 0;
    for (i = 0; i < length * 8; i++) {
        if (binary[i] == '0' && binary[i+1] == '0') {
            watermark[k] = 'a';
            k++;
            i++;
        } else if (binary[i] == '0' && binary[i+1] == '1') {
            watermark[k] = 'b';
            k++;
            i++;
        } else if (binary[i] == '1' && binary[i+1] == '0') {
            watermark[k] = 'c';
            k++;
            i++;
        } else if (binary[i] == '1' && binary[i+1] == '1') {
            watermark[k] = 'd';
            k++;
            i++;
        }
    }
}

void retrieveWatermark(char *watermark, int length) {
    int i;
    char binary[1000];
    int ascii;
    char originalText[1000];

    // Convert watermark to binary
    for (i = 0; i < length; i++) {
        switch (watermark[i]) {
            case 'a':
                binary[(i * 2)] = '0';
                binary[(i * 2)+1] = '0';
                break;
            case 'b':
                binary[(i * 2)] = '0';
                binary[(i * 2)+1] = '1';
                break;
            case 'c':
                binary[(i * 2)] = '1';
                binary[(i * 2)+1] = '0';
                break;
            case 'd':
                binary[(i * 2)] = '1';
                binary[(i * 2)+1] = '1';
                break;
        }
    }

    // Convert binary to original text
    for (i = 0; i < length * 2; i += 8) {
        ascii = (int)(atoi(strncpy(originalText, &binary[i], 8)));
        printf("%c", ascii);
    }
}

int main() {
    char text[1000];
    char watermark[1000];
    int length;

    printf("Enter the text to be watermarked:\n");
    fgets(text, 1000, stdin);
    length = strlen(text)-1; // Remove the newline character

    generateWatermark(text, watermark, length);
    printf("The generated watermark is:\n%s\n", watermark);

    printf("Retrieving the watermark:\n");
    retrieveWatermark(watermark, length);

    return 0;
}