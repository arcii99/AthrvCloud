//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: funny
#include <stdio.h>

/* Define the magic number */
#define MAGIC_NUMBER 0xBEEF

/* Define the size of the watermark */
#define WATERMARK_SIZE 16

/* Define a function to add the watermark to the data */
void add_watermark(unsigned char *data, int data_size, char *watermark) {
    int i;
    unsigned short magic_number = MAGIC_NUMBER;

    /* Add the magic number to the beginning of the data */
    for (i = 0; i < sizeof(unsigned short); i++) {
        *(data + i) = *((unsigned char *)&magic_number + i);
    }

    /* Add the watermark to the end of the data */
    for (i = 0; i < WATERMARK_SIZE; i++) {
        *(data + data_size - WATERMARK_SIZE + i) = *(watermark + i);
    }
}

/* Define a function to check if the data has a valid watermark */
int check_watermark(unsigned char *data, int data_size, char *watermark) {
    int i, result = 1;
    unsigned short magic_number;

    /* Check if the magic number is valid */
    magic_number = *((unsigned short *)data);
    if (magic_number != MAGIC_NUMBER) {
        result = 0;
    }

    /* Check if the watermark is valid */
    for (i = 0; i < WATERMARK_SIZE; i++) {
        if (*(data + data_size - WATERMARK_SIZE + i) != *(watermark + i)) {
            result = 0;
        }
    }

    return result;
}

int main() {
    unsigned char data[1024] = {0};
    int data_size = 1024;
    char *watermark = "FUNWATERMARK1234";

    /* Add the watermark to the data */
    add_watermark(data, data_size, watermark);

    /* Check if the watermark is valid */
    if (check_watermark(data, data_size, watermark)) {
        printf("The data has a valid watermark!\n");
    } else {
        printf("The data does not have a valid watermark!\n");
    }

    return 0;
}