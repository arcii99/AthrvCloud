//FormAI DATASET v1.0 Category: Recursive ; Style: futuristic
#include <stdio.h>

// Welcome to the future of computing! 
// This program will demonstrate the power of recursion and the wonders of the infinite universe.

void generateFractalGalaxy(int size){
    if(size <= 0){
        return;
    }
    
    // Creating an empty galaxy
    char galaxy[size][size];
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            galaxy[i][j] = '-';
        }
    }
    
    // Creating a black hole in the middle of the galaxy
    int center = size/2;
    galaxy[center][center] = '*';
    
    // Creating supernovae in three corners of the galaxy
    galaxy[0][0] = '!';
    galaxy[0][size-1] = '!';
    galaxy[size-1][0] = '!';
    
    // Creating a wormhole in the remaining corner
    galaxy[size-1][size-1] = '@';
    
    // Printing the current state of the galaxy
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            printf("%c ", galaxy[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    
    // Shrinking the current galaxy and calling the function recursively
    generateFractalGalaxy(size/2);
}

int main(){
    // Get ready for the ride of your life!
    // Set the size of the galaxy and let recursion take over.
    int size = 32;
    generateFractalGalaxy(size);
    
    return 0;
}