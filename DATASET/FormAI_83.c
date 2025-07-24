//FormAI DATASET v1.0 Category: Image Editor ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define constants for image dimensions
#define WIDTH 500
#define HEIGHT 500

// Declare function for creating random noise
void addNoise(char* img) {
    int i, j;
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            // Generate random values between 0-255 for RGB channels
            img[3*(i*WIDTH+j)] = rand() % 256; // Red Channel
            img[3*(i*WIDTH+j)+1] = rand() % 256; // Green Channel
            img[3*(i*WIDTH+j)+2] = rand() % 256; // Blue Channel
        }
    }
}

int main() {
    // Declare variables
    int choice;
    char filename[20];
    char img[3*WIDTH*HEIGHT];
    int i, j;

    // Generate random noise for image
    addNoise(img);

    // Display menu for user to choose different image effects
    printf("Welcome to the Cyberpunk Image Editor!\n");
    printf("Choose an option:\n");
    printf("1. Add Glitch Effect\n");
    printf("2. Add Vignette Effect\n");
    printf("3. Add Neon Glow Effect\n");
    printf("4. Save Image\n");
    printf("5. Exit\n");

    do {
        printf("Choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                // Add Glitch Effect
                for (i = 0; i < HEIGHT; i++) {
                    for (j = 0; j < WIDTH; j++) {
                        // Move each pixel randomly within its own block of 10x10 pixels
                        int x = j + (rand() % 10);
                        int y = i + (rand() % 10);

                        // Make sure pixel is within image dimensions
                        x = x >= WIDTH ? WIDTH-1 : x;
                        y = y >= HEIGHT ? HEIGHT-1 : y;

                        // Copy pixel data to new location
                        img[3*(i*WIDTH+j)] = img[3*(y*WIDTH+x)]; // Red Channel
                        img[3*(i*WIDTH+j)+1] = img[3*(y*WIDTH+x)+1]; // Green Channel
                        img[3*(i*WIDTH+j)+2] = img[3*(y*WIDTH+x)+2]; // Blue Channel
                    }
                }
                printf("Glitch Effect added!\n");
                break;

            case 2:
                // Add Vignette Effect
                for (i = 0; i < HEIGHT; i++) {
                    for (j = 0; j < WIDTH; j++) {
                        // Calculate distance from center pixel to current pixel
                        float dist = sqrt(pow(j-WIDTH/2, 2) + pow(i-HEIGHT/2, 2));
                        // Calculate brightness factor based on distance from center
                        float factor = (float)(1 - (dist / (sqrt(pow(WIDTH/2, 2) + pow(HEIGHT/2, 2)))));

                        // Apply brightness factor to each RGB channel
                        img[3*(i*WIDTH+j)] = (char)(img[3*(i*WIDTH+j)] * factor); // Red Channel
                        img[3*(i*WIDTH+j)+1] = (char)(img[3*(i*WIDTH+j)+1] * factor); // Green Channel
                        img[3*(i*WIDTH+j)+2] = (char)(img[3*(i*WIDTH+j)+2] * factor); // Blue Channel
                    }
                }
                printf("Vignette Effect added!\n");
                break;

            case 3:
                // Add Neon Glow Effect
                for (i = 0; i < HEIGHT; i++) {
                    for (j = 0; j < WIDTH; j++) {
                        // Add a white glow to neon colors (red, green, blue)
                        if (img[3*(i*WIDTH+j)] > 200 || img[3*(i*WIDTH+j)+1] > 200 || img[3*(i*WIDTH+j)+2] > 200) {
                            img[3*(i*WIDTH+j)] = 255; // Red Channel
                            img[3*(i*WIDTH+j)+1] = 255; // Green Channel
                            img[3*(i*WIDTH+j)+2] = 255; // Blue Channel
                        }
                    }
                }
                printf("Neon Glow Effect added!\n");
                break;

            case 4:
                // Save Image to file
                printf("Enter filename: ");
                scanf("%s", filename);

                FILE* fptr = fopen(filename, "wb");
                fwrite(img, sizeof(img), 1, fptr);
                fclose(fptr);

                printf("Image saved to file!\n");
                break;

            case 5:
                // Exit program
                printf("Exiting Cyberpunk Image Editor...\n");
                break;

            default:
                // Invalid choice
                printf("Invalid choice. Please choose a valid option.\n");
                break;
        }

    } while (choice != 5);

    return 0;
}