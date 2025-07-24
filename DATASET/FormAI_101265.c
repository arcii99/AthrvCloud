//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: multivariable
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define ROWS 4
#define COLS 4

/* Define the secret key */
const char* secret_key = "Cryptography";

/* Define the image matrix */
int img_matrix[ROWS][COLS] = {
    {10, 20, 30, 40},
    {50, 60, 70, 80},
    {90, 100, 110, 120},
    {130, 140, 150, 160}
};

/* Function to generate digital watermark */
void generate_watermark(const char* msg, int watermark[ROWS][COLS]) {
    int len = strlen(secret_key);
    int msg_len = strlen(msg);
    int i, j, k = 0, sum = 0;
    
    for(i=0; i<ROWS; i++) {
        for(j=0; j<COLS; j++) {
            if(k < msg_len) { 
                sum = (int)msg[k++] + (int)secret_key[i % len];
                watermark[i][j] = sum % 10;
            }
            else {
                watermark[i][j] = 0;
            }
        }
    }
}

/* Function to embed the watermark into image */
void embed_watermark(int img[ROWS][COLS], const int watermark[ROWS][COLS]) {
    int i, j;
    
    for(i=0; i<ROWS; i++) {
        for(j=0; j<COLS; j++) {
            if(watermark[i][j] == 0)
                img[i][j] = img[i][j] - 1;
            else if(watermark[i][j] == 1)
                img[i][j] = img[i][j] + 1;
        }
    }
}

/* Function to extract the watermark from an embedded image */
void extract_watermark(const int img[ROWS][COLS], int watermark[ROWS][COLS]) {
    int i, j;
    
    for(i=0; i<ROWS; i++) {
        for(j=0; j<COLS; j++) {
            if(img[i][j] % 2 == 0)
                watermark[i][j] = 0;
            else if(img[i][j] % 2 == 1)
                watermark[i][j] = 1;
        }
    }
}

int main() {
    int i, j;
    char msg[100];
    int watermark[ROWS][COLS], extracted[ROWS][COLS];
    
    /* Get message to be watermarked from user */
    printf("Enter message to be watermarked:\n");
    scanf("%[^\n]%*c", msg);
    
    /* Generate the digital watermark */
    generate_watermark(msg, watermark);
    
    /* Print the original image */
    printf("Original Image:\n");
    for(i=0; i<ROWS; i++) {
        for(j=0; j<COLS; j++) {
            printf("%d\t", img_matrix[i][j]);
        }
        printf("\n");
    }
    
    /* Embed the digital watermark into the image */
    embed_watermark(img_matrix, watermark);
    
    /* Print the watermarked image */
    printf("Watermarked Image:\n");
    for(i=0; i<ROWS; i++) {
        for(j=0; j<COLS; j++) {
            printf("%d\t", img_matrix[i][j]);
        }
        printf("\n");
    }
    
    /* Extract the watermark from the watermarked image */
    extract_watermark(img_matrix, extracted);
    
    /* Print the extracted watermark */
    printf("Extracted Watermark:\n");
    for(i=0; i<ROWS; i++) {
        for(j=0; j<COLS; j++) {
            printf("%d\t", extracted[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}