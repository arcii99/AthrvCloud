//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int checksum(char *s) {
    int sum = 0;
    for (int i = 0; i < strlen(s); i++) {
        sum += s[i];
    }
    return sum % 256;
}

int main() {
    printf("Welcome to the Checksum Calculator!\n");
    printf("Enter the string to calculate the checksum: ");
    char input[1000];
    fgets(input, 1000, stdin);
    int sum = checksum(input);
    printf("The checksum of \"%s\" is %d.\n", input, sum);
    printf("Thanks for using the Checksum Calculator!\n");
    return 0;
}