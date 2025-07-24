//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: brave
#include <stdio.h>

/* Calculates the C checksum of a given string */

unsigned char c_checksum(char* str){

    unsigned char sum = 0;
    int i;

    for(i = 0; str[i] != '\0'; i++){

        sum = (sum + str[i]) % 256;

    }

    /* Perform a one's complement of the sum */
    sum = ~sum;

    return sum;

}

int main(){

    char str[100];

    printf("Enter a string: ");
    fgets(str, 100, stdin);

    /* Remove trailing newline character */
    str[strcspn(str, "\n")] = '\0';

    unsigned char checksum = c_checksum(str);

    printf("The C checksum of '%s' is %d\n", str, checksum);

    return 0;

}