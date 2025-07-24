//FormAI DATASET v1.0 Category: Recursive ; Style: bold
#include <stdio.h>

/* This program will recursively print out all even numbers from 0 to the number entered by the user */

void printEven(int num){
    if(num == 0){ // Base case
        return;
    }
    else{
        printEven(num-1); // Recursive case
        if(num % 2 == 0){ // Check if number is even
            printf("%d ", num); // Print out even number
        }
    }
}

int main(){
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    printf("Even numbers from 0 to %d: ", num);
    printEven(num); // Call the printEven function
    return 0;
}