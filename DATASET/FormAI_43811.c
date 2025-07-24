//FormAI DATASET v1.0 Category: Pattern printing ; Style: portable
#include<stdio.h>
#include<stdlib.h>

int main(){
    int height, width, row, col, count=1;

    // Prompt user to enter height and width of pattern
    printf("Enter height of pattern: ");
    scanf("%d", &height);
    printf("Enter width of pattern: ");
    scanf("%d", &width);

    // Loop through each row
    for(row=1; row<=height; row++){

        // Loop through each column
        for(col=1; col<=width; col++){

            if(col==1){ // Print '*' only at the beginning of a row
                printf("*");
            }

            else if(row==1 || row==height){ // Print '*' for the first and last row
                printf("*");
            }
            else if(count%2==0){ // Print '-' for even number count
                printf("-");
            }
            else{ // Print '.' for odd number count
                printf(".");
            }
            count++;
        }
        printf("\n"); // Move to the next line after each row
        count++; // Increment the count variable after each row
    }
    return 0;
}