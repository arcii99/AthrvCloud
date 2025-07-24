//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: puzzling
#include <stdio.h>

int main() {

    printf("Welcome to the puzzling image processing program!\n");

    // initialize variables
    int image[10][10];
    int i, j, choice, flip;

    // generate random image
    for(i=0; i<10; i++) {
        for(j=0; j<10; j++) {
            image[i][j] = rand() % 256;
        }
    }

    // display original image
    printf("\nOriginal image:\n");
    for(i=0; i<10; i++) {
        for(j=0; j<10; j++) {
            printf("%d ", image[i][j]);
        }
        printf("\n");
    }

    // ask for user input
    printf("\nWhat would you like to do with the image?\n");
    printf("1. Flip the image\n");
    printf("2. Adjust brightness\n");
    printf("3. Adjust contrast\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    // process user input
    switch (choice) {
        case 1:
            printf("\nWhich direction would you like to flip the image?\n");
            printf("1. Horizontal\n");
            printf("2. Vertical\n");
            printf("Enter your choice: ");
            scanf("%d", &flip);

            // flip image horizontally
            if(flip == 1) {
                for(i=0; i<10; i++) {
                    for(j=0; j<5; j++) {
                        int temp = image[i][j];
                        image[i][j] = image[i][9-j];
                        image[i][9-j] = temp;
                    }
                }
                printf("\nFlipped horizontally!\n");
            }

            // flip image vertically
            else if(flip == 2) {
                for(i=0; i<5; i++) {
                    for(j=0; j<10; j++) {
                        int temp = image[i][j];
                        image[i][j] = image[9-i][j];
                        image[9-i][j] = temp;
                    }
                }
                printf("\nFlipped vertically!\n");
            }

            // wrong input
            else {
                printf("\nInvalid input! Aborting...\n");
                return 0;
            }

            // display flipped image
            printf("\nFlipped image:\n");
            for(i=0; i<10; i++) {
                for(j=0; j<10; j++) {
                    printf("%d ", image[i][j]);
                }
                printf("\n");
            }
            break;

        case 2:
            printf("\nBy how much would you like to adjust the brightness?\n");
            printf("Enter a value between -255 and 255: ");
            int brightness;
            scanf("%d", &brightness);

            // adjust brightness
            for(i=0; i<10; i++) {
                for(j=0; j<10; j++) {
                    image[i][j] += brightness;
                    if(image[i][j] < 0) {
                        image[i][j] = 0;
                    }
                    else if(image[i][j] > 255) {
                        image[i][j] = 255;
                    }
                }
            }
            printf("\nBrightness adjusted by %d!\n", brightness);

            // display adjusted image
            printf("\nAdjusted image:\n");
            for(i=0; i<10; i++) {
                for(j=0; j<10; j++) {
                    printf("%d ", image[i][j]);
                }
                printf("\n");
            }
            break;

        case 3:
            printf("\nBy how much would you like to adjust the contrast?\n");
            printf("Enter a value between -127 and 127: ");
            int contrast;
            scanf("%d", &contrast);

            // adjust contrast
            for(i=0; i<10; i++) {
                for(j=0; j<10; j++) {
                    image[i][j] = (int)(image[i][j] * contrast / 127.0);
                    if(image[i][j] < 0) {
                        image[i][j] = 0;
                    }
                    else if(image[i][j] > 255) {
                        image[i][j] = 255;
                    }
                }
            }
            printf("\nContrast adjusted by %d!\n", contrast);

            // display adjusted image
            printf("\nAdjusted image:\n");
            for(i=0; i<10; i++) {
                for(j=0; j<10; j++) {
                    printf("%d ", image[i][j]);
                }
                printf("\n");
            }
            break;

        default:
            printf("\nInvalid input! Aborting...\n");
            return 0;
    }

    // goodbye message
    printf("\nThank you for using the puzzling image processing program!\n");
    return 0;
}