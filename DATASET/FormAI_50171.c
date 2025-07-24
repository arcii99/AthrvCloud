//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: mind-bending
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int main() {

    // Welcome to the mind-bending world of cryptography!

    printf("Enter a string to be hashed: ");
    char s[100];
    scanf("%s", s);

    // Step 1: Clear your mind and focus on the task at hand

    // Step 2: Find the length of the string

    int len = strlen(s);

    // Step 3: Create a magic number

    int magic = 42;

    // Step 4: Initialize some variables

    int i, j, k;
    long long sum = 0;
    double root = 0;

    // Step 5: Do some math

    for(i = 0; i < len; i++) {
        sum += (int)s[i] * pow(magic, i);
    }

    // Step 6: Take the nth root of the sum, where n is the length of the string

    root = pow(sum, 1.0 / len);

    // Step 7: Print out the hash and let the user marvel at your brilliance

    printf("The hash of \"%s\" is %.10lf\n", s, root);

    return 0;
}