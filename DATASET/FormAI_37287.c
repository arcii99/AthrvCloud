//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: secure
#include <stdio.h>
#include <stdlib.h>

//Function to generate a random number from 0-9
int generateNumber(){
    int num = rand()%10; //Using rand() function to generate a random number
    return num;
}

int main(){

    printf("\n====Welcome to the C Pixel Art Generator!====\n");

    //Creating a 2D array to represent the pixel grid
    int pixelGrid[10][10];

    //Filling the pixel grid with random numbers
    for(int i=0; i<10; i++){
        for(int j=0; j<10; j++){
            pixelGrid[i][j] = generateNumber();
        }
    }

    //Printing the pixel art on the screen
    for(int i=0; i<10; i++){
        for(int j=0; j<10; j++){
            printf("%d ", pixelGrid[i][j]);
        }
        printf("\n");
    }

    printf("\n====Thank you for using the C Pixel Art Generator!====\n");

    return 0;
}