//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: brave
#include <stdio.h>
#include <stdlib.h>

#define MAX_STR_LEN 1000
#define WATERMARK_LEN 10

void print_array(unsigned char *arr, int len) {
    printf("Array contents: \n");
    for (int i = 0; i < len; i++) {
        printf("%hhu ", arr[i]);
    }
    printf("\n");
}

int main() {
    unsigned char original_str[MAX_STR_LEN], watermarked_str[MAX_STR_LEN + WATERMARK_LEN];
    unsigned char watermark[WATERMARK_LEN] = {12, 42, 55, 32, 1, 101, 7, 25, 48, 63}; // sample watermark
    char c;
    int i, j;

    printf("Enter the original string: ");
    fgets(original_str, MAX_STR_LEN, stdin);

    // Adding the watermark to the original string
    i = 0;
    j = 0;
    while (original_str[i] != '\0') {
        watermarked_str[j] = original_str[i];
        j++;
        if (j == WATERMARK_LEN) {
            for (int k = 0; k < WATERMARK_LEN; k++) {
                watermarked_str[j] = (unsigned char)(watermarked_str[j - WATERMARK_LEN] ^ watermark[k]);
                j++;
            }
        }
        i++;
    }
    watermarked_str[j] = '\0';

    printf("Original string: %s", original_str);
    printf("Watermark: ");
    print_array(watermark, WATERMARK_LEN);
    printf("Watermarked string: %s\n", watermarked_str);

    // Retrieving the watermark from the watermarked string
    i = 0;
    j = 0;
    while (watermarked_str[i] != '\0') {
        if (j == WATERMARK_LEN) {
            for (int k = 0; k < WATERMARK_LEN; k++) {
                watermark[k] = (unsigned char)(watermarked_str[i - WATERMARK_LEN] ^ watermarked_str[i]);
                i++;
            }
            break;
        }
        j++;
        if (j == WATERMARK_LEN) {
            j = 0;
        }
        i++;
    }

    printf("Retrieved watermark: ");
    print_array(watermark, WATERMARK_LEN);

    return 0;
}