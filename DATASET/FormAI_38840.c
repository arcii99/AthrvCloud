//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: cheerful
#include <stdio.h>

// Function to calculate checksum from input string
int checksum_calculator(char str[]) {
    int checksum = 0, i = 0;
    
    // Loop through string and add ASCII value of each character to checksum
    while (str[i] != '\0') {
        checksum += (int) str[i];
        i++;
    }
    
    // Return checksum
    return checksum;
}

int main() {
    char input_str[100];
    printf("*** Welcome to the Checksum Calculator! ***\n");
    
    // Ask user for input string
    printf("Please enter a string to calculate its checksum:\n");
    scanf("%s", input_str);
    
    // Call checksum_calculator function and print result
    int checksum = checksum_calculator(input_str);
    printf("The checksum of input string %s is %d.\n", input_str, checksum);
    
    return 0;
}