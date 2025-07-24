//FormAI DATASET v1.0 Category: Pattern printing ; Style: post-apocalyptic
#include<stdio.h>
#include<stdlib.h>

// Function to print the C pattern in a post-apocalyptic style
void print_c_pattern(){

    // Set the size of the grid
    int size = 10;

    // Randomly generate a starting point for the pattern
    int x_start = rand() % (size - 4) + 2;
    int y_start = rand() % (size - 4) + 2;

    // Print out the header
    printf("\n\n\n   ~~~ WELCOME TO THE POST-APOCALYPTIC C ZONE ~~~\n\n\n");

    // Print out the C pattern
    for(int i=0; i<size; i++){
        for(int j=0; j<size; j++){
            if(i==0 || i==size-1){
                printf("=");
            }
            else if(j==0 || j==size-1){
                printf("|");
            }
            else if(i==x_start && j>=y_start && j<=y_start+2){
                printf("#");
            }
            else if(i>=x_start+1 && i<=x_start+2 && j==y_start){
                printf("#");
            }
            else{
                printf(" ");
            }
        }
        printf("\n");
    }

    // Print out the footer
    printf("\n\n\n   ~~~ THIS IS YOUR SURVIVAL CAMP ~~~\n\n\n");
}

int main(){

    // Set the seed for the random number generator
    srand(time(NULL));

    // Call the function to print the C pattern in a post-apocalyptic style
    print_c_pattern();

    return 0;
}