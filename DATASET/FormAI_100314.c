//FormAI DATASET v1.0 Category: Image Editor ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_WIDTH 100
#define MAX_HEIGHT 100

// Function to read input file
void read_input_file(char* file_name, char image[MAX_HEIGHT][MAX_WIDTH]) {
    FILE *fp = fopen(file_name, "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    int row = 0, col;
    char line[MAX_WIDTH];

    while(fgets(line, MAX_WIDTH, fp) != NULL) {
        col = 0;
        while(line[col] != '\n' && line[col] != '\0') {
            image[row][col] = line[col];
            col++;
        }
        row++;
    }

    fclose(fp);
}

// Function to write output file
void write_output_file(char* file_name, char image[MAX_HEIGHT][MAX_WIDTH], int height, int width) {
    FILE *fp = fopen(file_name, "w");
    if (fp == NULL) {
        printf("Error writing to file.\n");
        exit(1);
    }

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            fputc(image[i][j], fp);
        }
        fputc('\n', fp);
    }

    fclose(fp);
}

// Function to add two images
void add_images(char image1[MAX_HEIGHT][MAX_WIDTH], char image2[MAX_HEIGHT][MAX_WIDTH], char result[MAX_HEIGHT][MAX_WIDTH], int height, int width) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int sum = image1[i][j] - '0' + image2[i][j] - '0';
            result[i][j] = '0' + sum;
        }
    }
}

int main() {
    char input_file1[] = "image1.txt";
    char input_file2[] = "image2.txt";
    char output_file[] = "result.txt";

    char input_image1[MAX_HEIGHT][MAX_WIDTH], input_image2[MAX_HEIGHT][MAX_WIDTH], output_image[MAX_HEIGHT][MAX_WIDTH];
    int height, width;

    // Read input images
    read_input_file(input_file1, input_image1);
    read_input_file(input_file2, input_image2);

    // Check if images have the same dimensions
    height = strlen(input_image1);
    width = strlen(input_image1[0]);

    if (height != strlen(input_image2) || width != strlen(input_image2[0])) {
        printf("Images have different dimensions.\n");
        exit(1);
    }

    // Add images and write result to file
    add_images(input_image1, input_image2, output_image, height, width);
    write_output_file(output_file, output_image, height, width);

    printf("Images added successfully.\n");

    return 0;
}