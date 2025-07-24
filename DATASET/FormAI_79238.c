//FormAI DATASET v1.0 Category: Computer Biology ; Style: funny
#include<stdlib.h>
#include<stdio.h>

int main(){
    int num_cells = 100;
    int num_divisions = 0;
    printf("Welcome to the Cell Division Simulator!\n");
    printf("Initial number of cells: %d\n", num_cells);
    while(num_cells < 1000000){
        //cell division code
        num_divisions++;
        num_cells *= 2;
        printf("Number of cells after %d divisions: %d\n", num_divisions, num_cells);
    }
    printf("Oops! The cells have taken over the world! Terminating program...");
    exit(0);
}