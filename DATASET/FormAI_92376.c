//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define image size
#define IMAGE_SIZE 64

// Define watermark size
#define WM_SIZE 8

// Define secret key
#define SECRET_KEY "MySecretKey"

// Function to get current time in string format
void get_current_time(char *time_str) {
    time_t raw_time;
    struct tm *time_info;
    time(&raw_time);
    time_info = localtime(&raw_time);
    strftime(time_str, 80, "%Y-%m-%d %H:%M:%S", time_info);
}

int main() {
    // Initialize image and watermark with random values between 0 and 255
    unsigned char image[IMAGE_SIZE][IMAGE_SIZE];
    unsigned char watermark[WM_SIZE][WM_SIZE];
    srand(time(NULL));
    for (int i = 0; i < IMAGE_SIZE; i++) {
        for (int j = 0; j < IMAGE_SIZE; j++) {
            image[i][j] = rand() % 256;
        }
    }
    for (int i = 0; i < WM_SIZE; i++) {
        for (int j = 0; j < WM_SIZE; j++) {
            watermark[i][j] = rand() % 256;
        }
    }

    // Print original image and watermark
    printf("Original Image:\n");
    for (int i = 0; i < IMAGE_SIZE; i++) {
        for (int j = 0; j < IMAGE_SIZE; j++) {
            printf("%03u ", image[i][j]);
        }
        printf("\n");
    }
    printf("\nOriginal Watermark:\n");
    for (int i = 0; i < WM_SIZE; i++) {
        for (int j = 0; j < WM_SIZE; j++) {
            printf("%03u ", watermark[i][j]);
        }
        printf("\n");
    }

    // Embed watermark using digital watermarking algorithm
    char time_info[80];
    get_current_time(time_info);
    int k = 0;
    for (int i = 0; i < WM_SIZE; i++) {
        for (int j = 0; j < WM_SIZE; j++) {
            int x = i + k;
            int y = j + k;
            int p = ((x + y) % 2 == 0) ? 1 : -1;
            int wm_p = watermark[i][j] * p;
            int wm_p_prime = wm_p + (image[x][y] - wm_p) * strlen(SECRET_KEY);
            image[x][y] = (unsigned char) wm_p_prime;
            k++;
        }
    }

    // Print watermarked image
    printf("\nWatermarked Image:\n");
    for (int i = 0; i < IMAGE_SIZE; i++) {
        for (int j = 0; j < IMAGE_SIZE; j++) {
            printf("%03u ", image[i][j]);
        }
        printf("\n");
    }

    // Extract embedded watermark using digital watermarking algorithm
    k = 0;
    unsigned char extracted_wm[WM_SIZE][WM_SIZE];
    for (int i = 0; i < WM_SIZE; i++) {
        for (int j = 0; j < WM_SIZE; j++) {
            int x = i + k;
            int y = j + k;
            int p = ((x + y) % 2 == 0) ? 1 : -1;
            int extracted_wm_p_prime = (image[x][y] - watermark[i][j] * p) / strlen(SECRET_KEY);
            extracted_wm[i][j] = (unsigned char) extracted_wm_p_prime;
            k++;
        }
    }

    // Print extracted watermark
    printf("\nExtracted Watermark:\n");
    for (int i = 0; i < WM_SIZE; i++) {
        for (int j = 0; j < WM_SIZE; j++) {
            printf("%03u ", extracted_wm[i][j]);
        }
        printf("\n");
    }

    // Verify extracted watermark is equal to original watermark
    int is_verified = 1;
    for (int i = 0; i < WM_SIZE; i++) {
        for (int j = 0; j < WM_SIZE; j++) {
            if (extracted_wm[i][j] != watermark[i][j]) {
                is_verified = 0;
                break;
            }
        }
        if (!is_verified) {
            break;
        }
    }

    if (is_verified) {
        printf("\nDigital watermarking was successful!\n");
    } else {
        printf("\nDigital watermarking failed!\n");
    }

    return 0;
}