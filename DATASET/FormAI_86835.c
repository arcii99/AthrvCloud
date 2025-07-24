//FormAI DATASET v1.0 Category: Image Editor ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

void menu() {
    printf("Welcome to the Image Editor:\n");
    printf("1. Load Image\n");
    printf("2. Convert to Grayscale\n");
    printf("3. Rotate Image\n");
    printf("4. Flip Image\n");
    printf("5. Invert Colors\n");
    printf("6. Save Image\n");
    printf("7. Exit\n");
}

int main() {
    //declare variables
    int choice, height, width, i, j, k, l;
    unsigned char (*image)[3] = NULL; //2D array for image data

    while(1) { //loop until user chooses to exit
        menu(); //display menu options
        printf("Enter choice: ");
        scanf("%d", &choice);

        if(choice == 1) { //load image
            char filename[100];

            printf("Enter filename: ");
            scanf("%s", filename);

            FILE *file = fopen(filename, "rb");
            if(!file) {
                printf("Error: Unable to open file!\n");
                continue;
            }

            //get image dimensions from file header
            fseek(file, 18, SEEK_SET);
            fread(&width, sizeof(int), 1, file);
            fread(&height, sizeof(int), 1, file);
            int padding = (4 - (width * 3) % 4) % 4; //padding to match 4-byte boundary

            //allocate memory for image data
            image = malloc(sizeof(unsigned char[height][3 * width]));

            //read image data from file, with padding
            for(i=0; i<height; i++) {
                for(j=0; j<width; j++) {
                    fread(&image[i][j*3], 3, 1, file);
                }
                fseek(file, padding, SEEK_CUR);
            }

            fclose(file);
            printf("Image loaded successfully!\n");
        }
        else if(choice == 2) { //convert to grayscale
            if(image == NULL) {
                printf("Error: No image loaded!\n");
                continue;
            }

            //convert each pixel using formula for grayscale
            for(i=0; i<height; i++) {
                for(j=0; j<width; j++) {
                    int avg = (image[i][j*3] + image[i][j*3+1] + image[i][j*3+2]) / 3;
                    image[i][j*3] = avg;
                    image[i][j*3+1] = avg;
                    image[i][j*3+2] = avg;
                }
            }

            printf("Image converted to grayscale!\n");
        }
        else if(choice == 3) { //rotate image
            if(image == NULL) {
                printf("Error: No image loaded!\n");
                continue;
            }

            //get user input for rotation angle and direction
            int angle, clockwise;
            printf("Enter rotation angle (90/180/270): ");
            scanf("%d", &angle);

            printf("Rotate clockwise or counterclockwise? (1=clockwise, 0=counterclockwise): ");
            scanf("%d", &clockwise);

            //allocate memory for rotated image data
            unsigned char (*rotated_image)[3] = malloc(sizeof(unsigned char[width][3 * height]));

            if(angle == 90) {
                //rotate 90 degrees clockwise
                for(i=0; i<width; i++) {
                    for(j=0, l=height-1; j<height; j++, l--) {
                        if(clockwise) {
                            rotated_image[i][j*3] = image[l][i*3];
                            rotated_image[i][j*3+1] = image[l][i*3+1];
                            rotated_image[i][j*3+2] = image[l][i*3+2];
                        }
                        else {
                            rotated_image[i][j*3] = image[j][i*3];
                            rotated_image[i][j*3+1] = image[j][i*3+1];
                            rotated_image[i][j*3+2] = image[j][i*3+2];
                        }
                    }
                }

                //update height and width variables
                int temp = height;
                height = width;
                width = temp;
            }
            else if(angle == 180) {
                //rotate 180 degrees
                for(i=0, k=width-1; i<height; i++, k--) {
                    for(j=0, l=height-1; j<width; j++, l--) {
                        rotated_image[i][j*3] = image[k][l*3];
                        rotated_image[i][j*3+1] = image[k][l*3+1];
                        rotated_image[i][j*3+2] = image[k][l*3+2];
                    }
                }
            }
            else if(angle == 270) {
                //rotate 270 degrees clockwise
                for(i=0, k=width-1; i<width; i++, k--) {
                    for(j=0; j<height; j++) {
                        if(clockwise) {
                            rotated_image[i][j*3] = image[j][k*3];
                            rotated_image[i][j*3+1] = image[j][k*3+1];
                            rotated_image[i][j*3+2] = image[j][k*3+2];
                        }
                        else {
                            rotated_image[i][j*3] = image[j][i*3];
                            rotated_image[i][j*3+1] = image[j][i*3+1];
                            rotated_image[i][j*3+2] = image[j][i*3+2];
                        }
                    }
                }

                //update height and width variables
                int temp = height;
                height = width;
                width = temp;
            }
            else {
                printf("Invalid angle specified!\n");
                free(rotated_image);
                continue;
            }

            //free original image data and assign rotated image data to original variable
            free(image);
            image = rotated_image;

            printf("Image rotated successfully!\n");
        }
        else if(choice == 4) { //flip image
            if(image == NULL) {
                printf("Error: No image loaded!\n");
                continue;
            }

            //get user input for flip direction
            int direction;
            printf("Flip horizontally or vertically? (1=horizontal, 0=vertical): ");
            scanf("%d", &direction);

            //allocate memory for flipped image data
            unsigned char (*flipped_image)[3] = malloc(sizeof(unsigned char[height][3 * width]));

            if(direction) {
                //flip horizontally
                for(i=0; i<height; i++) {
                    for(j=0, k=width-1; j<width; j++, k--) {
                        flipped_image[i][j*3] = image[i][k*3];
                        flipped_image[i][j*3+1] = image[i][k*3+1];
                        flipped_image[i][j*3+2] = image[i][k*3+2];
                    }
                }
            }
            else {
                //flip vertically
                for(i=0, k=height-1; i<height; i++, k--) {
                    for(j=0; j<width; j++) {
                        flipped_image[i][j*3] = image[k][j*3];
                        flipped_image[i][j*3+1] = image[k][j*3+1];
                        flipped_image[i][j*3+2] = image[k][j*3+2];
                    }
                }
            }

            //free original image data and assign flipped image data to original variable
            free(image);
            image = flipped_image;

            printf("Image flipped successfully!\n");
        }
        else if(choice == 5) { //invert colors
            if(image == NULL) {
                printf("Error: No image loaded!\n");
                continue;
            }

            //invert each pixel by subtracting its RGB values from 255 (assuming 8-bit color depth)
            for(i=0; i<height; i++) {
                for(j=0; j<width; j++) {
                    image[i][j*3] = 255 - image[i][j*3];
                    image[i][j*3+1] = 255 - image[i][j*3+1];
                    image[i][j*3+2] = 255 - image[i][j*3+2];
                }
            }

            printf("Image colors inverted!\n");
        }
        else if(choice == 6) { //save image
            if(image == NULL) {
                printf("Error: No image loaded!\n");
                continue;
            }

            char filename[100];
            printf("Enter filename: ");
            scanf("%s", filename);

            FILE *file = fopen(filename, "wb");
            if(!file) {
                printf("Error: Unable to open file!\n");
                continue;
            }

            //write image dimensions to file header
            fseek(file, 18, SEEK_SET);
            fwrite(&width, sizeof(int), 1, file);
            fwrite(&height, sizeof(int), 1, file);

            int padding = (4 - (width * 3) % 4) % 4;
            unsigned char *pad_data = calloc(padding, sizeof(char)); //padding array

            //write image data to file, with padding
            for(i=0; i<height; i++) {
                fwrite(&image[i][0], 3, width, file);
                fwrite(pad_data, 1, padding, file);
            }

            fclose(file);
            printf("Image saved successfully!\n");

            free(pad_data); //free padding array memory
        }
        else if(choice == 7) { //exit program
            printf("Goodbye!\n");
            break;
        }
        else {
            printf("Invalid choice! Try again.\n");
        }
    }

    //free image data memory
    if(image != NULL) {
        free(image);
    }

    return 0;
}