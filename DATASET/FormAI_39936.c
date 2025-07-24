//FormAI DATASET v1.0 Category: Pattern printing ; Style: secure
#include <stdio.h>
#include <stdbool.h>

// Function to check if the given number is even
bool isEven(int num){
    return (num % 2 == 0);
}

// Function to print a C pattern with the given number of rows
void printCPattern(int numRows){
    int midRow = numRows / 2;
    for(int row = 0; row < numRows; row++){
        for(int col = 0; col < numRows; col++){
            // Print the "C" character in the first and last column
            if(col == 0 || col == numRows-1){
                printf("C");
            }
            // Print the "C" characters in the middle rows
            else if(row == midRow){
                printf("C");
            }
            // Print a space character everywhere else
            else{
                printf(" ");
            }
        }
        printf("\n");
    }
}

int main(){
    int num;
    printf("Enter the number of rows for the C pattern: ");
    scanf("%d", &num);
    if(isEven(num)){
        printf("Number of rows must be an odd number.\n");
        return 0;
    }
    printCPattern(num);
    return 0;
}