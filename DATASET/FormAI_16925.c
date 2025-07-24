//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: funny
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

// A funny cryptographic hash function that returns bacon!
char *bacon_hash(char *input) {
    srand(time(NULL)); // seed random number generator with current time
    
    int length = strlen(input);
    char *output = (char*) malloc(length * sizeof(char));
    
    for (int i = 0; i < length; i++) {
        int random_num = rand() % 2; // randomly choose 0 or 1
        if (random_num == 0) {
            output[i] = 'b';
        } else {
            output[i] = 'a';
        }
    }
    
    printf("You inputted: %s\n", input);
    printf("Bacon Hash: %s\n", output);
    
    return output;
}

int main() {
    char input[50] = {0};
    printf("Enter a string to hash: ");
    scanf("%s", input);
    
    char *hash = bacon_hash(input);
    free(hash);
    
    return 0;
}