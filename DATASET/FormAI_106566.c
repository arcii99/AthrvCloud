//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: irregular
#include <stdio.h>
#include <stdlib.h>

int main() {
    char input[1000];
    int i, checksum = 0;
    
    printf("Enter the input string: ");
    fgets(input, 1000, stdin); // Reading the input string
    
    for(i=0; input[i]!='\0'; i++) {
        if(input[i] == ' ') {
            printf("\n * Skipping space character at index %d *\n", i);
            continue; // Skipping the space characters
        }
        else if(input[i] < 48 || input[i] > 122) { // Checking for ASCII values between 48 to 122 (i.e., alphanumeric characters)
            printf("\n * Invalid character found at index %d *\n", i);
            return 0; // Terminating the program if non-alphanumeric character is found
        } else {
            printf("\nProcessing character '%c' at index %d", input[i], i);
            checksum += input[i];
        }
    }
    printf("\n* Checksum value is: %d *\n", checksum); // Displaying checksum value
    
    return 0;// END of program
}