//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: detailed
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){

    srand(time(NULL));  //Seed for random values based on time
    char pixelArt[16][16]; //Array to hold the 16x16 pixel art
    

    //Loop through array and assign random values of O and X
    for(int i=0; i<16; i++){
        for(int j=0; j<16; j++){
            //Generate a random number between 0 and 1
            int randomNum = rand() % 2;

            //Assign values based on random number
            if(randomNum == 0){
                pixelArt[i][j] = 'O';
            }
            else{
                pixelArt[i][j] = 'X';
            }
        }
    }

    //Loop through array and print out the pixel art
    for(int i=0; i<16; i++){
        for(int j=0; j<16; j++){
            printf("%c ", pixelArt[i][j]);
        }
        printf("\n");
    }
    return 0;
}