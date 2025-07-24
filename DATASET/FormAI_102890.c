//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10 //size of the pixel art

void generatePixelArt(char art[SIZE][SIZE]); //function to generate the pixel art
void displayPixelArt(char art[SIZE][SIZE]); //function to display the pixel art
void savePixelArt(char art[SIZE][SIZE]); //function to save the pixel art to a file

int main() {
    char art[SIZE][SIZE]; //declare the pixel art array
    
    generatePixelArt(art); //call the function to generate the pixel art
    displayPixelArt(art); //display the pixel art
    savePixelArt(art); //save the pixel art to a file
    
    return 0;
}

//function to generate the pixel art
void generatePixelArt(char art[SIZE][SIZE]) {
    srand(time(NULL)); //seed the random number generator
    
    //loop through each pixel in the array and randomly assign it a '0' or '1' value
    for(int i = 0; i < SIZE; i++) {
        for(int j = 0; j < SIZE; j++) {
            int randNum = rand() % 2; //generate a random number between 0 and 1
            if(randNum == 0) {
                art[i][j] = '0'; //assign '0' to the pixel
            }
            else {
                art[i][j] = '1'; //assign '1' to the pixel
            }
        }
    }
}

//function to display the pixel art
void displayPixelArt(char art[SIZE][SIZE]) {
    //loop through each pixel in the array and print it to the console
    for(int i = 0; i < SIZE; i++) {
        for(int j = 0; j < SIZE; j++) {
            printf("%c ", art[i][j]); //print the pixel value
        }
        printf("\n"); //move to the next row
    }
}

//function to save the pixel art to a file
void savePixelArt(char art[SIZE][SIZE]) {
    FILE *fp; //declare file pointer
    fp = fopen("pixelArt.txt", "w"); //open file for writing
    
    //loop through each pixel in the array and write it to the file
    for(int i = 0; i < SIZE; i++) {
        for(int j = 0; j < SIZE; j++) {
            fputc(art[i][j], fp); //write the pixel value to the file
        }
        fprintf(fp, "\n"); //move to the next row
    }
    
    fclose(fp); //close the file
}