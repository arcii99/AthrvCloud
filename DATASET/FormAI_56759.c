//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_LENGTH 5000 // maximum length of input string
#define HASH_PRIME 5381 // prime number for hash function

// function to calculate hash value of a string using djb2 algorithm
unsigned long calculate_hash(char *str) {
    unsigned long hash = HASH_PRIME;
    int c;
    while ((c = *str++)) {
        hash = ((hash << 5) + hash) + c;
    }
    return hash;
}

// function to add watermark to a string
char* add_watermark(char *input) {
    char *watermark = "This is a digital watermark."; // watermark string
    char *output = malloc(sizeof(char) * (strlen(input) + strlen(watermark))); // allocate memory for output string
    strcpy(output, input);
    strcat(output, watermark); // concatenate input string with watermark
    return output;
}

// function to verify if a string has a valid watermark
int verify_watermark(char *input) {
    char *watermark = "This is a digital watermark."; // watermark string
    char *substr = strstr(input, watermark); // find substring in input
    if (substr == NULL) {
        return 0; // watermark not found
    } else {
        int index = (int)(substr - input); // get index of first character of watermark
        unsigned long hash = calculate_hash(input); // calculate hash value of input string
        return (index == strlen(input) - strlen(watermark)) && (hash % 2 == 0); // verify index and hash value
    }
}

int main() {
    char input[MAX_INPUT_LENGTH]; // input string
    printf("Enter a string: ");
    fgets(input, MAX_INPUT_LENGTH, stdin); // read input string from user
    char *watermarked_string = add_watermark(input); // add watermark to input string
    printf("Watermarked string: %s\n", watermarked_string); // print watermarked string
    int verified = verify_watermark(watermarked_string); // verify if watermarked string has valid watermark
    if (verified) {
        printf("Watermark verified!\n"); // if valid watermark, print success message
    } else {
        printf("Invalid watermark!\n"); // if invalid watermark, print error message
    }
    free(watermarked_string); // free memory allocated for watermarked string
    return 0;
}