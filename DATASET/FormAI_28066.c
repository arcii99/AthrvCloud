//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: Donald Knuth
/* The following code is a Checksum Calculator program written in Donald Knuth style */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function to calculate the checksum
int calculateChecksum(char s[]) {
    int sum = 0;
    int length = strlen(s);
    // loop through each character and add its ASCII value to the sum
    for(int i=0; i<length; i++) {
        sum += s[i];
    }
    return sum;
}

int main() {
    char input[256];
    int checksum;
    printf("Enter the input string: ");
    scanf("%s", input); // read the input string
    checksum = calculateChecksum(input); // calculate the checksum
    printf("Checksum: %d\n", checksum);  // print the checksum
    return 0;
}