//FormAI DATASET v1.0 Category: Pattern printing ; Style: curious
#include <stdio.h>

// Curious C Pattern Printing Program

int main() {
    int rows, i, j, k, space;
    
    printf("How many rows would you like in your pattern? ");

    while (scanf("%d", &rows) != 1 || rows < 1 || rows > 10){
        printf("Please enter a number between 1 and 10: ");
        while(getchar() != '\n');
    }

    printf("\n");

    for (i = 1; i <= rows; i++){ 
        
        if (i == 1){
            printf("Yay! We're starting! \n");
        }
        else{
            printf("Wonderful job, %d rows down! Let's keep going! \n", i-1);
        }

        for(space = i; space < rows; space++){
            printf(" ");
        }

        for(j = 1; j <= i; j++){
            printf("*");
        }
        for (k = 1; k < i; k++){
            printf("*");
        }

        printf("\n");
    }

    printf("\nWe did it! How does it look?\n");

    return 0;
}