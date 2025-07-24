//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: relaxed
#include <stdio.h>

int main() {
    int sum = 0; // initialize sum to 0
    char input[100]; // array to hold user input, assuming max input size of 100
    printf("Enter string to calculate checksum: ");
    scanf("%s", input); // read input string from user
    
    for (int i = 0; input[i] != '\0'; i++) { // iterate over each character in the string
        sum += input[i]; // add integer value of character to the sum
    }

    printf("Checksum: %d", sum); // print final sum as checksum value
    return 0; // end program
}