//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int MAX_LEN = 1000;

int main() {
    char originalText[MAX_LEN];
    char watermarkText[MAX_LEN];
    char watermarkedText[MAX_LEN];

    FILE *pFile = fopen("original_text.txt", "r");
    if (pFile == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }
    fgets(originalText, MAX_LEN, pFile);
    fclose(pFile);

    printf("Enter the watermark text: ");
    fgets(watermarkText, MAX_LEN, stdin);

    // Generate the watermarked text
    int lenOriginalText = strlen(originalText);
    int lenWatermarkText = strlen(watermarkText);
    char *pOriginalText = originalText;
    char *pWatermarkText = watermarkText;
    char *pWatermarkedText = watermarkedText;
    int count = 0;
    while (*pOriginalText != '\0') {
        *pWatermarkedText = *pOriginalText;
        if (count < lenWatermarkText) {
            *pWatermarkedText += (*pWatermarkText - '0');
            pWatermarkText++;
            count++;
        }
        pOriginalText++;
        pWatermarkedText++;
    }
    *pWatermarkedText = '\0';

    // Write the watermarked text to a file
    pFile = fopen("watermarked_text.txt", "w");
    if (pFile == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }
    fprintf(pFile, "%s", watermarkedText);
    fclose(pFile);

    // Verify the watermarked text
    pFile = fopen("watermarked_text.txt", "r");
    if (pFile == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }
    char verifiedText[MAX_LEN];
    fgets(verifiedText, MAX_LEN, pFile);
    fclose(pFile);

    char *pVerifiedText = verifiedText;
    pWatermarkText = watermarkText;
    pOriginalText = originalText;
    count = 0;
    while (*pVerifiedText != '\0') {
        if (*pVerifiedText != *pOriginalText) {
            printf("The watermarked text is not verified\n");
            return EXIT_FAILURE;
        }
        if (count < lenWatermarkText) {
            *pOriginalText += (*pWatermarkText - '0');
            pWatermarkText++;
            count++;
        }
        pVerifiedText++;
        pOriginalText++;
    }
    printf("The watermarked text is verified\n");

    return EXIT_SUCCESS;
}