//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

void print_watermark(char *watermark){
    printf("Digital Watermark: %s\n", watermark);
}

int main(void) {
    char *secret_message = "This is a secret message!";
    char *watermark = "1234567890abcdefghijklmnopqrstuvwxyz";
    int secret_message_length = strlen(secret_message);
    int watermark_length = strlen(watermark);

    char *watermarked_message = (char*)malloc(secret_message_length + watermark_length + 1);

    if(watermarked_message == NULL){ // if malloc return a null pointer it means there is an allocation error
        printf("Error: Could not allocate memory for watermarked message");
        return -1;
    }

    strcat(watermarked_message, secret_message);
    strcat(watermarked_message, watermark);

    print_watermark(watermark);
    printf("Original Message: %s\n", secret_message);
    printf("Watermarked Message: %s\n", watermarked_message);

    free(watermarked_message);
    watermarked_message = NULL;

    return 0;
}