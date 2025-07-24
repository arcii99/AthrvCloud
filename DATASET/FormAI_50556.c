//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: peaceful
#include <stdio.h>

int main() {
    char input[100];
    int sum = 0;
    
    printf("Enter a string to calculate checksum: ");
    fgets(input, sizeof(input), stdin); // read input string
    
    for (int i = 0; input[i] != '\0'; i++) {
        sum += input[i]; // add ASCII value of each character to sum
    }
    
    int checksum = sum % 256; // calculate checksum using modulus 256
    
    printf("Checksum of '%s' is %d\n", input, checksum);
    return 0;
}