//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: accurate
#include <stdio.h>  
#include <stdlib.h>  
#include <time.h>  
  
int main()  
{  
    int width, height, numPixels, numColors;  // initialize required variables  
    printf("Enter the Width and Height of Canvas: ");  
    scanf("%d %d",&width,&height);  // input width and height from user  
    printf("Enter the Number of Pixels: ");  
    scanf("%d",&numPixels);  // input number of pixels from user  
    printf("Enter the Number of Colors: ");  
    scanf("%d",&numColors);  // input number of colors from user  
      
    srand(time(NULL));  // initialize random seed using current time  
      
    for(int i=1;i<=numPixels;i++)  // loop to generate pixel values  
    {  
        int x = rand() % width;  // generate random x coordinate  
        int y = rand() % height;  // generate random y coordinate  
        int color = rand() % numColors;  // generate random color  
          
        printf("Paint pixel at (%d,%d) with color%d\n",x,y,color); // print generated pixel  
    }  
    return 0;  
}