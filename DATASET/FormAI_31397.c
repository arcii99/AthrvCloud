//FormAI DATASET v1.0 Category: Educational ; Style: enthusiastic
#include<stdio.h>

/* This program will generate a Fibonacci sequence for any range of numbers specified by the user. 
   The Fibonacci sequence is a series of numbers in which each number (Fibonacci number) is the sum of the two preceding ones.
   This program will also display the sequence in an artistic way to impress the user. */

int main() {

    int start, end, first, second, temp, count = 0; 

    printf("Welcome to the Fibonacci Sequence Generator. Let's get started!\n\n");

    printf("Please enter the starting number of the range: ");
    scanf("%d", &start);

    printf("Please enter the ending number of the range: ");
    scanf("%d", &end);

    first = 0;
    second = 1;
    
    while(first <= end) {
        if(first >= start) {
            printf("%d ", first); // print artistic sequence 
            count++;
            if(count % 5 == 0) {
                printf("\n");
            }
        }
      
        temp = first + second;
        first = second;
        second = temp;
    }
    
    printf("\n\nGreat job! Your Fibonacci sequence has been generated.\n");
    return 0;
}