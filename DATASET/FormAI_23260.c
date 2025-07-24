//FormAI DATASET v1.0 Category: Educational ; Style: Dennis Ritchie
#include <stdio.h> //standard input-output library

int main() { //main function

    int num; //declaring variable to store input

    printf("Enter a number: "); //asking user for input
    scanf("%d", &num); //taking input from user and storing it in 'num' variable

    if(num % 2 == 0){ //if 'num' is an even number
        printf("%d is an even number!", num); //printing out that the number is even
    }
    else{ //if 'num' is an odd number
        printf("%d is an odd number!", num); //printing out that the number is odd
    }

    return 0; //returning 0 indicating successful execution of program
}