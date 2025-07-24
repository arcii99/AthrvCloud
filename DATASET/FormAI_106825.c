//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/* Size of the watermark */
#define WATERMARK_SIZE 100

/* File names */
#define INPUT_FILE "input.txt"
#define OUTPUT_FILE "output.txt"

/* Function prototypes */
void addWatermark(FILE *input, FILE *output, char *watermark);
int detectWatermark(FILE *file, char *watermark);

/* Main function */
int main() {
    /* Generate random watermark */
    char watermark[WATERMARK_SIZE];
    srand(time(NULL));
    for (int i = 0; i < WATERMARK_SIZE; i++) {
        watermark[i] = rand() % 256;
    }
    
    /* Add watermark to input file */
    FILE *input = fopen(INPUT_FILE, "r");
    FILE *output = fopen(OUTPUT_FILE, "w");
    addWatermark(input, output, watermark);
    fclose(input);
    fclose(output);
    
    /* Detect watermark from output file */
    FILE *file = fopen(OUTPUT_FILE, "r");
    int result = detectWatermark(file, watermark);
    fclose(file);
    
    /* Print result */
    if (result > 0) {
        printf("Watermark detected successfully!\n");
    } else {
        printf("Watermark not detected, something went wrong.\n");
    }
    
    return 0;
}

/* Adds the given watermark to the input file and writes the result to the output file */
void addWatermark(FILE *input, FILE *output, char *watermark) {
    char buffer;
    int i = 0;
    while ((buffer = fgetc(input)) != EOF) {
        if (i < WATERMARK_SIZE) {
            /* Add watermark to current byte */
            buffer += watermark[i];
        }
        fputc(buffer, output);
        i = (i + 1) % WATERMARK_SIZE;
    }
}

/* Detects the specified watermark in the given file */
int detectWatermark(FILE *file, char *watermark) {
    char buffer;
    int i = 0;
    int matchCount = 0;
    while ((buffer = fgetc(file)) != EOF) {
        if (i < WATERMARK_SIZE) {
            /* Subtract watermark from current byte */
            buffer -= watermark[i];
            if (buffer == 0) {
                /* If current byte equals original byte, mark as match */
                matchCount++;
            }
        }
        i = (i + 1) % WATERMARK_SIZE;
    }
    return matchCount;
}