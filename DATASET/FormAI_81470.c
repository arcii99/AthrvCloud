//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: multivariable
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    int n;
    printf("Enter the size of the canvas (n x n): ");
    scanf("%d",&n);
    char canvas[n][n];
    srand(time(0)); //Seed the random number generator
    
    //Fill the canvas with random pixels
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int c = rand()%2; //Randomly select a pixel color (0 or 1)
            if(c==0) canvas[i][j] = ' '; //If color is 0, make it black
            else canvas[i][j] = 'X'; //If color is 1, make it white
        }
    }
    
    //Display the canvas
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%c ",canvas[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}