//FormAI DATASET v1.0 Category: Image Classification system ; Style: random
#include<stdio.h>
#include<stdlib.h>

int main(){

    // Initialize image data into 2D array
    int image[10][10] = {{1,2,1,1,3,2,1,1,2,1},
                         {2,3,3,2,1,2,1,1,3,1},
                         {1,3,2,2,1,3,1,2,2,1},
                         {1,2,3,3,1,2,2,3,3,1},
                         {3,1,2,3,3,2,1,2,1,2},
                         {3,2,3,1,3,1,2,2,2,3},
                         {2,3,2,2,2,1,2,1,3,2},
                         {3,3,1,2,1,3,1,1,2,2},
                         {2,1,2,3,2,1,2,1,1,3},
                         {2,1,2,3,2,1,3,1,2,2}};

    // Initialize target image value
    int target_value = 2;

    // Loop through each pixel to check if it matches target value
    for(int i=0; i<10; i++){
        for(int j=0; j<10; j++){
            if(image[i][j] == target_value){
                printf("Pixel at (%d,%d) matches target value!\n", i, j);
            }
        }
    }

    // Return success code
    return 0;
}