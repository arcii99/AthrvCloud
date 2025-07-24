//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: introspective
#include <stdio.h>

/*
* This is a C program that accepts user input string, calculates its checksum
* and displays the result to the user.
* The program makes use of introspective techniques to check for errors and validate user input.
*/

int main(void) {

    char str[50];
    int sum = 0, i;
    
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin); // get string from user input
    
    // Make sure the string is not empty
    if(str[0] == '\n'){
        printf("Error: String cannot be empty.");
        return 0;
    }
    
    // Loop through the string and calculate the checksum
    for(i = 0; str[i] != '\0'; i++) {
        sum += str[i];
    }
    
    // Introspect the result and display it to the user
    if(sum == 0) {
        printf("The checksum of the string is: %d", sum);
    }
    else {
        printf("The checksum of the string is: %d", sum % 255);
    }
    
    return 0;
}