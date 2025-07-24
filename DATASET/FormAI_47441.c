//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: complete
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    int height,width,pixel;
    int i,j;
    
    //Getting inputs from user
    printf("Enter the height of the pixel art: ");
    scanf("%d",&height);
    printf("Enter the width of the pixel art: ");
    scanf("%d",&width);

    //Creating and initializing 2D array for pixel art
    int pixelArt[height][width];
    for(i=0;i<height;i++){
        for(j=0;j<width;j++){
            pixelArt[i][j]=0;
        }
    }
    
    //Setting random 1's in pixel art
    srand(time(0));
    for(i=0;i<height;i++){
        for(j=0;j<width;j++){
            pixel=rand()%2;
            pixelArt[i][j]=pixel;
        }
    }

    //Printing pixel art
    for(i=0;i<height;i++){
        for(j=0;j<width;j++){
            if(pixelArt[i][j]==1){
                printf("\u2588 "); //Full block unicode character for 1
            }
            else{
                printf("\u2591 "); //Light shade unicode character for 0
            }
        }
        printf("\n");
    }
    return 0;
}