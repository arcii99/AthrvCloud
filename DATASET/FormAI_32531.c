//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define IMAGE_HEIGHT 500
#define IMAGE_WIDTH 500

int main()
{
    int image[IMAGE_HEIGHT][IMAGE_WIDTH];
    int flip[IMAGE_HEIGHT][IMAGE_WIDTH];
    int brightness = 30;
    int contrast = 20;
    
    /* Code for loading image into image[][] */
    
    /* Flipping image horizontally */
    for(int i=0; i<IMAGE_HEIGHT; i++)
    {
        for(int j=0; j<IMAGE_WIDTH; j++)
        {
            flip[i][IMAGE_WIDTH-j-1] = image[i][j];
        }
    }

    /* Adjusting brightness and contrast of image */
    for(int i=0; i<IMAGE_HEIGHT; i++)
    {
        for(int j=0; j<IMAGE_WIDTH; j++)
        {
            int value = (image[i][j] + brightness) * contrast;
            if(value > 255)
                value = 255;
            else if(value < 0)
                value = 0;
            image[i][j] = value;
        }
    }

    /* Code for saving flipped and adjusted image into file */

    return 0;
}