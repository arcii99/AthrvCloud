//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/* Let's generate a unique C Cryptographic hash function example program in a fun way */

/* Let's begin by defining our hash function */
char* my_hash_function(char* input_string) {
    srand(time(NULL));
    int hash = rand() % 10000 + 1; // generate a random number between 1 and 10000
    int len = strlen(input_string);
    for (int i = 0; i < len; i++) {
        if (i % 2 == 0) { // use a simple algorithm to modify the hash
            hash += input_string[i];
        } else {
            hash *= input_string[i];
        }
    }
    char* hash_str = malloc(sizeof(char) * 10); // allocate memory for the hash string
    sprintf(hash_str, "%d", hash); // convert the hash integer to a string
    return hash_str;
}

int main() {
    char input_string[100];
    printf("Enter a string to hash:");
    scanf("%s", input_string);
    char* hash = my_hash_function(input_string);
    printf("The hash of %s is %s\n", input_string, hash);
    free(hash); // free allocated memory
    return 0;
}