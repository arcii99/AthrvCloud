//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: innovative
#include <stdio.h>
#include <stdlib.h>

int main() {

    char data[100], checksum[10], temp[10];
    int i, j, sum = 0, checkSumLen;

    // Input data
    printf("Enter the data: ");
    gets(data);

    // Calculate the sum of ASCII values of input data
    for(i=0; data[i]!='\0'; i++) {
        sum += (int) data[i];
    }

    // Convert sum to hexadecimal string
    sprintf(temp, "%X", sum);

    // Calculate the checksum length
    checkSumLen = strlen(temp);

    // Store the last two digits of checksum in checksum array
    for(i=checkSumLen-2, j=0; i<checkSumLen; i++, j++) {
        checksum[j] = temp[i];
    }
    checksum[2] = '\0';

    // Output the checksum
    printf("The checksum of input data is: %s", checksum);

    return 0;
}