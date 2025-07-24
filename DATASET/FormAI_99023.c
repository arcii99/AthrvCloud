//FormAI DATASET v1.0 Category: Image Steganography ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encode(char *input_image, char *output_image, char *message) {
    FILE *fptr1, *fptr2;
    char buffer, ch;
    int i = 0;

    fptr1 = fopen(input_image, "rb");
    fptr2 = fopen(output_image, "wb");

    while(!feof(fptr1)) {
        fread(&buffer, sizeof(char), 1, fptr1);

        if(i < strlen(message)) {
            ch = message[i];

            for(int bit = 0; bit < 8; bit++) {
                int value = (ch >> bit) & 1;

                buffer = (buffer & 0xFE) | value;

                fwrite(&buffer, sizeof(char), 1, fptr2);
                fread(&buffer, sizeof(char), 1, fptr1);
            }
        } else {
            fwrite(&buffer, sizeof(char), 1, fptr2);
        }

        i++;
    }

    fclose(fptr1);
    fclose(fptr2);
}

void decode(char *output_image, int message_length) {
    FILE *fptr;
    char buffer, ch;
    int i = 0;

    fptr = fopen(output_image, "rb");

    while(!feof(fptr) && i < message_length) {
        ch = 0;

        for(int bit = 0; bit < 8; bit++) {
            fread(&buffer, sizeof(char), 1, fptr);

            ch = ch | ((buffer & 1) << bit);
        }

        printf("%c", ch);

        i++;
    }

    fclose(fptr);
}

int main() {
    char input_image[] = "input_image.bmp";
    char output_image[] = "output_image.bmp";
    char message[] = "This message is hidden in the image";
    int message_length = strlen(message);

    encode(input_image, output_image, message);

    printf("Message encoded successfully.\n");

    decode(output_image, message_length);

    return 0;
}