//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: cheerful
#include <stdio.h>

int main() {
    char input[100];
    int length, sum = 0, i, checksum;
    
    printf("Welcome to the Unique Checksum Calculator!\n");
    printf("Please enter the input string: ");
    scanf("%s", input);
    
    length = strlen(input);
    
    for(i=0; i<length; i++) {
        sum += input[i];
        printf("Added %d to the running total.\n", input[i]);
    }
    
    checksum = sum % 10;
    
    printf("The final checksum is %d!\n", checksum);
    printf("Thank you for using the Unique Checksum Calculator, have a great day!\n");
    
    return 0;
}