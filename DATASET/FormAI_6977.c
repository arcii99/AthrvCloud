//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: scientific
#include <stdio.h>
#include <stdint.h>
#include <string.h>

// Our custom cryptographic hash function
void my_hash_function(const char* input, char* output) {
    uint32_t hash_value = 5381;
    uint32_t c;

    while (*input != '\0') {
        c = (uint32_t) *input;
        hash_value = ((hash_value << 5) + hash_value) + c;  // hash_value * 33 + c
        input++;
    }

    // Convert hash_value to hexadecimal string
    sprintf(output, "%08x", hash_value);
}

int main() {
    const char* input_str = "Hello World!";
    char output_str[9];  // 8 hexadecimal digits plus null terminator

    my_hash_function(input_str, output_str);
    printf("Input string: %s\n", input_str);
    printf("Hash output: %s\n", output_str);

    return 0;
}