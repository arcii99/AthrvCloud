//FormAI DATASET v1.0 Category: Image Steganography ; Style: beginner-friendly
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

/* Function to convert message bit to ascii */
char* bit_to_ascii(char* message) {
    int i, j, num = 0;
    char *ascii = malloc(strlen(message)/8 + 1);

    for(i = 0; i < strlen(message); i += 8) {
        for(j = 0; j < 8; j++) {
            num += (message[i+j]-'0') * (1 << (7-j));
        }
        ascii[i/8] = (char) num;
        num = 0;
    }
    ascii[i/8] = '\0';
    return ascii;
}

/* Function to convert ascii to message bit */
char* ascii_to_bit(char* ascii) {
    int i, j, num;
    char *message = malloc(strlen(ascii)*8 + 1);

    for(i = 0, j = 0; i < strlen(ascii); i++, j += 8) {
        num = (int) ascii[i];
        message[j]   = (num & 128) ? '1' : '0'; // 128 = 1000 0000
        message[j+1] = (num & 64)  ? '1' : '0'; //  64 = 0100 0000
        message[j+2] = (num & 32)  ? '1' : '0'; //  32 = 0010 0000
        message[j+3] = (num & 16)  ? '1' : '0'; //  16 = 0001 0000
        message[j+4] = (num & 8)   ? '1' : '0'; //   8 = 0000 1000
        message[j+5] = (num & 4)   ? '1' : '0'; //   4 = 0000 0100
        message[j+6] = (num & 2)   ? '1' : '0'; //   2 = 0000 0010
        message[j+7] = (num & 1)   ? '1' : '0'; //   1 = 0000 0001
    }
    message[j] = '\0';
    return message;
}

/* Function to hide message inside an image */
void hide_message(unsigned char *image_data, char *message_bit) {
    int i, j, bit_index = 0;

    for(i = 0; i < strlen(message_bit); i += 3) {
        for(j = 0; j < 3; j++) {
            if(bit_index >= strlen(message_bit)) {
                return;
            }
            image_data[i+j] = (image_data[i+j] & ~1) | (message_bit[bit_index] - '0');
            bit_index++;
        }
    }
}

/* Function to extract message from image */
char* extract_message(unsigned char *image_data, int image_size) {
    int i, j;
    char message_bit[8] = {};
    char *extracted_bit = malloc(image_size*3 + 1);

    for(i = 0, j = 0; i < image_size; i += 3) {
        message_bit[0] = (image_data[i]   & 1) + '0';
        message_bit[1] = (image_data[i+1] & 1) + '0';
        message_bit[2] = (image_data[i+2] & 1) + '0';

        extracted_bit[j]     = message_bit[0];
        extracted_bit[j+1] = message_bit[1];
        extracted_bit[j+2] = message_bit[2];
        j += 3;
    }
    extracted_bit[j] = '\0';
    return extracted_bit;
}

int main() {
    FILE *fileptr_img;
    char *filename = "image.jpg";
    unsigned char *image_data;
    int image_size;
    char *message = "hello world";
    char *message_bit, *ascii_message, *extracted_bit, *extracted_message;

    /* Read the image file and get its size */
    fileptr_img = fopen(filename, "rb");
    fseek(fileptr_img, 0, SEEK_END);
    image_size = ftell(fileptr_img);
    fseek(fileptr_img, 0, SEEK_SET);

    /* Allocate memory for the image data */
    image_data = malloc(image_size*sizeof(unsigned char));

    /* Read the image */
    fread(image_data, sizeof(unsigned char), image_size, fileptr_img);
    fclose(fileptr_img);

    /* Convert message from ascii to bit */
    ascii_message = strdup(message);
    for(int i = 0; i < strlen(ascii_message); i++) {
        ascii_message[i] = tolower(ascii_message[i]);
    }
    message_bit = ascii_to_bit(ascii_message);

    /* Hide the message in the image */
    hide_message(image_data, message_bit);

    /* Extract the message from the image */
    extracted_bit = extract_message(image_data, image_size);
    extracted_message = bit_to_ascii(extracted_bit);

    /* Print the original message and the extracted message */
    printf("Original message: %s\n", message);
    printf("Extracted message: %s\n", extracted_message);

    /* Free the memory */
    free(image_data);
    free(message_bit);
    free(ascii_message);
    free(extracted_bit);
    free(extracted_message);

    return 0;
}