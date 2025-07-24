//FormAI DATASET v1.0 Category: Image Steganography ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

#define MAX_FILE_SIZE 10000

void hide_msg(char *img_data, char *msg) {
    int i, j;
    char bit, byte;
    
    for (i = 0; msg[i] != '\0'; i++) {
        byte = msg[i];
        for (j = 0; j < 8; j++) {
            bit = (byte >> j) & 1;
            if (bit == 1) {
                img_data[i*3 + j] |= 1;
            }
            else {
                img_data[i*3 + j] &= ~1;
            }
        }
    }
}

void extract_msg(char *img_data, char *msg, int size) {
    int i, j;
    char byte = 0;
    
    for (i = 0; i < size; i++) {
        for (j = 0; j < 8; j++) {
            byte |= ((img_data[i*3 + j] & 1) << j);
        }
        msg[i] = byte;
        if (msg[i] == '\0') {
            break;
        }
        byte = 0;
    }
}

int main() {
    FILE *img_file, *out_file;
    char img_data[MAX_FILE_SIZE], secret_msg[MAX_FILE_SIZE], out_data[MAX_FILE_SIZE];
    int img_size, msg_size;
    
    /* open image file */
    img_file = fopen("image.bmp", "rb");
    if (img_file == NULL) {
        printf("Error: file not found");
        return 1;
    }
    
    /* read image data */
    img_size = fread(img_data, 1, MAX_FILE_SIZE, img_file);
    fclose(img_file);
    
    /* get secret message from user */
    printf("Enter your secret message:\n");
    fgets(secret_msg, MAX_FILE_SIZE, stdin);
    msg_size = strlen(secret_msg);
    
    /* hide secret message in image data */
    hide_msg(img_data+54, secret_msg);
    
    /* write modified image data to new file */
    out_file = fopen("secret_image.bmp", "wb");
    fwrite(img_data, 1, img_size, out_file);
    fclose(out_file);
    
    /* read modified image data */
    img_file = fopen("secret_image.bmp", "rb");
    fread(out_data, 1, img_size, img_file);
    fclose(img_file);
    
    /* extract secret message from modified image data */
    extract_msg(out_data+54, secret_msg, msg_size);
    
    /* print extracted message */
    printf("Extracted message:\n%s", secret_msg);
    
    return 0;
}