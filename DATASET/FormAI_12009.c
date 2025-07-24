//FormAI DATASET v1.0 Category: Error handling ; Style: cheerful
// Let's write a program to handle errors, with a touch of cheerfulness!

#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("Hello there! Let's handle some errors with a smile! \n");
    int num = 0; // variable to store a number entered by user
    printf("Please enter a number: ");
    scanf("%d", &num); // read input from user

    // let's make sure the number entered is not negative
    if (num < 0) {
        printf("Oopsie! Negative number entered. Let's fix that with the power of positivity! \n");
        num = abs(num);
        printf("Your number has successfully been converted to its absolute value: %d\n", num);
    }

    // let's attempt to divide the number by 0 to generate an error
    printf("Let's now try to divide %d by 0 and see what happens! \n", num);
    int result;
    result = num / 0; // attempting to divide by 0

    // if we get here, the program has not crashed, which means it has handled the error gracefully!
    printf("\nWow, no errors occurred! It looks like our program is as tough as nails! \n");
    printf("We hope this program has brought a smile to your face! Have a great day! \n");

    return 0;
}