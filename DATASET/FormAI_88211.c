//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: surprised
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

void hash(const char *input_string, char *output_hash) {
    const int prime_number = 31;
    const int max_length = 200;
    int hash_value = 0;
    int prime_power = 1;

    for (int i = 0; i < strlen(input_string); i++) {
        hash_value = (hash_value + (input_string[i] - 'a' + 1) * prime_power) % max_length;
        prime_power = (prime_power * prime_number) % max_length;
    }

    sprintf(output_hash, "%d", hash_value);
}

int main() {
    printf("Hey there! This is a unique C Cryptographic hash function example program.\n");
    char input_string[100], output_hash[10];

    printf("Enter a string to hash: ");
    scanf("%s", input_string);
    hash(input_string, output_hash);

    printf("Hash of %s is: %s\n", input_string, output_hash);

    return 0;
}