//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: statistical
#include <stdio.h>

int main()
{
    int image[3][3] = {{1,1,1}, {2,2,2}, {3,3,3}}; //sample 3x3 image
    int brightness = 50; //brightness adjustment
    float contrast = 1.5; //contrast adjustment
    
    //flipping the image horizontally
    printf("Flipping the image horizontally:\n");
    for(int i=0; i<3; i++){
        for(int j=2; j>=0; j--){
            printf("%d ", image[i][j]);
        }
        printf("\n");
    }
    
    //adjusting the brightness of the image
    printf("\nAdjusting the brightness of the image:\n");
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            image[i][j] += brightness;
            printf("%d ", image[i][j]);
        }
        printf("\n");
    }
    
    //adjusting the contrast of the image
    printf("\nAdjusting the contrast of the image:\n");
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            image[i][j] = (int)( (image[i][j] - 128) * contrast + 128 );
            printf("%d ", image[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}