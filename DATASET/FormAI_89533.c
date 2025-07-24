//FormAI DATASET v1.0 Category: Fractal Generation ; Style: funny
#include <stdio.h>
#include <stdlib.h>

int main(){
    printf("Welcome to the crazy world of fractals!\n");

    int size;
    printf("Enter the size of the fractal: ");
    scanf("%d", &size);

    printf("\n");

    int **fractal = malloc(size * sizeof(int *));
    for(int i = 0; i < size; i++){
        fractal[i] = malloc(size * sizeof(int));
        for(int j = 0; j < size; j++){
            fractal[i][j] = rand() % 2;
        }
    }

    printf("Generating fractal...\n\n");

    for(int row = 0; row < size; row++){    
        for(int col = 0; col < size; col++){
            if(fractal[row][col] == 0){
                printf("*");
            }
            else{
                printf("#");
            }
        }
        printf("\n");
    }

    printf("\nWhoa! That's one funky looking fractal!\n");

    for(int i = 0; i < size; i++){
        free(fractal[i]);
    }
    free(fractal);

    printf("\nThanks for playing with fractals! See you next time.\n");

    return 0;
}