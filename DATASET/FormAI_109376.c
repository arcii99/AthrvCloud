//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function to generate digital watermark */
void generateWatermark(char *string, char *watermark) {
    char *temp = (char *)malloc(strlen(string) * sizeof(char));
    strcpy(temp, string);
    watermark[0] = '\0';

    while (*temp) {
        char digit[5];
        sprintf(digit, "%d", (int)*temp);
        strcat(watermark, digit);
        temp++;
    }

    free(temp);
}

/* Function to verify digital watermark */
int verifyWatermark(char *string, char *watermark) {
    char *temp = (char *)malloc(strlen(string) * sizeof(char));
    strcpy(temp, string);
    char *digit = strtok(watermark, ",");

    while (digit && *temp) {
        if ((int)*temp != atoi(digit)) {
            free(temp);
            return 0;
        }
        digit = strtok(NULL, ",");
        temp++;
    }

    free(temp);
    return 1;
}

int main() {
    char *string = "Hello, World!";
    char watermark[strlen(string) * 4];
    generateWatermark(string, watermark);

    printf("The digital watermark for \"%s\" is: %s\n", string, watermark);

    if (verifyWatermark(string, watermark)) {
        printf("Verification successful!\n");
    } else {
        printf("Verification failed.\n");
    }

    return 0;
}