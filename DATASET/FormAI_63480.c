//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>

/**
* Function to calculate the checksum of a given string
*
* @param str the input string
* @param len the length of the input string
* @return the checksum value
*/
int calculate_checksum(char *str, int len) {
    int i, sum = 0;

    for (i = 0; i < len; i++) {
        sum += str[i];
    }

    return sum % 256;
}

int main() {
    char input_string[50];
    int checksum;

    printf("Enter a string (max 50 characters): ");
    scanf("%s", input_string);

    checksum = calculate_checksum(input_string, strlen(input_string));

    printf("Checksum for string \"%s\" = %d\n", input_string, checksum);

    return 0;
}