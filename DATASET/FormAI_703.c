//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: intelligent
#include<stdio.h>
#include<stdlib.h>

int calculate_checksum(char* input_string) {
    // initialize the variables
    int i = 0;
    int checksum = 0;
    
    // loop through the string to calculate the checksum
    while(input_string[i] != '\0') {
        checksum += (int)input_string[i];
        i++;
    }
    
    return checksum;
}

int main() {
    char* input_string = NULL;
    size_t len = 0;
    
    // prompt the user to enter the string for which they want the checksum
    printf("Enter the string for which you want to calculate the checksum:\n");
    getline(&input_string, &len, stdin);
    
    // calculate the checksum
    int checksum = calculate_checksum(input_string);
    
    // print the checksum
    printf("The checksum of the string %s is: %d\n", input_string, checksum);
    
    // free the memory allocated for input_string
    free(input_string);
    return 0;
}