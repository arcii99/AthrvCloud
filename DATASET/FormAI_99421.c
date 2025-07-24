//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 512
#define HEIGHT 512

/* Function to flip an image horizontally */
void flip_horizontal(unsigned char img[WIDTH][HEIGHT])
{
    int i, j;
    unsigned char temp;
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH/2; j++) {
            temp = img[i][j];
            img[i][j] = img[i][WIDTH-j-1];
            img[i][WIDTH-j-1] = temp;
        }
    }
}

/* Function to adjust the brightness of an image */
void adjust_brightness(unsigned char img[WIDTH][HEIGHT], int delta)
{
    int i, j;
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            img[i][j] = img[i][j] + delta;
            if (img[i][j] > 255)
                img[i][j] = 255;
            if (img[i][j] < 0)
                img[i][j] = 0;
        }
    }
}

/* Function to adjust the contrast of an image */
void adjust_contrast(unsigned char img[WIDTH][HEIGHT], float alpha)
{
    int i, j;
    float temp;
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            temp = alpha * (img[i][j] - 128) + 128;
            if (temp > 255)
                img[i][j] = 255;
            else if (temp < 0)
                img[i][j] = 0;
            else
                img[i][j] = (unsigned char)temp;
        }
    }
}

/* Function to display the image */
void display_image(unsigned char img[WIDTH][HEIGHT])
{
    int i,j;
    for(i=0;i<HEIGHT;i++){
        for(j=0;j<WIDTH;j++){
            printf("%u ",img[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    unsigned char img[WIDTH][HEIGHT];
    int choice, delta;
    float alpha;

    /* Generate a random image */
    int i, j;
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            img[i][j] = rand() % 256;
        }
    }

    /* User menu */
    printf("Choose a task to perform:\n");
    printf("1. Flip image horizontally\n");
    printf("2. Adjust brightness\n");
    printf("3. Adjust contrast\n");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            flip_horizontal(img);
            printf("Image flipped horizontally.\n");
            break;
        case 2:
            printf("Enter brightness delta (-255 to 255): ");
            scanf("%d", &delta);
            adjust_brightness(img, delta);
            printf("Brightness adjusted.\n");
            break;
        case 3:
            printf("Enter contrast alpha (0 to 10): ");
            scanf("%f", &alpha);
            adjust_contrast(img, alpha);
            printf("Contrast adjusted.\n");
            break;
        default:
            printf("Invalid choice.\n");
            break;
    }

    // Display the modified image
    display_image(img);

    return 0;
}