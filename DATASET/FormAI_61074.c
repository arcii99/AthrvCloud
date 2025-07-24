//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_LENGTH 10

char *convert_to_hex(char input[MAX_INPUT_LENGTH]);

int main() {
    char input[MAX_INPUT_LENGTH];
    printf("Enter a decimal number: ");
    fgets(input, MAX_INPUT_LENGTH, stdin);
    char *hex = convert_to_hex(input);
    printf("Hexadecimal equivalent: %s\n", hex);
    free(hex);
    return 0;
}

char *convert_to_hex(char input[MAX_INPUT_LENGTH]) {
    int num = atoi(input);
    char hex[MAX_INPUT_LENGTH];
    int i = 0;
    while(num > 0) {
        int remainder = num % 16;
        if(remainder < 10) {
            hex[i++] = remainder + '0';
        } else {
            hex[i++] = remainder + 55; // Add ASCII value of A (65) - 10
        }
        num /= 16;
    }
    hex[i] = '\0';
    int len = strlen(hex);
    char *output = (char*) malloc((len+1) * sizeof(char));
    for(i = 0; i < len; i++) {
        output[i] = hex[len-i-1];
    }
    output[len] = '\0';
    return output;
}