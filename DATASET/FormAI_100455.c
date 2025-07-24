//FormAI DATASET v1.0 Category: Image Steganography ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MESSAGE_LEN 10000

/* Function to hide the message in the given image file */
void lsb_stegano_hide(char* img_file, char* message_file, char* stegano_file)
{
    FILE *img_fp = fopen(img_file, "rb");
    FILE *message_fp = fopen(message_file, "rb");
    FILE *stegano_fp = fopen(stegano_file, "wb");

    if (!img_fp || !message_fp || !stegano_fp) {
        printf("Error opening files!\n");
        exit(1);
    }

    char message[MAX_MESSAGE_LEN];
    int message_len = fread(message, sizeof(char), MAX_MESSAGE_LEN, message_fp);
    message[message_len] = '\0';

    fseek(img_fp, 0, SEEK_END);
    long img_size = ftell(img_fp);
    rewind(img_fp);

    unsigned char *img_data = (unsigned char*)malloc(sizeof(unsigned char) * img_size);
    fread(img_data, sizeof(unsigned char), img_size, img_fp);

    for (int i = 0, j = 0; j < message_len; i += 3, ++j) {
        // Convert pixel color values to binary representation
        unsigned char b1 = (img_data[i] & 1);
        unsigned char b2 = (img_data[i + 1] & 1);
        unsigned char b3 = (img_data[i + 2] & 1);

        // Hide the message in the least significant bit
        b1 |= ((message[j] >> 7) & 1);
        b2 |= ((message[j] >> 6) & 1);
        b3 |= ((message[j] >> 5) & 1);

        img_data[i] = (img_data[i] & ~1) | b1;
        img_data[i + 1] = (img_data[i + 1] & ~1) | b2;
        img_data[i + 2] = (img_data[i + 2] & ~1) | b3;
    }

    fwrite(img_data, sizeof(unsigned char), img_size, stegano_fp);

    fclose(img_fp);
    fclose(message_fp);
    fclose(stegano_fp);

    free(img_data);
}

/* Function to extract message from the given stegano-image file */
void lsb_stegano_extract(char* stegano_file)
{
    FILE *stegano_fp = fopen(stegano_file, "rb");

    if (!stegano_fp) {
        printf("Error opening file!\n");
        exit(1);
    }

    fseek(stegano_fp, 0, SEEK_END);
    long stegano_size = ftell(stegano_fp);
    rewind(stegano_fp);

    unsigned char *stegano_data = (unsigned char*)malloc(sizeof(unsigned char) * stegano_size);
    fread(stegano_data, sizeof(unsigned char), stegano_size, stegano_fp);

    char message[MAX_MESSAGE_LEN];
    int message_len = 0;

    for (int i = 0, j = 0; j < MAX_MESSAGE_LEN; i += 3, ++j) {
        // Extract the message from the least significant bit
        message[j] = ((stegano_data[i] & 1) << 7) |
            ((stegano_data[i + 1] & 1) << 6) |
            ((stegano_data[i + 2] & 1) << 5);

        ++message_len;
    }

    printf("Extracted message: %s\n", message);

    fclose(stegano_fp);

    free(stegano_data);
}

/* Main function */
int main()
{
    char img_file[] = "image.bmp"; // Replace with the input image file name
    char message_file[] = "message.txt"; // Replace with the input message file name
    char stegano_file[] = "stegano-image.bmp"; // Replace with the output stegano-image file name

    // Hide the message in the image file
    lsb_stegano_hide(img_file, message_file, stegano_file);

    // Extract the message from the stegano-image file
    lsb_stegano_extract(stegano_file);

    return 0;
}