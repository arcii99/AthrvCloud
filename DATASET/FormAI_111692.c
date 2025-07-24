//FormAI DATASET v1.0 Category: Image Editor ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Program to edit an image using C

int main() {
    char filename[100], choice;
    FILE *fp;

    printf("Enter the filename of the image you want to edit: ");
    scanf("%s", filename);

    fp = fopen(filename, "rb");

    if(fp == NULL) {
        printf("Error: File not found!\n");
        exit(1);
    }

    int height, width, colorDepth;
    char format[10];
    fscanf(fp, "%s%d%d%d", format, &width, &height, &colorDepth);
    printf("Image format: %s\n", format);
    printf("Image dimensions: %d x %d\n", width, height);
    printf("Color depth: %d\n", colorDepth);

    printf("Choose the editing option you want to perform:\n");
    printf("1. Increase brightness\n");
    printf("2. Decrease brightness\n");
    printf("3. Convert to grayscale\n");
    printf("4. Invert colors\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
    scanf(" %c", &choice);

    unsigned char byte[height][width][colorDepth];
    fread(byte, sizeof(byte), 1, fp);
    fclose(fp);

    switch(choice) {
        case '1':
            // Increase brightness by 50%
            for(int i=0; i<height; i++) {
                for(int j=0; j<width; j++) {
                    for(int k=0; k<colorDepth; k++) {
                        if((int)byte[i][j][k] + 127 > 255) {
                            byte[i][j][k] = 255;
                        }
                        else {
                            byte[i][j][k] += 127;
                        }
                    }
                }
            }
            printf("Image brightness increased by 50%%!\n");
            break;

        case '2':
            // Decrease brightness by 50%
            for(int i=0; i<height; i++) {
                for(int j=0; j<width; j++) {
                    for(int k=0; k<colorDepth; k++) {
                        if((int)byte[i][j][k] - 127 < 0) {
                            byte[i][j][k] = 0;
                        }
                        else {
                            byte[i][j][k] -= 127;
                        }
                    }
                }
            }
            printf("Image brightness decreased by 50%%!\n");
            break;

        case '3':
            // Convert to grayscale
            for(int i=0; i<height; i++) {
                for(int j=0; j<width; j++) {
                    int sum = 0;
                    for(int k=0; k<colorDepth; k++) {
                        sum += (int)byte[i][j][k];
                    }
                    int avg = sum/colorDepth;
                    for(int k=0; k<colorDepth; k++) {
                        byte[i][j][k] = (unsigned char)avg;
                    }
                }
            }
            printf("Image converted to grayscale!\n");
            break;

        case '4':
            // Invert colors
            for(int i=0; i<height; i++) {
                for(int j=0; j<width; j++) {
                    for(int k=0; k<colorDepth; k++) {
                        byte[i][j][k] = 255 - byte[i][j][k];
                    }
                }
            }
            printf("Image colors inverted!\n");
            break;

        case '5':
            // Exit
            printf("Exiting program...\n");
            exit(0);

        default:
            printf("Error: Invalid choice!\n");
            exit(1);
    }

    char newFilename[100];
    printf("Enter the filename to save the edited image: ");
    scanf("%s", newFilename);

    fp = fopen(newFilename, "wb");

    if(fp == NULL) {
        printf("Error: Could not create file!\n");
        exit(1);
    }

    fprintf(fp, "%s %d %d %d\n", format, width, height, colorDepth);
    fwrite(byte, sizeof(byte), 1, fp);
    fclose(fp);

    printf("Edited image saved to file!\n");

    return 0;
}