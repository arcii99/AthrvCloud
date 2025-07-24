//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: mathematical
#include <stdio.h>
#include <math.h>

/* This is a unique cryptographic hash function that uses mathematical operations */

int hash (char* str) {
    int i;
    int length = strlen(str);
    int sum = 0;
    int product = 1;
    for (i = 0; i < length; i++) {
        sum += str[i] * pow(2, i);
        product *= str[i] * pow(3, i);
    }
    return (sum * product) % 100000007;
}

int main() {
    char str[100];
    printf("Enter a string to hash: ");
    scanf("%s", str);
    int hashed = hash(str);
    printf("Hashed value of the string \"%s\" is %d.", str, hashed);
    return 0;
}