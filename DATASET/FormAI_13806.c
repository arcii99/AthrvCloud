//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char *filename;
    char *mode = "r";
    FILE *fptr;
    char c;
    int width, height, max_val;

    printf("Enter filename: ");
    scanf("%s", filename);

    fptr = fopen(filename, mode);

    if(fptr == NULL){
        printf("Error opening file!");
        exit(1);
    }

    char format[10]; 
    fscanf(fptr, "%s\n", format); // Get image format

    while ((c = fgetc(fptr)) == '#') {
        while (fgetc(fptr) != '\n') ;
    }
    ungetc(c, fptr); 

    fscanf(fptr, "%d %d\n", &width, &height); // Get image dimensions

    fscanf(fptr, "%d\n", &max_val); // Get max pixel value

    int img_arr[height][width][3]; // Create 3D array for image

    for(int i=0; i<height; i++) {
        for(int j=0; j<width; j++) {
            for(int k=0; k<3; k++) {
                fscanf(fptr, "%d", &img_arr[i][j][k]); // Store pixel values in 3D array
            }
        }
    }

    int choice;
    int temp_val;

    printf("Select a task:\n1. Flip Image\n2. Change Brightness/Contrast\n");
    scanf("%d", &choice);

    switch(choice) {
        case 1: // Flip Image
            for(int i=0; i<height; i++) {
                for(int j=0; j<width/2; j++) {
                    for(int k=0; k<3; k++) {
                        temp_val = img_arr[i][j][k];
                        img_arr[i][j][k] = img_arr[i][width-j-1][k];
                        img_arr[i][width-j-1][k] = temp_val;
                    }
                }
            }
            break;
        
        case 2: // Change Brightness/Contrast
            float brightness, contrast;
            printf("Enter brightness value (-255 to 255): ");
            scanf("%f", &brightness);
            printf("Enter contrast value (0.0 to 2.0): ");
            scanf("%f", &contrast);

            for(int i=0; i<height; i++) {
                for(int j=0; j<width; j++) {
                    for(int k=0; k<3; k++) {
                        img_arr[i][j][k] = (int)(contrast * ((float)img_arr[i][j][k] - 128) + 128 + brightness); // Apply brightness and contrast
                        if(img_arr[i][j][k] > 255) {
                            img_arr[i][j][k] = 255; // Ensure pixel value is within range
                        }
                        else if(img_arr[i][j][k] < 0) {
                            img_arr[i][j][k] = 0;
                        }
                    }
                }
            }
            break;

        default:
            printf("Invalid choice!");
            exit(1);
    }

    // Write modified image to file
    FILE *fout;
    char *outfile = "modified_image.ppm";
    fout = fopen(outfile, "w");

    fprintf(fout, "%s\n", format);
    fprintf(fout, "%d %d\n", width, height);
    fprintf(fout, "%d\n", max_val);

    for(int i=0; i<height; i++) {
        for(int j=0; j<width; j++) {
            for(int k=0; k<3; k++) {
                fprintf(fout, "%d ", img_arr[i][j][k]);
            }
            fprintf(fout, "\n");
        }
    }

    fclose(fout);

    printf("Task complete! Output written to %s\n", outfile);

    return 0;
}