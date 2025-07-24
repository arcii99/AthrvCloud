//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: lively
#include<stdio.h>

int main(){
    printf("Welcome to the Checksum Calculator!\n");
    printf("Please enter a string of numbers separated by spaces:\n");

    int inputArray[100]; // array to store user input
    int sum = 0; // initialize checksum value to zero

    // loop through user input and add each number to the checksum
    for(int i=0; i<100; i++){
        scanf("%d", &inputArray[i]); // read user input
        if(inputArray[i] == -1){ // end of input
            break;
        }
        sum += inputArray[i];
    }

    printf("Checksum: %d\n", sum);

    return 0;
}